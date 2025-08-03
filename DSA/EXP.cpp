#include<iostream>
#include<algorithm>
using namespace std;

void heapify(int arr[], int n , int i){
    int small = i;
    int l = 2*i+1, r = 2*i+2;
    if(l<n && arr[l]< arr[small])  small = l;
    if(r<n && arr[r]< arr[small])  small = r;
    if(small != i){
        int temp = arr[small]; arr[small] = arr[i]; arr[i] = temp;
        heapify(arr,n,small);
    }
}
void buildh(int arr[], int n){
    for(int i=n/2-1; i>=0; i--) heapify(arr,n,i);
}
void heapsort(int arr[], int n){
    buildh(arr,n);
    for(int i = n-1; i>=0 ; i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

void bubble(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]> arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j]; arr[j] = temp;
            }
        }
    }
}
void inss(int arr[], int n){
    for(int i=1; i<n; i++){
        int key = arr[i], j=i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j]; j--;
        }
        arr[j+1] = key;
    }
}
void sels(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int mix = i;
        for(int j=i+1; j<n; j++){
            if(arr[mix] > arr[j]) mix = j;
        }
        int temp = arr[mix];
        arr[mix] = arr[i]; arr[i] = temp;
    }
}
void b_s(int arr[],int n, int key){
    int l=0,r=n-1;
    while(l<r){
        int mid = l + (r-l)/2;
        if(arr[mid] == key ) {cout<<mid; break;}
        else if(key > arr[mid]) l = mid+1;
        else if(key < arr[mid]) r = mid-1;
    }
}
void insix(int arr[], int &n, int val,int ix){
    for(int i=n; i>=ix; i--){
        arr[i] = arr[i-1];
    }
    arr[ix] = val;
    n++;
}

void del(int arr[], int &n , int val){
    int ix=-1;
    for(int i=0; i<n; i++){
        if(arr[i] == val) {
            ix = i; break;
        }
    }
    if(ix==-1){ cout<<"Value not found!"<<endl; return;}
    for(int i=ix; i<n; i++){
        arr[i] = arr[i+1];
    } n--;
}
int main(){
    int arr[10] = {6,3,1,1,113,14,2,3,5,90};
    //bubble(arr,10);
    for(int i=0; i<10; i++) cout<<arr[i]<<' '; cout<<endl;
    //sels(arr,10);//inss(arr,10);
    heapsort(arr,10);
    for(int i=0; i<10; i++) cout<<arr[i]<<' '; cout<<endl;
    /*
    int arr[10] ={1,2,3,4,5} , n=5;
    int key ; cin>>key;
    insix(arr,n,key,0);
    for(int i=0; i<n; i++) cout<<arr[i]<<' '; cout<<endl;
    del(arr,n,key);
    for(int i=0; i<n; i++) cout<<arr[i]<<' ';
    b_s(arr,n,3);
    */
}
