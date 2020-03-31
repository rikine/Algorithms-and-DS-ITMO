#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
void dfs(int v, vector<vector<int>> &graph, vector<char> &fract, bool &flag) {
    for (int i = 0; i < graph[v].size(); i++) {
        int v1 = graph[v][i];
        if (!fract[v1]) {
            fract[v1] = fract[v] == 1 ? 2 : 1;
            dfs(v1, graph, fract, flag);
        }
        else if (fract[v1] == fract[v]) {
            flag = false;
            return;
        }
    }
}
 
int main()
{
    ifstream cin("bipartite.in");
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> graph(n);
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x - 1].push_back(y - 1);
        graph[y - 1].push_back(x - 1);
    }
 
    bool flag = 1;
    vector<char> fract(n);
    for (int i = 1; i < graph.size(); i++) {
        if (!fract[i]) {
            fract[i] = 1;
            dfs(i, graph, fract, flag);
        }
    }
 
    ofstream cout("bipartite.out");
    if (flag) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}
