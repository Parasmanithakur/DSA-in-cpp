#include<iostream>
#include<cmath>
using namespace std;

unsigned long long factorial(int n)
{
    const unsigned int M = 1000000007;
 
    unsigned long long f = 1;
    for (int i = 1; i <= n; i++)
        f = (f*i) % M;  // Now f never can
                        // exceed 10^9+7
    return f;
}
int main()
{
    int t,x;
    cin>>t;
    while(t--)
    {
        cin>>x;
        for(int i=0;i<pow(2,x)-1;i++)
        {
            if((i^i+1)==(i+2^i+3))
              cout<< factorial(i);
              
        }

    }
    return 0;

}