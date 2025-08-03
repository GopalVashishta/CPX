#include<iostream>
#define tabsz 10
using namespace std;
void insert(int hst[],int k){
    int index = k%tabsz;
    int si = index;
    while(hst[index]!= -1){
        index  = (index+1) % tabsz;
        if(si == index) {
            cout<<"hashtable is full:"; return ;
        }
    }
    hst[index] = k;
}
bool search(int hst[], int k){
    int index = k%tabsz;
    int si = index;
    while(hst[index]!= -1){
        if(hst[index]==k) return true;
        index  = (index+1) % tabsz;
        if(index == si) break;
    } return false;
}
void display(int hst[]){
    for(int i=0; i<tabsz; i++){
        if(hst[i]==-1) {cout<<i<<"-->"<<"empty"<<endl; continue;}
        cout<<i<<"-->"<<hst[i]<<endl;
    }
}
int main(){
    int  hashtable[tabsz];
    for(int i=0; i<tabsz; i++) hashtable[i] = -1;
    insert(hashtable, 20);
    insert(hashtable, 30);
    insert(hashtable, 25);
    insert(hashtable, 35);
    insert(hashtable, 40);
    display(hashtable);
    int k;
    cin>>k;
    if(search(hashtable,k)) cout<<"element is found"<<endl;
    else cout<<"Element is not found";
    //return (011100100110010101110100011101010111001001101110);

}
