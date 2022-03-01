#include<iostream>
#include<map>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

void single_source_shortest_path(map<char,vector<pair<char,int>>> adjl, vector<char> &topological_order, char start, int nodes, int edges){
    vector<int> hash_map(nodes,INT_MAX);
    hash_map[start] = 0;
    int i=0;
    for(;i<topological_order.size();i++) if (topological_order[i] == start) break;
    for(;i<topological_order.size();i++){
        for(auto next_member: adjl[topological_order[i]]){
            if (hash_map[next_member.first] > next_member.second+hash_map[topological_order[i]]){
                hash_map[next_member.first] = next_member.second+hash_map[topological_order[i]];
            }
        }
    }

    for(int i='A'; i<='Z'; i++){
        cout << hash_map[i] << ' ';
    }
}

void DFS(map<char,vector<pair<char,int>>> adjl, char start, vector<int> &visited, vector<char> &topological_order){
    for(auto curr:adjl[start]){
        if(!visited[curr.first]){
            DFS(adjl,curr.first,visited,topological_order);
        }
    }

    topological_order.push_back(start);
    visited[start] = 1;
}

vector<char> topological_sort(map<char,vector<pair<char,int>>> adjl, int nodes){
    vector<int> visited(nodes+1,0);
    vector<char> topological_order;
    for(auto initial:adjl){
        if(!visited[initial.first]) DFS(adjl,initial.first, visited, topological_order);
    }

    return topological_order;
}

int main(){
    int nodes, edges;
    map<char,vector<pair<char,int>>> adjl;
    cin >> nodes >> edges;

    char x, y;
    int w;
    for(int i=0;i<edges;i++){
        cin >> x >> y >> w;
        adjl[x].push_back({y,w});
    }
    vector<char> topological_order = topological_sort(adjl, nodes);
    reverse(topological_order.begin(), topological_order.end());
    for(auto i:topological_order){
        cout << i << ' ';
    }
    cout << '\n';


    single_source_shortest_path(adjl, topological_order, 'A', nodes, edges);
    return 0;
}