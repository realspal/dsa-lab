//DSA Set 3 Program 1 - Inorder, preorder and postorder traversal of binary tree
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data):data(data),left(NULL), right(NULL){}
};
void inorder(Node* head)
{
    if(head!=NULL)
    {
        inorder(head->left);
        cout<<head->data<<"  ";
        inorder(head->right);
    }
}
void preorder(Node* head)
{
    if(head!=NULL)
    {
        cout<<head->data<<"  ";
        preorder(head->left);
        preorder(head->right);
    }
}
void postorder(Node* head)
{
    if(head!=NULL)
    {
        postorder(head->left);
        postorder(head->right);
        cout<<head->data<<"  ";
    }
}
int main()
{
    Node* head = NULL;
    head=new Node(10);
    head->left = new Node(20);
    head->right = new Node(30);
    head->left->left = new Node(40);
    head->left->right = new Node(50);
    head->right->left = new Node(60);
    head->right->right = new Node(70);
    int ch=0;
    do
    {
    	cout<<"Enter : (1) In-order traversal (2) Pre-order traversal (3) Post-order traversal (4) Exit"<<endl;
    	cin>>ch;
    	switch(ch)
		{
			case 1:
			cout<<"In-order traversal   :   ";
    		inorder(head);
    		cout<<endl;
			break;
			case 2:
			cout<<"Pre-order traversal  :   ";
    		preorder(head);	
    		cout<<endl;
			break;
			case 3:
			cout<<"Post-order traversal :   ";
    		postorder(head);
			cout<<endl;
			break;
			case 4:
			break;
			default:
			cout<<"Invalid entry."<<endl;
			break;	
		}
	}
	while(ch!=4);
    return 0;
}