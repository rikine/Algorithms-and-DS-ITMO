#include <fstream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
 
vector<int> find(vector<vector<int>> &a) {
    vector<int> d(a.size(), -1);
    d[0] = 0;
    //stack<int> q1;
    queue<int> q;
    q.push(0);
    int temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        for (int i = 0; i < a[temp].size(); i++)
            if (d[a[temp][i]] == -1) {
                d[a[temp][i]] = d[temp] + 1;
                q.push(a[temp][i]);
            }
    }
    return d;
}
 
int main() {
    ifstream cin("pathbge1.in");
    int n, m, x, y;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        a[x - 1].push_back(y - 1);
        a[y - 1].push_back(x - 1);
    }
 
    vector<int> d = find(a);
    ofstream cout("pathbge1.out");
    for (int i = 0; i < d.size(); i++)
        cout << d[i] << " ";
    cin.close();
    cout.close();
    return 0;
}
