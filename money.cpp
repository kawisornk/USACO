/*
ID: gateaux1
PROG: money
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

long long answer[26][10001];

int main(){
ifstream fin ("money.in");
ofstream fout ("money.out");

int V,N;
fin >> V >> N;
long long value[V];
for(int i=0;i<V;i++){ fin >> value[i];}
for(int i=0;i<V;i++){ answer[i][0]=1;}
for(int i=0;i<V;i++){
        for(int j=1;j<=N;j++){
                                if(i==0){ answer[0][j] = (j%value[0]==0)?1:0;}
                                else{ if(j>=value[i])answer[i][j] = answer[i-1][j]+answer[i][j-value[i]];
                                      else{ answer[i][j]=answer[i-1][j];}
                                    }
        }

}
 fout << answer[V-1][N] << endl;
 return 0;
}
