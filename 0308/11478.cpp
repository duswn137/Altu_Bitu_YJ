//
// Created by 고연주 on 2022/03/14.
//

#include <iostream>
#include <set>

using namespace std;

int main(){
    string input;
    cin>>input;

    set<string> s;

    int len=input.size();
    for (int i = 0; i < len; i++) {
        for (int j = 1; j<=len-i; j++) {
            string sub=input.substr(i, j);
            s.insert(sub);

        }
    }
    cout<<s.size()<<'\n';
}