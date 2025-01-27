/*Adding and deleting according to certain budget*/
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
Node *insert(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);
    if (root->data < x)
    {
        root->left = insert(root->left, x);
    }
    else if (root->data > x)
    {
        root->right = insert(root->right, x);
    }
    return root;
}
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
Node *delNode(Node *root, int budget)
{
    if (root == NULL)
        return NULL;
    root->left = delNode(root->left, budget);
    root->right = delNode(root->right, budget);
    if (root->data > budget)
    {
        Node *temp = root->left ? root->left : root->right;
        delete root;
        return temp;
    }
    return root;
}
int main()
{
    Node *root = NULL;
    int n;
    cin >> n;
    cout << "Before Insertion: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    cout << "After Insertion: ";
    inOrder(root);
    cout << endl;

    int budget;
    cout << "Enter the budget: ";
    cin >> budget;

    root = delNode(root, budget);
    cout << "After Deletion: ";
    inOrder(root);
}