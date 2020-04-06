#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
 
int main() {
    ifstream cin("pathmgep.in");
    ofstream cout("pathmgep.out");
    long long INF = (long long)1e11 + 100;
    int n, s, f;
    cin >> n >> s >> f;
    int w;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w;
            if (i != j && w != -1)
                graph[i].push_back(make_pair(w, j));
        }
    }
 
    vector<long long> dist(n, INF);
    dist[s - 1] = 0;
    vector<char> used(n);
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        if (dist[v] == INF)
            break;
        used[v] = true;
 
        for (int j = 0; j < graph[v].size(); j++) {
            int to = graph[v][j].second; long long len = graph[v][j].first;
            if (dist[to] > dist[v] + len)
                dist[to] = dist[v] + len;
        }
    }
 
    if (dist[f - 1] == INF)
        cout << -1;
    else
        cout << dist[f - 1];
    return 0;
}
