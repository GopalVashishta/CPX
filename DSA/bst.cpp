#include<iostream>
using namespace std;

struct node{
    node* left;
    int data;
    node* right;
    node(int x) : data(x) ,left(nullptr), right(nullptr){};
};


node* findMin(node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

node* deletenode(node* root, int value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root->data) {
        root->left = deletenode(root->left, value);
    } else if (value > root->data) {
        root->right = deletenode(root->right, value);
    } else {
        // Case 1: node with no child (Leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: node with only one child
        else if (root->left == nullptr) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: node with two children
        else {
            node* temp = findMin(root->right);

            root->data = temp->data;

            root->right = deletenode(root->right, temp->data);
        }
    }
    return root;
}

void insert_in_bst(node*& root, int value) {
    node* newnode = new node(value);
    if (root == nullptr) {
        root = newnode;
        return;
    }
    node* temp = root;
    while (temp != nullptr) {
        if (value < temp->data) {
            if (temp->left == nullptr) {
                temp->left = newnode;
                return;
            }
            temp = temp->left;
        } else {
            if (temp->right == nullptr) {
                temp->right = newnode;
                return;
            }
            temp = temp->right;
        }
    }
}




void inorder(node* root){

    if(root== nullptr){
        return;
    }

    inorder(root->left);
    cout<< root->data<< " ";
    inorder(root->right);
}

void preorder(node* root){
    if(root== nullptr){
        return;
    }
    cout<< root->data<< " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root== nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<< root->data<< " ";
}


int main(){
     node* root = nullptr;
    int n;
    cout << "Enter number of elements to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int element;
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;
        insert_in_bst(root, element);
    }

    cout << "In-order traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
