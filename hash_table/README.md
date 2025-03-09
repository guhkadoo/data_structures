# Hash Table

A **hash table** (or hash map) is a data structure that provides efficient **key-value pair** storage. It allows for **constant-time complexity** (O(1)) for insertion, deletion, and lookup operations under ideal conditions. Hash tables are widely used for fast access to data and serve as the foundation for many applications like caches, databases, and symbol tables.

### **Hash Table Techniques**

There are two main techniques for resolving hash collisions in hash tables:

#### 1. **Chaining**

- **Chaining** resolves hash collisions by storing multiple elements that hash to the same index in a **linked list** (or another data structure like a tree or array).
- Each bucket in the hash table is a linked list that contains all the elements that hash to the same index.
  
##### **Advantages of Chaining:**
- Efficient handling of collisions.
- The hash table can grow dynamically, as linked lists can grow without pre-allocation.
- Simple implementation and understanding.

##### **Disadvantages of Chaining:**
- Requires additional memory for pointers in the linked lists.
- Lookup time can degrade if many elements hash to the same index.

#### 2. **Open Addressing**

- **Open addressing** resolves hash collisions by finding another open slot within the hash table itself (i.e., no linked lists are used).
- When a collision occurs, the algorithm probes for the next available slot, using techniques such as:
  - **Linear Probing**: Check the next slot in sequence.
  - **Quadratic Probing**: Check slots with a quadratic distance.
  - **Double Hashing**: Use a second hash function to find the next slot.

##### **Advantages of Open Addressing:**
- More memory efficient as it does not require extra space for linked lists.
- All elements are stored within the hash table, making it better suited for cache-friendly operations.

##### **Disadvantages of Open Addressing:**
- More complex to implement and manage.
- The table can become congested, leading to inefficient probing and performance degradation.
- Deletion can be tricky, as it may leave empty slots that affect probing.
