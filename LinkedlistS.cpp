//asuing data is stored in sorted manner
#include<iostream>
#include<vector>
#include<algorithm>
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
    vector<int> arrayForm();
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
void Linkedlist:: insert(int data ) // fun to insert data now in sorted manner
{
    Node *ptr,*qtr,*rtr;
    ptr=First;
    int flag=0;
    if(First->data>data)

    { 
        qtr=new Node;
        qtr->data=data;
        qtr->next=First;
        First=qtr;


      
    }
    else {
    while(ptr)
    {
        if(ptr->data>data)
          {  flag=1;
              break;}
         rtr=ptr; 
         ptr=ptr->next;
    }
    qtr=new Node;
    qtr->data=data;
    if (flag==1)
       {
           qtr->next=ptr;
           rtr->next=qtr;
      }
    else// inserting at last.
      {
          qtr->next=NULL;
          rtr->next=qtr;
      }  
    
    }
}

int Linkedlist :: maxElement()// funtion for max element but now array is sorted than its easy
{
    int x;
    //x=INT32_MIN; this will be used in unsorted array
    Node *ptr=First;
    while(ptr)
    {
        
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
 vector<int> Linkedlist::arrayForm()
{
    vector<int> arr;
    Node *ptr=First;
    while(ptr)
    {
        arr.push_back(ptr->data);
        ptr=ptr->next;
    }
    return arr;

}
void merge(Linkedlist l,Linkedlist l2)
{
    vector<int>larr1=l.arrayForm(),larr2=l2.arrayForm();
    vector<int> total;
    for(int x:larr1)
    {
        total.push_back(x);
    }
     for(int x:larr2)
    {
        total.push_back(x);
    }
    sort(total.begin(),total.end());
    int n=total.size(),arr[20];
    for(int i=0;i<n;i++)
      arr[i]=total[i];
    Linkedlist a(arr,n);
    a.display();
  
}
int main()
{
     int A[]={1,2,4,6,7};
     int B[]={3,4,7,9,10};
     Linkedlist l(A,4),l2(B,4);
     l.display();
     int x;
     cout<<"Enter a elemetn to be inserted";
     cin>>x;
     l.insert(x);
     l.display();
    cout<<"Max is "<<l.maxElement()<<"index at ";
    vector<int> help=l.Length(l.maxElement());// could have done easily 
    for(int x:help)
       cout<<x<<" ";
    cout<<endl;
    merge(l,l2);// very naive method

    cout<<endl;

     return 0;
}