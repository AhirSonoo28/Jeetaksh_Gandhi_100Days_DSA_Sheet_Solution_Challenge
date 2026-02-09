#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    // form equal to 2 or less than 2       there are no prime numbers
    if (n <= 2) return 0;
    // initializing a boolean vector to mark the prime numbers
    vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;
    // main logic to find the prime number using loop and marking the multiples of prime number as false
    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
        {
            for (int j = 2 * i; j < n; j += i)
                isPrime[j] = false;
        }
    }
    // couting the number of primes
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
            count++;
    }
    cout << count << endl;
    return 0;
}


//Leet code link :- https://leetcode.com/submissions/detail/1910434385/