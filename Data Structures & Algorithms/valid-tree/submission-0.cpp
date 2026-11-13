class Solution {
public:
    void addedge (vector<vector<int>> &adj, int v, int u){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool dfsRec (int s, int parent, vector<vector<int>> &adj, vector<int> &visited ){
        visited[s]=true;

        for(int v: adj[s]){
            if (visited[v]==false){
                if (dfsRec(v, s, adj, visited)==true)   
                    return true;   

            }else if (parent!=v){
                return true;
            }
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)
            return false;

        vector<vector<int>> adj(n);
        vector<int> visited(n, false);

        for (int i=0; i<edges.size(); i++)
            addedge(adj, edges[i][0], edges[i][1]);

        for (int i=0; i<edges.size(); i++){
            if(visited[i]==false){
                if(dfsRec(i, -1 , adj, visited)==true)
                    return false;
            }
        }
        return true;
    }
};
