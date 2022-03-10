//
// Created by 고연주 on 2022/03/10.
//

#include <iostream>
using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int h, m, s, q, now, t, c;

    cin >> h>>m>>s>>q;
    now=3600*h+60*m+s;
    for (int i=0; i<q; i++){
        cin >> t;
        if (t==3)
            cout << now / 3600 << " " << (now / 60)%60 << " " << now % 60 << '\n';
        else if (t == 1) {
            cin >> c;
            now = (now + c) % 86400;
        } else {
            cin >> c;
            now=(now-c)%86400;
            if (now<0){
                now+=86400;
            }
        }
    }
}