<?php
session_start();

$aModifer = $_POST["aModifer"];
$value = $_POST["value"];


if (isset($value)) {
    if ($aModifer === "libelle" || $aModifer === "pu") {
        $_SESSION["info"][$aModifer] = $value;
        print_r($_SESSION["info"]);
        header("Location: liste.php");
    } else {
        echo "ko 2";
    }
} else {
    echo "ko";
}
