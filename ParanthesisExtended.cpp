// for all kinds of bracket eg- (a+{b-f*d}-[a+v])
//using stack  stl
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<stack>
using namespace std;
bool check(string str)
{

    map<char ,char> Mapping;
    stack<char> S;
    Mapping[']']='[';
    Mapping['}']='{';
    Mapping[')']='(';
    map<char,char>::iterator it;
    for(int i=0;i<str.length();i++)
    {

        if (str[i]=='(' || str[i]=='{' || str[i]=='[')
           {

               S.push(str[i]);

           }
       
        else if(str[i]==')' || str[i]=='}' || str[i]==']')
        {
              if (S.empty())
           {
             return false;
          } 
          else
          {
             char ch =S.top();
             it=Mapping.find(str[i]);
             if (ch==Mapping[str[i]])
               {
                   S.pop();
               }
             else 
                 return false;
          }
        }  

    }
    return  true ;

    

}
int main()
{


    string S;
    cin>>S;
    if(check(S))
     {
         cout<<"YES";
     }
     else{
         cout<<"NO";
     }
     return 0;
}