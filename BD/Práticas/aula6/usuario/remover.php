<!DOCTYPE html>
<html>
   <head>
      <title>Remover</title>
      <?php include '../_cabecalho.php';?>
   </head> 
     
   <body>
      <?php include '../_navbar.php';?>
      	<?php
            	
                $query = "DELETE FROM papel WHERE id=".$_GET['id']; 
                if ($conn->query($query) === TRUE) {
                    echo "<p>Papel removido com sucesso!</p>";
                } else {
                    echo "Erro removendo papel: " . $conn->error;
                }
                echo "<a href='listar.php'>Listar Papel</a>";
                $conn->close();
        ?>
      
    	</body>
</html>