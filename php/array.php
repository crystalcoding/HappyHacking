<?php

$arr = array("a","b","c","d","e");

//print_r —  Prints human-readable information about a variable 
//print_r($arr);

//or use foreach
foreach( $arr as $ar){
	 print $ar;
}
print("\n");

$associ_array = array("jie"=>27, "glenn"=>28);
//print_r($associ_array);

//or use foreach
foreach($associ_array as $mykey => $myvalue){
    print("$mykey : $myvalue\n");
}

print "sizeof associ_array is:";
print sizeof($associ_array);
print "\n"
?>