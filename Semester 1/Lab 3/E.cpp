#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
 
void radixsort(vector <string> &a, int k, int n, int m) {
    for (int i = 0; i < k; i++) {
        vector <int> c(123);
        vector <string> b(n);
        for (int j = 97; j < 123; j++) {
            c[j] = 0;
        }
        for (int j = 0; j < n; j++) {
            char d = a[j][m - i - 1];
            c[d]++;
        }
        int cou = 0;
        for (int j = 97; j < 123; j++) {
            int temp = c[j];
            c[j] = cou;
            cou += temp;
        }
        for (int j = 0; j < n; j++) {
            int d = a[j][m - i - 1];
            b[c[d]] = a[j];
            c[d]++;
        }
        a = b;
    }
}
 
int main()
{
    ifstream fin("radixsort.in");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    vector <string> s;
    fin >> n >> m >> k;
    s.resize(n);
    for (int i = 0; i < n; i++)
        fin >> s[i];
     
    ofstream fout("radixsort.out");
    radixsort(s, k, n, m);
    for(int i=0;i<n;i++)
        fout << s[i] << endl;
    return 0;
}
