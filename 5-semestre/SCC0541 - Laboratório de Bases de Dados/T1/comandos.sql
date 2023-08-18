CREATE TABLE circuits (
  circuitId  SERIAL       NOT NULL PRIMARY KEY,
  circuitRef VARCHAR(255) NOT NULL UNIQUE,
  name       VARCHAR(255) NOT NULL,
  location   VARCHAR(255) DEFAULT NULL,
  country    VARCHAR(255) DEFAULT NULL,
  lat        FLOAT DEFAULT NULL,
  lng        FLOAT DEFAULT NULL,
  alt        INT DEFAULT NULL,
  url        VARCHAR(255) NOT NULL UNIQUE
);

CREATE TABLE constructors (
  constructorId SERIAL PRIMARY KEY NOT NULL,
  constructorRef VARCHAR(255) NOT NULL UNIQUE,
  name VARCHAR(255) NOT NULL UNIQUE,
  nationality VARCHAR(255) DEFAULT NULL,
  url VARCHAR(255) NOT NULL
);

CREATE TABLE drivers (
  driverId SERIAL PRIMARY KEY NOT NULL,
  driverRef VARCHAR(255) NOT NULL UNIQUE,
  number INTEGER DEFAULT NULL,
  code VARCHAR(3) DEFAULT NULL,
  forename VARCHAR(255) NOT NULL,
  surname VARCHAR(255) NOT NULL,
  dob DATE DEFAULT NULL,
  nationality VARCHAR(255) DEFAULT NULL,
  url VARCHAR(255) NOT NULL UNIQUE
);

CREATE TABLE seasons (
  year INTEGER PRIMARY KEY DEFAULT 0,
  url VARCHAR(255) NOT NULL UNIQUE
);

CREATE TABLE races (
  raceId SERIAL PRIMARY KEY,
  year INT NOT NULL DEFAULT 0,
  round INT NOT NULL DEFAULT 0,
  circuitId INT NOT NULL DEFAULT 0,
  name VARCHAR(255) NOT NULL,
  date DATE NOT NULL DEFAULT TO_DATE('0000-00-00','YYYY-MM-DD'),
  time TIME DEFAULT NULL,
  url VARCHAR(255) UNIQUE DEFAULT NULL,
  fp1_date DATE DEFAULT NULL,
  fp1_time TIME DEFAULT NULL,
  fp2_date DATE DEFAULT NULL,
  fp2_time TIME DEFAULT NULL,
  fp3_date DATE DEFAULT NULL,
  fp3_time TIME DEFAULT NULL,
  quali_date DATE DEFAULT NULL,
  quali_time TIME DEFAULT NULL,
  sprint_date DATE DEFAULT NULL,
  sprint_time TIME DEFAULT NULL,

  FOREIGN KEY (year) REFERENCES seasons(year),
  FOREIGN KEY (circuitId) REFERENCES circuits(circuitId)
);

CREATE TABLE driver_standings (
  driverStandingsId SERIAL NOT NULL PRIMARY KEY,
  raceId INTEGER NOT NULL DEFAULT 0,
  driverId INTEGER NOT NULL DEFAULT 0,
  points FLOAT NOT NULL DEFAULT 0,
  position INTEGER DEFAULT NULL,
  positionText VARCHAR(255) DEFAULT NULL,
  wins INTEGER NOT NULL DEFAULT 0,
  FOREIGN KEY (raceId) REFERENCES races (raceId),
  FOREIGN KEY (driverId) REFERENCES drivers (driverId)
);

CREATE TABLE status (
  statusId SERIAL NOT NULL PRIMARY KEY,
  status varchar(255) NOT NULL
);

CREATE TABLE lap_times (
  raceId INT,
  driverId INT,
  lap INT,
  position CHAR(3) NOT NULL,
  time INTERVAL NOT NULL,
  miliseconds INT,
	
	PRIMARY KEY (raceId, driverId, lap),
	FOREIGN KEY (raceId) REFERENCES races(raceId),
	FOREIGN KEY (driverId) REFERENCES drivers(driverId)
);

CREATE TABLE pit_stops (
  raceId INT NOT NULL,
  driverId INT NOT NULL,
  stop INT NOT NULL,
  lap INT NOT NULL,
  time TIME NOT NULL,
  duration VARCHAR(255) DEFAULT NULL,
  milliseconds INT DEFAULT NULL,
  PRIMARY KEY (raceId, driverId, stop),
  FOREIGN KEY (raceId) REFERENCES races(raceId),
  FOREIGN KEY (driverId) REFERENCES drivers(driverId)
);

CREATE TABLE qualifying (
  qualifyId SERIAL PRIMARY KEY,
  raceId INTEGER NOT NULL DEFAULT 0,
  driverId INTEGER NOT NULL DEFAULT 0,
  constructorId INTEGER NOT NULL DEFAULT 0,
  number INTEGER NOT NULL DEFAULT 0,
  position INTEGER DEFAULT NULL,
  q1 VARCHAR(255) DEFAULT NULL,
  q2 VARCHAR(255) DEFAULT NULL,
  q3 VARCHAR(255) DEFAULT NULL,
  FOREIGN KEY (raceId) REFERENCES races(raceId),
  FOREIGN KEY (driverId) REFERENCES drivers(driverId),
  FOREIGN KEY (constructorId) REFERENCES constructors(constructorId)
);

CREATE TABLE results (
  resultId SERIAL PRIMARY KEY,
  raceId INT NOT NULL DEFAULT 0,
  driverId INT NOT NULL DEFAULT 0,
  constructorId INT NOT NULL DEFAULT 0,
  number INT DEFAULT NULL,
  grid INT NOT NULL DEFAULT 0,
  position INT DEFAULT NULL,
  positionText VARCHAR(255) NOT NULL,
  positionOrder INT NOT NULL DEFAULT 0,
  points FLOAT NOT NULL DEFAULT 0,
  laps INT NOT NULL DEFAULT 0,
  time VARCHAR(255) DEFAULT NULL,
  milliseconds INT DEFAULT NULL,
  fastestLap INT DEFAULT NULL,
  rank INT DEFAULT 0,
  fastestLapTime VARCHAR(255) DEFAULT NULL,
  fastestLapSpeed VARCHAR(255) DEFAULT NULL,
  statusId INT NOT NULL DEFAULT 0,
  FOREIGN KEY (raceId) REFERENCES races(raceId),
  FOREIGN KEY (driverId) REFERENCES drivers(driverId),
  FOREIGN KEY (constructorId) REFERENCES constructors(constructorId),
  FOREIGN KEY (statusId) REFERENCES status(statusId)
);

CREATE TABLE airports (
  id INT PRIMARY KEY,
  ident VARCHAR(40) NOT NULL ,
  type VARCHAR(50) NOT NULL,
  name VARCHAR(255) NOT NULL,
  latdeg FLOAT NOT NULL ,
  longdeg FLOAT NOT NULL ,
  elevft VARCHAR(50),
  continent VARCHAR(20) DEFAULT NULL ,
  isocountry VARCHAR(20) NOT NULL ,
  isoregion VARCHAR(50) NOT NULL ,
  city VARCHAR(255),
  scheduled_service VARCHAR(255) NOT NULL ,
  gpscode VARCHAR(255),
  iatacode VARCHAR(255) DEFAULT NULL ,
  localcode VARCHAR(255),
  homelink VARCHAR(255) DEFAULT NULL,
  wikipedialink VARCHAR(255) DEFAULT NULL,
  keywords VARCHAR(400) DEFAULT NULL   
);

CREATE TABLE countries (
  id INT PRIMARY KEY,
  code VARCHAR(2) NOT NULL, 
  name VARCHAR(255) NOT NULL,
  continent VARCHAR(2) NOT NULL, 
  wikipedialink VARCHAR(255) NOT NULL,
  keyword VARCHAR(255) DEFAULT NULL 
);

CREATE TABLE geocities15k(
  geonameId INT PRIMARY KEY , 
  name VARCHAR(255) NOT NULL ,
  asciiName VARCHAR(255) NOT NULL ,
  alternateNames text,
  lat VARCHAR(20) NOT NULL ,
  long VARCHAR(20) NOT NULL ,
  featureClass CHAR(1) NOT NULL ,
  featureCode VARCHAR(255) NOT NULL ,
  Country VARCHAR(2) NOT NULL ,
  cc2 VARCHAR(10) DEFAULT NULL ,
  admin1code VARCHAR(50),
  admin2code VARCHAR(50) DEFAULT NULL ,
  admin3code VARCHAR(50) DEFAULT NULL ,
  admin4code VARCHAR(50) DEFAULT NULL ,
  population INT DEFAULT NULL ,
  elevation INT NOT NULL ,
  timezone VARCHAR(255) NOT NULL ,
  modification DATE NOT NULL 
);

\copy circuits FROM '/home/joao/Downloads/formula1/Data/circuits.csv' DELIMITER ',' CSV HEADER ENCODING 'UTF8' QUOTE '"' NULL '\N' ESCAPE '''';
\copy constructors FROM '/home/joao/Downloads/formula1/Data/constructors.csv' DELIMITER ',' CSV HEADER ENCODING 'UTF8' QUOTE '"' NULL '\N' ESCAPE '''';
\copy drivers FROM '/home/joao/Downloads/formula1/Data/drivers.csv' DELIMITER ',' CSV HEADER ENCODING 'UTF8' QUOTE '"' NULL '\N' ESCAPE '''';
\copy seasons FROM '/home/joao/Downloads/formula1/Data/seasons.csv' DELIMITER ',' CSV HEADER ENCODING 'UTF8' QUOTE '"' NULL '\N' ESCAPE '''';
\copy races FROM '/home/joao/Downloads/formula1/Data/races.csv' DELIMITER ',' CSV HEADER ENCODING 'UTF8' QUOTE '"' NULL '\N' ESCAPE '''';
\copy driver_standings FROM '/home/joao/Downloads/formula1/Data/driver_standings.csv' DELIMITER ',' CSV HEADER ENCODING 'UTF8' QUOTE '"' NULL '\N' ESCAPE '''';
\copy status FROM '/home/joao/Downloads/formula1/Data/status.csv' DELIMITER ',' CSV HEADER ENCODING 'UTF8' QUOTE '"' NULL '\N' ESCAPE '''';
\copy lap_times FROM '/home/joao/Downloads/formula1/Data/lap_times.csv' DELIMITER ',' CSV HEADER ENCODING 'UTF8' QUOTE '"' NULL '\N' ESCAPE '''';
\copy pit_stops FROM '/home/joao/Downloads/formula1/Data/pit_stops.csv' DELIMITER ',' CSV HEADER ENCODING 'UTF8' QUOTE '"' NULL '\N' ESCAPE '''';
\copy qualifying FROM '/home/joao/Downloads/formula1/Data/qualifying.csv' DELIMITER ',' CSV HEADER ENCODING 'UTF8' QUOTE '"' NULL '\N' ESCAPE '''';
\copy results FROM '/home/joao/Downloads/formula1/Data/results.csv' DELIMITER ',' CSV HEADER ENCODING 'UTF8' QUOTE '"' NULL '\N' ESCAPE '''';
\copy airports FROM '/home/joao/Downloads/formula1/Data/airports.csv' DELIMITER ',' CSV HEADER ENCODING 'UTF8' QUOTE '"' NULL '' ESCAPE '''';
\copy countries FROM '/home/joao/Downloads/formula1/Data/countries.csv' DELIMITER ',' CSV HEADER ENCODING 'UTF8' QUOTE '"' NULL '\N' ESCAPE '''';
\copy geocities15k FROM '/home/joao/Downloads/formula1/Data/CITIES15K.csv' DELIMITER ',' CSV HEADER ENCODING 'UTF8' QUOTE '"' NULL '\N' ESCAPE '''';