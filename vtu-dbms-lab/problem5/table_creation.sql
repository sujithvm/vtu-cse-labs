-- Creating Branch table

CREATE TABLE Branch (
	branchname VARCHAR(30) PRIMARY KEY,
	branchcity VARCHAR(30),
	assets REAL
);

DESC Branch;


-- Creating BankAccount table

CREATE TABLE BankAccount (
	accno INT PRIMARY KEY,
	branchname VARCHAR(30) REFERENCES Branch (branchname),
	balance REAL
);

DESC BankAccount;


-- Creating BankCustomer table

CREATE TABLE BankCustomer (
	customername VARCHAR(30) PRIMARY KEY,
	customerstreet VARCHAR(30),
	customercity VARCHAR(30)
);

DESC BankCustomer;


-- Creating Depositer table

CREATE TABLE Depositer (
	customername VARCHAR(30),
	accno INT,
	PRIMARY KEY (customername, accno),
	FOREIGN KEY (customername) REFERENCES BankCustomer (customername),
	FOREIGN KEY (accno) REFERENCES BankAccount (accno)
);

DESC Depositer;


-- Creating Loan table

CREATE TABLE Loan (
	loannumber INT PRIMARY KEY,
	branchname VARCHAR(30),
	amount REAL,
	FOREIGN KEY (branchname) REFERENCES Branch (branchname)
);

DESC Loan;


-- Creating Borrower table

CREATE TABLE Borrower (
	customername VARCHAR(30),
	loannumber INT,
	PRIMARY KEY (customername, loannumber),
	FOREIGN KEY (customername) REFERENCES BankCustomer (customername),
	FOREIGN KEY (LOANNUMBER) REFERENCES Loan (LOANNUMBER));

DESC Borrower;
