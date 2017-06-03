#include<iostream>

using namespace std;

class ZeroClass {};

class VirtualClass { virtual void test() {}; };

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
			void SetNum(const int& in) { num = in; };
};

int main (int argc, char* argv[])
{
	cout << "ZeroClass size " << sizeof(ZeroClass) << endl;
	cout << "OneByteClass size " << sizeof(VirtualClass) << endl;
	int set;
	float unin;
	int noset = set * 100 * unin;
	CopyAssign* ptr = new CopyAssign(100);
	ptr->SetNum(set);

	ptr = new CopyAssign(200);
	delete ptr;

	return 1;	
}
