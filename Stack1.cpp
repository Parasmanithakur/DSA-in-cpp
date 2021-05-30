#include<iostream>
#include<vector>
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
    vector<int> arr={1,2,3,4,5};
    Stack S;
    cout<<"is stack empty (1/0)"<<S.isEmpty()<<endl;
    cout<<"Populating it now"<<endl;
    for (int i= 0;i<arr.size();i++)
    {
       S.push(arr[i]);
    }
    cout<<"is stack empty (1/0)"<<S.isEmpty()<<endl;
    cout<<"Stack top is "<<S.stackTop()<<endl;
    for(int i=0;i<arr.size() && ! S.isEmpty();i++)
       cout<<"Stack at index "<<i <<"is  "<<S.peek(i)<<endl;
       cout<<endl;
    cout<<"Now poping";
    for(int i=0;i<arr.size();i++)
     {
         cout<<S.pop()<<" , "<<flush;
     }
     return 0;

    



}