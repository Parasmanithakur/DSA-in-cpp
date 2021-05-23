// map.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<string>
using namespace std;
void unordered_mapDemo()
{
	unordered_map<string, int> map;
	map["index1"] = 5;
	map["index2"] = 6;
	using ScoreMap = unordered_map <string, int>;
	using ScoreMapConstIter = ScoreMap::const_iterator;
	ScoreMap map1;
	map1["index1"] = 5;
	map1["index2"] = 6;
	for (ScoreMapConstIter it = map1.begin();it != map1.end();it++)
	{
		auto& key = it->first;
		auto& value = it->second;

		cout << key << "=" << value;
	}
	for (auto kv : map)
	{
		auto& key = kv.first;
		auto& value = kv.second;
		cout << key << "=" << value;
	}
	unordered_map<string, int> map;
}
int main()
{   
	map<int, int> A;
	A[1] = 100;
	A[2] = 1;
	A[123] = 245;
	map<char, int> cnt;
	string x = "bigBrownFox jump over fence";
	for (char c : x)
	{
		cnt[c]++;
	}
	cout << cnt['a'] << " " << cnt['z'] << endl;

}

