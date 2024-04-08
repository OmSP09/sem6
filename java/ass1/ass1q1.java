import java.io.*;
import java.util.*;

class ass1q1
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		HashMap<String,String> hm = new HashMap<>();
		
		System.out.println("\nHow many persons?");
		int n = sc.nextInt();
		
		for(int i=0;i<n;i++){
			System.out.println("\nEnter "+(i+1)+" person name:");
			String pname = sc.next();
			
			System.out.println("\nEnter "+(i+1)+" person phone number:");
			String pno = sc.next();
			hm.put(pname,pno);
		}
		System.out.println(hm.keySet());
		
		System.out.println("Enter a name to get phone number :");
		String getName = sc.next();
		
		if(hm.containsKey(getName)){
			System.out.println(hm.get(getName));
		}else{
			System.out.println("Person not present in hashtable !");
		}
		
	}
}
