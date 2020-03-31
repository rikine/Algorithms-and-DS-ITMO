#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector <int> a;
    ifstream fin("isheap.in");
    fin >> n;
    a.resize(n+1);
    for (int i = 1; i <= n; i++)
        fin >> a[i];
 
    ofstream fout("isheap.out");
    for (int i = 1; i <= n; i++) {
        if (2 * i <= n) {
            if (a[i] <= a[i * 2])
                continue;
            else {
                fout << "NO";
                return 0;
            }
        }
        if (2 * i + 1 <= n) {
            if (a[i] <= a[2 * i + 1])
                continue;
            else {
                fout << "NO";
                return 0;
            }
        }
    }
    fout << "YES";
    return 0;
}
