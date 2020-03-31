#include <iostream>
#include <fstream>
using namespace std;
 
int main() {
    long long a, b;
    ifstream fin("aplusb.in");
    fin >> a >> b;
    ofstream fout("aplusb.out");
    fout << a + b;
    fout.close();
    return 0;
}
