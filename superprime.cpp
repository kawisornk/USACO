/*
ID: gateaux1
PROG: sprime
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;
ifstream fin ("sprime.in");
ofstream fout ("sprime.out");
bool isprime (long num)
{
    if (num <=1)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false;
    else
    {
        bool prime = true;
        int divisor = 3;
        double num_d = static_cast<double>(num);
        int upperLimit = static_cast<int>(sqrt(num_d) +1);

        while (divisor <= upperLimit)
        {
            if (num % divisor == 0)
                prime = false;
            divisor +=2;
        }
        return prime;
    }
}
int check(int p,int n){ if(n==0)fout << p << endl;
                        else{ for(int i=1;i<=9;i++){
                                                        if(isprime(p*10+i))check(p*10+i,n-1);
                                                    }
                            }
                      }
int main(){
int k;
fin >> k;
check(2,k-1);
check(3,k-1);
check(5,k-1);
check(7,k-1);
return 0;
}
