<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Registration</title>
<style>
     body
     {
      font-size:x-large;    
     }
     h2
     {
      text-align:center;
      font-size:x-large;
     }
</style>
</head>
<body>
    <h2>Registration Form</h2>
    <form action="program1.jsp" method="post">
      Name : <input type="text" name="name" id="Name" placeholder="Enter Your Name" required><br><br>
      Email : <input type="email" name="email" id="Email" placeholder="Enter Your Email id" required><br><br>
      Contact Number : <input type="text" name="contact" id="Contact" placeholder="Enter Your Contact Number" required><br><br>
      Present Occupation : <input type="text" name="occupation" id="Occupation" placeholder="Enter Your Present Occupation" required><br><br>
      Year Of Passing : <input type="text" name="year" id="Year" placeholder="Enter Year Of Passing" required><br><br>
      Program Name : <select name="select">
                     <option value="Undergraduate">Undergraduate</option>
                     <option value="Graduate">Graduate</option>
                    </select><br>
      <input type="submit" value="Register"><br>
<%@ page import="java.sql.*" %>
<%@ page import="java.io.*" %>
<%@ page import="java.util.*" %>
<%@ page import="java.util.Scanner" %>
<%@ page import="java.util.*" %>
<%@ page import="java.sql.Connection" %>
<%
        out.print ("in jsp code");
        String name=request.getParameter("name");
        String email=request.getParameter("email");
        String contact=request.getParameter("contact");
        String occupation=request.getParameter("occupation");
        String year=request.getParameter("year");
        String select=request.getParameter("select");

        Connection conn = null;
        Statement stat = null;
        ResultSet res = null;
        PreparedStatement insert = null;
        Scanner input = new Scanner(System.in);
        try
        {
         	Class.forName("org.postgresql.Driver");
         	conn = DriverManager.getConnection("jdbc:postgresql://192.168.16.252/ty218550","ty218550","");
         	insert = conn.prepareStatement("insert into alumni values(?,?,?,?,?,?)");
         	if(conn==null)
         	{
         	       out.println("Connection failed");
         	}
         	else
         	{
         	       out.println("Connetion succesful..");
         	}
         	stat = conn.createStatement();
	
	         insert.setString(1,name);
	         insert.setString(2,email);
	         insert.setString(3,contact);
	         insert.setString(4,occupation);
	         insert.setString(5,year);
	         insert.setString(6,select);
	
	        insert.executeUpdate();
%>
<br><br>
Year Of Passing : <input type="text" name="y" id="Yea" placeholder="Enter Year Of Passing" required><br><br>
<input type="submit" value="Register"><br>
<%
	       String y=request.getParameter("y");
	       res = stat.executeQuery("select * from alumni where year_of_passing= "+y);
	       while(res.next())
	       {
%>
<table>	
<tr><td><%res.getString(1);%></td></tr>
<tr><td><%res.getString(2);%></td></tr>
<tr><td><%res.getString(3);%></td></tr>
<tr><td><%res.getString(4);%></td></tr>
<tr><td><%res.getString(5);%></td></tr>
<tr><td><%res.getString(6);%></td></tr>
</table>                    
<% 
	     	}
	}
	catch(Exception e)
	{
		out.println(e);
	}
	
%>
</form>
</body>
</html> 
