#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits>
#include <fstream>
#include <sstream>
#include <numeric>
#include <iomanip>
using namespace std;

void escribirDatos(std::vector<string> aux){
    std::cout << std::endl << std::endl;
    for (auto const& value : aux){
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main(){
    string trans1 = "";
    string trans2 = "";
    string mcode1 = "";
    string mcode2 = "";
    string mcode3 = "";
    ifstream fin1("transmission1.txt", ifstream::in);
    string line;
    while (fin1 >> line) {
        trans1 = trans1 + line + "\n";
    }
    fin1.close();
    ifstream fin2("transmission2.txt", ifstream::in);
    while (fin2 >> line) {
        trans2  = trans2 + line + "\n";
    }
    fin2.close();
    ifstream fin3("mcode1.txt", ifstream::in);
    while (fin3 >> line) {
        mcode1 = mcode1 + line + "\n";
    }
    fin3.close();
    ifstream fin4("mcode2.txt", ifstream::in);
    while (fin4 >> line) {
        mcode2 = mcode2 + line + "\n";
    }
    fin4.close();
    ifstream fin5("mcode3.txt", ifstream::in);
    while (fin5 >> line) {
        mcode3 = mcode3 + line + "\n";
    }
    fin5.close();
    cout << trans1 << endl << endl << trans2 << endl << endl << mcode1 << endl << endl << mcode2 << endl << endl << mcode3;
}