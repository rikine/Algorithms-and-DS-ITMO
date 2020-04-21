#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
using namespace std;
 
struct edge {
    int from, to, number;
    long long flow, c;
 
    edge(int from, int to, int number, int c) :from(from), to(to), number(number), c(c), flow(0) {}
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
 
long long  dfs(int v, long long flow, vector<int>& ptr, vector<edge>& edges, int t, vector<vector<int>>& graph, vector<int>& dist) {
    if (!flow || v == t)
        return flow;
 
    for (; ptr[v] < graph[v].size(); ++ptr[v]) {
        int id = graph[v][ptr[v]], to = edges[id].to;
        if (dist[to] != dist[v] + 1)
            continue;
        long long pushed = dfs(to, min(flow, edges[id].c - edges[id].flow), ptr, edges, t, graph, dist);
        if (pushed) {
            edges[id].flow += pushed;
            edges[id ^ 1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}
 
void decomposition(int s, vector<vector<int>>& graph, int t, vector<pair<long long, deque<int>>>& decomp, vector<edge>& edges) {
    long long decomp_flow = 0;
    deque<int> decompos;
 
    while (true) {
        decomp_flow = 0;
        int v = s;
        vector<bool> used(graph.size());
        while (!used[v]) {
            if (v == t) {
                break;
            }
 
            int edge_n = -1;
            for (auto g : graph[v]) {
                if (edges[g].flow > 0) {
                    edge_n = g;
                    break;
                }
            }
            if (edge_n == -1) {
                decompos.clear();
                break;
            }
            decompos.push_back(edge_n);
            used[v] = true;
            v = edges[edge_n].to;
        }
        if (used[v]) {//found cycle
            while (edges[decompos.front()].from != v) {
                decompos.pop_front();
            }
        }
        if (decompos.empty()) {
            break;
        }
        decomp_flow = 9e11;
        for (auto x : decompos) {
            if (edges[x].flow < decomp_flow) {
                decomp_flow = edges[x].flow;
            }
        }
        for (auto x : decompos) {
            edges[x].flow -= decomp_flow;
        }
        if (decomp_flow != 9e11) {
            decomp.push_back({ decomp_flow,decompos });
            decompos.clear();
        }
    }
}
 
int main() {
    ifstream cin("decomposition.in");
    ofstream cout("decomposition.out");
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> graph(n);
    vector<int> ptr(n);
    vector<int> dist(n);
    vector<edge> edges;
    edges.reserve(m * 2);
    int from, to, c;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> c;
        graph[from - 1].push_back(edges.size());
        edges.push_back(edge( from - 1, to - 1, i + 1, c));
         
        graph[to - 1].push_back(edges.size());
        edges.push_back(edge( to - 1, from - 1, i + 1, 0));
    }
 
    while(1) {
        if (!bfs(graph, edges, dist)) break;
        ptr.assign(n, 0);
        while (dfs(0, 9e11, ptr, edges, n - 1, graph, dist)) {}
    }
 
    vector<pair<long long, deque<int>>> decompositions;
    decomposition(0, graph, n - 1, decompositions, edges);
 
    cout << decompositions.size() << endl;
    for (auto x : decompositions) {
        cout << x.first << " ";
        cout << x.second.size() << " ";
        for (auto y : x.second) {
            cout << edges[y].number << " ";
        }
        cout << endl;
    }
    return 0;
}
