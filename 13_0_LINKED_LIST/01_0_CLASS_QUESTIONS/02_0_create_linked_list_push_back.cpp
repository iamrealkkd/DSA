#include<iostream>
using namespace std;
class Node{
    public:
         int data;
         Node* next;

         Node(int val){
            data = val;
            next = NULL;
         }
};

class List{
    Node* head;
    Node* tail;//not need to be public
public:
   List(){
    head = tail = NULL;
     
   }

   void push_front(int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = tail = newNode;
        return;
    }else{
        newNode -> next = head;
        head = newNode;
    }
   }

   void push_back(int val){
    Node* newNode = new Node(val);

    if(head == NULL){
        head = tail = newNode;
    }else{
        tail -> next = newNode;
        tail = newNode;
    }
   }

   void printLL(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
   }
};

int main(){

    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_back(5);

    ll.printLL();

    return 0;
}