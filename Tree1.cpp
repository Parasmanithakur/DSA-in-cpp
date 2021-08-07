#include <iostream>
#include <queue>
using namespace std;

class tree
{
public:
    int val;
    tree *left, *right;
    tree(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
    void preorder(tree *root);
    void postorder(tree *root);
    void inorder(tree *root);
    void levelorder(tree *root);
};
void tree::preorder(tree *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void tree::postorder(tree *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);

    cout << root->val << " ";
}
void tree::inorder(tree *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void tree::levelorder(tree *root)
{
    if (root == NULL)
        return;
    queue<tree *> q;

    q.push(root);
    q.push(NULL);
    tree *temp;
    cout << "level 0-";
    int i = 0;
    while (!q.empty())
    {

        temp = q.front();

        q.pop();
        if (temp != NULL)
        {
            cout << temp->val << " ";
            if (q.empty())
                break;
            if (temp == NULL)
                q.push(NULL);
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        else if (!q.empty())
        {

            q.push(NULL);
            i++;
            cout << "\nlevel " << i << "-";
        }
    }
}
int sumAtKlevel(tree *root, int k) //sum of all elements at kth level
{

    if (root == NULL)
        return 0;
    queue<tree *> q;

    q.push(root);
    q.push(NULL);
    tree *temp;

    int i = 0;
    int sum = 0;
    while (!q.empty())
    {

        temp = q.front();

        q.pop();
        if (temp != NULL)
        {
            sum += temp->val;

            if (q.empty())
                break;
            if (temp == NULL)
                q.push(NULL);
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        else if (!q.empty())
        {

            i++;
            if (i - 1 == k)
            {
                return sum;
            }
            q.push(NULL);
            sum = 0;
        }
    }
    return sum;
}
int coutNode(tree *root)
{
    if (root == NULL)
        return 0;
    return coutNode(root->left) + coutNode(root->right) + 1;
}
int sumNode(tree *root)
{
    if (root == NULL)
        return 0;
    return sumNode(root->left) + sumNode(root->right) + root->val;
}
int height(tree *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

/*
            1
           /   \
          2      3
         /  \   /  \
       4     5  6    7
*/
int main()
{
    tree *root = new tree(1);

    root->left = new tree(2);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->right = new tree(3);
    root->right->left = new tree(6);
    root->right->right = new tree(7);

    root->preorder(root);
    cout << endl;
    root->postorder(root);
    cout << endl;
    root->inorder(root);
    cout << endl;
    root->levelorder(root);
    cout << endl;
    cout << sumAtKlevel(root, 2) << endl; // sum at level    2;
    cout << coutNode(root) << endl;
    cout << sumNode(root) << endl;
    cout << height(root) << endl;
}
