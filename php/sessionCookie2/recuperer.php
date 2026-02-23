<?php
session_start();

$libelle = $_POST["libelle"];
$pu = $_POST["pu"];

if (isset($libelle) && isset($pu)) {
    if (!empty($libelle) & !empty($pu)) {
        $_SESSION["info"] = ["libelle" => $libelle, "pu" =>  $pu];
        setcookie("numbre produit", "0");
        header("Location:liste.php");
    } else {
        echo "ko2";
    }
} else {
    echo "ko";
}
