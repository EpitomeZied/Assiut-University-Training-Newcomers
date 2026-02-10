# 📘 Sheet #7: Recursion

[⬅️ Back to Main](../README.md) | [➡️ Next: Sheet #8](../11%20Sheet%20%238%20(General%20easy)/README.md)

## 📋 Overview

Master recursive thinking:
- Recursion basics
- Base cases and recursive cases
- Divide and conquer
- Backtracking introduction
- Dynamic programming basics

**Total Problems:** 26  
**Difficulty:** ⭐⭐ Medium to ⭐⭐⭐ Hard  
**Estimated Time:** 10-12 hours

## 🎯 Learning Objectives

- ✅ Think recursively
- ✅ Identify base cases
- ✅ Implement recursive solutions
- ✅ Optimize with memoization
- ✅ Solve backtracking problems

## 📊 Key Problems

| Problem | Title | Topics | Difficulty |
|---------|-------|--------|------------|
| A | Print Recursion | Basics | ⭐ Easy |
| J | Factorial | Classic | ⭐ Easy |
| K | Max Number | Array Recursion | ⭐⭐ Medium |
| O | Fibonacci | Sequences | ⭐⭐ Medium |
| T | Combination | Combinatorics | ⭐⭐⭐ Hard |
| U | Knapsack | DP | ⭐⭐⭐ Hard |
| V | Creating Expression 1 | Backtracking | ⭐⭐⭐ Hard |
| X | The Maximum Path-Sum | DP/Grid | ⭐⭐⭐ Hard |
| Y | Number of Ways | Combinatorics | ⭐⭐⭐ Hard |
| Z | Left Max | Array Processing | ⭐⭐⭐ Hard |

## 💡 Key Concepts

### Recursion Structure
```cpp
return_type function(parameters) {
    // Base case - stopping condition
    if (base_condition) {
        return base_value;
    }
    
    // Recursive case - call function with smaller problem
    return some_operation(function(smaller_problem));
}
```

### Classic Examples

**Factorial:**
```cpp
long long factorial(int n) {
    if (n <= 1) return 1;  // Base case
    return n * factorial(n - 1);  // Recursive case
}
```

**Fibonacci:**
```cpp
int fibonacci(int n) {
    if (n <= 1) return n;  // Base cases
    return fibonacci(n-1) + fibonacci(n-2);
}

// Optimized with memoization
int memo[100];
int fib(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fib(n-1) + fib(n-2);
}
```

**Print 1 to N:**
```cpp
void print1ToN(int n) {
    if (n == 0) return;  // Base case
    print1ToN(n - 1);    // Recursive call
    cout << n << " ";    // Print after recursion
}
```

**Print N to 1:**
```cpp
void printNTo1(int n) {
    if (n == 0) return;  // Base case
    cout << n << " ";    // Print before recursion
    printNTo1(n - 1);    // Recursive call
}
```

**Array Maximum:**
```cpp
int arrayMax(int arr[], int n) {
    if (n == 1) return arr[0];  // Base case
    return max(arr[n-1], arrayMax(arr, n-1));
}
```

**Power Function:**
```cpp
long long power(long long a, long long b) {
    if (b == 0) return 1;  // Base case
    if (b % 2 == 0) {
        long long half = power(a, b/2);
        return half * half;
    }
    return a * power(a, b-1);
}
```

### Backtracking Pattern
```cpp
void backtrack(parameters) {
    if (found_solution) {
        process_solution();
        return;
    }
    
    for (each choice) {
        make_choice();
        backtrack(new_parameters);
        unmake_choice();  // Backtrack
    }
}
```

**Example: Generate All Expressions**
```cpp
void generateExpressions(int arr[], int n, int i, 
                         long long current, int target) {
    if (i == n) {
        if (current == target) {
            // Found valid expression
        }
        return;
    }
    
    // Try addition
    generateExpressions(arr, n, i+1, current + arr[i], target);
    // Try subtraction
    generateExpressions(arr, n, i+1, current - arr[i], target);
    // Try multiplication
    generateExpressions(arr, n, i+1, current * arr[i], target);
}
```

### Dynamic Programming with Recursion

**Knapsack Problem:**
```cpp
int knapsack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0) return 0;
    
    if (wt[n-1] > W) {
        return knapsack(W, wt, val, n-1);
    }
    
    // Either include or exclude
    int include = val[n-1] + knapsack(W - wt[n-1], wt, val, n-1);
    int exclude = knapsack(W, wt, val, n-1);
    
    return max(include, exclude);
}
```

## 🎓 Study Tips

1. **Draw recursion tree** - Visualize the calls
2. **Identify base case** - What stops the recursion?
3. **Think smaller** - How to solve for n-1?
4. **Trust the recursion** - Don't trace every call
5. **Optimize when needed** - Use memoization

### Debugging Recursion
```cpp
void debug(int depth, string message) {
    for (int i = 0; i < depth; i++) cout << "  ";
    cout << message << endl;
}

int factorial(int n, int depth = 0) {
    debug(depth, "factorial(" + to_string(n) + ")");
    if (n <= 1) return 1;
    int result = n * factorial(n-1, depth+1);
    debug(depth, "returning " + to_string(result));
    return result;
}
```

## ⚠️ Common Mistakes

- **Missing base case** - Causes infinite recursion
- **Wrong base case** - Returns incorrect value
- **Stack overflow** - Too many recursive calls
- **Not returning value** - Forgot return statement
- **Modifying global state** - Can cause bugs in backtracking

### Stack Overflow Prevention
```cpp
// Bad - can cause stack overflow for large n
int sum(int n) {
    if (n == 0) return 0;
    return n + sum(n-1);
}

// Better - use iteration for simple cases
int sum(int n) {
    return n * (n + 1) / 2;  // Formula
}

// Or tail recursion (compiler optimization)
int sumTail(int n, int acc = 0) {
    if (n == 0) return acc;
    return sumTail(n-1, acc + n);
}
```

## 🏆 Challenge Problems

These require deep recursive thinking:

- **Problem U (Knapsack)** - Classic DP problem
- **Problem V (Creating Expression)** - Backtracking with operators
- **Problem X (Maximum Path-Sum)** - Grid DP
- **Problem Y (Number of Ways)** - Counting paths
- **Problem Z (Left Max)** - Array processing with recursion

## 📚 Resources

- [Recursion Tutorial](https://www.geeksforgeeks.org/recursion/)
- [Backtracking](https://www.geeksforgeeks.org/backtracking-algorithms/)
- [Dynamic Programming](https://www.geeksforgeeks.org/dynamic-programming/)

---

**Happy Coding! 🚀**
