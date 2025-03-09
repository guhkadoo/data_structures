# Recursion

**Recursion** is a technique where a function calls itself to solve a problem. It is widely used in algorithms like **divide and conquer**, **backtracking**, and **dynamic programming**.


## 🔄 Implemented Recursive Algorithms

### ✅ Implemented:
1. **Binary Search**
   - Searches for an element in a sorted array using the **divide and conquer** approach.
   - **Time Complexity:** O(log N).
   - **Pros:** Efficient for large sorted datasets.

2. **Factorial Calculation**
   - Computes `n! = n × (n-1) × ... × 1` recursively.
   - **Time Complexity:** O(N).
   - **Pros:** Simple mathematical implementation.

3. **Fibonacci Sequence**
   - Computes Fibonacci numbers where `F(n) = F(n-1) + F(n-2)`.
   - **Time Complexity:** O(2^N) (can be optimized using memoization).
   - **Cons:** Exponential time complexity without optimization.

4. **Peak Finding Algorithm**
   - Finds a peak element in an array where `arr[i]` is greater than or equal to its neighbors.
   - **Time Complexity:** O(log N).
   - **Pros:** Efficient for large datasets.

### 🚧 Yet to be Implemented:
- **Tower of Hanoi** (Classic recursion problem).
- **Backtracking Algorithms** (e.g., N-Queens, Sudoku Solver).
