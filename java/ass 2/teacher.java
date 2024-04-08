import java.sql.*;
import java.io.*;
import java.util.*;
class teacher
{
	public static void main(String[] args) throws IOException,ClassNotFoundException,SQLException
	{
		Scanner sc = new Scanner(System.in);
		Connection conn=null;	
		Statement stmt=null;
		ResultSet rs=null;
		PreparedStatement ps=null;
		try
		{
			Class.forName("org.postgresql.Driver");
			conn=DriverManager.getConnection("jdbc:postgresql://192.168.16.252/ty218550","ty218550","");
			if(conn==null)
			{
				System.out.println("\nconnection failed\n");
			}
			else
			{
				int ch,id,sub_code,result;
				String sql,t_name,sub_name,date,time,class_div;
				System.out.println("\nconnection successful...\n");
				stmt=conn.createStatement();
				do
				{
					System.out.println("\n1.Add record\n2.Display date wise lecture details for a specific teacher .\n3.Display class wise time table\n4.Modify record for specific teacher.\n5.Exit");
					System.out.println("\nEnter choice:");
					ch=sc.nextInt();
					if(ch==5)
					break;
					switch(ch)
					{
// add details......
						case 1:System.out.println("\nEnter the ID of Teacher you want to Insert\t");
							id=sc.nextInt();
							
							System.out.print("\nEnter the Name of Teacher\t");
							t_name=sc.next();				                                           //create table for teacher insert id and name.........kuch nhi ata....
							
							System.out.print("Enter the subject code\t");
							sub_code=sc.nextInt();
							
							System.out.print("\nEnter the subject name\t");
							sub_name=sc.next();
							
							System.out.print("\nEnter date\t");
							date=sc.next();
							
							System.out.print("\nEnter time\t");
							time=sc.next();
							
							System.out.print("\nEnter class division\t");
							class_div=sc.next();
							
							sql="Insert into teacher values(?,?,?,?,?,?,?)";
							
							
							
							ps=conn.prepareStatement(sql);
							ps.setInt(1,id);
							ps.setString(2,t_name);
							ps.setInt(3,sub_code);
							ps.setString(4,sub_name);
							ps.setString(5,date);
							ps.setString(6,time);
							ps.setString(7,class_div);
							result=ps.executeUpdate();
							if(result==1)
							{
								System.out.println("\nData Insertion successfully\n");
							}
							break;
							
							
						


//2.search by teacher
						case 2:
							System.out.println("Enter the name of teacher you want to Search\t");
                                          t_name = sc.next();
							sql="Select * from teacher where t_name =?";
							ps=conn.prepareStatement(sql);
                                                        ps.setString(1,t_name);
                                                        rs=ps.executeQuery();
							while(rs.next())
							{
								System.out.println("ID = "+rs.getInt(1)+"\t");
								System.out.println("Name = "+rs.getString(2)+"\t");
								System.out.println("SUBJECT CODE = "+rs.getInt(3)+"\n");
								System.out.println("SUBJECT = "+rs.getString(4)+"\n");
								System.out.println("DATE = "+rs.getString(5)+"\n");
								System.out.println("TIME = "+rs.getString(6)+"\n");
								System.out.println("CLASS DIVISION = "+rs.getString(7)+"\n");
							}
							rs.close();
							break;




//3.search by class
						case 3:
							System.out.println("Enter the class division\t");
                                          class_div = sc.next();
							sql="Select * from teacher where class_div =?";
							ps=conn.prepareStatement(sql);
                                                        ps.setString(1,class_div);
                                                        rs=ps.executeQuery();
							while(rs.next())
							{
								System.out.println("ID = "+rs.getInt(1)+"\t");
								System.out.println("Name = "+rs.getString(2)+"\t");
								System.out.println("SUBJECT CODE = "+rs.getInt(3)+"\n");
								System.out.println("SUBJECT = "+rs.getString(4)+"\n");
								System.out.println("DATE = "+rs.getString(5)+"\n");
								System.out.println("TIME = "+rs.getString(6)+"\n");
								System.out.println("CLASS DIVISION = "+rs.getString(7)+"\n");
							}
							rs.close();
							break;




//4.modify
						case 4:
							System.out.println("\nEnter the name of teacher you want to Modify\t");
							t_name= sc.next();
							System.out.print("\nEnter the Updated date\t");
							date=sc.next();
							System.out.print("\nEnter the Updated time\t");
							time=sc.next();
							System.out.print("\nEnter the Updated class division\t");
							class_div=sc.next();
                                                      
							sql="Update teacher SET date= ?, time= ?, class_div= ? where t_name= ?";
							ps=conn.prepareStatement(sql);
									  ps.setString(1,date);
                                                        ps.setString(2,time);
                                                        ps.setString(3,class_div);
                                                        ps.setString(4,t_name);
                                                        result=ps.executeUpdate();
                                                        if(result==1)
                                                        {
                                                                System.out.println("\nData Modified successfully\n");
                                                        }
                                                        break;
                                                        
						default:System.out.println("Wrong choice please enter correct choice\t");
							ch=sc.nextInt();
							break;
					}
				}while(ch!=6);
			}
		}
		catch(Exception e)
		{
			System.out.println(e);	
		}
		finally
		{
			stmt.close();
			conn.close();
		}
	}
}










