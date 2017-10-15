<!DOCTYPE html>
<html>
   <head>
      <title>Gravar</title>
      <?php include '../_cabecalho.php';?>
   </head> 
     
   <body>
      <?php include '../_navbar.php';?>
		<?php
		 
			//executa a query
			$sql = "INSERT INTO usuario_papel (usuario_id, papel_id) VALUES ('$_POST[usuario_id]','$_POST[papel_id]')";

			if ($conn->query($sql) === TRUE) {
				 echo "Usuario-Papel cadastrado com sucesso!";
			} else {
				 echo "Erro ao cadastrar usuario-papel: " . $sql . "<br>" . $conn->error;
			}
		echo "<p><a href=\"../index.php\">Home</a></p>";		
		$conn->close();
		?>
	</body>
</html>