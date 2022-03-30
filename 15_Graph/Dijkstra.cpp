#include<bits/stdc++.h>
using namespace std;
  
vector<int> Dijkstra(map<char,vector<pair<char,int>>> adjl, char start, int nodes){
    vector<int> dist_arr(nodes, INT_MAX);
    dist_arr[start] = 0;
    set<pair<int,char>> mpn;
    mpn.insert({0,start});
    while(!mpn.empty()){
        auto node = *(mpn.begin());
        for(auto ned: adjl[node.second]){
            dist_arr[ned.first] = min(dist_arr[ned.first],node.first+ned.second); 
            mpn.insert({dist_arr[ned.first],ned.first}) ;
        }
        mpn.erase(node);

    }

    for(auto a:dist_arr){
        if(a!=INT_MAX) cout << a << " ";
    }
}


int main(){
    int nodes, edges;
    cin >> nodes >> edges;

    map<char,vector<pair<char,int>>> adjl;
    
    for(int i=0;i<edges;i++){
        char x, y;
        int  w;
        cin >> x >> y >> w;
        adjl[x].push_back({y,w});
    }

    Dijkstra(adjl, 'A', nodes);
    return 0;
} 