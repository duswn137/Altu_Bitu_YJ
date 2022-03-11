//
// Created by 고연주 on 2022/03/10.
//

#include <iostream>

int main(){
    using namespace std;
    int h,m,s,now;

    cin>> h>>m>>s;
    now=h*3600+60*m+s;


    cout<<now/3600<<" "<<now<<'\n';
}