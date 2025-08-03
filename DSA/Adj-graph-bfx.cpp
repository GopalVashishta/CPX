#include<iostream>
#include<queue>
#include<stack>
#define mx 7
#define INF INT_MAX
#define v 4
using namespace std;
/*
void WarshallAlgo(int graph[v][v]){//for adjacency(existence of path)
    for(int k=0; k<v; k++){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
    //print
    cout<<"Transitive Closure Matrix:"<<endl;
    for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                    cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
}
//both are different algos
void floydWarsall(int graph[v][v]){//for weights(shortest path)
    for(int k=0; k<v; k++){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(graph[i][j] > graph[i][k] + graph[k][j]  && graph[i][k] != INF && graph[k][j]!= INF )
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
    //print
    for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                    cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
}
int main(){
    int graph[v][v] = {
            {0,1,0,0},
            {0,0,0,1},
            {0,0,0,0},
            {1,0,1,0}
            };
    WarshallAlgo(graph);
    return 0;
}
*/
void bfs(int arr[][mx],int start){
    queue<int> q;
    bool visited[mx]={false};//keep track of what node have been visited

    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int i=0; i<mx; i++){
            if(arr[node][i] == 1 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }

    }
}

void dfs(int arr[][mx],int start){
    stack<int> s;
    bool visited[mx]={false};//keep track of what node have been visited

    visited[start] = true;
    s.push(start);

    while(!s.empty()){
        int node = s.top();
        s.pop();
        cout<<node<<" ";
        for(int i=0; i<mx; i++){
            if(arr[node][i] == 1 && !visited[i]){
                visited[i] = true;
                s.push(i);
            }
        }

    }
}
void adj(int arr[][mx],int u, int v){
    arr[u][v]=1;
    arr[v][u]=1;//remove if directed graph
}

int main(){
    int arr[mx][mx] = {0};
    adj(arr,0,1);
    adj(arr,0,2);
    adj(arr,1,3);
    adj(arr,1,4);
    adj(arr,4,5);
    adj(arr,4,6);
    dfs(arr,0);
    return 0;
}
