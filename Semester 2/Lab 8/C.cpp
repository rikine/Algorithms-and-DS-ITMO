#include <fstream>
using namespace std;
 
int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n, m, x, y;
    cin >> n >> m;
    bool b;
    int matrix[100][100] = { 0 };
    for (int i = 0; i < m; i++) {
            cin >> x >> y;
            if (matrix[x - 1][y - 1] == 1) {
                cout << "YES";
                return 0;
            }
            matrix[x - 1][y - 1] = 1;
            matrix[y - 1][x - 1] = 1;
    }
    cout << "NO";
    cin.close();
    cout.close();
    return 0;
}
