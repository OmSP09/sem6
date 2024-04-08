<html>
	<body>
		<form action=q2.php method=POST>
			Enter directory name:<input type="text" name=d><br/>
			Enter file extension:<input type="text" name=ex><br/>
			<pre>
				<input type="submit" name=submit value=submit>
				<input type="reset" name=reset value=reset>
			</pre>
		</form>
	</body>
</html>

<?php

$dirname=$_POST['d'];
$ext=$_POST['ex'];

//open directory
$dir=opendir($dirname);

//loop through each file in the directory

while($file=readdir($dir)){

	//get the file extension
	$file_ext=pathinfo($file,PATHINFO_EXTENSION);
	
	if(!strcmp($file_ext,$ext)){	
		//get the file size and the last access time
		$size=filesize($dirname.'/'.$file);
		$access_time=date('Y-m-d H:i:s',filemtime($dirname.'/'.$file));
		
		//display the file name,size and last access time
		echo "$file-Size:$size bytes "."<br/>";
		echo "Last access-$access_time"."<br>";
	}
}

//close directory
closedir($dir);


?>
