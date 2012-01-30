<?php

$s = "live";
print("revese of live is: ");

//str_split — Convert a string to an array
$array = str_split($s);
//echo strlen($s);
//or use sizeof on an array
for ($i= sizeof($array)-1; $i>-1; --$i){
    print($array[$i]);
}
print("\n");

?>
