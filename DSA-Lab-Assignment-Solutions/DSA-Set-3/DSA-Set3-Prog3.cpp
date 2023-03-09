//DSA Set 3 Program 3 - Searching an element in BST
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data):data(data),left(NULL), right(NULL){}
};
class BST
{
    public:
    Node* insertNode(Node* root, int data)
    {
        if(root == NULL)
        return new Node(data);
        else
        {
            if(root->data > data)
            root->left = insertNode(root->left, data);
            else if(root->data < data)
            root->right = insertNode(root->right, data);     
        }
        return root;
    }
    void search(Node* root, int data)
    {
        if(root == NULL)
        {
            cout << "Element not found." << endl;
            return;
        }
        else
        {
            if(root->data == data)
            {
                cout << "Element found." << endl;
                return;
            }
            else if(data > root->data)
            search(root->right, data);
            else if(data < root->data)
            search(root->left, data);
        }
    }
    void inorder(Node* head)
    {
        if(head!=NULL)
        {
            inorder(head->left);
            cout<<head->data<<"  ";
            inorder(head->right);
        }
    }
};
int main()
{
    Node* root = NULL;
    BST obj;
    root = obj.insertNode(root,20);
    root = obj.insertNode(root,10);
    root = obj.insertNode(root,30);
    root = obj.insertNode(root,50);
    root = obj.insertNode(root,40);
    cout<<"Inorder traversal after inserting 5 nodes : ";
    obj.inorder(root);
    cout<<"\nSearching for 21 in the BST : ";
    obj.search(root,21);
    cout<<"Searching for 30 in the BST : ";
    obj.search(root,30);
}