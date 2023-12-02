#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

    //constructor
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this ->next !=NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory is free for the node with thw data "<<value<<endl;
    }
    

};

void insertNode(Node*&tail, int element , int d ){
    //Assuming that the element is present in the lsit
    //empty list
    if(tail==NULL){
        Node*newNode = new Node(d);
        tail = newNode;
        newNode ->next = newNode;
    }
    else{
        // non empty list
        //Assuming that the element is present in the lsit
        Node*curr = tail;
        while(curr->data !=element ){
            curr = curr->next;
        }
        //element is found ->curr is representing the element wala node
        Node*temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;

    }
}

void printNode(Node*&tail)
{
    Node*temp = tail;
    do {
        cout<<tail->data<<" ";
        tail = tail -> next;
    }while(tail!=temp);
    cout<<endl;
    

    
}

int main()
{
    Node*tail = NULL;
    insertNode(tail,5,3);
    printNode(tail);

    insertNode(tail , 3 , 7);
    printNode(tail);
    insertNode(tail , 6 , 12);
    printNode(tail);
    insertNode(tail , 5 , 7);
    printNode(tail);
    return 0;
}