<!DOCTYPE html>
<html>
	<head>
	    <title>Meu Espaço Html</title>
		 	<?php include '_cabecalho.php';?>
		
		</head>
	  <body> 
				<?php include '_navbar.php';?>
        <div>
					 <div class="login-page">
        <h2>Meu espaço Html</h2>
        <h3>Login</h3>
        <form action="sucesso.php" method="post">
          Email:<br>
          <input type="text" name="email" value=""><br>
          Senha:<br>
          <input type="password" name="senha" value=""><br>
        <input type="submit" value="Confirmar">
        </form>
     </div>
			</div>
	</body>
</html>