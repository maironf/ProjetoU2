<!DOCTYPE html>
<html>
   <head>
      <title>Editar</title>
      <?php include '../_cabecalho.php';?>
   </head> 
     
   <body>
      <?php include '../_navbar.php';?>
      	<?php
            
             
              if(isset($_POST['nome'])) {
                
                  //executa a query
                  $sql = "";
                 
                     $sql = "UPDATE papel SET nome='".$_POST['nome']."', descricao='".$_POST['descricao']."' WHERE id='".$_POST['id']."'";
                     echo "<p> Atualizando...Nome e Descrição</p>";
               
                  if ($conn->query($sql) === TRUE) {
                     echo "<p>Papel Atualizado com sucesso!</p>";
                  } else {
                     echo "<p>Erro ao Atualizar papel: " . $sql . "</p></br>" . $conn->error;
                  }
                echo "<a href='listar.php'>Listar Papeis</a>";
              }else {
                $query = "SELECT * FROM papel WHERE id=".$_GET['id']; 
                $result = $conn->query($query);
                echo "<h1> Editar Papel ID: ".$_GET['id']."</h1>";

                if ($result->num_rows > 0) {
                  // output data of each row 
                  $row = $result->fetch_assoc();
                  echo "<form action='editar.php' method='post'>";
                  echo "   <div class='form-group'>";
                  echo "      <label for='nome'>Nome:</label>";
                  echo "      <input type='text' class='form-control' id='nome' name='nome' value='".$row["nome"]."'>";
                  echo "   </div>";
                  echo "   <div class='form-grou'>";
                  echo "      <label for='descricao'>Descrição:</label>";
                  echo "      <input type='descricao' class='form-control' id='descricao' name='descricao' value='".$row["descricao"]."'>";
                  echo "   </div>";
                  echo "      <input type='hidden' id='id' name='id' value='".$row["id"]."'>";
                  echo "   <button type='submit' class='btn btn-default'>Atualizar</button>";
                  echo "</form>";
                }
              }
        ?>
      
    	</body>
</html>