#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
 
int main() {
    int n, i, ind, max = 0, min = 0, med = 0;
    double a[10000], b[10000], key = 0;
    ifstream fin("sortland.in");
    fin >> n;
    for (i = 0; i < n; i++) {
        fin >> a[i];
        b[i] = a[i];
    }
 
    for (int j = 1; j < n; j++) {
        key = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
 
    ind = n / 2;
    for (i = 0; i < n; i++) {
        if (a[0] == b[i])
            min = i + 1;
        if (a[ind] == b[i])
            med = i + 1;
        if (a[n - 1] == b[i])
            max = i + 1;
    }
    ofstream fout("sortland.out");
    fout << min << " " << med << " " << max;
    fout.close();
    return 0;
}
