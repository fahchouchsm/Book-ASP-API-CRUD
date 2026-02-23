<?php


require 'connectDB.php';

if (isset($_POST['nom'])) {
    $nom = $_POST['nom'];
    $prenom = $_POST['prenom'];
    $login = $_POST['login'];
    $pass = $_POST['pass'];

    print_r($_POST);

    if (strlen($nom) > 3 && strlen($prenom) > 3 && strlen($login) > 3 && strlen($pass) > 3) {
        if (preg_match('/^[a-zA-Z0-9]{3,30}/', $login) && preg_match('/^[a-zA-Z0-9 ]/', $pass) && preg_match('/^[a-zA-Z]/', $nom) && preg_match('/^[a-zA-Z]/', $prenom)) {
            $conn = connectDB();


            $stm = $conn->prepare("INSERT INTO users (nom, prenom, login, pass) VALUES (:nom, :prenom, :login, :pass)");
            $stm->bindParam(':nom', $nom);
            $stm->bindParam(':prenom', $prenom);
            $stm->bindParam(':login', $login);
            $stm->bindParam(':pass', $pass);
            $stm->execute();

            if ($stm->rowCount() > 0) {
                echo "ok";
            } else {
                echo "erreue d'insertion dans bas de donne";
            }
        } else {
            echo "ko 2";
        }
    } else {
        echo "ko";
    }
}
