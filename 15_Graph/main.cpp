#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


void DFS(map<int,vector<int>> adjl, int start){
    static vector<int> visited(adjl.size(),0);

    visited[start] = 1;
    cout << start << ' ';
    for(int i=0;i<adjl[start].size();i++){
        if(!visited[adjl[start][i]]) DFS(adjl,adjl[start][i]);
    }
}


void BFS(map<int,vector<int>> adjl, int start){
    static vector<int> visited(adjl.size(),0);
    queue<int> q;

    q.push(start);

    while(!q.empty()){
        for(int i=0;i<q.size();i++){
            if(!visited[q.front()]){
                cout << q.front() << ' ';
                visited[q.front()] = 1;
                
                for(int j=0;j<adjl[q.front()].size();j++){
                    q.push(adjl[q.front()][j]);
                }
            }
            q.pop();
        }
    }

}


int main(){
    int edges, nodes, x, y;
    cin >> edges >> nodes;
    vector<vector<int>> adjm(nodes+1,vector<int>(nodes+1,0));
    map<int,vector<int>> adjl;

    //adjacency matrix
    // for(int i=0;i<edges;i++){
    //     cin >> x >> y;
    //     adjm[x][y] = 1;
    //     adjm[y][x] = 1;
    // }
    // for(int i=0;i<nodes;i++){
    //     for(int j=0;j<nodes;j++){
    //         cout << adjm[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }


    //adjacency list
    for(int i=0;i<edges;i++){
        cin >> x >> y;
        if(x!=y)adjl[x].push_back(y);
        adjl[y].push_back(x);
    }

    for(auto i:adjl){
        cout << i.first << "->";
        for(int j=0;j<i.second.size();j++){
            cout << i.second[j] << ',';
        }
        cout << '\n';
    }

    BFS(adjl,0);
    cout << '\n';
    DFS(adjl,0);

    return 0;
}