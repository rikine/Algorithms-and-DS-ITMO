#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
struct edge {
    int from, to, minc, c, flow;
 
    edge(int from, int to, int minc, int c) : from(from), to(to), minc(minc), c(c), flow(0) {}
};
 
bool bfs(vector<vector<int>>& graph, vector<edge>& edges, vector<int>& dist) {
    queue<int> q;
    q.push(0);
    dist.assign(graph.size(), -1);
    dist[0] = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int i = 0; i < graph[v].size(); ++i) {
            int id = graph[v][i], to = edges[id].to;
            if (dist[to] == -1 && edges[id].flow < edges[id].c) {
                q.push(to);
                dist[to] = dist[v] + 1;
            }
        }
    }
    return dist[graph.size() - 1] != -1;
 
}
 
int  dfs(int v, int flow, vector<int>& ptr, vector<edge>& edges, int t, vector<vector<int>>& graph, vector<int>& dist) {
    if (!flow || v==t) 
        return flow;
 
    for (; ptr[v] < graph[v].size(); ++ptr[v]) {
        int id = graph[v][ptr[v]], to = edges[id].to;
        if (dist[to] != dist[v] + 1) 
            continue;
        int pushed = dfs(to, min(flow, edges[id].c - edges[id].flow), ptr, edges, t, graph, dist);
        if (pushed) {
            edges[id].flow += pushed;
            edges[id ^ 1].flow -= pushed;
            return pushed;
        }
    }
    return  0;
}
 
 
int main() {
    //ifstream cin("circulation.in");
    //ofstream cout("circulation.out");
    int n, m;
    cin >> n >> m;
    n += 2;
    vector<vector<int>> graph(n);
    vector<int> position(m);
    vector<edge> edges;
    edges.reserve(m * 6);
 
    int from, to, minc, c;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> minc >> c;
        graph[from].push_back(edges.size());
        position[i] = graph[from].back();
 
        edges.push_back(edge(from, to, minc, c - minc));
        graph[to].push_back(edges.size());
        edges.push_back(edge(to, from, 0, 0));
        graph[from].push_back(edges.size());
        edges.push_back(edge(from, n - 1, 0, minc));
        graph[n - 1].push_back(edges.size());
        edges.push_back(edge(n - 1, from, 0, 0));
        graph[0].push_back(edges.size());
        edges.push_back(edge(0, to, 0, minc));
        graph[to].push_back(edges.size());
        edges.push_back(edge(to, 0, 0, 0));
    }
 
    vector<int> ptr(n);
    vector<int> dist(n);
    long long flow = 0;
    while (1) {
        if (!bfs(graph, edges, dist))
            break;
        ptr.assign(n, 0);
        while (int pushed = dfs(0, 9e5, ptr, edges, n - 1, graph, dist)) {
            flow += pushed;
        }
    }
 
    for (auto g : graph[0]) {
        if (edges[g].flow < edges[g].c) {
            cout << "NO" << endl;
            return 0;
        }
    }
 
    cout << "YES" << endl;
    for (auto g : position) {
        if (edges[g].to != n - 1 && edges[g].from != 0) {
            cout << edges[g].flow + edges[g].minc << endl;
        }
    }
    return 0;
}
