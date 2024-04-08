import java.sql.*;
import java.io.*;
class employee
{
	public static void main(String[] args) throws IOException,ClassNotFoundException,SQLException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
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
				int ch,id,sal,result;
				String sql,name;
				System.out.println("\nconnection successful...\n");
				stmt=conn.createStatement();
				do
				{
					System.out.println("\n1.Enter details of Employee\n2.Modify Employee record\n3. Delete employee\n4.Search emplyee\n5.View all\n6.Exit");
					System.out.println("\nEnter choice:");
					ch=Integer.parseInt(br.readLine());
					if(ch==6)
					break;
					switch(ch)
					{
						case 1:System.out.println("\nEnter the ID of employee you want to Insert\t");
							id=Integer.parseInt(br.readLine());
							System.out.print("\nEnter the Name\t");
							name=br.readLine();
							System.out.print("Enter the Salary\t");
							sal=Integer.parseInt(br.readLine());
							sql="Insert into employee values(?,?,?)";
							ps=conn.prepareStatement(sql);
							ps.setInt(1,id);
							ps.setString(2,name);
							ps.setInt(3,sal);
							result=ps.executeUpdate();
							if(result==1)
							{
								System.out.println("\nData Insertion successfully\n");
							}
							break;
						case 2:System.out.println("\nEnter the ID of employee you want to Update\t");
							id=Integer.parseInt(br.readLine());
							System.out.print("\nEnter the Updated Name\t");
							name=br.readLine();
                                                        System.out.print("Enter the Updated Salary\t");
                                                        sal=Integer.parseInt(br.readLine());
							sql="Update employee SET e_name= ?, salary= ? where emp_id= ?";
							ps=conn.prepareStatement(sql);
							ps.setString(1,name);
                                                        ps.setInt(2,sal);
                                                        ps.setInt(3,id);
                                                        result=ps.executeUpdate();
                                                        if(result==1)
                                                        {
                                                                System.out.println("\nData Updated successfully\n");
                                                        }
                                                        break;
						case 3:System.out.println("Enter the ID of employee you want to Delete\t");
							id=Integer.parseInt(br.readLine());
							sql="Delete from employee where emp_id =?";
							ps=conn.prepareStatement(sql);
							ps.setInt(1,id);
							result=ps.executeUpdate();
							if(result==1)
                                                        {
                                                                System.out.println("\nData Deleted successfully\n");
                                                        }
							break;								
						case 4:System.out.println("Enter the ID of employee you want to Search\t");
                                                        id=Integer.parseInt(br.readLine());
							sql="Select * from employee where emp_id =?";
							ps=conn.prepareStatement(sql);
                                                        ps.setInt(1,id);
                                                        rs=ps.executeQuery();
							while(rs.next())
							{
								System.out.println("ID = "+rs.getInt(1)+"\t");
								System.out.println("Name = "+rs.getString(2)+"\t");
								System.out.println("Salary = "+rs.getInt(3)+"\n");
							}
							rs.close();
							break;
						case 5:
							rs=stmt.executeQuery("Select * from employee");
							while(rs.next())
                                                        {
                                                                System.out.println("ID = "+rs.getInt(1)+"\t");
                                                                System.out.println("Name = "+rs.getString(2)+"\t");
                                                                System.out.println("Salary = "+rs.getInt(3)+"\n");
                                                        }
                                                        rs.close();
							break;
						default:System.out.println("Wrong choice please enter correct choice\t");
							ch=Integer.parseInt(br.readLine());
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
