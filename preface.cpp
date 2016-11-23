/*
ID: gateaux1
PROG: preface
LANG: C++
*/

#include<iostream>
#include<fstream>

int a[3900][7];
int ans[7]={0};
using namespace std;

int func(int n){ //for 1-10
                if(n==1){       a[n][0] = 1; // I
                                a[n][1] = 0; // V
                                a[n][2] = 0; // X
                                a[n][3] = 0; // L
                                a[n][4] = 0; // C
                                a[n][5] = 0; // D
                                a[n][6] = 0; //M
                                }
                else if(n==2){  a[n][0] = 2; // I
                                a[n][1] = 0; // V
                                a[n][2] = 0; // X
                                a[n][3] = 0; // L
                                a[n][4] = 0; // C
                                a[n][5] = 0; // D
                                a[n][6] = 0; //M
                }
                else if(n==3){  a[n][0] = 3; // I
                                a[n][1] = 0; // V
                                a[n][2] = 0; // X
                                a[n][3] = 0; // L
                                a[n][4] = 0; // C
                                a[n][5] = 0; // D
                                a[n][6] = 0; //M
                }
                else if(n==4){  a[n][0] = 1; // I
                                a[n][1] = 1; // V
                                a[n][2] = 0; // X
                                a[n][3] = 0; // L
                                a[n][4] = 0; // C
                                a[n][5] = 0; // D
                                a[n][6] = 0; //M
                }
                else if(n==5){  a[n][0] = 0; // I
                                a[n][1] = 1; // V
                                a[n][2] = 0; // X
                                a[n][3] = 0; // L
                                a[n][4] = 0; // C
                                a[n][5] = 0; // D
                                a[n][6] = 0; //M
                }
                else if(n==6){  a[n][0] = 1; // I
                                a[n][1] = 1; // V
                                a[n][2] = 0; // X
                                a[n][3] = 0; // L
                                a[n][4] = 0; // C
                                a[n][5] = 0; // D
                                a[n][6] = 0; //M
                }
                else if(n==7){  a[n][0] = 2; // I
                                a[n][1] = 1; // V
                                a[n][2] = 0; // X
                                a[n][3] = 0; // L
                                a[n][4] = 0; // C
                                a[n][5] = 0; // D
                                a[n][6] = 0; //M
                }
                else if(n==8){ a[n][0] =  3; // I
                                a[n][1] = 1; // V
                                a[n][2] = 0; // X
                                a[n][3] = 0; // L
                                a[n][4] = 0; // C
                                a[n][5] = 0; // D
                                a[n][6] = 0; //M
                }
                else if(n==9){  a[n][0] = 1; // I
                                a[n][1] = 0; // V
                                a[n][2] = 1; // X
                                a[n][3] = 0; // L
                                a[n][4] = 0; // C
                                a[n][5] = 0; // D
                                a[n][6] = 0; //M
                }
                else if(n>=10 && n<=99){ int k=n/10;
                                         int j=n%10;
                                a[n][0] = a[j][0]; // I
                                a[n][1] = a[j][1]; // V
                                a[n][2] = a[k][0]+a[j][2]; // X
                                a[n][3] = a[k][1]; // L
                                a[n][4] = a[k][2]; // C
                                a[n][5] = 0; // D
                                a[n][6] = 0; //M
                                }
                else if(n>=100 && n<=999){  int k=n/100;
                                            int j=n%100;
                                            a[n][0] = a[j][0]; // I
                                            a[n][1] = a[j][1]; // V
                                            a[n][2] = a[j][2]; // X
                                            a[n][3] = a[j][3]; // L
                                            a[n][4] = a[k][0]+a[j][4]; // C
                                            a[n][5] = a[k][1]; // D
                                            a[n][6] = a[k][2]; //M
                                         }
                else{ //1900 -> XMM
                                            int k=n/1000;
                                            int j=n%1000;
                                            a[n][0] = a[j][0]; // I
                                            a[n][1] = a[j][1]; // V
                                            a[n][2] = a[j][2]; // X
                                            a[n][3] = a[j][3]; // L
                                            a[n][4] = a[j][4]; // C
                                            a[n][5] = a[j][5]; // D
                                            a[n][6] = a[k][0]+a[j][6]; //M
                }
                                ans[0]+=a[n][0]; // I
                                ans[1]+=a[n][1]; // V
                                ans[2]+=a[n][2]; // X
                                ans[3]+=a[n][3]; // L
                                ans[4]+=a[n][4]; // C
                                ans[5]+=a[n][5]; // D
                                ans[6]+=a[n][6]; //M
               }
int main(){
    ifstream fin ("preface.in");
    ofstream fout ("preface.out");
    int n;
    fin >> n;
    for(int i=1;i<=n;i++){ func(i);}
    for(int i=0;i<7;i++){ if(ans[i]==0)break;
                          else{
                                    if(i==0)fout << "I " << ans[i] << endl;
                                    else if(i==1)fout << "V " << ans[i] << endl;
                                    else if(i==2)fout << "X " << ans[i] << endl;
                                    else if(i==3)fout << "L " << ans[i] << endl;
                                    else if(i==4)fout << "C " << ans[i] << endl;
                                    else if(i==5)fout << "D " << ans[i] << endl;
                                    else if(i==6)fout << "M " << ans[i] << endl;

                              }
                        }
        return 0;
}
