#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>
using namespace std;
 
template<typename T>
class tree {
 
    template<typename T>
    class node {
    public:
        int dep;
        T value;
        node<T> *left;
        node<T> *right;
 
        node() {
            this->value = 0;
            this->left = nullptr;
            this->right = nullptr;
            this->dep = 0;
        }
 
        ~node() {
            delete left;
            delete right;
        }
    };
 
    node<T> *elem = new node<T>[200002];
 
    int height1(node<T> *p) {
        int l, r, h = 0;
        if (p != NULL) {
            l = height1(p->left);
            r = height1(p->right);
            h = (l > r ? l : r) + 1;
            p->dep = r - l;
        }
        return h;
    }
 
    bool istree1(node<T> *p, T min, T max) {
        if (p == NULL)
            return 1;
        if (p->value <= min || max <= p->value)
            return 0;
        return istree1(p->left, min, p->value) && istree1(p->right, p->value, max);
    }
public:
 
    void push(int idx, T value, int l, int r) {
        elem[idx].value = value;
        if (l != 0)
            elem[idx].left = &elem[l];
        if (r != 0)
            elem[idx].right = &elem[r];
    }
 
    int height() {
        return height1(&elem[1]);
    }
 
    bool istree() {
        return istree1(&elem[1], INT_MIN, INT_MAX);
    }
     
    void print(int n, ofstream &cout) {
        for (int i = 1; i <= n; i++)
            cout << elem[i].dep << endl;
    }
};
 
int main() {
    ifstream cin("balance.in");
    ofstream cout("balance.out");
    tree<int> a;
    int n;
    int value;
    int l, r;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> value >> l >> r;
        a.push(i, value, l, r);
    }
    a.height();
    a.print(n, cout);
    return 0;
}
