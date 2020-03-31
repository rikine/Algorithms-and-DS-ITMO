#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <iomanip> 
using namespace std;
 
struct Edges {
    int v1;
    int v2;
    int w;
};
 
int find(int v, vector<int>&p) {
    while (v != p[v])
        v = p[v];
    return v;
}
 
bool check(int v, int v1, vector<int>&p) {
    return find(v, p) == find(v1, p);
}
 
void unite(int v, int v1, vector<int>&p, vector<int>&s) {
    v = find(v, p);
    v1 = find(v1, p);
 
    if (s[v] > s[v1])
        swap(v, v1);
 
    s[v1] += s[v];
    p[v] = v1;
}
 
int main() {
    ifstream cin("spantree3.in");
    ofstream cout("spantree3.out");
    int n, m;
    cin >> n >> m;
    vector<Edges> e;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        e.emplace_back(Edges{ --a, --b, w});
        e.emplace_back(Edges{ b, a, w });
    }
    sort(e.begin(), e.end(), [](const Edges &left, const Edges &right) {
        return left.w < right.w;
    });
 
    vector<int> p(n);
    vector<int>s(n, 1);
    for (int i = 0; i < n; ++i)
        p[i] = i;
 
    long long ans = 0;
    for (auto edge : e) {
        if (!check(edge.v1, edge.v2, p)) {
            unite(edge.v1, edge.v2, p, s);
            ans += edge.w;
        }
    }
    cout << ans;
    return 0;
}
