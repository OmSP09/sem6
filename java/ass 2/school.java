import java.sql.*;
import java.io.*;
class school
{
	public static int getMark(int ta,int tc)
	{
		int marks;
		float per=((float)ta/(float)tc)*100;
		System.out.println(per);
		if(per>90)
			marks=10;
		else if(per>80)
			marks=9;
		else if(per>70)
                        marks=8;
		else if(per>60)
                        marks=7;
		else if(per>50)
                        marks=6;
		else if(per>40)
                        marks=5;
		else if(per>30)
                        marks=4;
		else if(per>20)
                        marks=3;
		else if(per>10)
                        marks=2;
		else
			marks=1;
		return marks;
	}
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
				System.out.println("\nConnection Failed\n");
			}
			else
			{
				int n,total_attended,total_conducted,max=0;
				int roll=0,result,marks;
				String sql,name,Class,subject;
				System.out.println("\n Connection Successful\n");
				stmt=conn.createStatement();
				System.out.print("\nEnter number of students:");
				n=Integer.parseInt(br.readLine());
				for(int i=0;i<n;i++)
				{
					System.out.print("\nEnter the name of student you want to insert:");
					name=br.readLine();
					System.out.print("\nEnter the class:");
					Class=br.readLine();
					System.out.println("\nEnter the subject:");
					subject=br.readLine();
					System.out.println("\nEnter the total attended lectures:");
					total_attended=Integer.parseInt(br.readLine());
					if(max<total_attended)
					{
						max=total_attended;
					}
					sql="Insert into attendance values(?,?,?,?,?)";
					ps=conn.prepareStatement(sql);
					++roll;
					ps.setInt(1,roll);
					ps.setString(2,name);
					ps.setString(3,Class);
					ps.setString(4,subject);
					ps.setInt(5,total_attended);
					result=ps.executeUpdate();
					if(result==1)
					{
						System.out.println("\nData inserted succesfully\n");
					}
				}
				System.out.print("\nEnter total number of lectures conducted:");
				total_conducted=Integer.parseInt(br.readLine());
				while(total_conducted<=max)
				{
					System.out.print("Conducted lectures cannot be less than attended lectures.Enter again:");
					total_conducted=Integer.parseInt(br.readLine());
				}
				rs=stmt.executeQuery("Select * from attendance");
				while(rs.next())
				{
					System.out.print("Roll number = "+rs.getInt(1)+"\t");
					System.out.print("Name = "+rs.getString(2)+"\t");
					System.out.print("Class = "+rs.getString(3)+"\t");
					System.out.print("Subject = "+rs.getString(4)+"\t");
					System.out.print("Total attended = "+rs.getInt(5)+"\t");
					System.out.print("Marks = "+getMark(rs.getInt(5),total_conducted)+"\n");
				}
				rs.close();
				sql="Delete from attendance";
				ps=conn.prepareStatement(sql);
				result=ps.executeUpdate();
				if(result==1)
				{
					System.out.println("\nData deleted successfully\n");
				}
			}
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}
