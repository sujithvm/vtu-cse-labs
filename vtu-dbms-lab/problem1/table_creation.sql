-- Creating Student table

CREATE TABLE Student (
		snum INT PRIMARY KEY NOT NULL,
		sname VARCHAR(15),
		major VARCHAR(15),
		slevel VARCHAR(15),
		age INT
	);

DESC Student;


-- Creating Faculty table

CREATE TABLE Faculty (
		fid INT PRIMARY KEY NOT NULL,
		fname VARCHAR(15),
		deptid INT
	);

DESC Faculty;


-- Creating Class table

CREATE TABLE Class (
		cname VARCHAR(15) PRIMARY KEY NOT NULL, 
		meets_at VARCHAR(15), 
		room VARCHAR(15), 
		fid INT REFERENCES Faculty (fid)
	);

DESC Class;


-- Creating Enrolled table

CREATE TABLE Enrolled (
		snum INT REFERENCES Student (snum),
		cname VARCHAR(15) REFERENCES Class (cname)
	);

DESC Enrolled;

