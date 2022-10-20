#include <bits/stdc++.h>
using namespace std;

void imprimemat(vector< vector <int>  > matriz, int x, int y){
    for (int i = 0; i < y; i++)
    {
        for (int e = 0; e < x; e++)
        {
            cout<<matriz[i][e]<<" ";
        }
        cout<<endl;
    }
}

void leeArchivos(string &trans1, string &trans2, string &mcode1, string &mcode2, string &mcode3){
    trans1 = "";
    trans2 = "";
    mcode1 = "";
    mcode2 = "";
    mcode3 = "";
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
}

void parte3(string trans1, string trans2){
    int t1=trans1.length();
    int t2=trans2.length();
    vector <vector <int > > matriz(t1,vector <int>(t2, 0));
    int maximo = 0;
    int inicio = 0;
    int fin = 0;
    for (int i = 0; i < t1; i++)
    {
        if (trans1[i]==trans2[0]){
            matriz[i][0]=1;
            maximo=1;
        }
        else{
            matriz[i][0]=0;
        }
    }
    for (int j = 0; j < t2; j++)
    {
        if (trans1[0]==trans2[j]){
            matriz[0][j]=1;
            maximo=1;
        }
        else{
            matriz[0][j]=0;
        }
    }
    
    for (int i = 1; i < t1; i++)
    {
        for (int j = 1; j < t2; j++)
        {
            if(trans1[i]==trans2[j]){
                matriz[i][j]=matriz[i-1][j-1]+1;
                if(matriz[i][j]>maximo){
                    maximo=matriz[i][j];
                    fin=i+1;
                    inicio=fin-maximo;
                }
            }
            else{
                matriz[i][j]=0;
            }
        }
    }
    cout<<inicio+1<<" "<<fin<<endl;
}



int main(){
    string trans1;
    string trans2;
    string mcode1;
    string mcode2;
    string mcode3;
    leeArchivos(trans1,trans2,mcode1,mcode2,mcode3);
    parte3(trans1,trans2);
    //cout << trans1 << endl << endl << trans2 << endl << endl << mcode1 << endl << endl << mcode2 << endl << endl << mcode3;
}