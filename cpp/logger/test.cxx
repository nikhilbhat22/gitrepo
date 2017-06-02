#include "logger.hxx"

int main()
{
	Logger::Log("start logging");
	Logger::Log("process started", Logger::LogEnum::LOG_DEBUG);
	Logger::Log("process ends");
	return 1;
}
