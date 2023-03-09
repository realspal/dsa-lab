//DSA Set 1 Program 10a - representing sparse matrix using array
#include<iostream>
using namespace std;
class Node
{
    public:
    int row,col;
    double data;
    Node *next;
    Node(int row,int col,double data)
    {
        this->row=row;
        this->col=col;
        this->data=data;
        this->next=NULL;
    }
};
int *row,*col;
double *data;
int numRows,numCols,n;
void displayMatrix()
{
    cout<<"\n-- MATRIX REPRESENTATION --\n"<<endl;
    int k=0;
    for(int i=1;i<=numRows;i++)
    {
        for(int j=1;j<=numCols;j++)
        {
            ///if(data==NULL)
            //cout<<" 0     ";
            //else
            //{
                if(row[k]==i && col[k]==j)
                {
                    cout<<data[k]<<"    ";
                    k++;
                }
                else
                cout<<" 0     ";
            //}
        }
        cout<<endl;
    }
}
void displayArray()
{
    cout<<"\n-- ARRAY REPRESENTATION --\n"<<endl;
    cout<<"Row     Col     Data"<<endl;
    cout<<"------------------------"<<endl;
    for(int i=0;i<n;i++)
    cout<<row[i]<<"       "<<col[i]<<"       "<<data[i]<<endl;
    cout<<endl;
}
void takeInput()
{
    int r,c;
    double v;
    cout<<"Enter number of rows             : ";
    cin>>numRows;
    cout<<"Enter number of columns          : ";
    cin>>numCols;
    cout<<"Enter number of non-zero entries : ";
    cin>>n;
    row=new int[n];
    col=new int[n];
    data=new double[n];
    for(int i=1;i<=n;i++)
    {
        cout<<"Enter row number, column number, data of entry "<<i<<" : ";
        cin>>ws;
        cin>>r>>c>>v;
        row[i-1]=r;
        col[i-1]=c;
        data[i-1]=v;
    }
}
int main()
{
    takeInput();
    displayArray();
    displayMatrix();
    return 0;
}