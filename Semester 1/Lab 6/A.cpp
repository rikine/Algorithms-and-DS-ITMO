#include <iostream>
#include <fstream>
using namespace std;
 
template<typename T>
class tree {
 
    template<typename T>
    class node {
        friend class tree<T>;
        T value;
        node<T> *left;
        node<T> *right;
 
        node() {
            this->value = 0;
            this->left = nullptr;
            this->right = nullptr;
        }
 
        ~node() {
            delete left;
            delete right;
        }
    };  
 
    node<T> *elem = new node<T>[200002];
 
public:
    void push(int idx, T value, int l, int r) {
        elem[idx].value = value;
        if (l != 0)
            elem[idx].left = &elem[l];
        if (r != 0)
            elem[idx].right = &elem[r];
    }
 
    int height() {
        node<T> *p = &elem[1];
        int l, r, h = 0;
        if (p != NULL) {
            l = height1(p->left);
            r = height1(p->right);
            h = ((l > r) ? l : r) + 1;
        }
        return h;
    }
 
    int height1(node<T> *p) {
        int l, r, h = 0;
        if (p != NULL) {
            l = height1(p->left);
            r = height1(p->right);
            h = ((l > r) ? l : r) + 1;
        }
        return h;
    }
};
 
int main() {
    ifstream cin("height.in");
    ofstream cout("height.out");
    tree<int> a;
    int n;
    int value;
    int l, r;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> value >> l >> r;
        a.push(i, value, l, r);
    }
    cout << a.height();
    return 0;
}
