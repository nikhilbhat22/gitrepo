import java.util.Date;

class first
{
	public static void main (String[] args)
	{
		System.out.println("Hi");
		Date current = new Date();
		System.out.println(current);
		//System.getProperties().list(System.out);

		Person p = new Person();
		System.out.println(" Person values " + p.Name() + ", " + p.Age());
		PassByRef(p);
		System.out.println(" Person values " + p.Name() + ", " + p.Age());
	}

	public static void PassByRef(Person in) {
		in.SetAge(26);
		in.SetName("Jack");
	}
}
