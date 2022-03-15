//
// Created by 고연주 on 2022/03/14.
//


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
vector<string> v;
map<string, int> m;
map<string, int>::iterator iter;

int main() {
    int n;
    string input;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input.substr(( input.rfind('.')+1)));
    }
    sort(v.begin(), v.end());

    string name = v[0];
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (name == v[i])
            count++;
        else if (name != v[i]) {
            m[name] = count;
            name = v[i];
            count = 1;
        }
    }

    //출력
    for (iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->first << " " << iter->second << '\n';
    }


}