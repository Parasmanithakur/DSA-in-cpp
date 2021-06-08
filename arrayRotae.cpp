#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	// your code goes here
	
	    
	    vector<long long> A;
	    
	    long long N,Q;
	   
	    cin>>N;
	    long long ans=0;
	    for(int i=0;i<N;i++)
	     {
	          long long x;
	          cin>>x;
	          A.push_back(x);
	           
	     }
	     long long k;
         cin>>k;
	       reverse(A.begin(),A.end());
           reverse(A.begin(),A.begin()+k);
           reverse(A.begin()+k,A.end());
        
        for(auto cur:A)
         {
              cout<<cur<<" ";
         }
	    
	
	return 0;
}
