#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
 
typedef vector<pair<long long, pair<int, int>>> vpp;
typedef vector<vector<int>> vv;
 
const long long INF = 9e18;
 
void dfs(int v, vv &graph, vector<char> &used) {
    used[v] = true;
    for (auto v1 : graph[v]) {
        if (!used[v1])
            dfs(v1, graph, used);
    }
}
 
int relax(int u, int v, long long w, vector<long long> &dist, vector<int> &p) {
    if (dist[v] > dist[u] + w) {
        dist[v] = max(-INF, dist[u] + w);
        p[v] = u;
        return v;
    }
    return -1;
}
 
vector<long long> ford(int s, vpp &graphedges, int n, vv &graph) {
    vector<long long> dist(n, INF);
    vector<int> p(n, -1);
    dist[s] = 0;
    int lastv = -1;
    for (int i = 0; i < n; i++) {
        lastv = -1;
        for (auto edge : graphedges) {
            if(dist[edge.second.first] < INF)
                lastv = max(lastv, relax(edge.second.first, edge.second.second, edge.first, dist, p));
        }
    }
 
    if (lastv != -1) {
        for (int i = 0; i < n; i++)
            lastv = p[lastv];
 
        vector<char> used(n);
        dfs(lastv, graph, used);
 
        for (int i = 0; i < n; i++)
            if (used[i])
                dist[i] = -INF;
    }
    return dist;
}
 
int main() {
    ifstream cin("path.in");
    ofstream cout("path.out");
 
    int n, m, s;
    cin >> n >> m >> s;
 
    int x, y;
    long long w;
    vpp graphedges;
    vv graph(n);
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        graph[x - 1].push_back(y - 1);
        graphedges.push_back(make_pair(w, make_pair(x - 1, y - 1)));
    }
 
    vector<long long> dist = ford(s - 1, graphedges, n, graph);
 
    for (auto res : dist) {
        switch (res){
        case -INF: {
            cout << "-";
            break;
        }
        case INF: {
            cout << "*";
            break;
        }
        default:
            cout << res;
            break;
        }
        cout << endl;
    }
    return 0;
}
