#include<iostream>
#include<vector>
using namespace std;
class Node  //node class 
{   public:
    int data;
    Node *next;
   };
class Linkedlist // best representation of ll is with using 2 class ,a-node b-linkedlist
{   private:
    Node *First;
    public:
    Linkedlist(int A[],int n);
    void insert(int data);
    void display();
    int maxElement();
    vector<int>  Length(int );
    int Delete(int data);
};
Linkedlist ::Linkedlist(int A[],int n)// constructor with arrgument of array and size
{
    Node *last,*T;
    First =new Node;
    First->data=A[0];
    First->next=NULL;
    last=First;
    for(int i=1;i<n;i++)
    {
        T=new Node;
        T->data=A[i];
        T->next=NULL;
        last->next=T;
        last=T;

    }


}
void Linkedlist::display()// for display 
{
    Node *ptr =First;
    while(ptr!=NULL)
    {
        cout<<ptr->data<< " ";
        ptr=ptr->next;
    }


}
void Linkedlist:: insert(int data ) // fun to insert data 
{
    Node *ptr,*qtr;
    ptr=First;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    qtr=new Node;
    qtr->data=data;
    qtr->next=NULL;
    ptr->next=qtr;
}

int Linkedlist :: maxElement()// funtion for max element 
{
    int x=INT32_MIN;
    Node *ptr=First;
    while(ptr)
    {
        if(ptr->data>x)
          x=ptr->data;
        ptr=ptr->next;

    }
    return x;
}
vector<int> Linkedlist :: Length(int data=-1)// for total lenght and overloaded for finding index of any presetn data
{
    vector<int> arr; 
    Node *ptr=First;
    int x=0,sum=0;
    if (data==-1)
     {
          while(ptr)
        {
           x++;
           sum+=ptr->data;
           ptr=ptr->next;
       }
     arr.push_back(x);
     arr.push_back(sum);
     }
     else
     {
         while(ptr)
         {
             if(ptr->data==data)
              break;
             ptr=ptr->next; 
              x++;
         }
         arr.push_back(x);
     }
    return arr;

}
int Linkedlist::Delete(int index)// delete at a index
{
     Node *ptr=First,*last=First,*qtr=NULL;
     int flag=0,x=-1;
     if(index==0)
     {
         ptr=First;
         First=First->next;
         delete ptr;
         flag=1;
     }
     else 
     {
     while(ptr)
     {
          x++;
          if(index==x)
           {   flag=1;
               break;
           }
          qtr=ptr;
          ptr=ptr->next;


     }
     if(flag==1)
     {
          qtr->next=ptr->next;
         delete ptr;
     }
     }
    
     
     return flag;
     

}
int main()
{
    int A[]={1,2,4,5,6};
    Linkedlist l(A,4);
    l.insert(7);
    l.display();
    cout<<"Max is "<<l.maxElement()<<"index at ";
    vector<int> help=l.Length(l.maxElement());

    for(int x:help)
       cout<<x<<" ";
    cout<<endl;   
    cout<<"Total length and total sum is ";
     vector<int> help1=l.Length();
    for(int x:help1)
       cout<<x<< " ";
    cout<<"Respectively ";   

    cout<<"Enter a index to be deleted";
    int x;
    cin>>x;
    if(x<0 ||!l.Delete(x))
       cout<<"index not found";
    else 
       cout<<"Deleted data at "<<x<<" index";
       l.display();


    return 0;
}