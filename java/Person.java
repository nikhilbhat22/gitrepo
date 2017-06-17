
class Person{

	private String name;
	private int age;

	public String Name(){
		return name;
	}

	public void SetName(String in) {
		name = in;	
	}

	public int Age(){
		return age;
	}

	public void SetAge(int in) {
		age = in;
	}

	public Person(){
		name = "Dummy";
		age = 1;
	}
}
