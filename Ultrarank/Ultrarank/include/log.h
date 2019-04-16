#pragma once
#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED

#include<string>
#include<time.h>
#include<windows.h>
using namespace std;

enum LogLevel {
	message = 0,
	error,
	warning,
	fatal,
};

class Log {
public:
	Log();
	~Log();

	//Initialization
	void init(string e_path);
	void write_log(string msg, LogLevel level);

protected:
	string log_name;
	string log_path;
	void get_exe_name();
	string get_current_time();
};

#endif // LOG_H_INCLUDED
