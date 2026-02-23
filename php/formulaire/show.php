<?php
$nom = $_POST["nom"];
$prenom = $_POST["prenom"] ? $_POST["prenom"] : "";
$dateNais = $_POST["dateNais"];
$moyenne = $_POST["moy"];
$niveau = $_POST["niv"];
$ar = isset($_POST["ar"]) ? $_POST["ar"] : "";
$fr = isset($_POST["fr"]) ? $_POST["fr"] : "";
$en = isset($_POST["en"]) ? $_POST["en"] : "";
$sexe = $_POST["sexe"];
$adr = $_POST["adr"];

if (isset($nom) && preg_match("/^[A-Za-z ]{3,30}$/", $nom)) {
    $date = explode("-", $dateNais);
    if (checkdate($date[1], $date[2], $date[0])) {
        if (is_numeric($moyenne) && $moyenne > 0 && $moyenne <= 20) {
            if (in_array($niveau, ["bac", "bac2", "bac3", "bac4", "bac5"])) {
                if (in_array($sexe, ["homme", "femme"])) {
                    echo "<h1>Informations</h1>";
                    echo "<p>Nom: $nom</p>";
                    echo "<p>Prénom: $prenom</p>";
                    echo "<p>Date de Naissance: $dateNais</p>";
                    echo "<p>Moyenne: $moyenne</p>";
                    echo "<p>Niveau: $niveau</p>";
                    echo "<p>Langues: ";
                    $langues = [];
                    if ($ar) $langues[] = $ar;
                    if ($fr) $langues[] = $fr;
                    if ($en) $langues[] = $en;
                    echo implode(", ", $langues);
                    echo "</p>";
                    echo "<p>Sexe: $sexe</p>";
                    echo "<p>Adresse: $adr</p>";
                } else {
                    echo "Erreur: Sexe invalide.";
                }
            } else {
                echo "Erreur: Niveau invalide.";
            }
        } else {
            echo "Erreur: Moyenne invalide.";
        }
    } else {
        echo "Erreur: Date de naissance invalide.";
    }
} else {
    echo "Erreur: Nom invalide.";
}
?>