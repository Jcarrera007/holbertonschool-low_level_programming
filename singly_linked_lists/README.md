# Linked Lists in C

## 📘 Overview

This project demonstrates how to build and use **singly linked lists** in C.
 It covers the structure of a linked list, how to traverse and print its contents,
 and explains when and why you'd choose a **linked list** over an **array**.

---

## 🧠 When and Why to Use Linked Lists vs Arrays

### ✅ Use **Linked Lists** when:
- You need **dynamic memory allocation** (the list can grow or shrink as needed).
- You're doing frequent **insertions or deletions**, especially in the middle or beginning of the list.
- Memory is fragmented, and you can't allocate large contiguous blocks (which arrays require).

### ⚠️ Use **Arrays** when:
- You need **random access** to elements by index (arrays allow O(1) access).
- The size of the data is known and won't change much.
- You want **better cache locality** (arrays store elements contiguously in memory).

| Feature                  | Linked List | Array     |
|--------------------------|-------------|-----------|
| Dynamic resizing         | ✅           | ❌ (unless realloc) |
| Fast random access       | ❌           | ✅         |
| Fast insert/delete       | ✅           | ❌         |
| Memory usage             | More (extra pointer per node) | Less        |
| Cache efficiency         | ❌           | ✅         |

---

## 🔨 How to Build and Use a Linked List in C

### 1. Define the Node Structure

```c
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;
