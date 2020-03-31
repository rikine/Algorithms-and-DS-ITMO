#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <list>
 
using namespace std;
 
class set
{
private:
    vector<list<string>> hashTable;
 
    unsigned hash(string key)
    {
        unsigned hash = 0;
        int charcode;
        const int k = 199;
        for (char i : key)
        {
            charcode = tolower(i) - 'a';
            hash = (hash * k + charcode) % hashTable.size();
        }
        return hash;
    }
 
public:
    set(unsigned size)
    {
        hashTable.resize(size);
    }
 
    bool exists(string key)
    {
        unsigned index = hash(key);
        for (string i : hashTable[index])
        {
            if (i == key)
                return true;
        }
        return false;
    }
 
    void insert(string key)
    {
        if (!exists(key))
            hashTable[hash(key)].push_back(key);
    }
 
    void remove(string key)
    {
        unsigned index = hash(key);
        for (auto i = hashTable[index].begin(); i != hashTable[index].end(); i++)
        {
            if (*i == key)
            {
                hashTable[index].erase(i);
                return;
            }
        }
    }
 
    vector<string> getAll()
    {
        vector<string> result;
        for (list<string> values : hashTable)
        {
            for (string value : values)
            {
                result.push_back(value);
            }
        }
        return result;
    }
 
    void reset()
    {
        unsigned size = hashTable.size();
        hashTable.clear();
        hashTable.resize(size);
    }
};
 
class map
{
private:
    struct node
    {
        string key;
        shared_ptr<set> values;
    };
 
    vector<list<node>> hashes;
 
    unsigned valuesetsize;
 
    unsigned hash(string key)
    {
        unsigned hash = 0;
        int charcode;
        const int k = 199;
        for (char i : key)
        {
            charcode = tolower(i) - 'a';
            hash = (hash * k + charcode) % hashes.size();
        }
        return hash;
    }
 
    shared_ptr<set> getvalueset(string key)
    {
        unsigned index = hash(key);
        for (node &node : hashes[index])
        {
            if (node.key == key)
            {
                return node.values;
            }
        }
        return nullptr;
    }
 
public:
    map(unsigned mapSize, unsigned valueSetSize)
    {
        hashes.resize(mapSize);
        this->valuesetsize = valueSetSize;
    }
 
    void put(string key, string value)
    {
        shared_ptr<set> valueSet = getvalueset(key);
        if (valueSet != nullptr)
            valueSet->insert(value);
        else
        {
            node newNode;
            newNode.key = key;
            newNode.values = make_shared<set>(valuesetsize);
            newNode.values->insert(value);
            hashes[hash(key)].push_back(newNode);
        }
    }
 
    vector<string> get(string key)
    {
        shared_ptr<set> valueSet = getvalueset(key);
        if (valueSet != nullptr)
            return valueSet->getAll();
        else
            return vector<string>(0);
    }
 
    void remove(string key, string value)
    {
        shared_ptr<set> valueSet = getvalueset(key);
        if (valueSet != nullptr)
            valueSet->remove(value);
    }
 
    void removeAll(string key)
    {
        unsigned index = hash(key);
        for (auto i = hashes[index].begin(); i != hashes[index].end(); i++)
        {
            if (i->key == key)
            {
                hashes[index].erase(i);
                return;
            }
        }
    }
};
 
int main()
{
    map map(100003, 235);
    ifstream cin("multimap.in");
    ofstream cout("multimap.out");
    string s, x, y;
    while (cin >> s)
    {
        cin >> x;
        if (s == "put")
        {
            cin >> y;
            map.put(x, y);
        }
        else if (s == "get")
        {
            vector<string> values = map.get(x);
            cout << values.size() << " ";
            for (string value : values)
                cout << value << " ";
            cout << endl;
        }
        else if (s == "delete")
        {
            cin >> y;
            map.remove(x, y);
        }
        else if (s == "deleteall")
        {
            map.removeAll(x);
        }
    }
    return 0;
}
