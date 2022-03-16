//
// Created by 고연주 on 2022/03/14.
//

#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m;
    cin>>t;
    for (int i = 0; i < t; i++) {
        cin>>n;
        unordered_map<int, int> memo;
        for (int j = 0; j < n; j++) {
            int num;
            cin>> num;
            memo[num]=1;
        }
        cin>>m;
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            if(memo[num]==1)
                cout<<"1\n";
            else
                cout<<"0\n";
        }
    }
    return 0;
}