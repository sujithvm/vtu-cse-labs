-- Creating Author table

CREATE TABLE Author (
	authorid INT PRIMARY KEY,
	name VARCHAR(30),
	city VARCHAR(30),
	country VARCHAR(30)
);

DESC Author;


-- Creating Publisher table

CREATE TABLE Publisher (
	publisherid INT PRIMARY KEY,
	name VARCHAR(30),
	city VARCHAR(30),
	country VARCHAR(30)  
);

DESC Publisher;


-- Creating BookCategory table

CREATE TABLE BookCategory (
	categoryid INT PRIMARY KEY,
	description VARCHAR(30)
);

DESC BookCategory;


-- Creating Catalog table

CREATE TABLE Catalog (
	bookid INT PRIMARY KEY,
	title VARCHAR(30),
	authorid INT REFERENCES Authos(authorid),
	publisherid INT REFERENCES PPUBLISHER(publisherid),
	categoryid INT REFERENCES BOOKCATEGORY(categoryid),
	yearofpublish INT,
	price INT
);

DESC Catalog;


-- Creating OrderDetails table

CREATE TABLE OrderDetails (
	orderno INT PRIMARY KEY,
	bookid INT REFERENCES Catalog(bookid),
	quantity INT
);

DESC OrderDetails;
