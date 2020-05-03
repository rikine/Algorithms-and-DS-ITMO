#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    ifstream cin("search1.in");
    ofstream cout("search1.out");

    string p, t;
    cin >> p >> t;
    vector<int> ans;
    int size_t = t.size();
    int size_p = p.size();
    for (int i = 0; i <= size_t - size_p; ++i){
        bool ok = true;
        for (int j = 0; j < p.size(); j++){
            if (p[j] != t[i + j])
                ok = false;
        }
        if (ok)
            ans.push_back(i + 1);
    }

    cout << ans.size() << endl;
    for (auto n : ans){
        cout << n << " ";
    }
    return 0;
}
