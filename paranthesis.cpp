//Paranthesis Check using Stack
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node //Class for node 
{
    public: 
    int data;
    Node *next;

};
class Stack  // class for implementing stack on nodes
{
    Node *top;
    public:
    Stack();
    void display();
    void push(int data);
    int pop();
    int isEmpty();
    int peek(int index);
    int stackTop();

};
Stack::Stack() // constructor
{
    top=nullptr;

}
int Stack::isEmpty() // to check if empty
{
    if(top==nullptr)
    {
        return 1;
    }
    else 
        return 0;
}
int Stack::peek(int index)
{
   if(isEmpty())
    {
        return -1;
    }
   else 
   { Node *ptr=top;
     for(int i=0;ptr!=nullptr && i<index;i++)
       {
            ptr=ptr->next;

       }
     if(ptr!=nullptr)
       {
           return ptr->data;
       }
     else 
         return -1;
     }
}
  int Stack::stackTop()
  {
      if(top)
        return top->data;
      else 
        return -1;  
  }
   void Stack::push(int data)
   {
       Node *ptr=top,*t= new Node;
       t->data=data;
       t->next=top;
       top=t;
   }

   int Stack:: pop()
   {
       int x;
       if (top==nullptr)
       {
           cout<<"Under flow";
           return -1;
       }
       else
       {
           Node *ptr=top;
           top=top->next;
           x=ptr->data;
           delete ptr;
           return x;

       }
   }
   
 int main()
 { 
    string str;
    Stack S;
    int flag=0;
    cin>>str;
    for(int i=0;i<str.length();i++)
    {

        if(str[i]=='(')// for only round brackets
          {
             S.push(1);
          }
        if(!S.isEmpty() && str[i]==')')
          {
             int pop =S.pop();
          }
        else if (S.isEmpty() && str[i]==')')  
         {

             flag=1;
             break;
         }

    
    }
    if(flag==1)
    {

        cout<<"NO"<<endl;
    }
    else
      cout<<"YES"<<endl;


   
     return 0;
 }   