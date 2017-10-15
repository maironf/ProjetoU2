<!DOCTYPE html>
<html>
   <head>
      <title>Cadastro</title>
      <?php include '../_cabecalho.php';?>
   </head> 
     
   <body>
      <?php include '../_navbar.php';?>
		<h1>
				Página de Cadastro
		</h1>
		<form action="gravar2.php" method="post">
		  Usuário 
		  <select name="usuario_id">
				<?php
   	          $query = "SELECT * FROM usuario"; 
            	$result = $conn->query($query);
   	          if ($result->num_rows > 0) {
               	while($row = $result->fetch_assoc()) {
                 	echo "<option value='".$row["id"]."'>".$row["nome"]."</option>";
								} 
            	} else {
               	echo "0 Resultados";
            	}
   	 ?>
			</select> 
		  Papel:  <select name="papel_id">
				<?php
   	          $query = "SELECT * FROM papel"; 
            	$result = $conn->query($query);
   	          if ($result->num_rows > 0) {
               	while($row = $result->fetch_assoc()) {
                 	echo "<option value='".$row["id"]."'>".$row["nome"]."</option>";
								} 
            	} else {
               	echo "0 Resultados";
            	}
            	$conn->close();
   	 ?>
			</select> 
			<input type="submit" class="btn btn-default" value="Cadastrar"/>
		</form>
	</body>
</html>