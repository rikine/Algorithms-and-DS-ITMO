#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <list>
 
using namespace std;
 
class linkedmap
{
    struct node
    {
        string key;
        string value;
        shared_ptr<node> next;
        shared_ptr<node> prev;
    };
 
    static shared_ptr<node> create_node(string key, string value)
    {
        shared_ptr<node> newnode = make_shared<node>();
        newnode->key = key;
        newnode->value = value;
        newnode->prev = nullptr;
        newnode->next = nullptr;
        return newnode;
    }
 
    vector<list<shared_ptr<node>>> data;
 
    shared_ptr<node> first;
    shared_ptr<node> last;
 
    unsigned hash(string key)
    {
        unsigned hash = 0;
        int charCode;
        const int k = 199;
        for (char i : key)
        {
            charCode = tolower(i) - 'a';
            hash = (hash * k + charCode) % data.size();
        }
        return hash;
    }
 
public:
    linkedmap()
    {
        data.resize(100003);
    }
 
    void put(string key, string value);
    string get(string key);
    void remove(string key);
    string prev(string key);
    string next(string key);
};
 
void linkedmap::put(string key, string value)
{
    unsigned index = hash(key);
    for (auto &i : data[index])
    {
        if (i->key == key)
        {
            i->value = value;
            return;
        }
    }
    shared_ptr<node> nodeput = create_node(key, value);
    nodeput->prev = last;
    if (last != nullptr)
        last->next = nodeput;
    last = nodeput;
    if (first == nullptr)
        first = nodeput;
    data[index].push_back(nodeput);
}
 
string linkedmap::get(string key)
{
    unsigned index = hash(key);
    for (auto i : data[index])
    {
        if (i->key == key)
            return i->value;
    }
    return "none";
}
 
void linkedmap::remove(string key)
{
    unsigned index = hash(key);
    for (auto &i : data[index])
    {
        if (i->key == key)
        {
            if (i->prev != nullptr)
                i->prev->next = i->next;
            else
                first = i->next;
            if (i->next != nullptr)
                i->next->prev = i->prev;
            else
                last = i->prev;
            data[index].remove(i);
            return;
        }
    }
}
 
string linkedmap::prev(string key)
{
    unsigned index = hash(key);
    for (auto i : data[index])
    {
        if (i->key == key)
        {
            if (i->prev != nullptr)
                return i->prev->value;
            else
                return "none";
        }
    }
    return "none";
}
 
string linkedmap::next(string key)
{
    unsigned index = hash(key);
    for (auto i : data[index])
    {
        if (i->key == key)
        {
            if (i->next != nullptr)
                return i->next->value;
            else
                return "none";
        }
    }
    return "none";
}
 
int main()
{
    linkedmap lm;
    ifstream cin("linkedmap.in");
    ofstream cout("linkedmap.out");
    string s, x, y;
    while (cin >> s)
    {
        cin >> x;
        if (s == "put")
        {
            cin >> y;
            lm.put(x, y);
        }
        else if (s == "get")
        {
            cout << lm.get(x) << endl;
        }
        else if (s == "delete")
        {
            lm.remove(x);
        }
        else if (s == "prev")
        {
            cout << lm.prev(x) << endl;
        }
        else if (s == "next")
        {
            cout << lm.next(x) << endl;
        }
    }
    return 0;
}
