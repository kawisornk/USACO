/*
ID: gateaux1
PROG: frac1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;


int relprime(int a,int b){
if(a==1 || b==1){ return true;}
else if(a==0 || b==0){ return false;}
else { if(a>b){ return relprime(a%b,b);}
        else{ return relprime(a,b%a);}
     }
}
bool comp(pair<int,int>  a,pair<int,int> b){ return ((float)a.first/(float)a.second)>((float)b.first/(float)b.second);
}

int main(){
ifstream fin ("frac1.in");
ofstream fout ("frac1.out");
int N;
fin >> N;
vector < pair<int,int> > v;

for(int i=1;i<=N;i++){  //i = denomenator
                        for(int j=1;j<i;j++){  //j = numerator
                                                if(relprime(i,j)){
                                                                    pair<int,int> k (j,i);
                                                                    v.push_back(k);
                                                                 }
                                             }
                     }
fout << "0/1" << endl;
sort(v.begin(),v.end(),comp);
while(!v.empty()){
    fout << v.back().first << "/" << v.back().second << endl;
    v.pop_back();
}
fout << "1/1" << endl;
}
