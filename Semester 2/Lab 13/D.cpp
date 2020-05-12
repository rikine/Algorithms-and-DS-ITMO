#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

vector<int> prefix_function(const string &s)
{
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

int main()
{
    int power;
    string text;
    cin >> power >> text;
    text += "#";
    vector<int> prefix = prefix_function(text);
    vector<vector<int>> ans(text.size(), vector<int>(power));
    for (int i = 0; i < text.size(); i++)
    {
        for (char c = 'a'; c < 'a' + power; c++)
        {
            if (i > 0 && c != text[i])
            {
                ans[i][c - 'a'] = ans[prefix[i - 1]][c - 'a'];
            }
            else
            {
                ans[i][c - 'a'] = i + (c == text[i]);
            }
        }
    }

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}
