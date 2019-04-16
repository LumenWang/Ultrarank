#pragma warning(disable:4996)
#include "include\log.h"
#include<fstream>
#include<string>
#include<iterator>
#include<iostream>

Log::Log() {
	if (log_name.size() > 0)log_name.clear();
	if (log_path.size() > 0)log_path.clear();
}

Log::~Log() {}

void Log::init(string e_path) {
	string tmp = e_path;
	string::iterator it;
	for (it = tmp.end() - 1; it != tmp.begin(); it--) {
		if (*it != '\\') {
			tmp.erase(it);
		}
		else if (*it == '\\') {
			break;
		}
	}
	tmp.erase(it);
	tmp.append("\\Ultrarank.log");
	log_path = tmp;
}

void Log::write_log(string msg, LogLevel level) {
	ofstream outfile;
	outfile.open(log_path.c_str(), ios::out | ios::app | ios::ate);
	switch (level) {
	case message:
		if (outfile.is_open())outfile << this->get_current_time().c_str() << ":    " << "message-------------" << msg.c_str() << endl;
		break;
	case error:
		if (outfile.is_open())outfile << this->get_current_time().c_str() << ":    " << "fault---------------" << msg.c_str() << endl;
		break;
	case warning:
		if (outfile.is_open())outfile << this->get_current_time().c_str() << ":    " << "warning-------------" << msg.c_str() << endl;
		break;
	case fatal:
		if (outfile.is_open())outfile << this->get_current_time().c_str() << ":    " << "error---------------" << msg.c_str() << endl;
		break;
	}
	outfile.close();
}


string Log::get_current_time() {
	time_t timep;
	time(&timep);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
	return tmp;
}




