<?php
$login = $_POST["login"];
$pass = $_POST["pass"];

if (!empty($login) || !empty($pass)) {
    if (preg_match("/[A-za-z1-9]{3,30}/", $login) && preg_match("/[A-za-z1-9]{3,30}/", $login)) {
        if (strrev($pass) == $login) {
            echo "good";
        } else {
            echo "not good";
        }
    } else {
        echo "ko 2";
    }
} else {
    echo "ko";
}
