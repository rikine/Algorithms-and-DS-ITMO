#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
using namespace std;

void dfs(int v, vector<vector<int>>&graph, vector<int>&used, vector<int>&order, stack <int>&vert, int &k) {
    used[v] = 1;
    for (int i = 0; i < graph[v].size(); i++) {
        int v1 = graph[v][i];
        if (!used[v1]) {
            dfs(v1, graph, used, order, vert, k);
            k++;
            order[v1] = k;
            vert.push(v1);
        }
    }
}

void dfs_comp(int v, vector<vector<int>>&graphInv, vector<int>&comp, int &cur_comp) {
    comp[v] = cur_comp;
    for (int i = 0; i < graphInv[v].size(); i++) {
        int v1 = graphInv[v][i];
        if (!comp[v1]) {
            dfs_comp(v1, graphInv, comp, cur_comp);
        }
    }
}
 
int main()
{
    ifstream cin("cond.in");
    int n, m, x, y;
    cin >> n >> m;
 
    vector<vector<int>> graph(n);
    vector<vector<int>> graphInv(n);
    vector<int> order(n);
    vector <int> used(n);
    stack<int> vert;
    vector <int> comp(n);
 
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x - 1].push_back(y - 1);
        graphInv[y - 1].push_back(x - 1);
    }
 
    int k = 0;
    for (int i = 0; i < graph.size(); i++) {
        if (!used[i]) {
            dfs(i, graph, used, order, vert, k);
            k++;
            order[i] = k;
            vert.push(i);
        }
    }
 
    int cur_comp = 1;
    int cur_vert = 0;
    for (int i = 0; i < graphInv.size(); i++) {
        cur_vert = vert.top();
        vert.pop();
        if (!comp[cur_vert]) {
            dfs_comp(cur_vert, graphInv, comp, cur_comp);
            cur_comp++;
        }
    }
 
    ofstream cout("cond.out");
    cout << cur_comp - 1 << "\n";
    for (int i = 0; i < comp.size(); i++)
        cout << comp[i] << " ";
    return 0;
}
