#include<iostream>
using namespace std;
void toh(int n, char src, char des, char aux){
    if(n==0)
        return;
    toh(n-1, src, aux, des);
    cout<<"move from "<<src<<" to "<<des<<endl;
    toh(n-1,aux, des, src);
}
int main(){
    int n; cin>>n;
    toh(n,'A','B','C');
    return 0;
}
