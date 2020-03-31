#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream> 
#include <string>
using namespace std;
 
double girl(vector <double> &h, int n)
{
    double l = 0, r = h[0];
    double epsilon = 0.0000001; //0.0000000001
    while (r - l > epsilon) {
        h[1] = (l + r) / 2;
        bool Up = true;
        for (int i = 2; i < n; i++) {
            h[i] = 2 * h[i - 1] - h[i - 2] + 2;
            if (h[i] < 0) {
                Up = false;
                break;
            }
        }
        if (Up) {
            r = h[1];
        }
        else {
            l = h[1];
        }
 
 
    }
    return h[n - 1];
 
}
int main()
{
    ifstream fin("garland.in");
    int n;
    vector<double> h;
    fin >> n;
    h.resize(n);
    fin >> h[0];
    ofstream fout("garland.out");
    fout.precision(2);
    fout << fixed << girl(h, n);
    return 0;
}
