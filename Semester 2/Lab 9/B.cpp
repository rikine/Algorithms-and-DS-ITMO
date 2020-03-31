#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
 
bool dfs(int v, const vector<vector<int>> &a, vector<int> &path, vector<char> &used, int &x, int &y) {
    used[v] = 1;
    for (int i = 0; i < a[v].size(); ++i) {
        int v1 = a[v][i];
        if (used[v1] == 0) {
            path[v1] = v;
            if (dfs(v1, a, path, used, x, y))
                return true;
        }
        else if (used[v1] == 1) {
            x = v1;
            y = v;
            return true;
        }
    }
    used[v] = 2;
    return false;
}
 
int main() {
    ifstream cin("cycle.in");
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> graph(n);
    int x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        graph[x - 1].push_back(y - 1);
    }
 
    vector<int> path(n, -1);
    vector<char> used(n);
    x = -1;
    for (int i = 0; i < n; ++i)
        if (dfs(i, graph, path, used, x, y))
            break;
 
    ofstream cout("cycle.out");
    if (x == -1) {
        cout << "NO";
    }
    else {
 
        vector<int> cycle;
        cycle.push_back(x);
        for (int i = y; i != x; i = path[i]) {
            cycle.push_back(i);
        }
        reverse(cycle.begin(), cycle.end());
        cout << "YES" << endl;
        for (int i = 0; i < cycle.size(); i++) {
            cout << cycle[i] + 1 << " ";
        }
    }
    return 0;
}
