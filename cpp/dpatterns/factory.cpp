#include "factory.hxx"
#include <iostream>

int SwapPLCalc::_register = SwapPLCalc::RegisterMethod();
int FXPLCalc::_register = FXPLCalc::RegisterMethod();

BasePLCalc::BasePLCalc()
{ }

SwapPLCalc::SwapPLCalc()
{ }

FXPLCalc::FXPLCalc()
{ }

BasePLCalc*
SwapPLCalc::CreatePLCalc()
{
	return new SwapPLCalc();
}

void
SwapPLCalc::CalcPL()
{
	std::cout << " Swap PL Calculation " << std::endl;
}

int
SwapPLCalc::RegisterMethod()
{
	Factory::Instance().Register(CTYPE_SWAP_PL, SwapPLCalc::CreatePLCalc);
}

BasePLCalc*
FXPLCalc::CreatePLCalc()
{
	return new FXPLCalc();
}

void
FXPLCalc::CalcPL()
{
	std::cout << " FX PL Calculation " << std::endl;
}

int
FXPLCalc::RegisterMethod()
{
	Factory::Instance().Register(CTYPE_FX_PL, FXPLCalc::CreatePLCalc);
}

//--------------------------------------------------------------------------------//

Factory::Factory()
{
}

Factory&
Factory::Instance()
{
	static Factory instance;
	return instance;
}

void
Factory::Register( ClassTypeEnum en, BasePLCalc* (*fptr) () )
{
	_collection.insert( std::make_pair(en, fptr) );
}

BasePLCalc*
Factory::GetRegisteredObject( ClassTypeEnum en )
{
	BasePLCalc* (*fptr) ();
	fptr = (_collection.find(en))->second;
	return fptr();
}
