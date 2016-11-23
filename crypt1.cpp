/*
ID: gateaux1
PROG: crypt1
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
int c=0;
int check(int b,int t[],int N){ for(int i=0;i<N;i++){ if(b==t[i])return true;
                                                    }
                                return false;
                    } //check if b is in list t
int ok3(int k,int a[],int N){ if(k<1000){ for(int i=2;i>=0;i--){  int b = k/(int(pow(10,i)));
                                                                      k -= b*(int(pow(10,i)));
                                                     if(!check(b,a,N)){
                                                                      return false;
                                                                     }
                                                              }
                            return true;}
else { return false;}
                      } // check if 3 digits is valid
int ok4(int k,int a[],int N){ if(k<10000){for(int i=3;i>=0;i--){  int b = k/(int(pow(10,i)));
                                                                    k -= b*(int(pow(10,i)));
                                                     if(!check(b,a,N)){
                                                                      return false;
                                                                     }
                                            }
    return true;}
else {return false;}
                      } // check if 4 digits are valid
int fun(int k1,int k2,int a[],int N){ if((k1<1000)&&(k1>100)){ if(k2<10){for(int j=0;j<N;j++){ if(ok3(k1*a[j],a,N))fun(k1,k2*10+a[j],a,N);
                                                                                               }
                                                                        }
                                                                else{ if(ok4(k1*k2,a,N)){c++;}
                                                                    }
                                                              }
                                      else{ for(int j=0;j<N;j++){
                                                               fun(k1*10+a[j],k2,a,N);
                                                                 }
                                          }
                                    }
int main(){
           ofstream fout ("crypt1.out");
           ifstream fin ("crypt1.in");
           int N;
           fin >> N;
           int a[N];
           for(int i=0;i<N;i++){ fin >> a[i];
           }
           fun(0,0,a,N);
           fout << c << endl;
           return 0;
}
