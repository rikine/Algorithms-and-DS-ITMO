#include <fstream>
#include <iostream>
#include <string>
using namespace std;
 
class stek {
private:
    int size;
    char *p;
 
public:
 
    stek() {
        size = 0;
    }
 
    void push_back(char a) {
        char *newarray = new char[size + 1];
        for (int i = 0; i < size; i++) {
            newarray[i] = p[i];
        }
        newarray[size++] = a;
        delete[] p;
        p = newarray;
    }
 
    void pop_back(char c, int *d) {
        if (size - 1 < 0 || !(p[size - 1] == '(' && c == ')' || p[size - 1] == '[' && c == ']')) {
            *d = 0;
            return;
        }
        char *newarray = new char[--size];
        for (int i = 0; i < size; i++) {
            newarray[i] = p[i];
        }
        delete[] p;
        p = newarray;
    }
 
    void del() {
        delete[] p;
        p = new char[0];
 
        size = 0;
    }
 
    int getsize() {
        return size;
    }
};
 
int main() {
    ifstream fin("brackets.in");
    ofstream fout("brackets.out");
    stek a;
    string s;
 
    while (fin >> s) {
        int n = s.size();
        int d = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[')
                a.push_back(s[i]);
            else {
                a.pop_back(s[i], &d);
                if (d == 0) {
                    fout << "NO" << endl;
                    break;
                }
            }
        }
        if (a.getsize() == 0 && d)
            fout << "YES" << endl;
        else if (d)
            fout << "NO" << endl;
        a.del();
    }
    return 0;
}
