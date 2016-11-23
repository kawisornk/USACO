/*
ID: gateaux1
PROG: subset
LANG: C++
*/

#include<iostream>
#include<fstream>
using namespace std;

int main(){
ifstream fin ("subset.in");
ofstream fout ("subset.out");
int n;
fin >> n;
int sum = n*(n+1)/2;
if(sum%2==1){   fout << 0 << endl;
                return 0;
            }
unsigned long table[n+1][sum/2 + 1];
for(int i=0;i<=n;i++){ table[i][0] = 1;
                           }
      for(int j=1;j<=sum/2;j++){ table[0][j] = 0;
                            }
     for(int i=1;i<=n;i++){
                            for(int j=1;j<=sum/2;j++){
                                            if(j>i*(i+1)/2){ table[i][j] = 0;}
                                            else if(j>=i)table[i][j] = table[i-1][j] + table[i-1][j-i];
                                            else{ table[i][j] = table[i-1][j];}
                                        }
            }
      fout << table[n][sum/2]/2 << endl;
      return 0;
}
