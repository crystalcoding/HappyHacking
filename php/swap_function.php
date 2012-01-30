<?php

// "&" -- pass by reference
function swap(&$a, &$b)
{
    $temp = $a;
    $a = $b;
    $b = $temp;
}

$apple = "apple";
$orange = "orange";

swap($apple, $orange);
print "apple became: $apple\n";
print "orange became: $orange\n";

?>