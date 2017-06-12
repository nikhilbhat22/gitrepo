#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>

class Base
{
private:
	int count;
public:
	Base() :count(0) {std::cout << " constructed Base " << std::endl;};
	Base(int i) :count(i) {std::cout << " constructed Base(int) " << std::endl;};
	Base(const Base& copy) {std::cout << "copy constructed Base " << std::endl;};
	~Base() {std::cout << " destroy Base " << std::endl;};

	int Count() {return count;}	
};

void sharedPtr(boost::shared_ptr<Base> & in)
{
	boost::shared_ptr<Base> copy (in);
	std::cout << "going out of scope" << std::endl;
}

void scopedPtr()
{
	boost::scoped_ptr<Base> smtPtr (new Base());
	std::cout << smtPtr->Count() << std::endl;
	smtPtr.reset(new Base(10));
}

int main ()
{
	boost::shared_ptr<Base> smtPtr(new Base(100));
	sharedPtr(smtPtr);
	std::cout << "scope is over " << std::endl;
}
