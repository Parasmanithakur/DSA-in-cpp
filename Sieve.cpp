#include <iostream>
#include <vector>

using namespace std;
void primeSieves(int n)
{
    int prime[100] = {0};
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= n; j = j + i)
                prime[j] = 1;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
            cout << i << " ";
    }
}
int main()
{

    int n;
    cin >> n;
    primeSieves(n);
    return 0;
}