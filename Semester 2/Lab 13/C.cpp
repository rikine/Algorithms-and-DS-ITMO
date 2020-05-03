#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

vector<int> prefix_function(const string& s){
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++){
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

int main(){
    ifstream cin("prefix.in");
    ofstream cout("prefix.out");

    string t;
    cin >> t;

    for (auto n : prefix_function(t))
        cout << n << " ";
    return 0;
}
