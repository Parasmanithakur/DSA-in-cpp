#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node *next;
};
class HashTable
  {
	public:
	Node **HT;
	HashTable();
	int hash(int key);
	void insert(int key);
	int search(int key);
	~HashTable();
  };
  HashTable:: HashTable()
  { HT =new Node* [10];
    for (int i=0;i<10;i++)
	{
		HT[i]=NULL;
	}
  };
int HashTable::hash(int key)
{
   return key%10;
}
void HashTable::insert(int key)
{
	int Hindex=hash(key);
    Node *p=new Node;
	p->data=key;
	p->next=nullptr;
	if(HT[Hindex]==NULL)
	{ 
       HT[Hindex]=p;
	}
    else
    {
		Node *t,*q;
		t=q=HT[Hindex];
		while(t && q->data<key)
		{
			t=q;
			q=q->next;
		}
     if(t==HT[Hindex])
	 {
	 p->next=HT[Hindex];
     HT[Hindex]=p;
     }else
	 {
       p->next=t->next;
       t->next=p;
	 }
	}
}
int HashTable::search(int key){
	int Hindex=hash(key);
	Node*p=HT[Hindex];
	while(p){
		if(p->data==key)
		{
			return p->data;
		}
        p=p->next;
	}
    return -1;
	}	
	HashTable::~HashTable() {
	for (int i=0; i<10; i++){
		Node* p = HT[i];
		while (HT[i]){
			HT[i] = HT[i]->next;
			delete p;
			p = HT[i];
		}
	}
	delete [] HT;
}

int main() {
	int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
	int n = sizeof(A)/sizeof(A[0]);
	HashTable H;
	for (int i=0; i<n; i++){
		H.insert(A[i]);
	}
	cout << "Successful Search" << endl;
	int key = 6;
	int value = H.search(key);
	cout << "Key: " << key << ", Value: " << value << endl;
	cout << "Unsuccessful Search" << endl;
	key = 95;
	value = H.search(key);
	cout << "Key: " << key << ", Value: " << value << endl;

	return 0;
}
	
    	
	  
	
	 