import java.io.*;
import java.util.*;

class ass1q3
{
	public static void main(String args[])
	{
		Set<String> flavors = new HashSet<>();
		Map<String,Double> prices = new HashMap<>();
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("\nEnter the number of ice cream flavors :");
		int n = sc.nextInt();
		for(int i=0;i<n;i++)
		{
			System.out.println("\nEnter ice cream flavor "+(i+1)+" :");
			String flavor = sc.next();
			flavors.add(flavor);
		}
		System.out.println(flavors);
		
		System.out.println("\nEnter the prices of flavors :");
		for(String flavor : flavors)
		{
			double price = sc.nextDouble();
			prices.put(flavor,price);
		}
		
		
		while(true)
		{
			System.out.println("\nMenu :");
			System.out.println("1.Search for specific flavor.");
			System.out.println("2.Sort all the flavor.");
			System.out.println("3.Exit.:\nEnter your choice :");
			int choice = sc.nextInt();
			
			switch(choice)
			{
				case 1:
					System.out.println("\nEnter the flavor to search for : ");
					String flavorToSearch = sc.next();
					if(flavors.contains(flavorToSearch))
					{
						System.out.println("Flavor found.......");
					}
					else
					{
						System.out.println("Flavor not found......");
					}
					break;
					
				case 2:
					System.out.println("Sorting flavors......");
					List<String> sortedFlavors = new ArrayList<>(flavors);
					Collections.sort(sortedFlavors );
					System.out.println("Sorted flavors : "+sortedFlavors);
					break;
					
				case 3:
					sc.close();
					return;
					
				default:
					System.out.println("Invalid choice..");
					
			}
		}
		
	}
}
