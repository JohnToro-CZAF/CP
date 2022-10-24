// Header Files
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;


/*
 * nodeVal is an array representing the value of each node in the tree.
edges is a two-dimensional array representing the the indices of the starting node and ending node of an edge of the tree.
 */

vector<vector<int> > adj;
vector<int> tin, tout;
vector<vector<int> > up;
vector<int> leaf;
int timer;
int n, l;
vector<int> values;
map<int, int> dp;

void dfs(int s, int p){
    tin[s] = ++timer;
    up[s][0] = p;
    for (int i = 1; i <= l; i++){
        up[s][i] = up[up[s][i-1]][i-1];
    }
    for(int v : adj[s]){
        if(v == p) continue;
        dfs(v, s);
    }
    tout[s] = ++timer;
}

void dfs_helper(int s, int p){
    int cnt = 0;
    for(int v : adj[s]){
        if (v == p) continue;
        dp[v] = dp[s] * values[v];
        dfs(v, s);
        cnt++;
    }
    if(cnt > 0){
        return;
    } else {
        leaf.push_back(s);
    }
}

bool is_ancestor(int u, int v){
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v){
    if(is_ancestor(u, v)){
        return u;
    }
    if(is_ancestor(v, u)){
        return v;
    }
    for(int i = l; i >= 0; i--){
        if(!is_ancestor(up[u][v], v)){
            u = up[u][i];
        }
    }
    return up[u][0];
}

int maxScore (vector<int> nodeVal, vector<vector<int> > edges)
{
    int  answer = -1e9;
    // Write your code here
    leaf.clear();
    values = nodeVal;
    dp.clear();
    int n = nodeVal.size();
    l = ceil(log2(n));
    tin.assign(n, 0);
    tout.assign(n, 0);
    up.assign(n, vector<int>(l+1));
    adj = vector<vector<int> >(n, vector<int>());
    for(int i = 0; i < n-1; i++){
        vector<int> e = edges[i];
        e[0]--; e[1]--;
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    cout << "ok" << endl;
    dfs(0, 0);
    dp[0] = nodeVal[0];
    dfs_helper(0, 0);
    cout << "ok" << endl;
    if(leaf.size() == 1){
        answer = dp[leaf[0]];
    }
    for(int i = 0; i < leaf.size(); i++){
        for(int j = i+1; j < leaf.size(); j++){
            int u = leaf[i];
            int v = leaf[j];
            int common = lca(u, v);
            long long temp = (long long)dp[u]*dp[v];
            temp /= (dp[common] * dp[common]);
            temp *= values[common];
            int res = temp;
            answer = max(answer, res);
        }
    }
    return answer;
}

int main()
{
    
    //input for nodeVal
    int nodeVal_size;
    cin >> nodeVal_size;
    vector<int> nodeVal;
    for ( int idx = 0; idx < nodeVal_size; idx++ )
    {
        int temp;
        cin >> temp;
        nodeVal.push_back(temp);
    }
    //input for edges
    int edges_row;
    int edges_col;
    cin >> edges_row;
    cin >> edges_col;
    
    vector<vector<int> > edges;
    for ( int idx = 0; idx < edges_row; idx++ )
    {
        vector<int> temp_vector;
        for ( int jdx = 0; jdx < edges_col; jdx++ )
        {
            int temp;
            cin >> temp;
            temp_vector.push_back(temp);
        }
        edges.push_back(temp_vector);
    }
    
    
    int result = maxScore(nodeVal, edges);
    cout << result;
    
    
    return 0;
}
