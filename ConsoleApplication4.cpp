
//coin change
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> den(10);
	int n,ans(0);
	for (int i = 0;i < 10;i++)
	{
		cin >> den[i];
	}
	sort(den.begin(), den.end(),greater<int>());
	cin >> n;
	int temp = n;
    for(int i=0;i<n;i++)
	{
		ans += n / den[i];
		
		
		n -= n / den[i] * den[i];
	}
	cout << ans;
	return 0;
}


