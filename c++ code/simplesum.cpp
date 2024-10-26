#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n) {
    if (n <= 2) return 0; // No primes less than 2

    vector<bool> isPrime(n, true); // Create a boolean array of size n
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false; // Mark multiples of i as non-prime
            }
        }
    }

    // Count primes
    int primeCount = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) primeCount++;
    }
    return primeCount;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = countPrimes(n);
    cout << "Number of prime numbers less than " << n << " is: " << result << endl;

    return 0;
}
