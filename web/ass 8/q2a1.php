<html>
	<body>
		<form action = "q2a1.php" method = POST>
			Book name<input type = text name = n><br>
			Book quantity<input type = text name = q><br>
			Book price<input type = text name = p><br>
			Book stock<input type = text name = s><br>
			<input type = submit name = sub>
		</form>		
		
	
	</body>
</html>

<?php 
	 class Book{
		var $book_name;
		var $book_qty;
		var $book_price;
		var $book_stock;

		function __construct($n , $qty,$p,$s)
		{
			$this->book_name = $n;
			$this->book_qty = $qty;
			$this->book_price = $p ;
			$this->book_stock = $s;
			

			 
		}

		function disp()
		{
			echo $this->book_name."<br>";
			echo $this->book_qty."<br>";
			echo $this->book_price."<br>";
			echo $this->book_stock."<br>";
				
		}

	
	}

	
	if(isset($_POST['sub']))
	{
		$obj = new Book($_POST['n'],$_POST['q'],$_POST['p'],$_POST['s']);
		$obj->disp();
	}
	
?>
