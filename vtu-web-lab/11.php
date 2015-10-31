<?php
    $db = mysql_connect("localhost", "root", "root123");
    mysql_select_db("test");

    $name = $_POST['name'];
    $addr1 = $_POST['addr1'];
    $addr2 = $_POST['addr2'];
    $email = $_POST['email'];

    mysql_query("INSERT INTO contact VALUES ('$name', '$addr1', '$addr2', '$email')");

    print "<table border=1>";
	print "<tr><td>Name</td><td>Address 1</td><td>Address 2</td><td>Email</td></tr>";

    $res = mysql_query("SELECT * FROM contact");
    while ($a = mysql_fetch_row($res))    
        print "<tr><td>$a[0]</td><td>$a[1]</td><td>$a[2]</td><td>$a[3]</td></tr>";
    
    print "</table>";

    mysql_close($db);
?>

