import java.io.*;
import java.util.*;

class Student
{
	int rollno;
	String name;
	int age;
	
	Student(int rollno, String name, int age)
	{
		this.rollno = rollno;
		this.name = name;
		this.age = age;
	}
}

class NameComparator implements Comparator<Student>
{
	public int compare(Student s1,Student s2)
	{
		return s1.name.compareTo(s2.name);
	}
}

class AgeComparator implements Comparator<Student>
{
	public int compare(Student s1,Student s2)
	{
		return s1.age - s2.age;
	}
}



class ass1q4
{
	public static void main(String args[])
	{
		ArrayList<Student> students = new ArrayList<>();
		students.add(new Student(50,"sanket",20));
		students.add(new Student(53,"Shreyas",21));
		students.add(new Student(62,"vaishnavi",19));
		students.add(new Student(14,"Atharva",23));	
		
		System.out.println("------------------------");
		System.out.println("Original list :");
		for(Student s : students)
		{
			System.out.println(s.rollno+" "+s.name+" "+s.age);
		}
		
		System.out.println("------------------------");
		Collections.sort(students, new NameComparator());
		System.out.println("Sorted by Name:");
		for(Student s : students)
		{
			System.out.println(s.rollno+" "+s.name+" "+s.age);
		}
		
		System.out.println("------------------------");
		Collections.sort(students, new AgeComparator());
		System.out.println("Sorted by Age:");
		for(Student s : students)
		{
			System.out.println(s.rollno+" "+s.name+" "+s.age);
		}
		
		System.out.println("------------------------");
	}
}
