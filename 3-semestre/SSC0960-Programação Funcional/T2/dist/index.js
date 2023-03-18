"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __asyncValues = (this && this.__asyncValues) || function (o) {
    if (!Symbol.asyncIterator) throw new TypeError("Symbol.asyncIterator is not defined.");
    var m = o[Symbol.asyncIterator], i;
    return m ? m.call(o) : (o = typeof __values === "function" ? __values(o) : o[Symbol.iterator](), i = {}, verb("next"), verb("throw"), verb("return"), i[Symbol.asyncIterator] = function () { return this; }, i);
    function verb(n) { i[n] = o[n] && function (v) { return new Promise(function (resolve, reject) { v = o[n](v), settle(resolve, reject, v.done, v.value); }); }; }
    function settle(resolve, reject, d, v) { Promise.resolve(v).then(function(v) { resolve({ value: v, done: d }); }, reject); }
};
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const fs_1 = __importDefault(require("fs"));
const csv_parse_1 = require("csv-parse");
const processFile = () => __awaiter(void 0, void 0, void 0, function* () {
    var e_1, _a;
    const records = [];
    const parser = fs_1.default
        // path to data.csv
        .createReadStream(`${__dirname}/../data.csv`)
        .pipe((0, csv_parse_1.parse)({
    // CSV options if any
    }));
    try {
        // não pode ser feito usando map pois o parser é um stream e map não processa stream
        for (var parser_1 = __asyncValues(parser), parser_1_1; parser_1_1 = yield parser_1.next(), !parser_1_1.done;) {
            const record = parser_1_1.value;
            if (record[0] == 'FIPS') { // skip header
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
            };
            records.push(arrayToObject);
        }
    }
    catch (e_1_1) { e_1 = { error: e_1_1 }; }
    finally {
        try {
            if (parser_1_1 && !parser_1_1.done && (_a = parser_1.return)) yield _a.call(parser_1);
        }
        finally { if (e_1) throw e_1.error; }
    }
    parser.destroy();
    return records;
});
(() => __awaiter(void 0, void 0, void 0, function* () {
    const records = yield processFile();
    const sumByStates = yield records
        .filter(record => record.State != '')
        .reduce((acc, curr) => {
        if (!acc[curr.State]) {
            acc = Object.assign(Object.assign({}, acc), { [curr.State]: curr.Confirmed });
        }
        else {
            acc = Object.assign(Object.assign({}, acc), { [curr.State]: acc[curr.State] + curr.Confirmed });
        }
        return acc;
    }, {});
    const mostConfirmedStates = Object.entries(sumByStates)
        .sort((a, b) => {
        return b[1] - a[1];
    })
        .slice(0, 3)
        .sort((a, b) => {
        return b[0].localeCompare(a[0]);
    });
    console.log("1: ", mostConfirmedStates);
}))();
(() => __awaiter(void 0, void 0, void 0, function* () {
    const records = yield processFile();
    const sumByStates = yield records
        .filter(record => record.State != '')
        .reduce((acc, curr) => {
        if (!acc[curr.State]) {
            acc = Object.assign(Object.assign({}, acc), { [curr.State]: curr.Active });
        }
        else {
            acc = Object.assign(Object.assign({}, acc), { [curr.State]: acc[curr.State] + curr.Active });
        }
        return acc;
    }, {});
    const lowestFiveActiveStates = Object.entries(sumByStates)
        .sort((a, b) => {
        return b[1] - a[1];
    })
        .slice(0, 10)
        .reverse()
        .slice(0, 5)
        .reduce((acc, curr) => {
        return acc += curr[1];
    }, 0);
    console.log('2:', lowestFiveActiveStates);
}))();
(() => __awaiter(void 0, void 0, void 0, function* () {
    const records = yield processFile();
    const highestDeathCountry = yield records
        .filter(record => record.Lat < 0)
        .sort((a, b) => {
        return b.Deaths - a.Deaths;
    })
        .slice(0, 1)[0];
    console.log('3:', highestDeathCountry.Deaths);
}))();
(() => __awaiter(void 0, void 0, void 0, function* () {
    const records = yield processFile();
    const highestDeathCountry = yield records
        .filter(record => record.Lat > 0)
        .sort((a, b) => {
        return b.Deaths - a.Deaths;
    })
        .slice(0, 1)[0];
    console.log('4:', highestDeathCountry.Deaths);
}))();
(() => __awaiter(void 0, void 0, void 0, function* () {
    const records = yield processFile();
    const sumByStates = yield records
        .filter(record => record.State != '')
        .reduce((acc, curr) => {
        if (!acc.hasOwnProperty(curr.State)) {
            acc = Object.assign(Object.assign({}, acc), { [curr.State]: {
                    Confirmed: curr.Confirmed,
                    Active: curr.Active,
                } });
        }
        else {
            acc = Object.assign(Object.assign({}, acc), { [curr.State]: {
                    Confirmed: acc[curr.State] + curr.Confirmed,
                    Active: acc[curr.State] + curr.Active,
                } });
        }
        return acc;
    }, {});
    const sumOfActiveCasesFromConfimedValueIsGreaterThen1m = Object.entries(sumByStates)
        .filter(record => record[1].Confirmed > 1000000)
        .reduce((acc, curr) => {
        return acc += curr[1].Active;
    }, 0);
    console.log("5: ", sumOfActiveCasesFromConfimedValueIsGreaterThen1m);
}))();
//# sourceMappingURL=index.js.map