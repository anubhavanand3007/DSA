#include<bits/stdc++.h>
using namespace std;

class graph{
    int nodes, edges;
    vector<vector<int>> adjl;
    vector<vector<int>> adjm;
    vector<bool> visited;
    int initial_node;

    public:
    graph(){
        //visited array
        vector<bool> visited(nodes+1,0);
        this->visited = visited;


        //inintial_node
        int a;
        for(int i=0;i<adjl.size();i++){
            bool found =0;
            for (int j=0;j<adjl[i].size();j++){
                a = i;
                break;
                found =1;
            }
            if(found)break;
        }
        this->initial_node = a;
    }

    void build_adjl(){
        cin >> nodes >> edges;
        vector<vector<int>> adjl(nodes+1);

        for(int i=0;i<edges;i++){
            int x, y;
            cin >> x >> y;
            adjl[x].push_back(y);
            if(x!=y) adjl[y].push_back(x);
        }
        
        this->adjl = adjl;
    }
    void build_adjm(){
        cin >> nodes >> edges;
        vector<vector<int>> adjm(nodes+1,vector<int>(nodes+1,0));
        for(int i=0;i<edges;i++){
            int x,y;
            cin >> x >> y;
            adjm[x][y] = 1;
            adjm[y][x] = 1;
        }

        this->adjm = adjm;
    }

    void display_adjm(){
        for(int i=0;i<nodes;i++){
            for(int j=0;j<nodes;j++){
                cout << adjm[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    void adjl_to_adjm(){
        vector<vector<int>> adjm(nodes+1,vector<int>(nodes+1,0));
        for(int i=0;i<adjl.size();i++){
            for(int j=0;j<adjl[i].size();j++){
                adjm[i][j] = 1;
                adjm[j][i] = 1;
            }
        }
        this->adjm = adjm;
    }

    void display_adjl(){
        for(int i=0;i<adjl.size();i++){
            if(adjl[i].size()){
                cout << i << "->";
                for(int j=0;j<adjl[i].size();j++){
                    cout << adjl[i][j] << ',';
                }
                cout << "\n";
            }
        }
    }

    void DFS(int root=0){
        if(!adjl[root].size())root=this->initial_node;
        visited[root] = 1;
        cout << root << ' ';

        for(int i=0;i<adjl[root].size();i++){
            if(!visited[adjl[root][i]]){
                DFS(adjl[root][i]);
            }
        }
    }

    void BFS(int root=0){
        if(!adjl[root].size())root=this->initial_node;
        cout << root << " ";
        visited[root] = 1;
        queue<int> q;
        q.push(root);
        while(!q.empty()){
            for(int i=0;i<q.size();i++){
                int curr_arr = q.front();
                for(int j=0;j<adjl[curr_arr].size();j++){
                    int curr_val = adjl[curr_arr][j];
                    if(!visited[curr_val]){
                        cout << curr_val << " ";
                        visited[curr_val] = 1;
                        q.push(curr_val);
                    }
                }
                q.pop();
            }
        }
        
    }
};

int solve(){
    graph a1;
    a1.build_adjl();
    // a1.display_adjl();
    // a1.adjl_to_adjm();
    // a1.build_adjm();
    // a1.display_adjm();
    // a1.DFS();
    a1.BFS();

    return 0;
}

int main(){

    solve();
    return 0;
}