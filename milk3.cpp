/*
ID: gateaux1
PROG: milk3
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

int tree[21][21][21]; // check if we already visit this path

short answer[21] = {0};
short A,B,C;
short a,b,c;
// pour from a to b
void a_b(){ short x = (B-b<a)?B-b:a;
            a = a-x;
            b = b+x;
          }
void a_c(){ short x = (C-c<a)?C-c:a;
            a = a-x;
            c = c+x;
          }
void b_a(){ short x = (A-a<b)?A-a:b;
            b = b-x;
            a = a+x;
          }
void b_c(){ short x = (C-c<b)?C-c:b;
            b = b-x;
            c = c+x;
          }
void c_a(){ short x = (A-a<c)?A-a:c;
                            c = c-x;
                            a = a+x;
                            }
void c_b(){ short x = (B-b<c)?B-b:c;
                            c = c-x;
                            b = b+x;
                            }
void check(){   if(a==0)answer[c]=1;

                if(tree[a][b][c]){  tree[a][b][c]=0;//this nide is visited

                                int x,y,z; // temporary value
                                x=a;
                                y=b;
                                z=c;
                                a_b();
                                check();
                                a=x;
                                b=y;
                                c=z;
                                a_c();
                                check ();
                                a=x;
                                b=y;
                                c=z;
                                b_a();
                                check ();
                                a=x;
                                b=y;
                                c=z;
                                b_c();
                                check ();
                                a=x;
                                b=y;
                                c=z;
                                c_a;
                                check ();
                                a=x;
                                b=y;
                                c=z;
                                c_b();
                                check ();
                             }
                else{ return;}
          }
int main(){
ifstream fin ("milk3.in");
ofstream fout ("milk3.out");
fin >> A >> B >> C;
a = 0;
b = 0;
c = C;
for(int i=0;i<=20;i++){ for(int j=0;j<=20;j++){ for(int k=0;k<=20;k++){ tree[i][j][k]=1; }
                                              }
                       }
check ();
int c=0;
for(short i=0;i<=C;i++){
                        if(answer[i]){c++;}
                       }
for(short i=0;i<=C;i++){
                        if(answer[i]>0&&c>1){fout << i << " ";
                                            c--;
                                            }
                        else if(answer[i]>0&&c==1)fout << i;
                       }
                    fout << endl;
                    return 0;
        }
