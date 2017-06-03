#include<iostream>

using namespace std;

class CopyAssign
{
	private:
			int num;
	public:
			CopyAssign() : num(100) {};
			CopyAssign(int in) : num(in) {};
			CopyAssign ( const CopyAssign& in )
			{
				cout << " copy constructor " << endl;
				num = in.num;
			};
			CopyAssign& operator = ( const CopyAssign& in )
			{
				cout << " assignment " << endl;
				num = in.num;
				return *this;
			};
			CopyAssign operator + ( const CopyAssign& in )
			{
				cout << " addition " << endl;
				CopyAssign temp;
				temp.num = num + in.num;
				return temp;
			};
		
			const int& Num() const { return num;};
};

int main (int argc, char* argv[])
{
	for (int i = 0 ; i < argc; ++i)
		cout << " [" << i << "] " <<  argv[i] << endl;

	char test [6] = {'h','e','l','l','o','\0'};
	char* p = test;
	cout << *p << endl;
	char** dblptr = &p;
	cout << *dblptr << endl;

	CopyAssign obj(10);	
	CopyAssign obj2(11);
	cout << " obj = obj2 " << endl;
	obj = obj2;
	cout << " CopyAssign objCopy = obj " << endl;
	CopyAssign objCopy = obj;
	cout << " objCopy = obj + obj2 " << endl;
	objCopy = obj + obj2;
	
	cout <<  " obj " << obj.Num() << endl;
	cout <<  " obj2 " << obj2.Num() << endl;
	cout <<  " objCopy " << objCopy.Num() << endl;
	
	return 1;	
}
