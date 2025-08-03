#include <iostream>
#include<stack>
#include<cmath>
#include<cstring>
using namespace std;
/*
struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};
Node* top = nullptr;
void push(Node*& top , int val){
    Node* newNode = new Node(val);
    newNode->next = top;
    top = newNode;
}
void pop(){
    Node* temp = top;
    top = top->next;
    delete temp;
}
void dis(){
    Node* temp = top;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
*/
int main() {
     stack <int> s;
     string str;
     cin>>str;
     int n = str.length();
     for(int i=0; i<n; i++){
        if(isdigit(str[i])){
            s.push(str[i]-'0');
        }
        else{
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            switch (str[i]){
                case '+':
                    s.push(a+b);
                    break;
                case '-':
                    s.push(a-b);
                    break;
                case '*':
                    s.push(a*b);
                    break;
                case '/':
                    s.push(a/b);
                    break;
                case '^':
                    s.push(pow(b,a));
                    break;
                default:
                    cout<<"invalid operator:";
            }
        }


     }
    cout<<s.top();
return 0;
}
