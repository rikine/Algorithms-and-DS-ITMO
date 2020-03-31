#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <map>
 
using namespace std;
 
class qua {
private:
 
    vector<unsigned short> reg;
    queue<unsigned short> q;
    map<string, int> labels;
    vector<string> com;
    int pos;
 
    void newl() {
        int id = 0;
        for (string i : com) {
            if (i[0] == ':') {
                i.erase(0, 1);
                labels.emplace(i, id);
            }
            id++;
        }
    }
 
    void add() {
        unsigned short x = q.front();
        q.pop();
        unsigned short y = q.front();
        q.pop();
        x = x + y;
        q.push(x);
    }
 
    void sub() {
        unsigned short x = q.front();
        q.pop();
        unsigned short y = q.front();
        q.pop();
        x = x - y;
        q.push(x);
    }
 
    void mul() {
        unsigned short x = q.front();
        q.pop();
        unsigned short y = q.front();
        q.pop();
        x = x * y;
        q.push(x);
    }
 
    void div() {
        unsigned short x = q.front();
        q.pop();
        unsigned short y = q.front();
        q.pop();
        y == 0 ? x = 0 : x = x / y;
        q.push(x);
    }
 
    void mod() {
        unsigned short x = q.front();
        q.pop();
        unsigned short y = q.front();
        q.pop();
        y == 0 ? x = 0 : x = x % y;
        q.push(x);
    }
 
    void putreg(char regis) {
        unsigned short x = q.front();
        q.pop();
        reg[regis - 'a'] = x;
    }
 
    void getreg(char regis) {
        q.push(reg[regis - 'a']);
    }
 
    void print(ofstream &cout) {
        unsigned short x = q.front();
        q.pop();
        cout << x << endl;
    }
 
    void printreg(ofstream &cout, char regis) {
        cout << reg[regis - 'a'] << endl;
    }
 
    void printchar(ofstream &cout) {
        unsigned char x = q.front() % 256;
        q.pop();
        cout << x;
    }
 
    void printregchar(ofstream &cout, char regis) {
        cout << (char)(reg[regis - 'a'] % 256);
    }
 
    void jump(string label) {
        pos = labels[label];
    }
 
    void jumpzero(char regis, string label) {
        if (reg[regis - 'a'] == 0)
            jump(label);
    }
 
    void jumpeq(char regis, char regis1, string label) {
        if (reg[regis - 'a'] == reg[regis1 - 'a'])
            jump(label);
    }
 
    void jumplarge(char regis, char regis1, string label) {
        if (reg[regis - 'a'] > reg[regis1 - 'a'])
            jump(label);
    }
 
public:
    qua() {
        reg.resize(26, 0);
        pos = 0;
    }
 
    void start(ofstream &cout) {
        newl();
        pos = 0;
        while (pos < com.size()) {
            string command = com[pos];
            if (command[0] == '+')
                add();
            else if (command[0] == '-')
                sub();
            else if (command[0] == '*')
                mul();
            else if (command[0] == '/')
                div();
            else if (command[0] == '%')
                mod();
            else if (command[0] == '>')
                putreg(command[1]);
            else if (command[0] == '<')
                getreg(command[1]);
            else if (command[0] == 'P')
                command.size() == 1 ? print(cout) : printreg(cout, command[1]);
            else if (command[0] == 'C')
                command.size() == 1 ? printchar(cout) : printregchar(cout, command[1]);
            else if (command[0] == ':') {
                pos++;
                continue;
            }
            else if (command[0] == 'J') {
                command.erase(0, 1);
                jump(command);
            }
            else if (command[0] == 'Z') {
                char regis = command[1];
                command.erase(0, 2);
                jumpzero(regis, command);
            }
            else if (command[0] == 'E') {
                char regis = command[1];
                char regis1 = command[2];
                command.erase(0, 3);
                jumpeq(regis, regis1, command);
            }
            else if (command[0] == 'G') {
                char regis = command[1];
                char regis1 = command[2];
                command.erase(0, 3);
                jumplarge(regis, regis1, command);
            }
            else if (command[0] == 'Q')
                return;
            else {
                if(command[0] >= '0' && command[0] <= '9')
                    q.push(stoi(command));
            }
            pos++;
        }
    }
 
    void push(string s) {
        com.push_back(s);
    }
 
};
 
int main() {
    ifstream cin("quack.in");
    ofstream cout("quack.out");
    qua a;
    string s;
    while (cin>>s) {
        a.push(s);
    }
    a.start(cout);
    return 0;
}
