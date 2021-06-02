// give the first negative element in a subarray
//variation of sliding window
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;


void Neg(vector<int>arr,int n,int k) // 2 pointer method
{

    int i,j,flag=0;
    i=j=0;
    int sum=0;
    deque<int> q;
    int max;
    while(j<n)
    {
        
        if(arr[j]<0 )
         { q.push_back(arr[j]); // pushing all negative numbers 
             
              }
  
         
         if(j-i+1<k)
          { j++;
            continue;
          }

         if(j-i+1==k)
            {
                
                if(!q.empty()) // checking if deque is empty
                 {
                      int neg=q.front();

                   cout<<neg;
                 }
                 else 
                  cout<<0;
                  if(arr[i]<0 )  // poping the number no longer in sub array
                  {
                     q.pop_front();
                   }
                 
                   
                   i++;
            }
            j++;

  

                 
            }    
            
        
         
    }
 
   







vector<int> bforce(vector<int> arr,int n,int k)  //brute force method just to check
{
    int flag=0;
    vector<int> Final;
    for(int i=0;i+k-1<n;i++)
    {
        flag=0;
        for(int j=i;j-i+1<=k;j++)
        {
            if(arr[j]<0)
             {
                 Final.push_back(arr[j]);
                 flag=1;
                 break;

             }
        }
        if(flag==0)
        {
           Final.push_back(0) ;
        }
    }
    return Final;
}
int main()
{
   vector<int> arr,sumArr;
   int n,k;// n= size of array and K is length of subarray
   cin>>n;
   int i;
   for( i=0;i<n;i++)
   {
       int x;
       cin>>x;
       arr.push_back(x);
   }
   cin>>k;
   vector <int> Arr=bforce(arr,n,k);// using brute force method
   for(auto cur:Arr)
   {
        cout<<cur<<" ";
   }
   cout<<endl;
   Neg(arr,n,k);
   return 0;
}
