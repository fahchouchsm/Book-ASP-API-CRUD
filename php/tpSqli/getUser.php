<?php

function getUser(PDO $conn, string $login)
{
    $stm = $conn->prepare("SELECT * FROM users WHERE login = :login");
    $stm->bindParam(':login', $login);
    $stm->execute();
    $user = $stm->fetch(PDO::FETCH_ASSOC);
    if ($user) {
        return $user;
    } else {
        return null;
    }
}
