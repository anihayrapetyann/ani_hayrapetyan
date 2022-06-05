CREATE DATABASE Library;
USE Library;
-- DROP DATABASE Library;
 
 CREATE TABLE Authors (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Authors_Name VARCHAR(20),
    Authors_Surname VARCHAR(60)
 );
 
 CREATE TABLE Publisher (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    `Name` VARCHAR(50)
 );
 
 CREATE TABLE Users (
   Id INT AUTO_INCREMENT PRIMARY KEY,
   User_Name VARCHAR(20),
   User_Surname VARCHAR(20)
   );
 
 CREATE TABLE Books (
    Books_Id INT AUTO_INCREMENT PRIMARY KEY,
    Title VARCHAR(200),
    Pub_Date DATE,
    Authors_Id INT,
    Publisher_Id INT,
    CONSTRAINT FK_books_authors FOREIGN KEY(Authors_Id ) REFERENCES Authors(Id),
    CONSTRAINT FK_books_publisher FOREIGN KEY (Publisher_Id) REFERENCES Publisher(Id)
 );
 
 CREATE TABLE Subscribers (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    NAME VARCHAR(30),
    Surname VARCHAR(50),
    Birthdate DATE,
    Address VARCHAR(255)
 );
 
 
 CREATE TABLE Book_Subscriber (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Subscriber_Id INT,
    Book_Id INT,
    Taken_Date DATE,
    Returned_Date DATE,
    Deadline DATE,
    Users_Id INT,
    CONSTRAINT FK_books_subscribers_Subscribers FOREIGN KEY(Subscriber_Id) REFERENCES Subscribers(Id),
    CONSTRAINT FK_books_Subscribers FOREIGN KEY(Book_Id) REFERENCES Books( Books_Id),
    CONSTRAINT FK_books_Subscribers_users FOREIGN KEY(Users_Id) REFERENCES Users( Id)
 );
 
 CREATE TABLE Book_inventory (
 
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Book_Id INT,
    Subscriber_Id INT,
    Condition1 VARCHAR(50),
    `Status` VARCHAR(100),
    CONSTRAINT FK_inventory_book FOREIGN KEY (Book_Id) REFERENCES Books(Books_Id),
    CONSTRAINT FK_inventory_subscriber FOREIGN KEY(Subscriber_Id) REFERENCES Book_Subscriber(Id)
);
 
INSERT INTO Authors(Authors_Name, Authors_Surname)
VALUES
    ('Mark', 'Twain'),
    ('George', 'Orwell'),
    ('Lewis', 'Carrol'),
    ('Ernest', 'Hemingway'),
    ('William', 'Shakespeare'),
    ('Jane', 'Austen');
    
-- SELECT *
-- FROM Authors
-- WHERE Authors_Name LIKE 'wi%';
 
INSERT INTO Publisher (name)
VALUES
    ('CreateSpace Independent Publishing Platform'),
    ('Signet; 50th Anniversary edition'),
    ('Amereon Ltd; F edition'),
    ('Edit Print');
    
insert into Books (Title, Pub_Date, Authors_Id, Publisher_Id)
values
    ('The Adventures of Tom Sawyer', '2020-12-14', 1, 1),
    ('Animal Farm', '2004-04-06', 2, 2),
    ('Alices Adventures in Wonderland', '2020-11-14', 3, 1),
    ('Winner Take Nothing', '2014-06-16', 4, 3),
    ('As you like it', '1998-06-18', 5, 3),
    ('Pride and Prejudice', '2021-02-15', 6, 1);
    
INSERT INTO Users (User_Name, User_Surname)
VALUES
    ('John', 'Adams'),
    ('Peter', 'Smith'),
    ('Kate', 'Perry');
    
    
INSERT INTO Subscribers ( `Name`, Surname, Birthdate, Address )
VALUES
	('James',  'Wilson', '1998-06-17', 'Oxford'),
	('Robert', 'Lewis',  '1997-12-18', 'London'),
	('Thomas', 'Walker', '1997-04-1', 'Manchester'),
	('Nancy',  'Owen',   '1990-06-27', 'Liverpool'),
	('Sandra', 'Holmes', '1979-06-15', 'Wells'),
	('Ashley', 'Chapman', '2008-06-07', 'Bristol'),
	('Steven', 'Oldman', '2001-03-7', 'Linkoln');
 
INSERT INTO Book_Subscriber (Subscriber_Id, Book_Id, Taken_Date, Returned_Date, Deadline, Users_Id)
VALUES
	(1, 1, '2022-04-18', '2022-04-22', '2022-05-18', 1),
	(2, 3, '2022-04-18', '2022-04-21', '2022-05-18', 2),
	(3, 4, '2022-04-18',     NULL,     '2022-05-18', 1),
	(4, 2, '2022-04-18', '2022-06-22', '2022-05-18', 3),
	(5, 5, '2022-04-18',' 2022-04-20', '2022-05-17', 1),
    (6, 6, '2022-04-18', '2022-05-22', '2022-05-18', 3),
	(7, 6, '2022-04-18', '2022-04-20', '2022-05-17', 1);
 
INSERT INTO Book_inventory ( Book_Id, Subscriber_Id , Condition1, `Status`)
VALUES
	(2, 4, 'perfect', 'exists'),
	(1, 5, 'shabby',  'sent to repair'),
	(2, 1, 'perfect', 'does not exist'),
	(3, 2, 'torn',    'does not exist'),
	(5, 1, 'perfect', 'does not exist'),
	(1, 5, 'shabby',  'sent to repair'),
	(1, 1, 'perfect', 'exists'),
	(5, 5, 'shabby',  'exists'),
	(1, 1, 'perfect', 'exists'),
	(2, 1, 'perfect', 'exists'),
	(6, 5, 'shabby',  'exists'),
	(2, 1, 'perfect', 'exists'),
	(4, 7, 'torn',    'exists'),
	(4, 6, 'perfect', 'exists'),
	(4, 5, 'shabby',  'exists'),
	(6, 6, 'perfect', 'exists'),
	(5, 7, 'torn',    'exists'),
	(3, 3, 'perfect', 'exists'),
	(3, 3, 'shabby',  'exists'),
	(5, 5, 'perfect', 'exists'),
	(3, 3, 'torn',    'exists');
 
ALTER TABLE Book_inventory DROP FOREIGN KEY FK_inventory_subscriber;
 
ALTER TABLE Book_inventory DROP COLUMN Subscriber_Id;
 
ALTER TABLE Book_Subscriber
ADD COLUMN Inventory_Id int  AFTER Users_Id;
 
-- VIEW 1
CREATE VIEW Books_of_subscribers AS
SELECT s.Name, s.Surname, b.Title, a.Taken_Date, a.Returned_Date, a.Deadline, u.User_Name, u.User_Surname
FROM Subscribers s, Books b, Book_Subscriber a, Users u
WHERE a.Subscriber_Id = s.Id
AND a.Book_Id = b.Books_Id
AND a.Users_Id = u.Id;

SELECT *
FROM Books_of_subscribers;
 
 -- VIEW 2
CREATE VIEW Books_in_repair AS
SELECT b.Title
FROM Book_inventory a, Books b
WHERE `Status` = 'sent to repair'
AND a.Book_Id = b.Books_Id;
 
SELECT Books_in_repair.Title, COUNT(*) FROM Books_in_repair
GROUP BY Title;
 
SELECT s.Name, s.Surname, d.Taken_Date, d.Returned_Date, d.Deadline
FROM Subscribers s, Book_Subscriber d
WHERE  d.Subscriber_Id = s.Id  
AND d.Returned_Date IS NULL
AND d.Deadline < curdate();
-- or  d.Deadline < d.Returned_Date;
 
SELECT s.Name, s.Surname, d.Taken_Date, d.Returned_Date, d.Deadline
FROM Subscribers s, Book_Subscriber d
WHERE  d.Subscriber_Id = s.Id  
AND d.Deadline < d.Returned_Date;
 
SELECT Subscriber_Id, COUNT(*) FROM Book_Subscriber
WHERE Deadline < Returned_Date
OR Returned_Date IS NULL
GROUP BY Subscriber_Id;
 
-- select * from Books_in_repair;