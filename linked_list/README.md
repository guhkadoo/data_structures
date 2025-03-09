# Linked List

A **Linked List** is a linear data structure where elements are stored in nodes, and each node contains a reference (or link) to the next node in the sequence. Linked lists allow efficient insertion and deletion operations, particularly when dealing with dynamic data sizes.

### **Types of Linked Lists**

The directory includes the implementation of different types of linked lists:

#### 1. **Singly Linked List**
- In a **Singly Linked List**, each node has a reference to the next node, and the last node points to `NULL`.
- Operations like insertion, deletion, and traversal are performed in O(n) time complexity.

#### 2. **Doubly Linked List**
- A **Doubly Linked List** allows traversal in both directions (forward and backward). Each node has two references: one pointing to the next node and one pointing to the previous node.
- It is useful when frequent back-and-forth traversal is needed.

#### 3. **Circular Linked List**
- A **Circular Linked List** is similar to a singly linked list, but the last node points back to the first node instead of `NULL`.
- This structure is particularly useful in applications where data needs to be continuously accessed in a circular fashion.

## 📝 To-Do List

- [ ] Implement Doubly Linked List
- [ ] Implement Circular Linked List
- [ ] Refactor Singly Linked List
