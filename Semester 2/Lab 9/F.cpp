#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
void dfs(int v, vector<vector<int>> &graph, vector<int> &result) {
    for (int i = 0; i < graph[v].size(); i++) {
        int v1 = graph[v][i];
        if (result[v1] == -1) {
            dfs(v1, graph, result);
        }
    }
    for (int i = 0; i < graph[v].size(); i++) {
        result[v] = max(result[v], (result[graph[v][i]] + 1) % 2);
    }
    if (result[v] == -1) 
        result[v] = 0;
}
 
int main() {
    ifstream cin("game.in");
    ofstream cout("game.out");
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    vector <vector<int>> graph(n);
    vector<int> result(n, -1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }
    dfs(s, graph, result);
    if (result[s]) {
        cout << "First player wins";
    }
    else {
        cout << "Second player wins";
    }
    return 0;
}
