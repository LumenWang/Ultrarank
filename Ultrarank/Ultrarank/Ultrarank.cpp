// Ultrarank.cpp : 定义控制台应用程序的入口点。

#include"include/log.h"
#include"include/config.h"
#include"include\rank.h"
#include <iostream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
using namespace std;

int main(int argc, char *argv[])
{
	Config myConfig;
	if (argc == 1) {
		myConfig.write_config_file();
	}
	else if (argc > 1) {
		string config_path = argv[1];
		config_path.append("//sort.cfg");
		myConfig.read_config_file(config_path);
		myConfig.show_para();
		cout << endl;
		ultra_rank(myConfig);
	}
	exit(1);
}


