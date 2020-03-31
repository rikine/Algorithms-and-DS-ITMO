#include <iostream>
#include <fstream>
using namespace std;
 
int main() {
    long long a, b;
    ifstream fin("aplusbb.in");
    fin >> a >> b;
    ofstream fout("aplusbb.out");
    fout << a + b*b;
    fout.close();
    return 0;
}
