// cubeFree number ,if a number is not a cube or has no factors which are cube
#include <iostream>
#include <vector>
using namespace std;
vector<bool> isCube(5005, 0);
void Cube(int n)

{
    isCube[0] = 0;
    isCube[1] = 0;
    for (int i = 2; i * i * i <= n; i++) //sieveing all cubes and its multiples

    {

        if (isCube[i] == 0)
        {
            for (int j = i * i * i; j <= n; j = j * i)
                isCube[j] = 1;
        }
    }
}
int main()
{

    Cube(5004);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        if (isCube[n] == 0)
        {
            cout << "yes" << endl;
        }
        else
            cout << "no" << endl;
    }
}
