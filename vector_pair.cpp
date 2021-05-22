 #include<iostream>
#include<vector>
//#include <bits/stdc++.h>
#include<algorithm>

using namespace std;
bool mycompare(pair<int, int>p1, pair<int, int>p2)
{
	return p1.first < p2.first;
}
int main()
{
	vector <int > v1;
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	vector <int>::iterator it;
	for (it = v1.begin();it != v1.end();it++)
	{
		cout << *it << endl;
	}
	for (auto element : v1)
	{
		cout << element << endl;
	}
	vector <int> v2(3, 50);
	swap(v1, v2);
	//qsort(v2);
	vector <pair<int, int>> v;
	int arr[] = { 3,2,5,4,6,1,0 };

	for (auto element : v2)
	{
		cout << element << endl;
	}
	for (int i = 0;i < (sizeof(arr) / sizeof(arr[0]));i++)
	{
		v.push_back(make_pair(arr[i],i));

	}
	int m;
	m=*max_element(v1.begin(), v1.end());
	cout << "m"<<m<<endl;
	sort(v.begin(), v.end(), mycompare);
	for (int i = 0;i < v.size();i++)
	{
		arr[v[i].second] = i;
	}

	
	for (int i = 0;i < v.size();i++)
		cout << arr[i];

	return 0;
}