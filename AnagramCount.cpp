//counting occurence of anagram in a given string

#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;
int AnaCount(string S,string anagram)
{
   int k=anagram.length();
   int j=0,i=0;
   map<char,int> m;
   
   int count=0,ans=0;
   for(int i=0;i<k;i++)
     {
         
         if(m.find(anagram[i])!=m.end()) 
            {
               m[anagram[i]]+=1;
            }
         else 
              m[anagram[i]]=1;   
     }
    
     count =m.size();
    // cout<<"dis"<<count<<endl;
   while (j<S.length())
   {
       
           if (m.find(S[j])!=m.end())
              {
                
                m[S[j]]-=1;

                if(m[S[j]]==0)
                  count--;
              }
            if(j-i+1<k)
             { 
                 j++;
                 continue;
             }  
             if(j-i+1==k)
             {

               if(count==0)
                 { ans++;
                   // cout<<S[j];
                 }
               if(m.find(S[i])!=m.end())
                {
                   if(m[S[i]]==0)
                      count++;
                    m[S[i]]+=1;  
                }  
                i++;

             }
             j++;
    }
      return ans;


}
int main()
{


    int x;
    string Str,anagram;
    cin>>Str;
    cout<<"Now enter the anagram string"<<endl;
    cin>>anagram;
    int ans=AnaCount(Str,anagram);
    cout<<ans;


}