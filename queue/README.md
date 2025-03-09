# Queue

A **Queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle. This means that elements are added at the back (enqueue) and removed from the front (dequeue). Queues are widely used in scheduling, buffering, and breadth-first search (BFS) algorithms.

## 🔄 Types of Queues

### ✅ Implemented:
1. **Simple Queue (FIFO)**
   - Basic queue with enqueue and dequeue operations.
   - **Time Complexity:** O(1) for both enqueue and dequeue.

### 🚧 Yet to be Implemented:
2. **Circular Queue**
   - Overcomes the limitation of a simple queue by connecting the last position back to the first, optimizing space usage.
   - **Time Complexity:** O(1) for enqueue and dequeue.

3. **Double-Ended Queue (Deque)**
   - Allows insertion and deletion from both ends.
   - **Time Complexity:** O(1) for insertions and deletions at both ends.

4. **Priority Queue**
   - Each element has a priority, and elements are dequeued based on priority rather than order.
   - **Time Complexity:** O(log N) with a heap implementation.
