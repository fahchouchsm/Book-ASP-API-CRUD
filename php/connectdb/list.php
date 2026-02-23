<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>liste des produits</title>
</head>

<body>
    <table border="1" cellpadding='5' cellspacing='0'>
        <tr>
            <th>produit</th>
            <th>prix</th>
            <th>quantité</th>
            <th>categorie</th>
        </tr>
        <tr>
            <?php
            require_once 'connectdb.php';
            $query = "SELECT p.id,p.libelle, p.pu, p.qte, c.libelle as category FROM produit p INNER JOIN categorie c ON p.categoryId = c.id";
            $result = $conn->query($query);
            $data = $result->fetchAll(PDO::FETCH_ASSOC);
            for ($i = 0; $i < count($data); $i++) {
                echo "<tr>";
                echo "<td>" . $data[$i]["libelle"] . "</td>";
                echo "<td>" . $data[$i]["pu"] . "</td>";
                echo "<td>" . $data[$i]["qte"] . "</td>";
                echo "<td>" . $data[$i]["category"] . "</td>";
                echo "</tr>";
            }

            ?>
        </tr>
    </table>
</body>

</html>