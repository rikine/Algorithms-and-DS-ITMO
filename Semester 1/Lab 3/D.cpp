#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
void siftDown(int *a, int root, int bottom)
{
    int maxChild;
    int done = 0;
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom) 
            maxChild = root * 2;
        else if (a[root * 2] > a[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        if (a[root] < a[maxChild])
        {
            swap(a[root], a[maxChild]);
            root = maxChild;
        }
        else
            done = 1;
    }
}
 
void heapSort(int *a, int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
        siftDown(a, i, n - 1);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(a[0], a[i]);
        siftDown(a, 0, i - 1);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ifstream fin("sort.in");
    fin >> n;
    int a[100001];
    for (int i = 0; i < n; i++)
        fin >> a[i];
 
    heapSort(a, n);
 
    ofstream fout("sort.out");
    for (int i = 0; i < n; ++i) 
        fout << a[i] << " ";
 
    return 0;
}
