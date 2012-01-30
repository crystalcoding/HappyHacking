<html>
<body>
<?php print ("hello world\n") ?>
<?php mysql_connect("localhost", "username", "password") or
die(mysql_error());

mysql_select_db("login") or die(mysql_error());

$data = mysql_query("SELECT * from users;")
or die(mysql_error());

while($info = mysql_fetch_array($data))
{
      print "name:".$info["name"]. "\n";
      print "password:".$info["password"]. "\n";
}

echo "5-10=".substract(5,10);

function substract($x, $y)
{
      return $x-$y;
}
?>
</body></html>
