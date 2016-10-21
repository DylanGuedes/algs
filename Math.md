# Matemática

## 1. Gerador de primos
```C++
int that = 31632;
vector<bool> is_prime(32000, true);
is_prime[0] = false;
is_prime[1] = false;
primes.push_back(2);

for (int i=3; i<=that; i+=2) {
          if (is_prime[i] == true) {
                  int thatidx = that/i;
                  FOR(j, i, thatidx+1) {
                          is_prime[i*j] = false;
                  }
                  primes.push_back(i);
          }
}
```
