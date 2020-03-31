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
    void insert(T data, long long idx);
    void removeat(string s);
    void pop_back();
    long long search(string s);
    int getsize() { return size; }
    T& operator[](const long long idx);
 
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
    node<T> *current = this->head;
 
    while (current != nullptr) {
        if (current->data.first == data.first) {
            current->data.second = data.second;
            return;
        }
        current = current->pnode;
    }
 
    head = new node<T>(data, head);
    size++;
}
 
template<typename T>
void list<T>::insert(T data, long long idx)
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
void list<T>::removeat(string s)
{
    long long idx = search(s);
 
    if (idx == 0)
        pop_front();
 
    else if (idx > 0) {
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
long long list<T>::search(string s)
{
    node<T> *current = this->head;
 
    int c = 0;
    while (current != nullptr) {
        if (current->data.first == s)
            return c;
 
        current = current->pnode;
        c++;
    }
 
    return -1;
}
 
template<typename T>
T & list<T>::operator[](const long long idx)
{
    int count = 0;
    node<T> *current = this->head;
 
    while (current != nullptr) {
        if (count == idx)
            return current->data;
 
        current = current->pnode;
        count++;
    }
}
 
long long gethash(string x) {
    long long hash = 0;
    int charCode;
    const int k = 199;
    for (char i : x) {
        charCode = tolower(i) - 'a';
        hash = (hash * k + charCode) % n;
    }
    return hash;
}
 
int main() {
    ifstream cin("map.in");
    ofstream cout("map.out");
    vector<list<pair<string, string>>> a(n);
    string s;
    string x, y;
    while (cin >> s) {
        if (s == "put") {
            cin >> x >> y;
            a[gethash(x)].push_front(make_pair(x, y));
        }
        else if (s == "delete") {
            cin >> x;
            a[gethash(x)].removeat(x);
        }
        else if (s == "get") {
            cin >> x;
            long long hash = gethash(x);
            long long idx = a[hash].search(x);
            if (idx == -1) {
                cout << "none" << endl;
            }
            else {
                cout << a[hash][idx].second << endl;
            }
        }
    }
    return 0;
}
