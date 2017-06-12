#include <map>

enum ClassTypeEnum
{
	CTYPE_SWAP_PL = 0,
	CTYPE_FX_PL = 1
};

class BasePLCalc
{
	public:
			BasePLCalc();
			virtual void CalcPL() = 0;
};
class SwapPLCalc : public BasePLCalc
{
	public:
			SwapPLCalc();
			static BasePLCalc* CreatePLCalc();
			virtual void CalcPL();
			static int RegisterMethod();
	private:
			static int _register;
};
class FXPLCalc : public BasePLCalc
{
	public:
			FXPLCalc();
			static BasePLCalc* CreatePLCalc();
			virtual void CalcPL();
			static int RegisterMethod();
	private:
			static int _register;
};

class Factory
{
private:
		Factory();
public:
		static Factory& Instance();
		void Register(ClassTypeEnum en, BasePLCalc* (*) ());
		BasePLCalc*	GetRegisteredObject(ClassTypeEnum en);
private:
		std::map<int, BasePLCalc* (*) ()> _collection;
};
