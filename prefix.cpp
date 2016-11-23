/*
USER: gateaux1
PROG: prefix
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

vector<string> primatives;
string S = "";

int main(){
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");

    string input;
    fin >> input;
    while(input != "."){
        primatives.push_back(input);
        fin >> input;
    }
    fin >> input;
    while(!fin.eof()){
        S += input;
        fin >> input;
    }

    int bigPos = 0;
    vector<bool> visitable(S.length());
    for(int i = 0; i < S.length(); i++) visitable[i] = false;
    for(int i = 0; i < S.length(); i++){
        if(i != 0 && !visitable[i - 1]) continue;
        for(int j = 0; j < primatives.size(); j++){
            if(i + primatives[j].length() < S.length() + 1 && S.substr(i, primatives[j].length()) == primatives[j]){
                if(i == 0) visitable[0] = true;
                int id = i + primatives[j].length();
                if(primatives[j].length () != 1) id--;
                visitable[id] = true;
                if(i + primatives[j].length() > bigPos) bigPos = i + primatives[j].length();
            }
        }
    }
    for(int i = S.length() - 1; i >= 0; i--){
        if(visitable[i]){
            fout << i + 1 << endl;
            return 0;
        }
    }
    fout << 0 << endl;
    return 0;
}
