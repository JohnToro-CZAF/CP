class Solution {
public:
    vector<int> temp;
    vector<int> adj;
    map<int, int> in_degree;
    // Note: if there is a cycle, the size of the return will be less than n.
    int topological_sort( vector<int>& only) {
        vector<int> order;
        for (int i : only){
            int neighbor = adj[i];
            if(neighbor == -1) continue;
            in_degree[neighbor]++;
        }
        for (int i : only)
            if (in_degree[i] == 0)
                order.push_back(i);

        int current = 0;

        while (current < int(order.size())) {
            int node = order[current++];

            int neighbor = adj[node];
            if(neighbor == -1) continue;
            if (--in_degree[neighbor] == 0)
                order.push_back(neighbor);
        }

        return int(order.size());
    }
    void dfs(int s, vector<int>& visited){
        temp.push_back(s);
        int neighbor = adj[s];
        if(neighbor != -1 && visited[neighbor] == false){
            visited[neighbor] = true;
            dfs(neighbor, visited);
        }
    }
    int longestCycle(vector<int>& edges) {
        adj = edges;
        int ans = 0;
        int n = edges.size();
        vector<int> visited(n, false);
        for(int a = 0; a < n; a++){
            if(!visited[a]){
                in_degree.clear();
                temp.clear();
                visited[a] = true;
                dfs(a, visited);
                int locl = topological_sort(temp);
                ans = max(int(temp.size()) - locl, ans);
            }
        } 
        if(ans == 0){
            return -1;
        } else {
            return ans;
        }
    }
};