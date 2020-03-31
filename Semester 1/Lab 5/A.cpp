#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
 
#define n 1000003

template <typename T>
class list {
public:
    list();
    ~list();
 
    void push_back(T data);
    void pop_front();
    void clear();
    void push_front(T data);
    void insert(T data, int idx);
    void removeat(int idx);
    void pop_back();
    int search(T data);
    int getsize() { return size; }
    T& operator[](const int index);
 
private:
 
    template <typename T>
    class node {
    public:
        node *pnode;
        T data;
        node(T data = T(), node *pnode = nullptr) 
        {
            this->data = data;
            this->pnode = pnode;
        }
    };
 
    int size;
    node <T> *head;
};
 
template <typename T>
list<T>::list() 
{
    size = 0;
    head = nullptr;
}
 
template <typename T>
list<T>::~list() 
{
    clear();
}
 
template<typename T>
void list<T>::push_back(T data)
{
    if (head == nullptr)
        head = new node<T>(data);
 
    else {
 
        node<T> *current = this->head;
 
        while (current->pnode != nullptr) {
            current = current->pnode;
        }
 
        current->pnode = new node<T>(data);
    }
 
    size++;
}
 
template<typename T>
void list<T>::pop_front()
{
    node <T> *temp = head;
 
    head = head->pnode;
 
    delete temp;
    size--;
}
 
template<typename T>
void list<T>::clear()
{
    while (size) {
        pop_front();
    }
}
 
template<typename T>
void list<T>::push_front(T data)
{
    head = new node<T>(data, head);
    size++;
}
 
template<typename T>
void list<T>::insert(T data, int idx)
{
    if (idx == 0)
        push_front(data);
    else {
        node<T> *prev = this->head;
        for (int i = 0; i < idx - 1; i++)
            prev = prev->pnode;
 
        prev->pnode = new node<T>(data, prev->pnode);
 
        size++;
    }
 
}
 
template<typename T>
void list<T>::removeat(int idx)
{
    if (idx == 0)
        pop_front();
    else {
        node<T> *prev = this->head;
        for (int i = 0; i < idx - 1; i++)
            prev = prev->pnode;
 
        node<T> *todel = prev->pnode;
        prev->pnode = todel->pnode;
        delete todel;
        size--;
    }
}
 
template<typename T>
void list<T>::pop_back()
{
    removeat(size - 1);
}
 
template<typename T>
int list<T>::search(T data)
{
    int cou = 0;
    node<T> *current = this->head;
 
    while (size != 0 && current->data != data && current->pnode != nullptr) 
    {
        cou++;
        current = current->pnode;
    }
 
    if (size == 0 || current->data != data && current->pnode == nullptr)
        return -1;
     
    return cou;
}
 
template<typename T>
T & list<T>::operator[](const int index)
{
    int count = 0;
    node<T> *current = this->head;
 
    while (current != nullptr) {
        if (count == index)
            return current->data;
 
        current = current->pnode;
        count++;
    }
}
 
int gethash(int x) {
    x = x < 0 ? -x : x;
    return x % n;
}
 
int main() {
    ifstream cin("set.in");
    ofstream cout("set.out");
    vector <list<int>> a(n);
    string s;
    int x;
    int hash;
    while (cin >> s) {
        if (s == "insert") {
            cin >> x;
            hash = gethash(x);
            int check = a[hash].search(x);
            if (check != -1)
                continue;
 
            a[hash].push_front(x);
        }
        else if (s == "delete") {
            cin >> x;
            hash = gethash(x);
            int check = a[hash].search(x);
            if (check == -1)
                continue;
 
            a[hash].removeat(a[hash].search(x));
        }
        else if (s == "exists") {
            cin >> x;
            bool t;
            a[gethash(x)].search(x) == -1 ? t = 0 : t = 1;
            if (t)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
    }
    return 0;
}
