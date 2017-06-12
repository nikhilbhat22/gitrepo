#include "factory.hxx"
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int main ()
{
	string input;
	cout << " Enter Obj to be created " << endl;
	getline(cin,input);

	ClassTypeEnum en(CTYPE_SWAP_PL);	

	BasePLCalc* ptr = 0;
			
	if (input == "SWAP" || input == "swap" || input == "Swap")
		ptr = Factory::Instance().GetRegisteredObject(CTYPE_SWAP_PL);
	else if (input == "FX" || input == "fx" || input == "Fx")
		ptr = Factory::Instance().GetRegisteredObject(CTYPE_FX_PL);
	else
		cout << "unregistered class" << endl;

	if (ptr)
	{
		ptr->CalcPL();
		delete ptr;
	}
	
	return 0;
}
