#include <fstream>
#include <vector>
#include <stack>
using namespace  std;
 
bool dfs(int v, vector<int> &used, vector<vector<int>> &a, stack<int> &sorted) {
    used[v] = 1;
    for (int i = 0; i < a[v].size(); ++i) {
        int v1 = a[v][i];
        if (used[v1] == 0) {
            if (dfs(v1, used, a, sorted))
                return true;
        }
        else if (used[v1] == 1)
            return true;
 
    }
    used[v] = 2;
    sorted.push(v);
    return false;
}
 
bool top_sort(vector<vector<int>> &a, stack<int> &sorted) {
    vector<int> used(a.size(), 0);
    for (int i = 0; i < a.size(); ++i)
        if (!used[i])
            if (dfs(i, used, a, sorted))
                return true;
    return false;
}
 
int main() {
    ifstream cin("topsort.in");
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
 
    int x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        graph[x - 1].push_back(y - 1);
    }
 
    ofstream cout("topsort.out");
    stack<int> sorted;
    if (top_sort(graph, sorted)) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cout << sorted.top() + 1 << " ";
        sorted.pop();
    }
    return 0;
}
