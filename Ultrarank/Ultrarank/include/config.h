#pragma once
#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#include <iostream>
#include<stdio.h>
#include<string>
#include<map>
#include<fstream>
#include<stdlib.h>
using namespace std;

class Config {
private:
	string data_path   = "";
	string export_path = "";
	long long data_num = 0 ;

public:
	Config() {};
	~Config() {};

	//Gets
	string get_data_path();
	string get_export_path();
	long long get_data_num();

	//Writer
	void write_config_file();
	void write_new_conf_information();
	void write_new_conf_data_path();
	void write_new_conf_export_path();
	void write_new_conf_data_num();

	//Reader
	void read_config_file(string cfg_path);
	
	//Display
	void show_para();
	
};

#endif // CONFIG_H_INCLUDED
