import java.io.*;
import java.util.*;

public class ass1q2
{
	public static void main(String args[]) throws IOException
	{
		LinkedList l1 = new LinkedList();
		LinkedList l2 = new LinkedList();
		LinkedList l3 = new LinkedList();
		LinkedList l4 = new LinkedList();

		int n;
		String ch;
	
		
		Scanner sc =new Scanner(System.in);
		
		System.out.print("\n Enter the numbers for LinkedList 1 :");
		do
		{
			System.out.print("\n Enter the number \n");
			
			
			n = sc.nextInt(); 

			while(l1.contains(n)==true)
			{
				System.out.print("\nDuplicate values not allowed. \n Enter Again:");
				
				n = sc.nextInt();
			}
			System.out.print("\n Do you want to continue:");
			
			ch = sc.next();
			l1.add(n);
						
		
		}while(ch.equals("Y") || ch.equals("y"));
	
		System.out.print("\n Enter the number for LinkedList 2 :");
		
		do
		{
			System.out.print("\n Enter the number \n");

			
			n = sc.nextInt();

			while(l2.contains(n)==true)
			{
				System.out.print("\n Duplicate values not allowed. \n Enter Again:");
				
				n = sc.nextInt();
			}
			System.out.print("\n Do you want to  continue:");
			
			ch = sc.next();
			l2.add(n);			
		}while(ch.equals("Y") || ch.equals("y"));

		System.out.print("LinkedList 1:"+l1+"\n");

		System.out.print("LinkedList 2:"+l2+"\n");
		
		for(int i=0;i<l1.size();i++)
		{
			l3.add(l1.get(i));
		}
		for(int i=0;i<l2.size();i++)
		{
			if(l3.contains(l2.get(i))==false)
				l3.add(l2.get(i));
		}
		for(int i=0;i<l1.size();i++)
		{
			l4.add(l1.get(i));
		}
		l4.retainAll(l2);

		System.out.print("Union of LinkedList : "+l3+"\n");
		System.out.print("Intersection of LinkedList :"+l4+"\n");
			
		
	}
} 
