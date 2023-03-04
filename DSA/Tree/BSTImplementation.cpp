// Function Implementation
#include <iostream>
using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode *getnewNode(int data)
{
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
BstNode *Insert(BstNode *root, int data)
{
    if (root == NULL)
    {
        root = getnewNode(data);
        return root;
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
        return root;
    }
    else
    {
        root->right = Insert(root->right, data);
        return root;
    }
}
BstNode *Search(int key, BstNode *root)
{
    if (root==NULL || key == root->data)
    {
        return root;
    }
    else if(key < root->data)
    {
        Search(key, root->left);
    }
    else
    {
        Search(key, root->right);
    }
}
BstNode *findLargestNode(BstNode *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
BstNode *Delete(BstNode *root, int x)
{
    BstNode *temp;
    if (root == NULL)
    {
        cout << "Tree is empty\n";
        return root;
    }
    else if (x < root->data)
    {
        root->left = Delete(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = Delete(root->right, x);
    }
    else
    {
        temp = root;
        if (root->left == NULL && root->right == NULL) // Node is a leaf node;
        {
            temp = root;
            root = NULL;
        }
        else if (root->left == NULL)//if node has only right child
        {
            
            temp = root;
            root = root->right;
        }
        else if(root->right==NULL)//only left child
        {

            temp = root;
            root = root->left;
        }
        else//node has both left and right children
        {
            temp = findLargestNode(root->left);
            root->data = temp->data;
            root->left = Delete(root->left, temp->data);
        }
        delete (temp);
    }
    return root;
}
void DisplayInOrder(BstNode *root)
{
    if (!root)
    {
        return;
    }
    DisplayInOrder(root->left);
    cout << root->data << "  ";
    DisplayInOrder(root->right);
}
int main()
{
    BstNode *root = NULL;
    root = Insert(root, 4);
    root = Insert(root, 7);
    root = Insert(root, 2);
    root = Insert(root, 3);
    root = Insert(root, 6);
    root = Insert(root, 1);
    root = Insert(root, 5);
    DisplayInOrder(root);
    
    cout << "\nThe largest root is:" << findLargestNode(root)->data << endl;
    root = Delete(root, 4);
    DisplayInOrder(root);
    BstNode *found = Search(4, root);
    if(found)
        cout << "\nSearch Successful" << endl;
    else
        cout << "\nSearch Unsuccessful" << endl;
    return 0;
}