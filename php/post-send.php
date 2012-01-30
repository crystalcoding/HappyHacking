<?php
session_start();
$_SESSION['good'] = 1;
?>
<form action="post-receive.php" method="post">
name: <input type="text" name="name" value="lala">
password: <input type="text" name="password">
<input type="submit" />
</form>
<?php
echo $_SESSION['good'];
?>