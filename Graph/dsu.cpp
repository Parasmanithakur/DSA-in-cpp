#include <iostream>
#include <vector>

using namespace std;
int parent[] = {0, 3, 2, 2, 6, 5, 6};
int find(int n)
{
    if (n == parent[n])
        return n;
    else
        return find(parent[n]);
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    parent[a] = b;
}
int main()
{
    cout << find(1) << " " << find(4) << " " << find(5) << endl;
    Union(1, 4);
    cout
        << find(1) << " " << find(4) << " " << find(5);
    return 0;
}