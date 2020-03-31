#include <iostream>
#include <string>
#include <fstream>
using namespace std;
 
class priority_q {
    class elem {
        friend class priority_q;
 
        int val;
        int ind;
    };
    elem *a = new elem[1000000];
 
    void heap_down(int i) {
        while (2 * i + 1 < size) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
 
            int j = l;
 
            if (r < size && a[r].val < a[l].val)
                j = r;
            if (a[i].val <= a[j].val)
                break;
 
            swap(a[i], a[j]);
            i = j;
        }
    }
 
    void heap_up(int i) {
 
        while (a[i].val < a[(i - 1) / 2].val) {
            swap(a[i], a[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
 
    int size;
 
public:
    priority_q() {
        size = 0;
    }
 
    void push_back(int x, int i) {
 
        a[size].ind = i;
        a[size].val = x;
        heap_up(size++);
    }
 
    void pop_back(ofstream &fout) {
        if (size > 0) {
 
 
            fout << a[0].val << endl;
            a[0] = a[--size];
 
            heap_down(0);
        }
        else {
            fout << '*' << endl;
        }
    }
 
    void decrease(int x, int j) {
        for (int i = 0; i < size; i++)
            if (a[i].ind == j) {
                a[i].val = x;
                heap_up(i);
                return;
            }
    }
 
    int getsize() {
        return size;
    }
 
    ~priority_q() {
        delete[] a;
    }
};
 
int main() {
    ifstream fin("priorityqueue.in");
    ofstream fout("priorityqueue.out");
    priority_q a;
    string s;
    int cou = 1;
    while (fin >> s) {
        if (s == "push") {
            int x;
            fin >> x;
            a.push_back(x, cou);
        }
        else if (s == "extract-min") {
            a.pop_back(fout);
        }
        else if (s == "decrease-key") {
            int x, y;
            fin >> y >> x;
            a.decrease(x, y);
        }
        cou++;
    }
    return 0;
}
