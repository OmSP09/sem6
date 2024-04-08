<html>
	<body>
		<form action = "q2a2.php" method = POST>
			Length of Rectangle<input type = text name = l><br>
			Breadth of rectangle<input type = text name = b><br>
			Side of Square<input type = text name = s><br>
			Radius of circle<input type = text name = r><br>
			<input type = submit name = sub>
		</form>		
		
	
	</body>
</html>
<?php 
	
	interface inter{
		function area();	
	}	
	class Rectangle implements inter{
		public $len;
		public $bre;
		function __construct($l , $b)
		{
			$this->len = $l;
			$this->bre = $b;
		}

		function area()
		{
			$area  =$this->len*$this->bre; 
			echo "Area of rectangle  is ".$area;
		}
		
	}
	
	class Square extends Rectangle implements inter{
		function area()
		{
			$area  =$this->len*$this->bre; 
			echo "Area  of square   is ".$area;
		}
	}

	class Circle implements inter{
		public $rad;
		function __construct($r)
		{
			$this->rad = $r;
		}
		
		function area()
		{
			$area = 3.14 * $this->rad *$this->rad;
			echo "Area of circle is ".$area;
		}
	}
if(isset($_POST['sub']))
	$l = $_POST['l'];
	$b = $_POST['b'];
	$s = $_POST['s'];
	$r = $_POST['r'];
	$obj = new Rectangle($l,$b);
	$obj2 = new Square($s,$s);
	$obj3 = new Circle($r);

	$obj->area();
	echo"<br>";
	$obj2->area();
	echo"<br>";
	$obj3->area();
	 
?>
