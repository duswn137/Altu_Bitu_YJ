//
// Created by 고연주 on 2022/03/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int ppl, tip;
    int sum=0;
    vector<int> arr;
    cin>>ppl;
    for (int i = 0; i < ppl; i++) {
        cin>>tip;
        arr.push_back(tip);
    }
    sort(arr.begin(), arr.end(), greater<int>());
    for (int i = 0; i < ppl; i++) {
        if(arr[i]-i<0)
            break;
        sum+=(arr[i]-i);
    }
    cout<<sum;

}