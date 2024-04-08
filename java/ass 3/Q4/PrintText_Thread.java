import java.util.Scanner;



public class PrintText_Thread extends Thread
{

	private final String text;
	private final int n;
	public PrintText_Thread (String text,int n)
	{
		this.text=text;
		this.n=n;
	}
	@Override
	public void run()
	{
		for(int i=0;i<n;i++)
		{
			System.out.println(text);
			
		}
	}
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the value of n :");
		int n=sc.nextInt();
		Thread t1=new Thread(new PrintText_Thread("thread1",n));
		Thread t2=new Thread(new PrintText_Thread("thread2",n));
		Thread t3=new Thread(new PrintText_Thread("thread",n));

		t1.start();
		t2.start();
		t3.start();
	}


}


