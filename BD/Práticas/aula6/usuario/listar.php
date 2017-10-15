<!DOCTYPE html>
<html>
   <head>
      <title>Prática 05 - Listar Papeis</title>
      <?php include '../_cabecalho.php';?>
   </head> 
     
   <body>
      <?php include '../_navbar.php';?>
	<div class="container">
		<h2>Papeis Cadastrados</h2>
		<table class="table">
			<thead>
				<tr>
					<th>ID</th>
					<th>Nome</th>
					<th>Descrição</th>
					<th></th>
			   	<th></th>
				</tr>
			</thead>
			<tbody>

				<?php
            
							
   	          $query = "SELECT * FROM papel"; 
					    if(isset($_GET['search'])) {
								$query = "SELECT * FROM papel WHERE nome LIKE '%".$_GET['search']."%'"; 
							}
				      
            	$result = $conn->query($query);
   	          if ($result->num_rows > 0) {
               	// output data of each row 
               	while($row = $result->fetch_assoc()) {
									
                 	echo "<tr> <td> ".$row["id"]."</td>".
										"<td>".$row["nome"]."</td> <td>" .
										"<td>".$row["descrcao"]."</td>";
									if(isset( $_SESSION["logged"]) && $_SESSION["logged"]==true) {
										echo  "<td><a href='editar.php?id=".$row["id"]."'><button type='button' class='btn btn-info btn-sm'>Editar</button></a> </td>".
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
