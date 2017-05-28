
class Logger
{
public:
	Log();
	Write(const char* in);
	Write(const int& in);
	Write(const string& in);
private:
	Logger() :_logger(NULL) {};
	Logger* _logger;
};
