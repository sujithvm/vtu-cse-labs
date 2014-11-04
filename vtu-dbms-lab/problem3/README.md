Problem Statement
=================

### Relations

Consider the following database of student enrollment in courses & books adopted for each course.

STUDENT (regno: string, name: string, major: string, bdate:date)

COURSE (course #:int, cname:string, dept:string)

ENROLL ( regno:string, course#:int, sem:int, marks:int)

BOOK _ ADOPTION (course# :int, sem:int, book-ISBN:int)

TEXT (book-ISBN:int, book-title:string, publisher:string, author:string)


### Queries


i. Create the above tables by properly specifying the primary keys and the foreign keys.

ii. Enter at least five tuples for each relation.

iii. Demonstrate how you add a new text book to the database and make this book be adopted by some
department.

iv. Produce a list of text books (include Course #, Book-ISBN, Book-title) in the alphabetical order for courses
offered by the ‘CS’ department that use more than two books.

v. List any department that has all its adopted books published by a specific publisher.

vi. Generate suitable reports.

vii. Create suitable front end for querying and displaying the results.
