-- Creating Flights table

CREATE TABLE Flights (
		flno INT PRIMARY KEY,
		ffrom VARCHAR(15) NOT NULL,
		tto VARCHAR(15) NOT NULL,
		distance INTEGER,
		departs TIMESTAMP,
		arrives TIMESTAMP,
		price REAL
	);

DESC Flights;


-- Creating Aircraft table

CREATE TABLE Aircraft (
		aid INT PRIMARY KEY,
		aname VARCHAR(15),
		cruisingrange INT
	);

DESC Aircraft;


-- Creating Employees table

CREATE TABLE Employees (
		eid INT PRIMARY KEY,
		ename VARCHAR(15),
		salary REAL
	);

DESC Employees;


-- Creating Certified table

CREATE TABLE Certified (
	eid INT NOT NULL,
	aid INT NOT NULL,
	PRIMARY KEY (eid, aid), 
	FOREIGN KEY (eid) REFERENCES Employees (eid),
	FOREIGN KEY (aid) REFERENCES Aircraft (aid));

DESC Certified;

