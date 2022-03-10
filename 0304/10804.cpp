//
// Created by 고연주 on 2022/03/10.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> arr(21);
    int first, last;
    for (int i = 0; i < 21; i++)
        arr[i] = i;
    for (int i = 0; i < 10; i++) {  //  구간 개수
        cin>>first>> last;
        reverse(arr.begin() + first, arr.begin() + last + 1);
    }
    for (int i=1; i<21; i++)
        cout<<arr[i]<<' ';

    return 0;
}
