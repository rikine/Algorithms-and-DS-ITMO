#include <fstream>
#include <vector>
using namespace std;
 
void find(vector<vector<int>> &a, int i, vector<int> &comp, int comp_number) {
    comp[i] = comp_number;
    for (int j = 0; j < a[i].size(); j++)
        if (comp[a[i][j]] == 0)
            find(a, a[i][j], comp, comp_number);
}
 
int main() {
    ifstream cin("components.in");
    ofstream cout("components.out");
    int n, m, x, y;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        a[x - 1].push_back(y - 1);
        a[y - 1].push_back(x - 1);
    }
 
    vector<int> comp(n, 0);
    int comp_numb = 0;
    for (int i = 0; i < n; i++)
        if (comp[i] == 0)
            find(a, i, comp, ++comp_numb);
 
    cout << comp_numb << endl;
    for (int i = 0; i < n; i++)
        cout << comp[i] << " ";
    cin.close();
    cout.close();
    return 0;
}
