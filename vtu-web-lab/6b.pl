#!/usr/bin/perl
use CGI':standard';
print "Content-type:text/html\n\n";

open(FILE,'<count.txt');
$count=<FILE>;
close(FILE);

$count++;

open(FILE,'>count.txt');
print FILE "$count";
close(FILE);

print "View count : $count";

