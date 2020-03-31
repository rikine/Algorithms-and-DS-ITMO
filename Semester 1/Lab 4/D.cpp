#include <iostream>
#include <string>
#include <fstream>
using namespace std;
 
class stek {
private:
    int size;
    long long *p;
 
public:
 
    stek() {
        size = 0;
        p = new long long[300];
    }
 
    void push_back(long long a) {
        p[size++] = a;
    }
 
    long long pop_back() {
        return p[--size];;
    }
 
    void print(ofstream &fout) {
        fout << p[size - 1];
    }
 
    int getsize() {
        return size;
    }
 
    ~stek() {
        delete[] p;
    }
};
 
int isDigit(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}
 
int main(){
    ifstream fin("postfix.in");
    ofstream fout("postfix.out");
    char c;
    stek a;
    while (fin >> c) {
 
        if (isDigit(c)) {
            a.push_back(c - '0');
        }
 
        else if (c == '+' && a.getsize()>1) {
            int c = a.pop_back();
            int b = a.pop_back();
            int temp = b + c;
            a.push_back(temp);
        }
 
        else if (c == '-' && a.getsize() > 1) {
            int c = a.pop_back();
            int b = a.pop_back();
            int temp = b - c;
            a.push_back(temp);
        }
 
        else if (c == '*' && a.getsize() > 1) {
            int c = a.pop_back();
            int b = a.pop_back();
            int temp = b * c;
            a.push_back(temp);
        }
 
    }
    a.print(fout);
    return 0;
}
