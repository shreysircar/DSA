#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Prime check in O(√n)
bool prime(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Factorization using prime() — overall O(√n log n)
vector<int> factorize(long long n) {
    vector<int> factors;
    for (long long i = 2; i * i <= n; i++) {
        if (prime(i)) { // O(√i) check
            while (n % i == 0) { // divides repeatedly
                factors.push_back((int)i);
                n /= i;
            }
        }
    }
    if (n > 1) factors.push_back((int)n); // remaining prime
    return factors;
}

int main(){
  vector<long long> arr = {10, 15, 60, 97, 100};

    cout << "Prime check results:\n";
    for (auto num : arr) {
        cout << num << ": " << (prime(num) ? "Prime" : "Not prime") << "\n";
    }

    cout << "\nPrime factorization :\n";
    for (auto num : arr) {
        auto factors = factorize(num);
        cout << num << " = ";
        for (size_t j = 0; j < factors.size(); j++) {
            cout << factors[j];
            if (j + 1 < factors.size()) cout << " * ";
        }
        cout << "\n";
    }

    return 0;
}

