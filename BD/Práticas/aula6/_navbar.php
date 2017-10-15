<?php
  session_start();
	$conn = new mysqli("localhost","root","","info");   
  if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
  }
  echo "<div class='container-fluid' style='background-color:#F44336;color:#fff;height:150px;'>";
  echo "<center><h1>HTML Para Vida </h1></center>";
  echo "<center><h3>Plataforma Grátis de aprendizado</h3></center>";
  echo "<center><p>A mais de 10 anos no mercado</p></center>";
  echo "</div>";
  echo "<nav class='navbar navbar-default' data-spy='affix' data-offset-top='197'>";
  echo "    <div class='navbar-header'>";
  echo "      <a class='navbar-brand' href='index.php'>Html para vida</a>";
  echo "    </div>";
  echo "    <ul class='nav navbar-nav'>";
  echo "     <li class='active'><a href='index.php'>Home</a></li>";
  echo "		 <li class='dropdown'>";
  echo "      <a class='dropdown-toggle' data-toggle='dropdown' href='#'>Usuario <span class='caret'></span></a>";
  echo "       <ul class='dropdown-menu'>";
  echo "          <li><a href='/aula6/usuario/listar.php'>Listar</a></li>";
  echo "          <li><a href='/aula6/usuario/cadastro2.php'>Cadastrar</a></li>";
  echo "       </ul>";
  echo "      </a> ";
  echo "     </li> ";

  echo "		 <li class='dropdown'>";
  echo "      <a class='dropdown-toggle' data-toggle='dropdown' href='#'>Papel <span class='caret'></span></a>";
  echo "       <ul class='dropdown-menu'>";
  echo "          <li><a href='/aula6/papel/listar.php'>Listar</a></li>";
  echo "          <li><a href='/aula6/papel/cadastro2.php'>Cadastrar</a></li>";
  echo "       </ul>";
  echo "      </a> ";
  echo "     </li> ";

  echo "		 <li class='dropdown'>";
  echo "      <a class='dropdown-toggle' data-toggle='dropdown' href='#'>Usuário_Papel <span class='caret'></span></a>";
  echo "       <ul class='dropdown-menu'>";
  echo "          <li><a href='/aula6/usuario_papel/listar.php'>Listar</a></li>";
  echo "          <li><a href='/aula6/usuario_papel/cadastro2.php'>Cadastrar</a></li>";
  echo "       </ul>";
  echo "      </a> ";
  echo "     </li> ";

  echo "   <form action='usuario/listar.php' class='navbar-form navbar-left'>";
  echo "    <div class='form-group'>";
  echo "      <input type='text' name='search' class='form-control' placeholder='Procurar'>";
  echo "    </div>";
  echo "    <button type='submit' class='btn btn-default'>OK</button>";
  echo "  </form>";
  echo "    </ul><ul class='nav navbar-nav navbar-right'>";
   if( isset( $_GET["logout"]) ) {
      $_SESSION["logged"]=false;
     }
  if( isset( $_SESSION["logged"]) && $_SESSION["logged"]==true)  {
      echo "<li><a data-toggle='tooltip' title='".implode(",".$_SESSION["user.roles"])."'href='#'>".$_SESSION["user.email"]."</a></li>";
      echo "<li><a href='index.php?logout=true'><span class='glyphicon glyphicon-log-in'></span> Logout</a></li>";
   } else { 
      echo "<li><a href='usuario/cadastro.php'><span class='glyphicon glyphicon-user'></span> Cadastrar</a></li>";
      echo "<li><a href='login.php'><span class='glyphicon glyphicon-log-in'></span> Login</a></li>";
   }
  echo "   </ul>";
  echo "  </div>";
  echo "</nav>";
?>



