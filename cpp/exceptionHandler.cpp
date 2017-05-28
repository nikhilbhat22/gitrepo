#include <iostream>
#include <typeinfo>
//#include <exception>
//#include <math.h>

using namespace std;

class DynamicA
{

public:
	DynamicA() {}
	virtual ~DynamicA() {}
};

class DynamicB : public DynamicA
{ };

class DynamicC : public DynamicA
{
public:
	int x;
	DynamicC(): x(100) {}
	void X() {cout << x << endl;}
};

struct DivideByZeroException : public std::exception
{
	const char* what() const throw ()
	{
		return "Trying to divide by zero. Exception!!!";
	}
};

bool StringIsNumber(string in)
{
	for (string::iterator it = in.begin(); it != in.end(); ++it)
	{
		if (!isdigit(*it))
			return false;
	}
	return true;
}

int main ()
{
	cout << " Enter an integer : ";
	int d1;
	string in;
	getline(cin, in);

	DynamicA* A = new DynamicB();

	try
	{
		if (!StringIsNumber(in))
			throw "Exception: Value not a number";

		d1 = atoi (in.c_str());
		int d = 1;
		int c;

		if (d1 == 0)
			throw DivideByZeroException();
		else if (d1 == 10)
			throw 1;

		c = d/d1;
		cout << " type of : " << typeid(*A).name() << endl;
		DynamicC& C = dynamic_cast<DynamicC&> (*A);
		C.X();
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}
	catch (DivideByZeroException ex)
	{
		cout << ex.what() << endl;
	}
	catch (int t)
	{
		cout << "integer exception caught " << endl;
	}
	catch (std::bad_cast c)
	{
		cout << c.what() << endl;
	}
	cout << "running " << endl;
}
