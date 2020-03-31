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
        int height;
        int idx;
        T value;
        node<T> *left;
        node<T> *right;
 
        node() {
            height = 1;
            value = NULL;
            left = nullptr;
            right = nullptr;
            idx = 0;
        }
        node(T value) {
            this->value = value;
            height = 1;
            left = nullptr;
            right = nullptr;
            idx = 0;
        }
 
        ~node() {
            delete left;
            delete right;
        }
    };
 
    node<T> *elem = new node<T>[200002];
 
    node<T> *root = elem + 1;
 
    int height1(node<T> *p) {
        int l, r, h = 0;
        if (p != NULL) {
            l = height1(p->left);
            r = height1(p->right);
            h = (l > r ? l : r) + 1;
            p->height = h;
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
 
    int height(node<T> *p)
    {
        return p ? p->height : 0;
    }
 
    int bfactor(node<T> *p)
    {
        return height(p->right) - height(p->left);
    }
 
    void fixheight(node<T> *p)
    {
        int l = height(p->left);
        int r = height(p->right);
        p->height = (l > r ? l : r) + 1;
    }
 
    node<T>* rotateright (node<T> *p){
        node<T>* q = p->left;
        p->left = q->right;
        q->right = p;
        fixheight(p);
        fixheight(q);
        return q;
    }
 
    node<T>* rotateleft(node<T> *q){
        node<T>* p = q->right;
        q->right = p->left;
        p->left = q;
        fixheight(q);
        fixheight(p);
        return p;
    }
 
    node<T>* balance(node<T> *p){
        fixheight(p);
        if (bfactor(p) == 2)
        {
            if (bfactor(p->right) < 0)
                p->right = rotateright(p->right);
            return rotateleft(p);
        }
        if (bfactor(p) == -2)
        {
            if (bfactor(p->left) > 0)
                p->left = rotateleft(p->left);
            return rotateright(p);
        }
        return p;
    }
 
    int count(node<T> *p, int i) {
        if (p != NULL) {
            p->idx = i;
            if(p->left != NULL)
                i = count(p->left, i + 1);
            if (p->right != NULL)
                i = count(p->right, i + 1);
        }
        return i;
    }
 
    void print(node<T> *p, ofstream &cout) {
        if (p != NULL) {
            cout << p->value << " ";
            if (p->left != NULL)
                cout << p->left->idx << " ";
            else
                cout << 0 << " ";
            if (p->right != NULL)
                cout << p->right->idx << " ";
            else
                cout << 0 << " ";
            cout << endl;
 
            if (p->left != NULL)
                print(p->left, cout);
            if (p->right != NULL)
                print(p->right, cout);
        }
    }
 
    node<T>* insert(node<T>* p, int k)
    {
        if (!p) 
            return new node<T>(k);
        if (k < p->value)
            p->left = insert(p->left, k);
        else
            p->right = insert(p->right, k);
        return balance(p);
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
        return height1(root);
    }
 
    bool istree() {
        return istree1(root, INT_MIN, INT_MAX);
    }
     
    void print(ofstream &cout) {
        count(root, 1);
        print(root, cout);
    }
 
    void bal() {
        height();
        root = balance(root);
    }
 
    void insert(int value) {
        root = insert(root, value);
    }
 
    void push() {
        root = NULL;
    }
};
 
int main() {
    ifstream cin("addition.in");
    ofstream cout("addition.out");
    tree<int> a;
    int n;
    int value;
    int l, r;
    cin >> n;
    if (n == 0)
        a.push();
    for (int i = 1; i <= n; i++) {
        cin >> value >> l >> r;
        a.push(i, value, l, r);
    }
    int key;
    cin >> key;
    a.height();
    a.insert(key);
    cout << n + 1 << endl;
    a.print(cout);
    return 0;
}
