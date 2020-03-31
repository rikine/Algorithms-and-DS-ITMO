#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
 
int kth(vector <int> &a, int l, int r, int k)
{
    int x = a[(l + r) / 2];
    int i = l, j = r;
    while (i <= j){
        while (a[i] < x) 
            i++; 
        while (a[j] > x) 
            j--;
 
        if (i <= j){ 
            swap(a[i], a[j]); 
            i++; 
            j--; 
        }
    } 
    if (l <= k && k <= j) 
        return kth(a, l, j, k); 
    if (i <= k && k <= r) 
        return kth(a, i, r, k); 
    return a[k];
}
 
int main() {
    ifstream fin("kth.in");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, A, B, C, a1, a2;
    cin >> n >> k;
    k--;
    vector <int> a(n);
    cin >> A >> B >> C >> a[0] >> a[1];
    for (int i = 2; i < n; i++) 
        a[i] = A * a[i - 2] + B * a[i - 1] + C;
    ofstream fout("kth.out");
    cout << kth(a, 0, a.size()-1, k);
    fout.close();
    return 0;
}
