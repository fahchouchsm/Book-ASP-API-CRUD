<?php
session_start();

$libelle = $_SESSION["info"]["libelle"];
$pu = $_SESSION["info"]["pu"];

if (!empty($libelle)) {
    echo "$libelle <a href='update.php?m=libelle'>modifier</a> <a href='delete.php?m=libelle'>surpprimer</a> <br>";
}

if (!empty($pu)) {
    echo "$pu <a href='update.php?m=pu'>modifier</a> <a href='delete.php?m=pu'>surpprimer</a><br>";
}

echo "<a href='formulaire.html'>formulaire</a>";
