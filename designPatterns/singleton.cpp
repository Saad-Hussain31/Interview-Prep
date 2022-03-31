#include <iostream>
#include <string>
#include <vector>

class Logger {
public:
	//static memfunc that access our static variable
/*	static Logger* GetInstance() {
		if(s_instance == nullptr) {
			s_instance = new Logger;
		}
		return s_instance;
	}
*/
	static Logger& GetInstance() {
		static Logger* s_instance = new Logger;
		return *s_instance;
	}
	
	void print() {
		std::cout << "Accessing the log \n";
		for(auto& eles : m_messages) {
			std::cout << eles << "\n";
		}
	}

	void add(std::string s) {
		m_messages.push_back(s);
	}


private:
	Logger() {
		std::cout << "Logger created \n";
	}
	~Logger() {
		std::cout << "Logger destroyed\n";
	}
	//static Logger* s_instance;
	std::vector<std::string> m_messages;
};

//Logger* Logger::s_instance= nullptr;
int main() {
	Logger::GetInstance().add("msg 1");
	Logger::GetInstance().add("msg 2");
	Logger::GetInstance().add("msg 3");
	Logger::GetInstance().print(); //using thru getinsta() coz its gonna ret 1 single instance
/*	Logger logger1;
	Logger logger2;
	Logger logger3;
	Logger logger4;
*/
	return 0;
}
