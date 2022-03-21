//
// Created by 고연주 on 2022/03/21.
//

#include <iostream>
#include <cmath>
using namespace std;

//소수인지 검사
bool isPrime(int p){
    for (int i =2; i< sqrt(p); i++){
        if (p%i==0)
            return false;
    }
    return true;
}


int main(){
    int num=0;
    int a, b;
    for(int i=1; i<num/2; i++){
        a = 2 * i + 1;
        b = num - a;
        if(isPrime(a) and isPrime(b)){
            cout<<a<<" + "<<b<<'\n';
            break;
        }
        else
            cout<<"Goldbach's conjecture is wrong.";
    }

}