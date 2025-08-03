#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<algorithm>
using namespace std;

void bubble_sort(int arr[],int  n){
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    int hold = arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=hold;
                    }
            }
    }

}
void bs(vector<int> arr, int a){
    int l =0, r = arr.size()-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(arr[mid] == a){ cout<<mid; return;}
        else if(arr[mid] > a) r = mid-1;
        else l = mid+1;
    }
}
/////////////////////////////////////////////////
void insertion_sort(int arr[],int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j=i-1;

        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}
////////////////////////////////////////////////////
void selection_sort(int arr[],int n){

    for(int i=0; i<n-1; i++){
            int minIx=i;

        for(int j=i+1; j<n; j++){

            if(arr[minIx]>arr[j])
                minIx=j;
        }

        int temp= arr[i];
        arr[i]= arr[minIx];
        arr[minIx]=temp;
    }
}

//head sort
void heapify(int arr[],int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && arr[left]>arr[largest])
        largest = left;
    if(right<n && arr[right]>arr[largest])
        largest = right;
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void bh(int arr[],int n){
    for(int i=n/2-1; i>=0; i--)
        heapify(arr,n,i);
}
void heapsort(int arr[],int n){
    bh(arr,n);
    for(int i=n-1; i>0; i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}
void delh(int arr[],int n){
    if(n==0){  cout<<"it is emtpy"<<endl; return;}
    arr[0] = arr[n-1];
    heapify(arr,n,0)
}
//heap end

//merge sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
    k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
         }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
         }
}
void mergeSort(vector<int>& arr, int left, int right) {
     if (left >= right)
        return;
     int mid = left + (right - left) / 2;
     mergeSort(arr, left, mid);
      mergeSort(arr, mid + 1, right);
       merge(arr, left, mid, right);
}
// end merge



// Quick-sort
int partition(vector<int>& arr, int low, int high) {

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {

    if (low < high) {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
// end quick sort




void printVector(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " "; cout << endl;
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    //selection_sort(arr, n);
    heapsort(arr,n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}


/*
int main(){

    int arr[8] = {1,2,3,4,5,7,8,9};
    int n=8 , key;
    cin>>key;
    int mid,anc=0,lw=0,hg=n;
    while(lw<=hg){
        mid = (lw+hg)/2;
        if(arr[mid]==key){
               anc++; break;}
        else if(key<arr[mid]){
            hg = mid-1;
        }
        else if(key>arr[mid]){
            lw = mid+1;
        }
    }

   (anc==1)? cout<<"The index is: "<<mid : cout<<"Not found";

    int n;
    cin>>n;
    cout<<"Enter elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int n= sizeof(arr)/sizeof(arr[0]);
    int ix,val;
    cout<<"Enter the index and value for del:";
    cin>>val;
    for(int i=n;i>=ix;i--){
        arr[i+1] = arr[i];
    }
    arr[ix]=val;

    for(int i=0;i<=n;i++){
        if (arr[i]== val) {ix = i ; break;}
        else ix=-124;
    }
    for(int i=ix;i<=n;i++){
        arr[i] = arr[i+1];
    }
    n--;
    for(int i=0;i<n;i++){
        if(ix<0) break;
        cout<<arr[i]<<" ";
    }












/*
    int main(){
    string x,h;
    int x=0;
    cin>>x;
    cin.ignore();
    getline(cin,h);
    cout<<h<<endl<<x;
    int n = 0;
    for(int i=0;i< h.length()/2;i++){

    }
    (n == x.length()-1) ? cout<<"Found": cout<<"Not found";
    (x==h.length()/2) ? cout<<"It is palindrome" : cout<<"Not a palindrome";
}
*/
