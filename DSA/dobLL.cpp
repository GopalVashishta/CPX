#include<iostream>
using namespace std;
struct Node{
    Node *pre;
    int data;
    Node *next;

    Node(int val){
        data = val;
        pre = next = nullptr;
    }
};

void inS(Node*& head, int el){
    Node* newNode = new Node(el);
    if(head == nullptr)
        head=newNode;
    else{
        newNode->next = head;
        head->pre=newNode;
        head=newNode;
    }
}
void inL(Node*& head, int el){
    Node* newNode = new Node(el);
    if(head == nullptr)
        head = newNode;
    else{
        Node *temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->pre = temp;
    }
}
void inBw(Node*& head, int el,int poz){
    Node* newNode = new Node(el);
    int ix=0;
    if(head == nullptr)
        head = newNode;
    else{
        Node *temp = head;
        while(ix!=poz-1){
            temp = temp->next;
            ix++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->pre = temp;
    }
}
//delete
void delP(Node*& head,int pos, int& n){
    int ix=0;
    if(pos>=n) cout<<"out of bounds";
    Node* temp = head;
    while(ix!=pos-1){
        temp = temp->next;
        ix++;
    }
    if(temp == nullptr) cout<<"Nothin to del"<<endl;
    else if(ix==n-1){
        temp->pre->next = nullptr;
        delete temp; n--;
    }
    else if (ix ==0){
        head = head->next;
        delete temp; n--;
    }
    else{
        temp->next->pre =  temp->pre;
        temp->pre->next = temp->next;
        delete temp; n--;
    }
}

void dis(Node *head){
    Node*temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
//Circular LL
void disc(Node *head){
    if(head == nullptr) { cout<<"Nothing to print";
            return;}
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
}

void inBc(Node*& head, int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
        newNode->pre = newNode->next = newNode;
        head = newNode;
    }
    else{
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        newNode->pre = temp;
        head = newNode;
    }
}
int main(){
    Node * head = nullptr;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int el; cin>>el;
        inBc(head,el);
    }

    //dis(head);
    //delP(head,n-1,n);
    //dis(head);
    disc(head);
}
