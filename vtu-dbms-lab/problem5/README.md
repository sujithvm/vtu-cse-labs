Problem Statement
=================

### Relations

Consider the following database for a banking enterprise

BRANCH(branch-name:string, branch-city:string, assets:real)

ACCOUNT(accno:int, branch-name:string, balance:real)

DEPOSITOR(customer-name:string, accno:int)

CUSTOMER(customer-name:string, customer-street:string, customer-city:string)

LOAN(loan-number:int, branch-name:string, amount:real)

BORROWER(customer-name:string, loan-number:int)


### Queries


i. Create the above tables by properly specifying the primary keys and the foreign keys

ii. Enter at least five tuples for each relation

iii. Find all the customers who have at least two accounts at the Main branch.

iv. Find all the customers who have an account at all the branches located in a specific city.

v. Demonstrate how you delete all account tuples at every branch located in a specific city.

vi. Generate suitable reports.

vii. Create suitable front end for querying and displaying the results.


