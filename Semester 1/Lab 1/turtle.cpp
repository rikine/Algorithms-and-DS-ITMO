#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
 
int h, w, a[1000][1000];
 
int main() {
    ifstream fin("turtle.in");
    fin >> h >> w;
 
    for (int i = h-1; i >= 0; i--)
        for (int j = 0; j < w; j++) 
            fin >> a[i][j];
 
    for (int i = 1; i < h; i++)
        a[i][0] += a[i - 1][0];
    for (int j = 1; j < w; j++)
        a[0][j] += a[0][j - 1];
 
    for (int i = 1; i < h; i++)
        for (int j = 1; j < w; j++) 
            a[i][j] += max(a[i - 1][j], a[i][j - 1]);
 
    ofstream fout("turtle.out");
    fout << a[h-1][w-1];
    fout.close();
    return 0;
}
