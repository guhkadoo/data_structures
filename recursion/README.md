# Recursion

**Recursion** is a technique where a function calls itself to solve a problem. It is widely used in algorithms like **divide and conquer**, **backtracking**, and **dynamic programming**.

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

5. **Recursive Chain**
   - A recursive function need not to call itself directly. Rather, it may call itself indirectly. As in the following example:
   ```c
   a(formal parameters)
   {
       .
       .
       .
       b(arguments)
       .
   } /*end a*/

   b(formal parameters)
   {
       .
       .
       .
       a(arguments)
       .
   } /*end b*/
   ```
   In this example function a calls b, which may in turn call a, which may again call b. Thus both a and b are
   recursive, since they indirectly call on themselves.
   More than two routines may participate in a recursive chain.

   - Recursive Definition of Algebraic Expressions
   As an example of a recursive chain, consider the following group of definitions:
   1. An **expression** is a term followed by a plus sign followed by a term, or a term alone.
   2. A **term** is a factor followed by an asterisk followed by a factor, or a factor alone.
   3. A **factor** is either a letter or an expression enclosed in parentheses.

   The program **recursive_chain.c** reads a string and then prints "valid" if it is a valid expression and "invalid" if
   it is not.
   The three routines expr, term and factor are recursive, since each may call itself indirectly.

   E.g: "(a*b+c*d)+(e*(f)+g)"

### 🚧 Yet to be Implemented:
- **Tower of Hanoi** (Classic recursion problem).
- **Backtracking Algorithms** (e.g., N-Queens, Sudoku Solver).
