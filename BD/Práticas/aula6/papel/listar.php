<!DOCTYPE html>
<html>
   <head>
      <title>Prática 04 - Listar</title>
      <?php include '../_cabecalho.php';?>
   </head> 
     
   <body>
      <?php include '../_navbar.php';?>
	<div class="container">
		<h2>Usuários Cadastrados</h2>
		<table class="table">
			<thead>
				<tr>
					<th>ID</th>
					<th>Nome</th>
					<th>E-mail</th>
					<th>Password</h1>
					<th></th>
			   	<th></th>
				</tr>
			</thead>
			<tbody>

				<?php
            	$conn = new mysqli("localhost","root","","info");   
            	if ($conn->connect_error) {
               	die("Connection failed: " . $conn->connect_error);
            	}
							
   	          $query = "SELECT * FROM usuario"; 
					    if(isset($_GET['search'])) {
								$query = "SELECT * FROM usuario WHERE nome LIKE '%".$_GET['search']."%'"; 
							}
				      
            	$result = $conn->query($query);
   	          if ($result->num_rows > 0) {
               	// output data of each row 
               	while($row = $result->fetch_assoc()) {
									
                 	echo "<tr> <td> ".$row["id"]."</td>".
										"<td>".$row["nome"]."</td> <td>" . $row["email"]. "</td>".
										"<td>".$row["senha"]."</td>";
									if(isset( $_SESSION["logged"]) && $_SESSION["logged"]==true) {
										echo  "<td><a href='editar.php?id=".$row["id"]."'><button type='button' class='btn btn-warning btn-sm'>Editar</button></a> </td>".
													"<td><a href='remover.php?id=".$row["id"]."'><button type='button' class='btn btn-danger btn-sm'>Apagar</button></a></td></tr>";
                		} else {
										echo "<td></td><td></td></tr>";
									}
								} 
            	} else {
               	echo "0 Resultados";
            	}
            	$conn->close();
   	 ?>

			</tbody>
		</table>
	</div>	
	
	<p><a href="../index.php">Home</a></p>
</body>

</html>

