<?php
session_start();

require "connectDB.php";
require "getUser.php";

if (isset($_POST["login"])) {
    $login = $_POST["login"];
    $pass = $_POST["pass"];

    if (preg_match('/^[a-zA-Z0-9]{3,30}/', $login) && preg_match('/^[a-zA-Z0-9 ]{3,30}/', $pass)) {
        $user =  getUser(connectDB(), $login);
        if (!$user) {
            echo "utulisateur introuvable";
            exit();
        }
        $conn = connectDB();
        if ($user["pass"] == $pass) {
            if ($user["blocked"] == 0) {
                setcookie("loginToken", $user["id"]);
                $_SESSION["loginToken"] = $user["id"];
                echo "vous etes connected";
                decrimentT($conn, $user);
            } else {
                echo "votre compte est bloque";
                exit();
            }
        } else {
            incrementerT($conn, $user);
        }
    } else {
        echo "ko 2";
    }
} else {
    echo "ko";
}

function decrimentT(PDO $conn, $user)
{
    $stm = $conn->prepare("UPDATE users SET tantative = 0 WHERE id = :id");
    $stm->bindParam(':id', $user["id"]);
    $stm->execute();
}


function incrementerT(PDO $conn, $user)
{
    $tentative = $user["tantative"] + 1;
    if ($user["tantative"] >= 3) {
        bloquer($conn, $user);
    } else {
        $stm = $conn->prepare("UPDATE users SET tantative = :tentative WHERE id = :id");
        $stm->bindParam(':id', $user["id"]);
        $stm->bindParam(':tentative', $tentative);
        $stm->execute();
        echo "votre login ou mot de passe est incorrect";
    }
}


function bloquer(PDO $conn, $user)
{
    $stm = $conn->prepare("UPDATE users SET blocked = 1 WHERE id = :id");
    $stm->bindParam(':id', $user["id"]);
    $stm->execute();
    echo "votre compte est bloque";
}
