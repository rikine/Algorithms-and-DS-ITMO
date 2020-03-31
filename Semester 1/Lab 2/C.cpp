#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
 
long long res = 0;
 
void Mergesort(vector <int> &a, int start, int end) {
    if (end - start < 2)
        return;
    if (end - start == 2) {
        if (a[start] > a[start + 1]) {
            swap(a[start], a[start + 1]);
            res++;
        }
        return;
    }
    Mergesort(a, start, start + (end - start) / 2);
    Mergesort(a, start + (end - start) / 2, end);
    vector<int>b;
    int b1 = start, e1 = start + (end - start) / 2, b2 = e1;
    while (b.size() < end - start) {
        if (b1 >= e1) {
            b.push_back(a[b2]);
            b2++;
        }
        else if (b2 < end && a[b2] < a[b1]) {
            b.push_back(a[b2]);
            res += e1 - b1;
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
    ifstream fin("inversions.in");
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
    Mergesort(a, 0, n);
    ofstream fout("inversions.out");
    fout << res;
    fout.close();
    return 0;
