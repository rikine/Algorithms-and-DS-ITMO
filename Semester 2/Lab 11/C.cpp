#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;
 
int main() {
    ifstream cin("pathbgep.in");
    ofstream cout("pathbgep.out");
    long long INF = (long long)1e11;
 
    int n, m;
    cin >> n >> m;
 
    int a, b, w;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        graph[a - 1].emplace_back(make_pair(b - 1, w));
        graph[b - 1].emplace_back(make_pair(a - 1, w));
    }
 
    vector<long long> dist(n, INF);
    dist[0] = 0;
 
    set<pair<long long, int>> s;
    s.insert(make_pair(0, 0));
 
    while (!s.empty()) {
        pair<long long, int> v = *s.begin();
        s.erase(s.begin());
 
        for (auto edge : graph[v.second]) {
            if (dist[edge.first] > v.first + edge.second) {
                s.erase(make_pair(dist[edge.first], edge.first));
                dist[edge.first] = v.first + edge.second;
                s.insert(make_pair(dist[edge.first], edge.first));
            }
        }
    }
 
    for (auto w : dist)
        cout << w << " ";
 
    return 0;
}
