//given a array and its size ,find the maximum sum for a given k subset
//subset is consequtive numbers

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxubset(vector<int>arr,int n,int k) // 2 pointer method
{

    int i,j;
    i=j=0;
    int sum=0;
    vector<int>sumArr;
    int max;
    for(j=0;j<n;j++)
    {
        if(j<k)
         { sum+=arr[j];
         }
         
         else{
             sumArr.push_back(sum);
             sum=sum-arr[i]+arr[j];
             i++;
         }
         
  }
  sumArr.push_back(sum);
   for(int i =0;i<sumArr.size();i++)

     cout<<sumArr[i]<< " ";
     cout<<endl;
   


  return    *max_element(sumArr.begin(),sumArr.end());




}
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
        sum=sum-arr[i-1]+arr[i+k-1];
        sumArr.push_back(sum);

      

   }
   cout<<endl;
   for(int i =0;i<sumArr.size();i++)

     cout<<sumArr[i]<< " ";
     cout<<endl;
   
    cout<<*max_element(sumArr.begin(),sumArr.end())<<endl;
    cout<<maxubset(arr,n,k);
   


}