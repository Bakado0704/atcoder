// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ull = unsigned long long;
const double PI = acos(-1);
template <class T>
void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

int main() {
  long long N;
  cin >> N;

  if (N <= 999) {
    cout << N << endl;
  } else if (N <= 9999) {
    int four = N / 1000;
    int three = (N % 1000) / 100;
    int two = ((N % 1000) % 100) / 10;
    cout << four << three << two << 0 << endl;
  } else if (N <= 99999) {
    int five = N / 10000;
    int four = (N % 10000) / 1000;
    int three = ((N % 10000) % 1000) / 100;
    cout << five << four << three << 0 << 0 << endl;
  } else if (N <= 999999) {
    int six = N / 100000;
    int five = (N % 100000) / 10000;
    int four = ((N % 100000) % 10000) / 1000;
    cout << six << five << four << 0 << 0 << 0 << endl;
  } else if (N <= 9999999) {
    int seven = N / 1000000;
    int six = (N % 1000000) / 100000;
    int five = ((N % 1000000) % 100000) / 10000;
    cout << seven << six << five << 0 << 0 << 0 << 0 << endl;
  } else if (N <= 99999999) {
    int eight = N / 10000000;
    int seven = (N % 10000000) / 1000000;
    int six = ((N % 10000000) % 1000000) / 100000;
    cout << eight << seven << six << 0 << 0 << 0 << 0 << 0 << endl;
  } else if (N <= 999999999) {
    int eight = N / 100000000;
    int seven = (N % 100000000) / 10000000;
    int six = ((N % 100000000) % 10000000) / 1000000;
    cout << eight << seven << six << 0 << 0 << 0 << 0 << 0 << 0 << endl;
  }
}