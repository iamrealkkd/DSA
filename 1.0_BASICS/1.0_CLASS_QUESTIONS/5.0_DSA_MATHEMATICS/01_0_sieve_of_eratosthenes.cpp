#include <iostream>
#include <vector>
using namespace std;

// Function to check if a single number is prime
bool isPrime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

// Sieve of Eratosthenes to find all primes up to n
void sieve(int n) {

    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; i++) {

        if (prime[i]) {

            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }

        }
    }

    cout << "Prime numbers up to " << n << " are:\n";

    for (int i = 2; i <= n; i++) {
        if (prime[i])
            cout << i << " ";
    }

    cout << endl;
}

int main() {

    int n;

    cout << "Enter a number: ";
    cin >> n;

    // Check if single number is prime
    if (isPrime(n))
        cout << n << " is a Prime Number\n";
    else
        cout << n << " is NOT a Prime Number\n";

    cout << endl;

    // Print primes up to n using sieve
    sieve(n);

    return 0;
}