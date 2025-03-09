# Pattern Searching

Pattern searching (or string matching) algorithms are used to find occurrences of a pattern within a larger text. These algorithms are widely used in text processing, search engines, bioinformatics, and data compression.

### ✅ Implemented:
1. **Naive Substring Matching**  
   - A straightforward approach that slides the pattern over the text and checks for a match at every position.  
   - **Time Complexity:** O((N - M + 1) * M) in the worst case.  
   - **Pros:** Simple to implement.  
   - **Cons:** Inefficient for large texts and patterns.

2. **Rabin-Karp Algorithm**  
   - Uses a rolling hash function to find patterns efficiently.  
   - **Time Complexity:** O(N + M) on average, but **O(NM)** in the worst case.  
   - **Pros:** Fast in practice when using a good hash function.  
   - **Cons:** Hash collisions can degrade performance.

### 🚧 Yet to be Implemented:
3. **Knuth-Morris-Pratt (KMP) Algorithm**  
   - Preprocesses the pattern to avoid unnecessary comparisons.  
   - **Time Complexity:** O(N + M).  
   - **Pros:** Efficient for multiple searches of the same pattern.  

4. **Boyer-Moore Algorithm**  
   - Skips unnecessary comparisons using two heuristics (Bad Character & Good Suffix).  
   - **Time Complexity:** O(N/M) on average, but **O(NM) worst case**.  
   - **Pros:** One of the fastest practical string matching algorithms.  

5. **Aho-Corasick Algorithm**  
   - Builds a finite automaton for multiple pattern searches at once.  
   - **Time Complexity:** O(N + total pattern length).  
   - **Pros:** Very efficient for multiple pattern searches.  
