# 📘 Sheet #6: Math & Geometry

[⬅️ Back to Main](../README.md) | [➡️ Next: Sheet #7](../10%20Sheet%20%237%20(Recursion)/README.md)

## 📋 Overview

Mathematical and geometric problem solving:
- Number theory (primes, GCD, LCM)
- Modular arithmetic
- Matrix operations
- Combinatorics
- Basic geometry

**Total Problems:** 14  
**Difficulty:** ⭐⭐ Medium to ⭐⭐⭐ Hard  
**Estimated Time:** 6-8 hours

## 🎯 Learning Objectives

- ✅ Solve number theory problems
- ✅ Work with large numbers
- ✅ Implement mathematical algorithms
- ✅ Handle geometric calculations
- ✅ Master modular arithmetic

## 📊 Key Problems

| Problem | Title | Topics | Difficulty |
|---------|-------|--------|------------|
| A | Power Of Two | Powers | ⭐⭐ Medium |
| B | Prime Checking | Primes | ⭐⭐ Medium |
| D | XOR | Bitwise | ⭐⭐ Medium |
| F | Multiplication of Matrices | Linear Algebra | ⭐⭐⭐ Hard |
| G | Summation of Divisors | Number Theory | ⭐⭐ Medium |
| H | GCD | Euclidean Algorithm | ⭐⭐ Medium |
| K | Combination and Permutation | Combinatorics | ⭐⭐⭐ Hard |
| L | Pascal Triangle | DP | ⭐⭐⭐ Hard |
| R | Distance Points | Geometry | ⭐⭐ Medium |

## 💡 Key Concepts

### Fast Exponentiation
```cpp
long long power(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
```

### GCD (Euclidean Algorithm)
```cpp
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}
```

### Prime Factorization
```cpp
vector<int> primeFactors(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}
```

### Combinatorics
```cpp
// nCr = n! / (r! * (n-r)!)
long long nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    
    long long result = 1;
    for (int i = 0; i < r; i++) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}
```

### Matrix Multiplication
```cpp
void multiplyMatrix(int A[][MAX], int B[][MAX], int C[][MAX], 
                    int n, int m, int p) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
```

### Distance Between Points
```cpp
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
```

## 🎓 Study Tips

1. **Learn algorithms** - Don't brute force everything
2. **Handle overflow** - Use long long for large numbers
3. **Use modulo** - For very large results
4. **Practice geometry** - Draw diagrams
5. **Understand formulas** - Derive them yourself

## ⚠️ Common Mistakes

- Integer overflow in multiplication
- Division before multiplication in nCr
- Not handling modulo correctly
- Floating point precision errors
- Wrong matrix multiplication order

## 📚 Resources

- [CP-Algorithms Math](https://cp-algorithms.com/algebra/fundamentals.html)
- [Number Theory](https://www.geeksforgeeks.org/number-theory-competitive-programming/)

---

**Happy Coding! 🚀**
