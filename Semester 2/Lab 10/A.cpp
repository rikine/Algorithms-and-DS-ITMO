#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
 
int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n, m;
    cin >> n >> m;
    int x, y;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[--x].push_back(--y);
        graph[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
        cout << graph[i].size() << " ";
    return 0;
}
