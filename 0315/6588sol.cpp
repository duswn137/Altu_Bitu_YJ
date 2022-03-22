//
// Created by 고연주 on 2022/03/22.
//

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 1e6;                   //  문제에서 설정한 입력받는 값의 상한

//에라토스테네스의 체, 미리 SIZE까지의 소수 판단
vector<bool> isPrime() {                //소수인지 판단에서 배열에 저장
    vector<bool> is_prime(SIZE + 1, true); //소수 판단 여부 저장

    is_prime[0] = is_prime[1] = false;      //  0과 1은 소수가 아니라서 false로 저장
    for (int i = 2; i * i <= SIZE; i++) {       //소수인지 판단할때 루트값까지만 계산해주면 되니까 i*i 사용
        if (!is_prime[i]) { //소수가 아니라면
            continue;
        }
        //i가 소수라면
        for (int j = i * i; j <= SIZE; j += i) {        //i*i부터 i의 값만큼 증가시켜주면 i의 배수를 제거할 수 있다
            is_prime[j] = false; //i의 배수 제거
        }
    }
    return is_prime;                        //배열 리턴
}

//골드바흐의 추측 판단 함수
int checkGoldbach(int n, vector<bool> &is_prime) {
    for (int i = 3; i <= n / 2; i += 2) { //홀수만 검사, n/2 이상의 값은 어차피 n-i를 통해 검사되므로 n/2까지 검사
        if (is_prime[i] && is_prime[n - i]) { //두 홀수 모두 소수라면 (골드바흐의 추측이 맞은 경우)
            return i; //두 홀수 소수 중 작은 값 리턴
        }
    }
    return 0; //골드바흐의 추측이 틀린 경우
}

/**
 * "골드바흐의 추측"
 * 4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다. -> 이를 증명하는 문제
 * -> 에라토스테네스의 체를 활용하여 미리 SIZE 까지의 소수 판별
 * -> 두 홀수 소수의 합으로 나타낼 수 있는지 판단
 */

int main() {                                            //  메인함수
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;                                          //입력받을 숫자 선언하기
    vector<bool> is_prime = isPrime(); //소수 판단 여부 저장

    while (true) {                                   // 반복문
        //입력
        cin >> n;                                   //  입력받기
        if (n == 0)
            break;

        //연산
        int prime = checkGoldbach(n, is_prime); //골드바흐의 추측이 맞는지 체크
        if (prime) //맞다면 -> 두 홀수 소수 중 작은 값 리턴받은 경우
            cout << n << " = " << prime << " + " << n - prime << '\n';
        else //틀리다면 -> 0 리턴받은 경우
            cout << "Goldbach's conjecture is wrong.\n";

    }

    return 0;
}