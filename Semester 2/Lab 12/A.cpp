#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
 
struct edge {
    int from;
    int to;
    int c;
    int flow;
 
    edge(int from, int to, int c) :from(from), to(to), c(c), flow(0) {}
};
 
vector<pair<int, int>> bfs(vector<vector<int>>& graph, vector<edge>& edges) {
    queue<int> q;
    vector<pair<int, int>> path(graph.size(), {-1, -1});
    vector<bool> used(graph.size());
    q.push(0);
    used[0] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto e : graph[v]) {
            int to = edges[e].to; int c = edges[e].c; int flow = edges[e].flow;
            if (!used[to] && c > flow) {
                used[to] = true;
                q.push(to);
                path[to].first = v;
                path[to].second = e;
            }
        }
    }
    vector<pair<int, int>> p;
    if (path[graph.size() - 1].first == -1)
        return p;
 
    for (auto v = path[graph.size() - 1]; v.first != -1; v = path[v.first]) {
        p.push_back(v);
    }
    return p;
}
 
int edmond_carp(vector<vector<int>>& graph, vector<edge>& edges) {
    long long ans = 0;
    vector<pair<int, int>> path = bfs(graph, edges);
    while (!path.empty()) {
        long long cf = (int)numeric_limits<int>::max();
        for (auto g : path) {
            cf = cf > edges[g.second].c - edges[g.second].flow ? edges[g.second].c - edges[g.second].flow : cf;
        }
        for (auto& e : path) {
            edges[e.second].flow += cf;
            edges[e.second ^ 1].flow = -edges[e.second].flow;
        }
        ans += cf;
        path = bfs(graph, edges);
    }
    return ans;
}
 
int main() {
    ifstream cin("maxflow.in");
    ofstream cout("maxflow.out");
    int n, m;
    cin >> n >> m;
    int x, y, c;
    vector<vector<int>> graph(n);
    vector<edge> edges;
    edges.reserve(m);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> c;
        graph[x - 1].push_back(edges.size());
        edges.push_back(edge(x - 1, y - 1, c));
        graph[y - 1].push_back(edges.size());
        edges.push_back(edge(y - 1, x - 1, 0));
 
    }
    cout << edmond_carp(graph, edges);
    return 0;
}
