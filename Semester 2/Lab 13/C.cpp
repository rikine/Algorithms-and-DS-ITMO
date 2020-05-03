#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

constexpr long long k = 10e9 + 7;

vector<int> z_function(const string& s){
    vector<int> z(s.size());
    int l = 0, r = 0;
    for (int i = 1; i < s.size(); i++){
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

vector<int> sub_str_search(const string &t, const string &p){
    int n = t.size();
    int m = p.size();

    vector<int> z = z_function(p + '#' + t);
    vector<int> ans;
    for(int i = m; i < z.size(); i++){
        if(z[i] == p.size())
            ans.push_back(i - p.size());
    }
    return ans;
}

int main(){
    ifstream cin("search2.in");
    ofstream cout("search2.out");

    string p, t;
    cin >> p >> t;

    vector<int> ans = sub_str_search(t, p);
    cout << ans.size() << endl;
    for (auto n : ans)
        cout << n << " ";
    return 0;
}
