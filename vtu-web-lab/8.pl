#!/usr/bin/perl

use CGI':standard';
print "content-type:text/html\n\n";

use DBI;
$dbh = DBI->connect("DBI:mysql:test","root","root");
$name=param("name");
$age=param("age");
$sql="insert into Students values('$name','$age')";
$sth=$dbh->prepare($sql);
$sth->execute;
#if 0
$sql = "select * from Students";
$sth = $dbh->prepare($sql);
$sth->execute;
print "<table border size=1>
Dept of CSE, PESIT Bangalore South Campus
Page 21
Web Programming Lab Manual (10CSL78)
<tr>
<th>Name</th>
<th>Age</th>
</tr>
";
while(($name,$age)=$sth->fetchrow())
{
print "<tr>
<td>$name</td>
<td>$age</td>
</tr>
";
}
$sth->finish();
$dbh->disconnect();
print"</table> </HTML>";
#endif
