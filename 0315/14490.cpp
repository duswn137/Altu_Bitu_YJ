//
// Created by 고연주 on 2022/03/21.
//


#include <iostream>

using namespace std;
int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int main(){
    string input;
    cin>>input;

    int n=0, m=0;
    for (int i =0; i<input.length(); i++){
        if (input[i]==':'){
            string temp=input.substr(0,i);
            n=stoi(temp);
            temp=input.substr(i+1, input.length());
            m=stoi(temp);
            break;
        }
    }
    int g=gcd(n,m);
    n/=g;
    m/=g;
    cout<<n<<":"<<m<<"\n";

}