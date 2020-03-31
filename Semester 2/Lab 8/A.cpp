#include <fstream>
using namespace std;
 
int main() {
    ifstream cin("input.txt");
    int n, m;
    int matrix[100][100] = { 0 };
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        matrix[x - 1][y - 1] = 1;
    }
    ofstream cout("output.txt");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cin.close();
    cout.close();
    return 0;
}
