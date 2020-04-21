#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
 
bool dfs(int v, vector<vector<int>>& graph, vector<int>& mt, vector<int>& used, int comp) {
    if (used[v] == comp)
        return false;
 
    used[v] = comp;
    for (auto to : graph[v]) {
        if (mt[to] == -1 || dfs(mt[to], graph, mt, used, comp)) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}
 
int kunchik(vector<vector<int>> &graph, int n1, int n2) {
    vector<int> mt(n2, -1);
    vector<int> used(n1, -1);
 
    int res = 0;
    for (int comp = 0; comp < n1; comp++) {
        if (dfs(comp, graph, mt, used, comp))
            res++;
    }
    return res;
}
 
int main() {
    ifstream cin("matching.in");
    ofstream cout("matching.out");
    int n1, n2, k;
    cin >> n1 >> n2 >> k;
 
    int x, y;
    vector<vector<int>> graph(n1);
    for(int i = 0; i < k; i++) {
        cin >> x >> y;
        graph[x - 1].push_back(y - 1);
    }
     
    cout << kunchik(graph, n1, n2);
    return 0;
}
