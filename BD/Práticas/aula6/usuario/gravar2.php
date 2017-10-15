<!DOCTYPE html>
<html>
   <head>
      <title>Prática 05 - Gravar</title>
      <?php include '../_cabecalho.php';?>
   </head> 
     
   <body>
      <?php include '../_navbar.php';?>
		<?php
		 
		  //Método SHA - criptografa 
			$password = sha1($_POST['senha']);

			//executa a query
			$sql = "INSERT INTO usuario (nome, email, senha ) VALUES ('$_POST[nome]','$_POST[email]', '$password')";

			if ($conn->query($sql) === TRUE) {
				 echo "Usuario cadastrado com sucesso!";
			} else {
				 echo "Erro ao cadastrar usuario: " . $sql . "<br>" . $conn->error;
			}
		echo "<p><a href=\"../index.php\">Home</a></p>";		
		$conn->close();
		?>
	</body>
</html>