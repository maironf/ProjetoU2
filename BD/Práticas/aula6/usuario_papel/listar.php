<!DOCTYPE html>
<html>
   <head>
      <title>Prática 05 - Listar</title>
      <?php include '../_cabecalho.php';?>
   </head> 
     
   <body>
      <?php include '../_navbar.php';?>
	<div class="container">
		<h2>Papeis associados a Usuários Cadastrados</h2>
		<table class="table">
			<thead>
				<tr>
					<th>ID</th>
					<th>Usuario</th>
					<th>Papel</th>
					<th></th>
			   	<th></th>
				</tr>
			</thead>
			<tbody>

				<?php
            
				//SELECT usuario_papel.id, usuario.id AS uid, usuario.nome AS unome, papel.id AS pid, papel.nome AS pnome FROM usuario, papel, usuario_papel WHERE usuario.id = usuario_papel.usuario_id AND papel.id = usuario_papel.papel_id;
				
							$query = "SELECT usuario_papel.id, usuario.id AS uid, usuario.nome AS unome, papel.id AS pid, papel.nome AS pnome  ".
								"FROM usuario, papel, usuario_papel ".
								"WHERE usuario.id = usuario_papel.usuario_id AND papel.id = usuario_papel.papel_id;";
				
					    if(isset($_GET['search'])) {
								$query = "SELECT * FROM usuario_papel WHERE nome LIKE '%".$_GET['search']."%'"; 
							}
				      
            	$result = $conn->query($query);
   	          if ($result->num_rows > 0) {
               	while($row = $result->fetch_assoc()) {
                 	echo "<tr> <td> ".$row["id"]."</td>".
										"<td>".$row["unome"]."</td> " .
										"<td>".$row["pnome"]."</td>";
									if(isset( $_SESSION["logged"]) && $_SESSION["logged"]==true) {
										if (in_array("ADMIN", $_SESSION["user.roles"])) {
											  	echo  "<td><a href='editar.php?id=".$row["id"]."'><button type='button' class='btn btn-info btn-sm'>Editar</button></a> </td>".
													"<td><a href='remover.php?id=".$row["id"]."'><button type='button' class='btn btn-danger btn-sm'>Apagar</button></a></td></tr>";
                		} else {
												echo  "<td><a href='editar.php?id=".$row["id"]."'><button type='button' class='btn btn-info btn-sm'>Editar</button></a> </td>".
												"</tr>";
										
										} 
									
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
