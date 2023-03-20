#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

int main()
{
    Node *root = NULL;
    int arr[] = {9, 3, 10, 32, 4, 0, 2, 87, 36, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n;i++)
    {
        root = insert(root, arr[i]);
    }

        int searchValue;
    cout << "Enter a value to search in the tree: ";
    cin >> searchValue;

    if (search(root, searchValue))
    {
        cout << searchValue << " found in the tree." << endl;
    }
    else
    {
        cout << searchValue << " not found in the tree." << endl;
    }

    return 0;
}
