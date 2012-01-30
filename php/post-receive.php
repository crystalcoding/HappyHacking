<?php
//this must be present to retrieve
//the previous session
session_start();

function check_session()
{
if ($_SESSION['good'] == 2 ){
   echo "password is correct";
   echo "<br>";

}
else {
   echo "password is not correct\n";
   echo "<br>";
}

}

echo $_POST['name'];
echo "<br>";
echo $_POST['password'];
echo "<br>";

if ($_POST['name'] == 'jie' && $_POST['password'] == 'cute'){
   $_SESSION['good'] = 2;
}

check_session();

echo "print session good";
echo $_SESSION['good'];
echo "<br>";
echo "delete the session";
session_destroy();
//or delete the specific session, unset($_SESSION['good']);
echo "<br>";
?>