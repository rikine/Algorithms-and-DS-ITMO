#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <iomanip> 
using namespace std;
  
float dist(int x0, int y0, int x1, int y1) {
    return sqrt((x0 - x1)*(x0 - x1) + (y0 - y1)*(y0 - y1));
}
  
int main() {
    ifstream cin("spantree.in");
    ofstream cout("spantree.out");
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    vector<vector<float>> e(n, vector<float>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j)
                e[i][j] = dist(v[i].first, v[i].second, v[j].first, v[j].second);
            else
                e[i][j] = 1e6;
        }
    }
  
    v.clear();
    const float INF = 1e6;
    vector <float> dist(n, INF);
    dist[0] = 0;
    vector <bool> used(n, false);
    float ans = 0;
    for (int i = 0; i < n; ++i)
    {
        float min_dist = INF;
    float u = 0;
        for (int j = 0; j < n; ++j)
            if (!used[j] && dist[j] < min_dist)
            {
                min_dist = dist[j];
                u = j;
            }
        ans += min_dist;
        used[u] = true;
        for (int v = 0; v < n; ++v)
            dist[v] = min(dist[v], e[u][v]);
    }
    cout << setprecision(10) << ans;
    return 0;
}
