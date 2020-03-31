#include <fstream>
#include <vector>
#include <queue>
using namespace std;
 
vector<char> find(vector<vector<char>> &a, pair<int, int> s, pair<int, int> e) {
    vector<vector<vector<char>>> temp(a.size(), vector<vector<char>>(a[0].size()));
    queue<pair<int, int>> q;
    q.push(s);
    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        if (t.first == e.first && t.second == e.second)
            return temp[t.second][t.first];
         
        if (t.second > 0 && a[t.second - 1][t.first] != '#'
        && temp[t.second - 1][t.first].empty()) {
            temp[t.second - 1][t.first] = temp[t.second][t.first];
            temp[t.second - 1][t.first].push_back('U');
            q.push(make_pair(t.first, t.second - 1));
        }
 
        if (t.second < a.size() - 1 && a[t.second + 1][t.first] != '#'
            && temp[t.second + 1][t.first].empty()) {
            temp[t.second + 1][t.first] = temp[t.second][t.first];
            temp[t.second + 1][t.first].push_back('D');
            q.push(make_pair(t.first, t.second + 1));
        }
 
        if (t.first > 0 && a[t.second][t.first - 1] != '#'
            && temp[t.second][t.first - 1].empty()) {
            temp[t.second][t.first - 1] = temp[t.second][t.first];
            temp[t.second][t.first - 1].push_back('L');
            q.push(make_pair(t.first - 1, t.second));
        }
 
        if (t.first < a[t.first].size() - 1 && a[t.second][t.first + 1] != '#'
            && temp[t.second][t.first + 1].empty()) {
            temp[t.second][t.first + 1] = temp[t.second][t.first];
            temp[t.second][t.first + 1].push_back('R');
            q.push(make_pair(t.first + 1, t.second));
        }
    }
 
    return vector<char>();
}
 
int main() {
    ifstream cin("input.txt");
    int n, m;
    cin >> n >> m;
 
    vector<vector<char>> a(n, vector<char>(m));
    pair<int, int> s, e;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                s.first = j;
                s.second = i;
            }
            if (a[i][j] == 'T') {
                e.first = j;
                e.second = i;
            }
        }
    }
 
    vector<char> p = find(a, s, e);
 
    ofstream cout("output.txt");
    if (p.size()) {
        cout << p.size() << endl;
        for (char v : p)
            cout << v;
    }
    else
        cout << -1;
    cin.close();
    cout.close();
    return 0;
}
