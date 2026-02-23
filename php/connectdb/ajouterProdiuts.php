<?php

require_once 'connectdb.php';

$libelle = $_POST['libelle'];
$prix = $_POST['pu'];
$qantity = $_POST['quantite'];
$idcategorie = $_POST['idCategory'];

print_r($_POST);

if (!isset($libelle) || !preg_match("/^[a-zA-Z0-9 ]{3,}$/", $libelle)) {
    echo "ko 1 <br>";
} elseif (!isset($prix) || !is_numeric($prix) || $prix <= 0) {
    echo "ko 2 <br>";
} elseif (!isset($qantity) || !is_numeric($qantity) || $qantity < 0) {
    echo "ko 3  <br>";
} elseif (!isset($idcategorie) || !is_numeric($idcategorie) || $idcategorie <= 0) {
    echo "ko 4 <br>";
} else {
    header("Location : list.php");
}
