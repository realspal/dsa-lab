//DSA Set 3 Program 5 - Checking for and converting to AVL tree
#include<iostream>
#include<vector>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int x):data(x),left(NULL), right(NULL){}
};
int heightOfTree(Node* root)
{
    if(root == NULL)
    return 0;
    else
    return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
}
bool isAVL(Node* root)
{
    if(root == NULL)
    return true;
    else if(abs(heightOfTree(root->left) - heightOfTree(root->right)) <= 1)
    {
        bool left = isAVL(root->left);
        bool right = isAVL(root->right);
        if(left && right)
        return true;
        else
        return false;
    }
    return false;   
}
void fill_arr(Node* root, vector<int>& ele)
{
    if(root == NULL)
    return;
    else
    {
        fill_arr(root->left, ele);
        ele.push_back(root->data);
        fill_arr(root->right, ele);
    }
}
Node* buildTree(vector<int> ele, int start, int end)
{
    if(start > end)
    return NULL;
    int mid = (start+end)/2;
    Node* root = new Node(ele[mid]);
    root->left = buildTree(ele, start, mid-1);
    root->right = buildTree(ele, mid+1, end);
    return root;
}
Node* toAVL(Node* root)
{
    vector<int> ele;
    fill_arr(root, ele);
    Node* newroot = buildTree(ele, 0, ele.size()-1);
    return newroot;
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
int main()
{
    Node* root = new Node(27);
    root->left = new Node(13);
    root->right = new Node(31);
    root->left->left = new Node(8);
    root->left->right = new Node(21);
    root->left->right->left = new Node(16);
    root->left->right->right = new Node(25);
    root->left->right->right->right = new Node(26);
    root->right->left = new Node(28);
    cout<<"Inorder traversal of given tree : ";
    inorder(root);
    Node* avl = NULL;
    if(!isAVL(root))
    {
        cout << "\nGiven tree is not AVL tree." << endl;
        cout << "Converting it to AVL tree..." << endl;
        avl = toAVL(root);
        cout<<"Inorder traversal of AVL tree : ";
        inorder(root);
    }
    else
    cout << "\nGiven tree is AVL tree." ;
    if(isAVL(avl))
    cout << "\nNew tree is AVL tree (balanced)." << endl;
}