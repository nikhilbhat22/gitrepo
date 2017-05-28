#include <fstream>

class Logger
{
public:
	virtual ~Logger();
	static Logger& Log();
	void Write(const char* in);
private:
	Logger();
	static Logger* _logger;
	std::ofstream _file;
};
