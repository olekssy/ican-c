#include "iostream"
#include <cstddef>
#include <cstdlib>

using namespace std;

constexpr uint64_t fibonacci(const int n);
uint64_t fibo_memo(int n, uint64_t memo[]);
constexpr uint64_t tribonacci(int n);
uint64_t tribo_memo(int n, uint64_t memo[]);

constexpr uint64_t fibonacci(const int n) {
  return n <= 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

uint64_t fibo_memo(int n, uint64_t memo[]) {
  if (n <= 2)
    return 1;
  if (memo[n] == 0) {
    memo[n] = fibo_memo(n - 1, memo) + fibo_memo(n - 2, memo);
  }
  return memo[n];
}

constexpr uint64_t tribonacci(int n) {
  if (n <= 2)
    return 1;
  if (n == 3)
    return 2;
  return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}

uint64_t tribo_memo(int n, uint64_t memo[]) {
  if (n <= 2)
    return 1;
  if (n == 3)
    return 2;
  if (memo[n] == 0) {
    memo[n] = tribo_memo(n - 1, memo) + tribo_memo(n - 2, memo) +
              tribo_memo(n - 3, memo);
  }
  return memo[n];
}

int main(int argc, char *argv[]) {
  const int N = 50;

  // Fibo with memoization
  uint64_t fib_memo[N] = {0};
  for (int n = 1; n < N; n++) {
    cout << "FiboMemo(" << n << ") = " << fibo_memo(n, fib_memo) << endl;
  }
  cout << endl;

  // Tribonacci with memo
  uint64_t trib_memo[N] = {0};
  for (int n = 1; n < N; n++) {
    cout << "TriboMemo(" << n << ") = " << tribo_memo(n, trib_memo) << endl;
  }
  cout << endl;

  // Fibo w/o memoization
  for (int n = 1; n < N; n++) {
    cout << "Fibo(" << n << ") = " << fibonacci(n) << endl;
  }
  cout << endl;

  // tribo w/o memoization
  for (int n = 1; n < N; n++) {
    cout << "Tribo(" << n << ") = " << tribonacci(n) << endl;
  }

  return EXIT_SUCCESS;
}
