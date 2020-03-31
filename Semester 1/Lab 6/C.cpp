#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
 
#define INF 1000000010
 
struct node {
    int x;
    node* l = nullptr, * r = nullptr;
 
    node(int x_) {
        x = x_;
    }
};
 
struct tree {
    node* head = nullptr;
 
    void add(int x) {
        if (!head) {
            head = new node(x);
            return;
        }
        node* cur = head;
        while (true) {
            if (x < cur->x) {
                if (cur->l) {
                    cur = cur->l;
                }
                else {
                    cur->l = new node(x);
                    return;
                }
            }
            else if (x > cur->x) {
                if (cur->r) {
                    cur = cur->r;
                }
                else {
                    cur->r = new node(x);
                    return;
                }
            }
            else {
                return;
            }
        }
    }
 
    void pop(int x) {
        if (!head) {
            return;
        }
 
        node* prev = nullptr;
        node* cur = head;
        node* l = nullptr, * r = nullptr;
        bool right = false;
        while (true) {
            if (x < cur->x) {
                if (cur->l) {
                    prev = cur;
                    right = false;
                    cur = cur->l;
                }
                else {
                    return;
                }
            }
            else if (x > cur->x) {
                if (cur->r) {
                    prev = cur;
                    right = true;
                    cur = cur->r;
                }
                else {
                    return;
                }
            }
            else {
                l = cur->l;
                r = cur->r;
                delete cur;
                break;
            }
        }
        if (!prev) {
            head = l;
        }
        else if (right) {
            prev->r = l;
        }
        else {
            prev->l = l;
        }
        cur = l;
        if (!cur && !prev) {
            head = r;
        }
        else if (!cur && right) {
            prev->r = r;
        }
        else if (!cur && !right) {
            prev->l = r;
        }
        if (!cur) return;
 
        while (cur->r) {
            cur = cur->r;
        }
        cur->r = r;
    }
 
    bool exists(int x) {
        if (!head) {
            return false;
        }
        node* cur = head;
        while (true) {
            if (x < cur->x) {
                if (cur->l) {
                    cur = cur->l;
                }
                else {
                    return false;
                }
            }
            else if (x > cur->x) {
                if (cur->r) {
                    cur = cur->r;
                }
                else {
                    return false;
                }
            }
            else {
                return true;
            }
        }
    }
 
    int next(int x) {
        if (!head) {
            return INF;
        }
        int ans = INF;
        node* cur = head;
        while (true) {
            if (x < cur->x) {
                ans = min(ans, cur->x);
                if (cur->l) {
                    cur = cur->l;
                }
                else {
                    return ans;
                }
            }
            else if (x >= cur->x) {
                if (cur->r) {
                    cur = cur->r;
                }
                else {
                    return ans;
                }
            }
        }
    }
 
    int prev(int x) {
        if (!head) {
            return -INF;
        }
        int ans = -INF;
        node* cur = head;
        while (true) {
            if (x <= cur->x) {
                if (cur->l) {
                    cur = cur->l;
                }
                else {
                    return ans;
                }
            }
            else if (x > cur->x) {
                ans = max(ans, cur->x);
                if (cur->r) {
                    cur = cur->r;
                }
                else {
                    return ans;
                }
            }
        }
    }
};
 
int main()
{
    ifstream cin("bstsimple.in"); 
    ofstream cout("bstsimple.out");
    string s;
    tree O;
    while (cin >> s) {
        int x;
        cin >> x;
        if (s == "insert") {
            O.add(x);
        }
        else if (s == "delete") {
            O.pop(x);
        }
        else if (s == "exists") {
            if (O.exists(x)) {
                cout << "true\n";
            }
            else {
                cout << "false\n";
            }
        }
        else if (s == "next") {
            int ans = O.next(x);
            if (ans == INF) {
                cout << "none\n";
            }
            else {
                cout << ans << endl;
            }
        }
        else if (s == "prev") {
            int ans = O.prev(x);
            if (ans == -INF) {
                cout << "none\n";
            }
            else {
                cout << ans << endl;
            }
        }
    }
    return 0;
}
