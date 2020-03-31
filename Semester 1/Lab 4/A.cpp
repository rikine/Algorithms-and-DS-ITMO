#include <fstream>
#include <iostream>
using namespace std;
 
class stek{
private:
    int sizep;
    int size;
    int *p;
 
public:
 
    stek() {
        size = 0;
        sizep = 0;
    }
 
    void push_back(int a) {
        size++;
 
        if (size >= sizep) {
            sizep = (sizep + 1) * 2;
            int *newarray = new int[sizep];
            for (int i = 0; i < size - 1; i++) {
                newarray[i] = p[i];
            }
            newarray[size - 1] = a;
            delete[] p;
            p = newarray;
        }
        else {
            p[size - 1] = a;
        }
    }
 
    void pop_back(ofstream &fout) {
        fout << p[--size] << endl;
    }
 
    ~stek() {
        delete[] p;
    }
 
};
 
int main() {
    ifstream fin("stack.in");
    stek a;
    int n;
    char c;
    fin >> n;
    int x = 0;
 
    ofstream fout("stack.out");
    for (int i = 0; i < n; i++) {
        fin >> c;
        if (c == '+') {
            fin >> x;
            a.push_back(x);
        }
        else
            a.pop_back(fout);
    }
    return 0;
}
