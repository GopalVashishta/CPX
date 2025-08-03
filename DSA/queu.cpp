#include<iostream>
#include<queue>
using namespace std;
struct node{
    int data;
    node* next;
    node(int a){ data = a; next = nullptr;}
};
void insertAtbeg(node*& head, int val){
    node* newNode = new node(val);
    newNode->next = head; head= newNode;
}
void insertAtEnd(node*& head, int val){
    node* newNode = new node(val);
    if(head == nullptr){head = newNode; return;}
    node* temp= head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertAtix(node*& head, int val, int ix){
    node* newNode = new node(val);
    if(head == nullptr){head = newNode; return;}
    if(ix == 0){ newNode->next = head; head=newNode; return;}
    int n =0; node* temp= head;
    while(temp->next !=nullptr){ n++; temp = temp->next;} temp=head;
    if(ix > n){return;} n=0;
    while(n != ix -1){
        temp = temp->next; n++;
    }
    newNode->next = temp->next; temp->next = newNode;
}
void ipriq(node*& head, int val){
    node* newNode = new node(val); //cout<<val<<" ";
    if(head == nullptr){ head = newNode; return;} //empty
    if(val > head->data ){ newNode->next = head; head=newNode; return;} //value > head
    node* temp = head;
    while(temp->next != nullptr && val <= temp->next->data){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}


int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    node* head = nullptr;
    for(int i=0; i<n; i++){
        ipriq(head,arr[i]);
    }

    node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}
/*
// array implementation : in this create an array and make 2 ptrs for front and rear/back insert at rear index as the size inc.
    just do arr++; to move the ptr to next place and ignore the previous value and the size and initial value of //front,back is -1;

// just do linked list operations just do head = head->next , and delete temp ,, rear(back) will help only if its a two way linked list(doubly ll)

or just use the damn library
*/
/*
int main(){
    queue <int>p;
    for(int i=0; i<9; i++){
        int a; cin>>a;
        p.push(a);
    }

    queue <int> z =p;
    while(!z.empty()){
        cout<<z.front()<<" ";
        z.pop();
    }
    cout<<"thiss is size "<<p.size()<<endl;

    priority_queue <int>x;
    for(int i=0; i<9 ; i++){
        int a ;
        cin>>a;
        x.push(a);
    }
    cout << "Priority Queue: ";
    while (!x.empty()) {
        cout << x.top() << ' ';
        x.pop();
    }
}
*/

