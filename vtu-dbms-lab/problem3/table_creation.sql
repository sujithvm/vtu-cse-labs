-- Creating Student table

CREATE TABLE Student (
	regno VARCHAR(30) PRIMARY KEY,
	sname VARCHAR(30),
	major VARCHAR(30),
	bdate DATE 
); 

DESC Student;


-- Creating Course table

CREATE TABLE Course (
	course INT PRIMARY KEY,
	cname VARCHAR(30),
	dept VARCHAR(30)
); 

DESC Course;


-- Creating Enroll table

CREATE TABLE Enroll (
	regno VARCHAR(30) ,
	course INT,
	sem INT,
	marks INT,
	PRIMARY KEY (regno, course, sem),
	FOREIGN KEY (regno) REFERENCES Student(regno),
	FOREIGN KEY (course) REFERENCES Course(course)); 

DESC Enroll;


-- Creating Text table

CREATE TABLE Text (
	bookisbn INT PRIMARY KEY,
	booktitle VARCHAR(30),
	publisher VARCHAR(30),
	author VARCHAR(30)
);

DESC Text;


-- Creating BookAdoption table

CREATE TABLE BookAdoption (
	course INT NOT NULL,
	sem INT NOT NULL,
	bookisbn INT NOT NULL,
	PRIMARY KEY (course, sem, bookisbn),
	FOREIGN KEY (course) REFERENCES Course (course),
	FOREIGN KEY (bookisbn) REFERENCES Text (bookisbn)
); 

DESC BookAdoption;


