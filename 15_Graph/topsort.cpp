#include<iostream>
#include<map>
#include<vector>
using namespace std;

void DFS(map<char,vector<char>> adjl, char start, vector<int> &visited, vector<char> &toporder){
    for(int i=0;i<adjl[start].size();i++){
        if(!visited[adjl[start][i]]){
            DFS(adjl,adjl[start][i],visited,toporder);
        }
    }

    toporder.push_back(start);
    visited[start] = 1;
}

int main(){
    int nodes, edges;
    cin >> nodes >> edges;
    map<char,vector<char>> adjl;


    char x,y;
    for(int i=0;i<edges;i++){
        cin >> x >> y;
        adjl[x].push_back(y);
    }

    for(auto i:adjl){
        cout << i.first << "->";
        for(auto j:i.second){
            cout << j << ",";
        }
        cout << '\n';
    }

    vector<char> toporder;
    vector<int> visited('Z'+1,0);
    for(auto i:adjl){
        if(!visited[i.first]){
            DFS(adjl, i.first, visited, toporder);
        }
    }

    for(auto i:toporder){
        cout << i << " ";
    }
}