import fs from 'fs';
import { parse } from 'csv-parse';

type RecordCsv = {
  FIPS: string;
  Admin2: string;
  State: string;
  Country_Region: string;
  Last_Update: string;
  Lat: number;
  Long_: number;
  Confirmed: number;
  Deaths: number;
  Recovered: string;
  Active: number;
  Combined_Key: string;
  Incidence_Rate: string;
  Case_Fatality_Ratio: string;
}

const processFile = async () : Promise<RecordCsv[]> => {
  const records : Array<RecordCsv> = [];
  const parser = fs
    // path to data.csv
    .createReadStream(`${__dirname}/../data.csv`)
    .pipe(parse({
    // CSV options if any
    }));
  
  // não pode ser feito usando map pois o parser é um stream e map não processa stream
  for await (const record of parser) {
    
    if(record[0] == 'FIPS'){ // skip header
      continue;
    } // skip header
    const arrayToObject = {
      FIPS: record[0],
      Admin2: record[1],
      State: record[2],
      Country_Region: record[3],
      Last_Update: record[4],
      Lat: Number(record[5]),
      Long_: Number(record[6]),
      Confirmed: Number(record[7]),
      Deaths: Number(record[8]),
      Recovered: record[9],
      Active: Number(record[10]),
      Combined_Key: record[11],
      Incidence_Rate: record[12],
      Case_Fatality_Ratio: record[13],
    }
    records.push(arrayToObject);
  }
  parser.destroy();

  return records;
};

(async () => {
  const records : RecordCsv[] = await processFile();
  const sumByStates : Object = await records
    .filter(record => record.State != '')
    .reduce((acc, curr) => {
      if(!acc[curr.State]){
        acc= {
          ...acc,
          [curr.State]: curr.Confirmed
        };
      } else {
        acc = {
          ...acc,
          [curr.State]: acc[curr.State] + curr.Confirmed
        }
      }
      return acc;
    }, {})

  const mostConfirmedStates = Object.entries(sumByStates)
    .sort((a, b) => {
      return b[1] - a[1];
    })
    .slice(0,3)
    .sort((a, b) => {
      return b[0].localeCompare(a[0]);
    });
    
  console.log("1: ", mostConfirmedStates);

})();


(async () => {
  const records : RecordCsv[] = await processFile();
  const sumByStates : Object = await records
    .filter(record => record.State != '')
    .reduce((acc, curr) => {
      if(!acc[curr.State]){
        acc= {
          ...acc,
          [curr.State]: curr.Active
        };
      } else {
        acc = {
          ...acc,
          [curr.State]: acc[curr.State] + curr.Active
        }
      }
      return acc;
    }, {})

  const lowestFiveActiveStates = Object.entries(sumByStates)
    .sort((a, b) => {
      return b[1] - a[1];
    })
    .slice(0,10)
    .reverse()
    .slice(0,5)
    .reduce((acc, curr) => {
      return acc += curr[1]
    },0);

  console.log('2:', lowestFiveActiveStates);

})();

(async () => {
  const records : RecordCsv[] = await processFile();

  const highestDeathCountry : RecordCsv  = await records
    .filter(record => record.Lat < 0)
    .sort((a, b) => {
      return b.Deaths - a.Deaths;
    })
    .slice(0,1)[0];

  console.log('3:', highestDeathCountry.Deaths);

})();

(async () => {
  const records : RecordCsv[] = await processFile();

  const highestDeathCountry : RecordCsv = await records
    .filter(record => record.Lat > 0)
    .sort((a, b) => {
      return b.Deaths - a.Deaths;
    })
    .slice(0,1)[0];

  console.log('4:', highestDeathCountry.Deaths);

})();

(async () => {
  const records : RecordCsv[] = await processFile();
  const sumByStates : Object = await records
    .filter(record => record.State != '')
    .reduce((acc, curr) => {
      if(!acc.hasOwnProperty(curr.State)){
        acc= {
          ...acc,
          [curr.State]: {
            Confirmed: curr.Confirmed,
            Active: curr.Active,
          }
        };
      } else {
        acc = {
          ...acc,
          [curr.State]: {
            Confirmed: acc[curr.State] + curr.Confirmed,
            Active: acc[curr.State] + curr.Active,
          }
        }
      }
      return acc;
    }, {})

  const sumOfActiveCasesFromConfimedValueIsGreaterThen1m = Object.entries(sumByStates)
    .filter(record => record[1].Confirmed > 1000000)
    .reduce((acc, curr) => {
      return acc += curr[1].Active
    }, 0)

  console.log("5: ", sumOfActiveCasesFromConfimedValueIsGreaterThen1m);

})();