#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
 
void dfs(int v, vector<vector<int>> &graph, vector<char> &used, vector<int> &ans) {
    used[v] = true;
    for (int i = 0; i < graph[v].size(); i++) {
        int v1 = graph[v][i];
        if (!used[v1]) {
            dfs(v1, graph, used, ans);
        }
    }
    ans.push_back(v);
}
 
bool check(vector<vector<int>> &graph, vector<int> &ans) {
    for (int i = ans.size() - 1; i > 0; i--) {
        bool f = true;
        int v = ans[i];
        for (int j = 0; j < graph[v].size(); j++) {
            if (graph[v][j] == ans[i - 1]) {
                f = false;
            }
        }
        if (f) {
            return false;
        }
    }
    return true;
}
 
int main() {
    ifstream cin("hamiltonian.in");
    ofstream cout("hamiltonian.out");
    int n, m;
    cin >> n >> m;
    vector<char> used(n);
    vector<vector<int>> graph(n);
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i])
            dfs(i, graph, used, ans);
    }
    if (check(graph, ans)) 
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
