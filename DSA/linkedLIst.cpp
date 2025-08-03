#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};
void ins(node **head, int ele){
    node* newNode = new node();
    newNode->data=ele;
    newNode->next = nullptr;
    if(*head == nullptr){
        *head = newNode;
        return;
    }
        node *temp = *head;
        while(temp->next != nullptr){
            temp=temp->next;
        }
        temp->next=newNode;


}
node* isnS(node * head, int ele){
    node *neW = new node();
    neW->data = ele;
    neW->next = head;
    return neW;
}
void dis(node* head){
    node *pt = head;
    while(pt != nullptr){
        cout<<pt->data<<" ";
        pt=pt->next;
    }
}
void insBw(node **head, int ele,int pos){
    node* newNode = new node();
    newNode->data = ele;
    newNode->next = nullptr;
    node *p = *head; int ix=0;
    if(pos==0){
        newNode->next = *head;
        *head = newNode;
    }
    while(ix!=pos-1){
        p=p->next; ix++;
    }
    newNode->next= p->next;
    p->next = newNode;

}
void delEnd(node * head){
    if(head == nullptr || head->next == nullptr) {
        cout<<"The linked list is empty";
        return;
    }
    node *temp = head;
    while((temp->next)->next !=0){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}
int main(){
    struct node *head = nullptr;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int ele ; cin>>ele;
        ins(&head,ele);
    }
    //dis(head);
    cout<<endl;
    delEnd(head);
    //insBw(&head,69,2);
    dis(head);
}
