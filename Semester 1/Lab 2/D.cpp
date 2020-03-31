#include <iostream>
#include <vector>
#include <fstream>
 
using namespace std;
 
int main()
{
    ifstream fin("antiqs.in");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> mas(n);
 
    for (int i = 0; i < n; i++)
        mas[i] = i + 1;
 
    for (int i = 2; i < n; i++)
        swap(mas[i], mas[i / 2]);
 
    ofstream fout("antiqs.out");
    for (int i = 0; i < n; i++)
        cout << mas[i] << " ";
    fout.close();
    return 0;
}
