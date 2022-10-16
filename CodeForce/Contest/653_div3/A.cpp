#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'isSpecial' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts UNWEIGHTED_INTEGER_GRAPH tree as parameter.
 */

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i].
 *
 */
vector<bool> visited;
 
void dfs(int s, vector<vector<int>>& adj, vector<int>& dp){
    visited[s] = true;
    for(int&x : adj[s]){
        if(!visited[x]){
            dp[x] = max(dp[s] + 1, dp[x]);
            dfs(x, adj, dp);
        }
    }
}

void dfsfinal(int s, vector<vector<int>>& adj, vector<int>& dp, int start, int notgo){
    visited[s] = true;
    for(int&x : adj[s]){
        if(s == start && x == notgo) continue;
        if(!visited[x]){
            dp[x] = max(dp[s] + 1, dp[x]);
            dfsfinal(x, adj, dp, start, notgo);
        }
    }
}

vector<int> isSpecial(int tree_nodes, vector<int> tree_from, vector<int> tree_to) {
    int n = tree_nodes;
    visited = vector<bool>(n, false);
    vector<vector<int>> adj(n, vector<int>());
    for(int i = 0; i < (int) tree_from.size(); i++){
        adj[tree_from[i]-1].push_back(tree_to[i] - 1);
        adj[tree_to[i]-1].push_back(tree_from[i] - 1);
    }
    // find the leaf from 0 
    vector<int> dpfirst(n, 0);
    dfs(0, adj, dpfirst);
    int leaf = max_element(dpfirst.begin(), dpfirst.end()) - dpfirst.begin();
    // reset to find dim
    vector<int> dpdim(n, 0);
    visited = vector<bool>(n, false);
    dfs(leaf, adj, dpdim);
    int dim = *max_element(dpdim.begin(), dpdim.end());
    int target = max_element(dpdim.begin(), dpdim.end()) - dpdim.begin();
    // cout << dim << endl;
    
    // if dim is even then there is a center
    visited = vector<bool>(n, false);
    vector<int> ans(n, 0);
    vector<int> dpcenter(n, 0);
    vector<int> path;
    if(dim % 2 == 0){
        int center = 0;
        // find center by either dfs or bfs on the path from leaf to target 
        vector<int> fromleaf(n, 0);
        vector<int> fromtarget(n, 0);
        dfs(leaf, adj, fromleaf);
        visited = vector<bool>(n, false);
        dfs(target, adj, fromtarget);
        for(int i = 0; i < n; i++){
            if(fromleaf[i] == fromtarget[i] && fromleaf[i] == dim/2){
                center = i;
                break;
            }
        }
        visited = vector<bool>(n, false);
        dfsfinal(center, adj, dpcenter, center, -1);
        int chkdp = *max_element(dpcenter.begin(), dpcenter.end());
        for(int i = 0; i < n ; i++){
            if(dpcenter[i] == chkdp){
                ans[i] = 1;
            }
        }
    } else {
        // there are two centers
        int center1, center2;
        // find center by either dfs or bfs on the path from leaf to target  
        vector<int> fromleaf(n, 0);
        vector<int> fromtarget(n, 0);
        dfs(leaf, adj, fromleaf);
        visited = vector<bool>(n, false);
        dfs(target, adj, fromtarget);
        for(int i = 0; i < n; i++){
            if(fromleaf[i] == (dim+1)/2 && fromtarget[i] == dim/2){
                center1 = i;
            }
            if(fromleaf[i] == (dim)/2 && fromtarget[i] == (dim+1)/2){
                center2 = i;
            }
        }
        visited = vector<bool>(n, false);
        dfsfinal(center1, adj, dpcenter, center1, center2); 
        dfsfinal(center2, adj, dpcenter, center2, center1);
        int chkdp = *max_element(dpcenter.begin(), dpcenter.end());
        for(int i = 0; i < n ; i++){
            if(dpcenter[i] == chkdp){
                ans[i] = 1;
            }
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string tree_nodes_edges_temp;
    getline(cin, tree_nodes_edges_temp);

    vector<string> tree_nodes_edges = split(rtrim(tree_nodes_edges_temp));

    int tree_nodes = stoi(tree_nodes_edges[0]);
    int tree_edges = stoi(tree_nodes_edges[1]);

    vector<int> tree_from(tree_edges);
    vector<int> tree_to(tree_edges);

    for (int i = 0; i < tree_edges; i++) {
        string tree_from_to_temp;
        getline(cin, tree_from_to_temp);

        vector<string> tree_from_to = split(rtrim(tree_from_to_temp));

        int tree_from_temp = stoi(tree_from_to[0]);
        int tree_to_temp = stoi(tree_from_to[1]);

        tree_from[i] = tree_from_temp;
        tree_to[i] = tree_to_temp;
    }

    vector<int> result = isSpecial(tree_nodes, tree_from, tree_to);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
