
#include <iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
	vector<int> values = { 1,2,3,4,5 };
	for (int value : values) //Range based loop short hand but limited
     	cout << value;
	for (vector<int>::iterator it = values.begin();
		it != values.end();it++)
	{
		cout << *it;
	}
	unordered_map<string, int> map;
	map["index1"] = 5;
	map["index2"] = 6;
	using ScoreMap = unordered_map <string, int>;
	using ScoreMapConstIter = ScoreMap::const_iterator;
	ScoreMap map1 ;
	map1["index1"] = 5;
	map1["index2"] = 6;
	for (ScoreMapConstIter it = map1.begin();it != map1.end();it++)
	{
		auto& key = it->first;
		auto& value = it->second;
		
		cout  << key<<"=" << value;
	}
	for (auto kv : map)
	{
		auto& key = kv.first;
		auto& value = kv.second;
		cout << key << "=" << value;
	}
	/*for (const auto &[key, value] : map1)
		cout << key << "=" << value;   c++17*/ 
	//cin.get();

}


