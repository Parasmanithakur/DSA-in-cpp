#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node *next;
};
class Hashtable1 
{
 public:
	Node **H;
	Hashtable1();
	void insert(int);
	int search(int);
	int Hashfun(int, int);
	~Hashtable1();
};
Hashtable1::Hashtable1()
{
	H = new Node *[10];
	for (int i = 0;i < 10;i++ )
	{
		H[i] = nullptr;
	}

}
Hashtable1::~Hashtable1()
{

}
int Hashtable1::Hashfun(int key, int i)
{
	return (key % 10 + i) % 10;
}
void Hashtable1::insert(int key)
{
	Node *q;
	for (int i = 0;i < 10;i++)
	{
		q = H[Hashfun(key, i)];
		if (q == NULL)
		{
			q->data = key;
			break;
		}
	}
}
int Hashtable1::search(int key)
{
	for (int i = 0;i < 10;i++)
	{
		if (H[Hashfun(key, i)]->data == key)
		{
			return key;

		}
		else if (H[Hashfun(key, i)] == NULL)
			return -1;
	}
}
int main()
{
	Hashtable1 h;
	h.insert(5);
	h.insert(6);
	h.insert(15);
	if (h.search(15) != -1) { cout << "found";
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
