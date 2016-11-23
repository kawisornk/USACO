/*
ID: gateaux1
PROG: runround
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;
int intlength(long m){
int k=10,i=1;
while(k<m){
    i++;
    k*=10;
}
return i;
}
int position(int m,int i){ // least bit = position 1
while(i>0){m=m/10;
i--;}
return m%10;
}
bool unique(long m){
int digit[10]={0};
int k;
while(m>0){
    k = m%10;
    if(digit[k]==1 || k==0)return false;
    digit[k]=1;
    m = (m-k)/10;

}
return true;
}

bool check(long m){
     if(!unique(m))return false;
     int j = intlength(m);
     int num[10]={0},visit[10]={0},l=0;
     int k=0;
     for(int i=0;i<j;i++){ num[i]=position(m,j-1-i);}
     while(visit[l]==0){  visit[l]=1;
                          l=(l+num[l])%j;
                          k++;
     }
if(k==j && l==0)return true;
else return false;
}

int main(){
ifstream fin("runround.in");
ofstream fout("runround.out");

long m;
fin >> m;
m++;
while(!check(m))m++;
fout << m << endl;
}
