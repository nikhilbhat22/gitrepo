#include "logger.hxx"
#include <sstream>
#include <ctime>
#include <iostream>

Logger* Logger::_logger = NULL;

void
Logger::Log(const char* in)
{
	if (!_logger)
		_logger = new Logger();

	_logger->write(in);
}

Logger::Logger()
{
	_file.open("app.log", std::ofstream::app);
	_logLevel = LOG_ERROR;
}

Logger::~Logger()
{
	std::cout << "closing the file"<<std::endl;
	_file.close();
}

void
Logger::write(const char* in, LogEnum level)
{
	if (level > _logLevel)
		return;
	
	if (!_file.is_open())
		_file.open("app.log", std::ofstream::app);

	std::time_t now;
	time(&now);
	struct tm* timeinfo = localtime(&now);

	char ptr[30];
	strftime(ptr, 30, "%Y-%m-%d %H:%M:%S : ", timeinfo); 

	std::ostringstream str;
	str  << "[" << ptr << _EnumToStr(level) << "] " << in << std::endl;
	std::cout << "str " << str.str();
	_file << str.str();
	_file.flush();
}

const char*
Logger::_EnumToStr(LogEnum level)
{
	switch (level)
	{
		case LOG_ERROR:
			return "LOG_ERROR";
		case LOG_WARNING:
			return "LOG_WARNING";
		case LOG_AUDIT:
			return "LOG_AUDIT";
		case LOG_DEBUG:
			return "LOG_DEBUG";
	}
}
