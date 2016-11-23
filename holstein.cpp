/*
ID: gateaux1
PROG: holstein
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
int req[25];
int feed[25][25];
struct triplet { long k;
                 int n;
                 int a[25];
                 int latest;
                };
typedef struct triplet triplet;
int meet_requirement(long k,int V,int G,int a[]){
                        for(int i=0;i<V;i++){ if(a[i]<req[i])return false;
                        }
                        return true;
}
int pow(int k){ if(k==0)return 1;
            else {return 2*(pow(k-1));}
          }
int main(){
ifstream fin ("holstein.in");
ofstream fout ("holstein.out");
queue<triplet> myqueue;
int V,G;
// 1<=V<=25, 1<=G<=15
fin >> V;
for(int i=0;i<V;i++){
    fin >> req[i];
}
fin >> G;
for(int i=0;i<G;i++){
                    for(int j=0;j<V;j++){
                                        fin >> feed[i][j];
                    }
}
triplet x;
x.k=0;
x.n=0;
x.latest=-1;
for(int i=0;i<V;i++){ x.a[i] = 0;}
myqueue.push(x);
while(!myqueue.empty()){ triplet x = myqueue.front();
                         myqueue.pop();
                         //b[x.k] = 1;
                         if(meet_requirement(x.k,V,G,x.a)){ fout << x.n;
                                                            int i=1;
                                                            while(x.k>0){
                                                                        if(x.k%2==0){ i++;
                                                                                      x.k/=2;
                                                                                    }
                                                                        else { fout << " " << i;
                                                                              x.k--;
                                                                              i++;
                                                                              x.k/=2;
                                                                             }
                                                                        }
                                                            fout << endl;
                                                            return 0;
                                                          }
                         else{
                                for(int i=(x.latest)+1;i<G;i++){
                                                                        triplet y;
                                                                        y.k = x.k + pow(i);
                                                                        y.n = x.n + 1;
                                                                        y.latest = i;
                                                                        for(int j=0;j<V;j++){ y.a[j] = (x.a[j]+feed[i][j]);
                                                                                            }
                                                                        myqueue.push(y);
                                                                }
                             }
}
}
