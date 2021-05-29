//given a array and its size ,find the maximum sum for a given k subset
//subset is consequtive numbers

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
   vector<int> arr,sumArr;
   int n;
   cin>>n;
   int i;
   for( i=0;i<n;i++)
   {
       int x;
       cin>>x;
       arr.push_back(x);
   }
   cout<<"total 1 index"<<i;
   int k;
   cin>>k;
   int sum=0;
    for(int j=0;j<k;j++)
       {
           sum+=arr[j];

       }
    sumArr.push_back(sum);
   for(int i=1;i+k-1<n;i++)
   {
        sum=sum-arr[i-1]+arr[i+k-1];//o(n) soln is the best ,naive sol would be of o(n*K)
        sumArr.push_back(sum);

      

   }
   cout<<endl;
   for(int i =0;i<sumArr.size();i++)

     cout<<sumArr[i]<< " ";
     cout<<endl;
   
    cout<<*max_element(sumArr.begin(),sumArr.end());

   


}
