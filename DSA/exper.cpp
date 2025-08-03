#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{
    node* left;
    int data;
    node* right;
    node(int a) : data(a), left(nullptr) , right(nullptr){}
};

void insBst(node*& root, int data){

    node* newNode = new node(data);
    if(root == nullptr){
        root = newNode;
        return;
    }
    node* temp = root;
    while(temp!= nullptr){
    if(data < temp->data ){
            if(temp->left == nullptr){
                temp->left = newNode; return;
            }
        temp= temp->left;
        }
    else {
        if(temp->right == nullptr){
            temp->right = newNode; return; }
        temp = temp->right;
        }

    }
}
void inorder(node* root){
    if(root == nullptr){
       return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    int n;
    cin>>n;
    node* root = nullptr;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        insBst(root,a);
    }
    inorder(root);
}







//struct pq{
//    string n;
//    int pri;
//};
//
//compare(pq a, pq b){
//        return a.pri > b.pri;
//}
//
//int main(){
//    int n;
//    cin>>n;
//    pq arr[n];
//    for(int i=0; i<n; i++)
//        cin>> arr[i].n>>arr[i].pri;
//    for(int i=0; i<n; i++){
//        for(int j=0; j<n; j++){
//            if(arr[i].pri < arr[j].pri){
//                swap(arr[i] , arr[j]);
//            }
//        }
//    }
//    sort(arr, arr+n, compare);
//    for(int i=0; i<n; i++){
//        cout<<arr[i].n <<" "<<arr[i].pri<<endl;
//    }
//
//}
