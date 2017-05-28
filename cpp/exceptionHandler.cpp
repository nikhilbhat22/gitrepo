#include <iostream>
#include <exception>

using namespace std;

struct DivideByZeroException : public std::exception
{
	const char* what() const throw ()
	{
		return "Trying to divide by zero. Exception!!!";
	}
};

int main ()
{
	int d = 1;
	int d1 = 0;	
	int c;

	try
	{
		if ( d1 == 0)
			throw DivideByZeroException();

		c = d/d1;
	}
	catch (const char* ex)
	{
		cout << " catching an exception " << ex << endl;
	}
	catch (DivideByZeroException ex)
	{
		cout <<  ex.what() << endl;
	}
	cout << "running " << endl;
}
