#include <fstream>
using namespace std;
 
int main() {
    ifstream cin("input.txt");
    int n, x;
    cin >> n;
    int matrix[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            matrix[i][j] = x;
        }
    }
     
    ofstream cout("output.txt");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] != matrix[j][i] || i == j && matrix[i][j] == 1) {
                cout << "NO";
                return 0;
            }
    cout << "YES";
    cin.close();
    cout.close();
    return 0;
}
