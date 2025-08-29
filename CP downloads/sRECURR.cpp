#include<iostream>
using namespace std;
//ALWAYS TRY TO MAKE A RECURSION TREE IF U CAN'T UNDERSTAND THE PROBLEM 

//all Combination print
void pr(vector<int> arr){
    if(arr.empty()){ cout<<"{}"<<endl; return; }
    for(auto it: arr) cout<<it<<" ";
    cout<<endl;
}
void prComb(int ix, vector<int> arr, vector<int> & ds){
    if(ix == arr.size()){
        pr(ds);
        return;
    }
    ds.push_back(arr[ix]);
    prComb(ix+1, arr, ds);
    ds.pop_back();
    prComb(ix+1, arr, ds);
}
/*
int main(){
    vector<int> arr = {1,2,3};
    vector<int> ds;
    prComb(0,arr, ds);
}
*/

//backTracking (knapsack type tree) SUBSEQUENCES pow(2,n)
void recTree(int ind, vector<int> ds, int arr[], int n){
    if(ind>=n){
        for(auto i: ds) cout<<i<" ";

        if(ds.size() == 0) cout<<"{}"<<endl;
        
        cout<<endl;
        return;
    }
    ds.push_back(arr[ind]); //selected
    recTree(ind+1,ds,arr,n);//next node of tree if selected
    //backtracked then
    ds.pop_back()//for not selected
    recTree(ind+1,ds,arr,n);//next node of tree if not selected
}
//sum 
int sumN(int n){
    if(n ==1) return 1;
    return n+sumN(n-1);
}
void sm(int i , int s){
    if(i<0){
        cout<<s<<endl;; return;
    }
    sm(i-1, s+i);
}
//recursive reverse func.
int arr[] = {1,2,3,4,5};
void sw(int l, int r){
    if(l>=r) return;
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
    sw(++l, --r);
}

//fibonnacii
int fib(int n){
    if(n<=1) return n;
    return fib(n-1)+fib(n-2);
}

int main(){
    cout<<"Enter a no."<<endl;
    int n; cin>>n;
    //cout<<sumN(n)<<endl;
    sm(n,0); cout<<endl;
    //for(int i=0; i<5; i++) cout<<arr[i];
    //cout<<endl;
    sw(0,4);
    for(int i=0; i<5; i++) cout<<arr[i]; cout<<endl;
    cout<<fib(4)<<endl;
}