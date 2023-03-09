//DSA Set 3 Program 4 - Counting number of leaf nodes in BST
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
    int getLeafCount(Node* root)
    {
        if(root == NULL)    
        return 0;
        if(root->left == NULL && root->right == NULL)
        return 1;        
        else
        return getLeafCount(root->left)+getLeafCount(root->right);
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
    cout << "\nNumber of leaf nodes : " << obj.getLeafCount(root);
}   