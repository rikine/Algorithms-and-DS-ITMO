#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
 
void input(int &n, vector <int> &a, int &m, vector <int> &b) {
    ifstream fin("binsearch.in");
    fin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        fin >> a[i];
    fin >> m;
    b.resize(m);
    for (int i = 0; i < m; i++)
        fin >> b[i];
}
 
void binsearch(ofstream &fout, vector <int> &a, int n, int b) {
    int low = 0;
    int i = 1;
    int high = n - 1;
 
    while (low <= high) {
        int mid = low + (high - low) / 2;
 
        if (b == a[mid]) {
            int lower = mid, higher = mid;
            if (mid - i > -1)
                while (b == a[mid - i]) {
                    lower = mid - i;
                    i++;
                    if (mid - i <= -1)
                        break;
                }
            fout << lower + 1 << " ";
            i = 1;
            if (mid + i < n)
                while (b == a[mid + i]) {
                    higher = mid + i;
                    i++;
                    if (mid + i >= n)
                        break;
                }
            fout << higher + 1 << endl;
            return;
        }
        else if (b > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    fout << -1 << " " << -1 << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    vector <int> a, b;
 
    input(n, a, m, b);
 
    ofstream fout("binsearch.out");
    for (int i = 0; i < m; i++) {
        binsearch(fout, a, n, b[i]);
    }
    return 0;
}
