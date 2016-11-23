/*
 ID: gateaux1
 PROG: wormhole
 LANG: C++
 */
#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;
int cnt=0;
int walk(int s,int x,int a[][2],int p[],int N,int c){           if(c==0){
                                                                          return walk(s,p[s],a,p,N,1);
                                                                          }
                                                                 else if(c>N){ return true;
                                                                                       } //loop
                                                                 else { int k=N;
                                                                        int j=-1;
                                                                        for(int i=0;i<N;i++){
                                                                                             if((a[i][1]==a[x][1])&&(a[i][0]>a[x][0])&&((a[i][0]<j)||(k==N))){ j = a[i][0];
                                                                                                                                                               k=i;
                                                                                                                                                             }

                                                                                            }
                                                                       if(k==N){
                                                                                return false;
                                                                               } // no loop
                                                                       else{ if(k==s)return true;
                                                                             else {return walk(s,p[k],a,p,N,c+1);}
                                                                            }

                                                                      }
} // return true if there is loop
int check(int a[][2],int p[],int N){ int c=0;
                                     for(int i=0;i<N;i++){
                                                        if((walk(i,i,a,p,N,0))){c=1;
                                                                                break;
                                                                               }
                                                                                //loop
                                                         }
                                     if(c==1)return true;
                                     else{ return false;} //no loop
                                   } //true if this pairing create loops
void pairing(int p[],int k,int l[],int N,int a[][2]){ if(k==(N-1)){ if((check(a,p,N))){ cnt++; //got loop
                                                                                     }
                                                                 }
                                                    else if(l[k]==-1){ pairing(p,k+1,l,N,a); //k is already paired
                                                                     }
                                                    else{ for(int j=k+1;j<N;j++){ int m[N],n[N];
                                                                                   for(int i=0;i<N;i++){ m[i]=p[i];
                                                                                                         n[i]=l[i];
                                                                                                       }
                                                                                  if(l[j]==0){ m[k]= j;
                                                                                               m[j]= k;
                                                                                               n[k]= -1;
                                                                                               n[j]= -1;
                                                                                               pairing(m,k+1,n,N,a);
                                                                                             }
                                                                                  }
                                                        }
                                                   }
int main(){
ofstream fout ("wormhole.out");
ifstream fin ("wormhole.in");
int N;
fin >> N;
int a[N][2],p[N],l[N];
for(int i=0;i<N;i++){ fin >> a[i][0] >> a[i][1];
                      p[i] = 0;
                      l[i] = 0;
                    }
pairing(p,0,l,N,a);

fout << cnt << endl;
return 0;
}


