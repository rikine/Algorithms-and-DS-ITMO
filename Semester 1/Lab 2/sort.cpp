#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
 
void Mergesort(vector <int> &a, int start,int end) {
    if (end - start < 2)
        return;
    if (end - start == 2) {
        if (a[start] > a[start + 1])
            swap(a[start], a[start + 1]);
        return;
    }
    Mergesort(a, start, start + (end - start) / 2);
    Mergesort(a, start + (end - start) / 2, end);
    vector<int>b;
    int b1 = start, e1 = start + (end - start) / 2, b2=e1;
    while (b.size() < end - start) {
        if (b1>=e1 || (b2<end && a[b2] <= a[b1])) {
            b.push_back(a[b2]);
            b2++;
        }
        else {
            b.push_back(a[b1]);
            b1++;
        }
    }
    for (int i = start; i < end; i++) {
        a[i] = b[i - start];
    }
}
 
int main() {
    ifstream fin("sort.in");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, i;
    vector <int> a;
    fin >> n;
    for (i = 0; i < n; i++) {
        int x;
        fin >> x;
        a.push_back(x);
    }
    Mergesort(a, 0, a.size());
    ofstream fout("sort.out");
    for (i = 0; i < n; i++)
        fout << a[i] << " ";
    fout.close();
    return 0;
}
