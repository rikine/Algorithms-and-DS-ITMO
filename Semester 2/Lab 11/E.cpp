#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
 
const long long INF = 1e11 + 9;
typedef vector<pair<long long, pair<int, int>>> vpp;
 
int relax(int u, int v, long long w, vector<long long> &dist, vector<int> &p) {
    if (dist[v] > dist[u] + w) {
        dist[v] = max(-INF, dist[u] + w);
        p[v] = u;
        return v;
    }
    return -1;
}
 
bool check(int u, int v, long long w, vector<long long> &dist) {
    return dist[v] > dist[u] + w;
}
stack<int> ford(vpp &graph, int n) {
    vector<long long> dist(n, INF);
    vector<int> p(n, -1);
    stack<int> path;
    int lastv = -1;
    for (int i = 0; i < n; i++) {
        lastv = -1;
        for (auto edge : graph) {
                lastv = max(lastv, relax(edge.second.first, edge.second.second, edge.first, dist, p));
        }
    }
    if (lastv != -1) {
        int v = lastv;
        for (int i = 0; i < n; i++)
            v = p[v];
 
        for (int u = v; ; u = p[u]) {
            path.push(u);
            if (u == v && path.size() > 1)
                break;
        }
    }
    return path;
}
 
int main() {
    fstream cin("negcycle.in");
    ofstream cout("negcycle.out");
 
    int n;
    cin >> n;
 
    long long w;
    vpp graph;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w;
            if (w != 1e9)
                graph.push_back(make_pair(w, make_pair(i, j)));
        }
    }
    stack<int> path = ford(graph, n);
    int ns = path.size();
    if (ns) {
        cout << "YES" << endl << ns << endl;
        for (int i = 0; i < ns; i++) {
            cout << path.top() + 1 << " ";
            path.pop();
        }
    }
    else
        cout << "NO";
    return 0;
}
