#pragma warning(disable:4996)
#include"include\rank.h"
#include"include\config.h"
#include"include\log.h"
#include<sstream>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>

using namespace std;

double *array_ = NULL;
long long data_num = 0;

void ultra_rank(Config myConfig) {

	// initialization
	Log mylog;
	mylog.init(myConfig.get_export_path());

	long long data_num = myConfig.get_data_num();
	array_ = (double*)malloc(data_num * sizeof(double));

	// load original data
	clock_t ultra_start = clock(), ultra_end;
	clock_t load_start = clock(), load_end;
	ifstream file_reader(myConfig.get_data_path().c_str(), ios::binary);

	if (file_reader.is_open()) {
		string open_success = "....Open original data success!";
		cout << open_success << endl;
		mylog.write_log(open_success, message);

		long size;
		char * buffer;
		filebuf *pbuf;

		pbuf = file_reader.rdbuf();							//利用filebuf *pbuf对ifstream输入流内容重定向
		size = pbuf->pubseekoff(0, ios::end, ios::in);		//获取文件字节大小，1字节==asizeof(char)
		pbuf->pubseekpos(0, ios::in);						//将指针位置更改为文件初始位置
		buffer = new char[size];							//预先为字符串分配与文件大小相同的缓冲区
		pbuf->sgetn(buffer, size);							//调用filebuf的sgetn()函数填充字符串缓冲区char *buffer

		file_reader.close();
		string input(buffer);
		delete[]buffer;
		istringstream ss_sim(input);
		string fVecSim;

		long long load_id = 0;
		while (ss_sim >> fVecSim) {
			array_[load_id++] = atof(fVecSim.c_str());
			fVecSim.clear();
		}

		string load_success = "....Load original data success!";
		cout << load_success << endl;
		mylog.write_log(load_success, message);

		load_end = clock();
		double load_time = double((load_end - load_start)*1.0 / CLOCKS_PER_SEC);
		
		string s_load_time = to_string(load_time);
		string load_info = "......The load time is:";
		load_info.append(s_load_time.c_str()).append("s");

		cout << load_info << endl;
		mylog.write_log(load_info, message);


		//rank
		clock_t rank_start = clock(), rank_end;
		sort(array_, array_ + data_num);

		rank_end = clock();
		string rank_success = "....Rank success!";
		cout << rank_success << endl;
		mylog.write_log(rank_success, message);

		double rank_time = double((rank_end - rank_start)*1.0 / CLOCKS_PER_SEC);
		string s_rank_time = to_string(rank_time);
		string rank_info = "......The rank time is:";
		rank_info.append(s_rank_time.c_str()).append("s");

		cout << rank_info << endl;
		mylog.write_log(rank_info, message);


		//export data
		clock_t export_start = clock(), export_end;
		ofstream file_export(myConfig.get_export_path().c_str(), ios::binary);
		file_export << std::setprecision(10);

		for (unsigned i = 0; i < data_num; i++) {
			double tmp = array_[i];
			char str[30];
			sprintf(str, "%.9e\n", tmp);
			file_export << str;
		}

		ultra_end = export_end = clock();
		string export_success = "....Export success!";
		cout << export_success << endl;

		mylog.write_log(export_success, message);

		double export_time = double((export_end - export_start)*1.0 / CLOCKS_PER_SEC);
		string s_export_time = to_string(export_time);
		string export_info = "......The export time is:";
		export_info.append(s_export_time.c_str()).append("s");
		cout << export_info << endl;
		mylog.write_log(export_info, message);

		double ultrarank_time = double((ultra_end - ultra_start) *1.0 /CLOCKS_PER_SEC);
		string s_ultrarank_time = to_string(ultrarank_time);
		string ultra_info = "....The ultrarank time is:";
		ultra_info.append(s_ultrarank_time.c_str()).append("s");
		cout << ultra_info << endl;
		mylog.write_log(ultra_info, message);
	}
	else {
		string open_fail = "....Open original data failed!";
		cout << open_fail << endl;
		mylog.write_log(open_fail, error);
	}

	//free
	free(array_);
}