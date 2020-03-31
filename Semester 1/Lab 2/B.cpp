#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
 
 
/*stable_sort(v.begin(), v.end(), [](const auto& l, const auto& r) {
    return l.first < r.first;
});
*/
 
void mergesort(vector<pair<string, string>> &a, int start, int end) {
    if (end - start < 2)
        return;
    mergesort(a, start, start + (end - start) / 2);
    mergesort(a, start + (end - start) / 2, end);
    vector <pair <string, string>> b;
    int b1 = start; 
    int e1 = start + (end - start) / 2;
    int b2 = e1;
    while (b.size() < end - start) {
        if (b1 >= e1 || (b2 < end && a[b2].first < a[b1].first)) {
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
 
int main()
{
    vector<pair<string, string>> v;
 
    ifstream fin("race.in");
    int n, i;
    fin >> n;
    string country, name;
 
    for (i = 0; i < n; i++) {
        fin >> country >> name;
        v.push_back(make_pair(country, name));
    }
 
    mergesort(v, 0, v.size());
 
    ofstream fout("race.out");
    country = v[0].first;
    fout << "=== " << country << " ===" << endl;
    for (const auto& it : v) {
        if (country != it.first) {
            country = it.first;
            fout << "=== " << country << " ===" << endl;
        }
        fout << it.second << endl;
    }
    return 0;
}
