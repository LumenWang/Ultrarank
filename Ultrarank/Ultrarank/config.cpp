#include"include\config.h"
#include<fstream>

//1.Gets
string Config::get_data_path() {
	return data_path;
}

string Config::get_export_path() {
	return export_path;
}

long long Config::get_data_num() {
	return data_num;
}


//2.New File
void Config::write_config_file() {
	write_new_conf_information();
	write_new_conf_data_path();
	write_new_conf_export_path();
	write_new_conf_data_num();
}

void Config::write_new_conf_information() {
	string information = "# welcome to Ultrarank\n";
	information = information + "# please configure data-path and export-path\n";
	ofstream outfile;
	outfile.open("sort.cfg", ios::out | ios::app | ios::ate);
	if (outfile.is_open()) {
		outfile << information << endl;
	}
	else {
		cout << "in function 'write_new_conf_information_1', file open failed" << endl;
	}
}

void Config::write_new_conf_data_path() {
	ofstream outfile;
	outfile.open("sort.cfg", ios::out | ios::app | ios::ate);
	if (outfile.is_open()) {
		string info = "[data-path]";
		outfile << info << endl;
		outfile << "data_path=" << data_path << "\n" << endl;
	}
	else {
		cout << "in function 'write_new_conf_data_path', open file failed" << endl;
	}
}

void Config::write_new_conf_export_path() {
	ofstream outfile;
	outfile.open("sort.cfg", ios::out | ios::app | ios::ate);
	if (outfile.is_open()) {
		string info = "[export-path]";
		outfile << info << endl;
		outfile << "export_path=" << export_path << "\n" << endl;
	}
	else {
		cout << "in function 'write_new_conf_export_path', open file failed" << endl;
	}
}

void Config::write_new_conf_data_num() {
	ofstream outfile;
	outfile.open("sort.cfg", ios::out | ios::app | ios::ate);
	if (outfile.is_open()) {
		string info = "[data-num]";
		outfile << info << endl;
		outfile << "data_num=" << to_string(data_num) << "\n" << endl;
	}
	else {
		cout << "in function 'write_new_conf_data_num', open file failed" << endl;
	}
}


//3.Display
void Config::show_para() {
	cout << "#########################################################" << endl;
	cout << "The Paras are as follows:" << endl;
	cout << "data_path:       " << this->data_path	 << endl;
	cout << "export_path:     " << this->export_path << endl;
	cout << "data_num:        " << this->data_num << endl;
	cout << "#########################################################" << endl;
}


//4.Reader
void Config::read_config_file(string config_path) {	//它的参数是一个直接定位到文件名的绝对路径，可以直接用ifstream的open方法打开
	ifstream config_file;
	config_file.open(config_path.c_str());
	string str_line;
	if (config_file.is_open()) {
		while (!config_file.eof()) {
			getline(config_file, str_line);
			if ((str_line.find('#') == 0) || (str_line.find('[') == 0)) {
				continue;
			}
			size_t pos = str_line.find('=');
			string str_key = str_line.substr(0, pos);
			string str_value = str_line.substr(pos + 1);

			if (str_key == "data_path") {
				data_path = str_value;
			}
			if (str_key == "export_path") {
				export_path = str_value;
			}
			if (str_key == "data_num") {
				data_num = stoll(str_value);
			}
		}
	}
}









































//void Config::write_variable_datapath(string path_with_in_cfg) {
//	ofstream outfile;
//	outfile.open(path_with_in_cfg.c_str(), ios::out | ios::app | ios::ate);
//	if (outfile.is_open()) {
//		outfile << "data_path=\"" << data_path << "\"" << endl;
//	}
//	else {
//		cout << "in function'write_in_conf_datapath', file open failed" << endl;
//	}
//}

//void Config::write_variable_exportpath(string path_with_in_cfg) {
//	ofstream outfile;
//	outfile.open(path_with_in_cfg.c_str(), ios::out | ios::app | ios::ate);
//	if (outfile.is_open()) {
//		outfile << "Export_path=\"" << export_path << "\"" << endl;
//	}
//	else {
//		cout << "in function 'write_in_conf_Exportpath', file open failed" << endl;
//	}
//}










//void configer::ConfigFileRead_train(map<string, string>& m_mapConfigInfo) {
//	ifstream configFile;
//	string path = "./conf/train.conf";
//	configFile.open(path.c_str());
//
//
//	string str_line;
//	if (configFile.is_open())
//	{
//		while (!configFile.eof())
//		{
//			getline(configFile, str_line);
//			if (str_line.find('#') == 0)
//			{
//				continue;
//			}
//			size_t pos = str_line.find('=');
//			string str_key = str_line.substr(0, pos);
//			string str_value = str_line.substr(pos + 1);
//			m_mapConfigInfo.insert(pair<string, string>(str_key, str_value));
//		}
//	}
//	else
//	{
//		cout << "Cannot open config file train.conf ";
//		exit(-1);
//	}
//}
//
//void configer::ConfigFileRead_cg(map<string, string>& m_mapConfigInfo) {
//	ifstream configFile;
//	string path = "./conf/bestcg.conf";
//	configFile.open(path.c_str());
//	string str_line;
//	if (configFile.is_open())
//	{
//		while (!configFile.eof())
//		{
//			getline(configFile, str_line);
//			if (str_line.find('#') == 0)
//			{
//				continue;
//			}
//			size_t pos = str_line.find('=');
//			string str_key = str_line.substr(0, pos);
//			string str_value = str_line.substr(pos + 1);
//			m_mapConfigInfo.insert(pair<string, string>(str_key, str_value));
//		}
//	}
//	else
//	{
//		cout << "Cannot open config file bestcg.conf ";
//		exit(-1);
//	}
//}
//
//void configer::PrintConfig(map<string, string>& m) {
//	map<string, string>::const_iterator mite = m.begin();
//	for (; mite != m.end(); ++mite) {
//		cout << mite->first << "=" << mite->second << endl;
//	}
//}




