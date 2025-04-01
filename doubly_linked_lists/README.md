# Doubly Linked Lists in C

## 📘 What Is a Doubly Linked List?

A **doubly linked list** is a type of linked data structure where each node contains **three parts**:
1. A pointer to the **previous node**
2. A **data value**
3. A pointer to the **next node**

This structure allows you to **traverse the list in both directions** — forward and backward —
which is not possible with a singly linked list.

### 📊 Visual Example:

/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * 
 */
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;
