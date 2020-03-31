#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
 
int main() {
    int n, a[11000], i, key = 0;
    ifstream fin("smallsort.in");
    fin >> n;
    for (i = 0; i < n; i++)
        fin >> a[i];
    for (int j = 1; j < n; j++) {
        key = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
    ofstream fout("smallsort.out");
    for (i = 0; i < n; i++)
        fout << a[i] << " ";
    fout.close();
    return 0;
}
