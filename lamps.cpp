/*
ID: gateaux1
PROG: lamps
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<utility>
#include<sstream>

using namespace std;

ifstream fin ("lamps.in");
ofstream fout ("lamps.out");

int lamp[10001]={0};
int flag=0;

int check(int c1,int c2,int c3,int c4,int N){ stringstream os;
for(int i=1;i<=N;i++){
                        if(i%3 == 1){
                                        if(i%2==0){
                                                    if(lamp[i]!=0 && (c1+c3+c4+1)%2 != lamp[i]%2)return 0; // 1 3 4
                                                    else{ os << (c1 + c3 + c4+1)%2;}
                                                    }
                                        else{ if(lamp[i]!=0 && (c1 + c2 + c4+1)%2 != lamp[i]%2)return 0;
                                              else{ os << (c1 + c2 + c4+1)%2;}
                                            } // 1 2 4
                                    }
                       else{
                            if(i%2==0){
                                                    if(lamp[i]!=0 && (c1 + c3+1)%2 != lamp[i]%2)return 0; // 1 3
                                                    else{ os << (c1 + c3+1)%2;}
                                                    }
                            else{ if(lamp[i]!=0 && (c1 + c2+1)%2 != lamp[i]%2)return 0;
                                  else{ os << (c1 + c2+1)%2;}
                                } // 1 2
                       }

}
fout << os.str() << endl;
flag =1;
return 0;
}
int main(){

int N,C;
fin >> N >> C;
int k=0;
do{ fin >> k;
    if(k!=-1)lamp[k]=1; //on = 1
  }while(k!=-1);
do{ fin >> k;
    if(k!=-1)lamp[k]=2; //off = 2
  }while(k!=-1);
if(C>=1 && C%2==1)check(1,0,0,0,N); //1 0000
if(C>=2 && C%2==0)check(0,1,1,0,N); //6 0000
if(C>=3 && C%2==1)check(1,1,0,1,N); //11 0011
if(C>=2 && C%2==0)check(0,0,1,1,N); //12 0011
if(C>=2 && C%2==0)check(1,0,1,0,N); //5 0101
if(C>=1 && C%2==1)check(0,1,0,0,N); //2 0101
if(C>=1 && C%2==1)check(0,0,0,1,N); //8 0110
if(C>=4 && C%2==0)check(1,1,1,1,N); //15 0110
if(C>=3 && C%2==1)check(0,1,1,1,N);  //14 1001
if(C>=2 && C%2==0)check(1,0,0,1,N); //9 1001
if(C>=1 && C%2==1)check(0,0,1,0,N); //4 1010
if(C>=2 && C%2==0)check(1,1,0,0,N); //3 1010
if(C>=2 && C%2==0)check(0,1,0,1,N); //10 1100
if(C>=3 && C%2==1)check(1,0,1,1,N); //13 1100
if(C>=3 && C%2==1)check(1,1,1,0,N); //7 1111
check(0,0,0,0,N); //0 1111
if(flag==0)fout << "IMPOSSIBLE" << endl;
return 0;
}
