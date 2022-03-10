//
// Created by 고연주 on 2022/03/10.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, a, b;
    int sum=0;
    vector<int> arr_A;
    vector<int> arr_B;
    vector<int> arr_index;

    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>a;
        arr_A.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        cin>>b;
        arr_B.push_back(b);
    }
    sort(arr_A.begin(),arr_A.end())

}