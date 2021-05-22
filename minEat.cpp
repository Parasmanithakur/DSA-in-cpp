//Question on bsearch
//https://www.codechef.com/problems/MINEAT
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

typedef  long long ll;


int main() {

	int T, H, N, x;
	float h;
	cin >> T;

	while (T--)
	{
		cin >> N >> H;
		vector<int> arr;
		for (int i = 0;i < N;i++)
		{
			cin >> x;
			arr.push_back(x);
		}
		sort(arr.begin(), arr.end());
		ll l, r,ans;
		l = 1;
		r = 1e9;
		while (l <= r)
		{
			ll mid = l + (r - l) / 2;
			int h = 0;
			for (int j = arr.size() - 1;j >= 0;j--)
			{

				h = h + ceil(double(arr[j]) /double( mid));

			}
			if (h <= H)
			{
				r = mid - 1;
				ans = mid;
			}
			else
				l = mid + 1;
		}

		arr.clear();
		cout << ans<<endl;
	}
	return 0;
}
