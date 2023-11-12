#include<iostream>
using namespace std;

//Node structure
class Node{
    public:
    int row;
    int column;
    int value;
    Node* next;

    Node(int r,int c,int v){
        row=r;
        column=c;
        value=v;
        next=NULL;
    }
};


//Linkedlist structure
class LinkedList{
    Node *head;

    public:
    LinkedList(){
        head=NULL;
    }

    //insertion
    void insert(int r,int c,int v){
        Node * newnode=new Node(r,c,v);
        if(head==NULL){
            head=newnode;
        }
        else{
            Node * temp=head;

            //traversal
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    
    void printList(){
        Node *temp=head;
        
        while(temp!=NULL){
            cout<<"Row "<<temp->row<<" Column "<<temp->column<<" Value "<<temp->value<<endl;
            temp=temp->next;
        }
    }

};




int main(){
    int m,n;
    cout<<"Enter matrix dimensions ";
    cin>>m;
    cin>>n;

    int mat[m][n];
    cout<<"Enter matrix elements"<<endl;

    LinkedList ll;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
            //Inserting non-zero elements into the linkedlist
            if(mat[i][j]!=0){
                ll.insert(i,j,mat[i][j]);
            }
        }
    }

    //LinkedList representation of sparse matrix
    ll.printList();

}