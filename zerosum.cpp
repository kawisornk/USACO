/*
ID: gateaux1
PROG: zerosum
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

ifstream fin ("zerosum.in");
ofstream fout ("zerosum.out");

char a[10]={'0','1','2','3','4','5','6','7','8','9'};
void func(int next,int sum, int sign,int acc, string str,int N){
    if(next==N+1){
                if((sum + sign*acc) == 0){ fout << str << endl; return;}
                }
    else{
            func(next+1,sum,sign,acc*10+next,str+" "+a[next],N);
            func(next+1,sum+sign*acc,1,next,str+"+"+a[next],N);
            func(next+1,sum+sign*acc,-1,next,str+"-"+a[next],N);
    }
}

int main(){
int N;
fin >> N;
func(2,0,1,1,"1",N);
}
