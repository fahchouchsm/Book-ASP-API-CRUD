<?php
session_start();
$aSurpprimer = $_GET["m"];

$_SESSION["info"][$aSurpprimer] = "";
setcookie()

header("Location:liste.php");
