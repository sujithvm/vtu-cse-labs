<?php
    $inTwoMonths = 24 * 60 * 60 * 60 + time();
    setcookie('lastVisit', date("G:i -m/d/y"), $inTwoMonths);
    if (isset($_COOKIE['lastVisit'])) 
        echo "Last date : ".$_COOKIE['lastVisit'];
    else
        echo "Got some stale cookies";
?>
