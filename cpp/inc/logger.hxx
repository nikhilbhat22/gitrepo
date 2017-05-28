
class Logger
{
public:
	static Logger& Log();
	Write(const char* in);
	Write(const int& in);
	Write(const string& in);
private:
	Logger() {};
	static Logger* _logger;
	ofstream _file;
};
