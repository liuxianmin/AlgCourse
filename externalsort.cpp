#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <ctime>
#include <algorithm>

using namespace std;

int main (int argc, const char * argv[])
{
	if(argc < 2) 
	{
		cout << "请输入排序整数的数目" << endl;
		return 0;
	}
	int num = atoi(argv[1]);
	cout << "排序数目:" << num << endl;

	cout << "hello world!" << endl;
	time_t nowtime = chrono::system_clock::to_time_t(chrono::system_clock::now());
	// cout << "当前时间:\t"<<nowtime<<"\t"<<ctime(&nowtime)<<endl;
	vector<int> inputdata;
	default_random_engine random(nowtime);
	uniform_int_distribution<int> rr(0,10000);
	for(int i=0;i < num;i++)
		inputdata.push_back(rr(random));
	cout <<"完成数据生成:" <<inputdata.size() << endl;
	// cout << "=========================" << endl;
	// for(int i = 0;i < inputdata.size() ; i++)
	//	cout << inputdata[i] << " ";
	//cout << endl;
	//cout << "-------------------------" << endl;
	auto starttime = chrono::system_clock::now();
	sort(inputdata.begin(),inputdata.end());
	auto endtime = chrono::system_clock::now();

	//for(int i = 0;i < inputdata.size() ; i++)
	//	cout << inputdata[i] << " ";
	//cout << endl;
	cout << "完成排序，花费时间（秒）:"<< double((chrono::duration_cast<chrono::microseconds>(endtime-starttime)).count()) * chrono::microseconds::period::num / chrono::microseconds::period::den << endl;
	return 1;
}
