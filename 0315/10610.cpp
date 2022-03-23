//
// Created by 고연주 on 2022/03/21.
//


#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string N;
    cin >> N;

    int sum=0;

    for (int i =0 ; i<N.length(); i++){
        sum+=N[i]-'0';           //  문자열>정수형 변환
    }
    sort(N.begin(), N.end(), greater<>());

    if(N[N.length()-1]!='0' || sum%3!=0)
        cout<<-1;
    else
        cout<<N;





}