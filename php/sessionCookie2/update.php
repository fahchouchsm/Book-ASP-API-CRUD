<?php
$aModifer = $_GET["m"];

if ($aModifer == "libelle" || $aModifer == "pu") {
    echo "
    <h3>Modifier le $aModifer</h3>
    <form
      action='update_v.php'
      method='post'
    >
    <label for='value'>$aModifer : </label>
    <input type='text' pattern='[a-zA-Z1-9]{3,30}' id='value' placeholder='$aModifer' name='value'>
    <input type='hidden' name='aModifer' value='$aModifer'>
    <br/>
    <input type='submit'>
    </form><br/>
    <a href='list.php'>retourner</a>
    ";
} else {
    echo "ko";
}
