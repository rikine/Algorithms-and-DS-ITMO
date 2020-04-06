#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    ifstream cin("pathsg.in");
    ofstream cout("pathsg.out");
    int n, m;
    cin >> n >> m;
 
    int a, b, w;
    vector<vector<long long>> graph(n, vector<long long>(m, 1e8));
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        graph[a - 1][b - 1] = w;
    }
 
    for (int i = 0; i < n; i++)
        graph[i][i] = 0;
 
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
    return 0;
}
