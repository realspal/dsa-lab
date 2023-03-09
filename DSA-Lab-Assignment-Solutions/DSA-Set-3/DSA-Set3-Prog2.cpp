//DSA Set 3 Program 2 - Operations on BST
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data):data(data),left(NULL), right(NULL){}
};
int flag=0;
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
    Node* findNode(Node* root)
    {
        Node* temp = root;
        while(temp->left)
        temp = temp->left;
        return temp;
    }
    Node* deleteNode(Node* root, int data)
    {
        if(root == NULL)
        {
        	cout << "Data not found" << endl;
        	flag=1;
		}
        else
        {
            if(root->data == data)
            {
                if((root->left == NULL) && (root->right == NULL))
                {
                    delete root;
                    return NULL;
                }
                else if((root->left == NULL) && (root->right))
                {
                    auto temp = root->right;
                    delete root;
                    return temp;
                }
                else if((root->right == NULL) && (root->left))
                {
                    auto temp = root->left;
                    delete root;
                    return temp;
                }
                else
                {
                    Node* replace = findNode(root->right);
                    root->data = replace->data;
                    deleteNode(root->right, replace->data);
                }
            }
            else if(root->data > data)
            root->left = deleteNode(root->left, data);
            else if(root->data < data)
            root->right = deleteNode(root->right, data);
        }
        return root;
    }
    void findMinimum(Node* root)
    {
        auto temp = root;
        while(temp->left)
        temp = temp->left;
        cout << "Minimum number is : " <<temp->data << endl;
    }
    void findMaximum(Node* root)
    {
        auto temp = root;
        while(temp->right)
        temp = temp->right;
        cout << "Maximum number is : " <<temp->data << endl;
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
    int ch=0,d=0;
    do
    {
    	cout<<"Enter : (1) Insert node (2) Delete node (3) Find minimum (4) Find maximum (5) Exit"<<endl;
    	cin>>ch;
    	switch(ch)
		{
			case 1:
			cout<<"Enter data of node to be inserted : ";
			cin>>d;
			root = obj.insertNode(root,d);
			cout<<"Inserted node with data = "<<d<<". Inorder traversal : ";
    		obj.inorder(root);
    		cout<<endl;
			break;
			case 2:
			cout<<"Enter data of node to be deleted : ";
			cin>>d;
			root = obj.deleteNode(root,d);
			if(flag==0)
			{
				cout<<"Deleted node with data = "<<d<<". Inorder traversal : ";
    			obj.inorder(root);
    			cout<<endl;
			}
			else
			flag=0;
			break;
			case 3:
			obj.findMinimum(root);
			break;
			case 4:
			obj.findMaximum(root);
			break;
			case 5:
			break;
			default:
			cout<<"Invalid entry."<<endl;
			break;	
		}
	}
	while(ch!=5);
}