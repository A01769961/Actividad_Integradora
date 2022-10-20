#include <bits/stdc++.h>
using namespace std;

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

vector<int> zFunction(string E){
    vector<int> res(E.size(), 0);
    int i = 1;
    while(i<E.size()){
        int j = 0;
        for(int x = i; x<E.size(); x++){
            if(E[x] == E[j]){
                res[i] = res[i] + 1;
                j++;
            }else{
                break;
            }
        }
        i++;
    }
    return res;
}

void part1(string trans, string mcode){
    string complete = mcode + "$" + trans;
    std::vector<int> Z = zFunction(complete);
    int x = 0;
    for(int i = 0; i < Z.size(); i++){
        if(mcode.length() - 1 == Z[i]){
            std::cout << "true " << i - mcode.length() << endl;
            x = 1;
            break;
        }
    }
    if(x == 0){
        std::cout << "false" << endl;
    }
}

void part2(string palin){
    string fin = "|";
    for(int i = 0; i < palin.length(); i++){
        fin = fin + palin[i] + "|";
    }
    int initPos = 0;
    int longestLeng = 0;
    string palindrome;
    string longestPalindrome;
    for(int i = 0; i < fin.length(); i++){
        int j = 1;
        palindrome = fin[i];
        do{
            if(i - j >= 0 && i + j <= fin.length() - 1){
                if(fin[i-j] == fin[i+j]){
                    palindrome = fin[i-j] + palindrome + fin[i+j];
                    // std::cout << endl << palindrome << endl;
                    j++;
                    continue;
                }else{
                    if(j > longestLeng){
                        longestLeng = j;
                        longestPalindrome = palindrome;
                        initPos = i - j + 1;
                        j = 1;
                        break;
                    }else{
                        j = 1;
                        break;
                    }
                }
            }else{
                if(j > longestLeng){
                    longestLeng = j;
                    longestPalindrome = palindrome;
                    initPos = i - j + 1;
                    j = 1;
                    break;
                }else{
                    j = 1;
                    break;
                }
            }
        }while(true);
    }
    longestPalindrome.erase(std::remove(longestPalindrome.begin(), longestPalindrome.end(), '|'), longestPalindrome.end());
    string complete = longestPalindrome + "$" + palin;
    std::vector<int> Z = zFunction(complete);
    for(int i = 0; i < Z.size(); i++){
        if(longestPalindrome.length() == Z[i]){
            int j = i - longestPalindrome.length();
            std::cout << j << " " << j + longestPalindrome.length() - 1 << endl;
            break;
        }
    }
}

pair<int,int> part3(string trans1, string trans2){
    pair <int,int> resultado;
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
    resultado.first=inicio+1;
    resultado.second=fin;
    return resultado;
}

int main(){
    string trans1;
    string trans2;
    string mcode1;
    string mcode2;
    string mcode3;
    pair<int,int> respuesta3;
    leeArchivos(trans1,trans2,mcode1,mcode2,mcode3);
    std::cout << "  parte 1" << endl;
    part1(trans1, mcode1);
    part1(trans1, mcode2);
    part1(trans1, mcode3);
    part1(trans2, mcode1);
    part1(trans2, mcode2);
    part1(trans2, mcode3);
    std::cout << "  parte 2" << endl;
    part2(trans1);
    part2(trans2);
    std::cout << "  parte 3" << endl;
    respuesta3=part3(trans1,trans2);
    cout<<respuesta3.first<<" "<<respuesta3.second<<endl;
    // cout << trans1 << endl << endl << trans2 << endl << endl << mcode1 << endl << endl << mcode2 << endl << endl << mcode3;
}