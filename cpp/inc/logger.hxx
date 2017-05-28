#include <fstream>

enum LogEnum
{
	LOG_ERROR,
	LOG_WARNING,
	LOG_AUDIT,
	LOG_DEBUG
};

class Logger
{
public:
	virtual ~Logger();
	static void Log(const char* in);

	void SetLogLevel(LogEnum en);

private:
	Logger();
	void write(const char* in, LogEnum en = LOG_ERROR);
	const char* _EnumToStr(LogEnum en);

	static Logger* _logger;
	std::ofstream _file;
	LogEnum _logLevel;
};
