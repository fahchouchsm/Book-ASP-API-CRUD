<?php
function connectDB()
{
    return new PDO('mysql:host=localhost;dbname=sqli', 'root', '');
}
