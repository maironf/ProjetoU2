<!DOCTYPE html>
<html>
   <head>
      <title>Prática 04 - Sucesso</title>
      <?php include '_cabecalho.php';?>
   </head> 
     
   <body>
      <?php include '_navbar.php';?>
    <?php
      //Conexão com o bando de dados: host , usuario, senha, banco de dados
      $conn = new mysqli("localhost","root","","info");  
      if ($conn->connect_error) { 
        die("Connection failed: " . $conn->connect_error);
      }
      //consulta SQL 
      $query = "SELECT * FROM usuario";
      //resultado da consulta
      $result = $conn->query($query);
    
      $logado = false;
      //Dados retornados do formulário - página anterior(index.html - login)
      $senha = $_POST['senha'];
      $email = $_POST['email'];
      if ($result->num_rows > 0) {
        while($row = $result->fetch_assoc()) {
          if(sha1($senha)==$row["senha"] && $email==$row["email"]) {
            $logado=true;
             $_SESSION["logged"]=true;
             $_SESSION["user.name"]=$row["nome"];
             $_SESSION["user.email"]=$row["email"];
            break;
          }
        }
      }
      if($logado==true) {
         header('Location: index.php');
      } else {
        echo "Senha ou Email inexistente";
      }
      $conn->close();
    ?>
  </body>
</html>



