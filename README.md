# Push Swap - Sorting Algorithm Challenge 📊

Welcome to my **Push Swap** project! This project is all about creating an efficient algorithm to sort data on a stack using a limited set of operations. It’s a fun and challenging exercise in algorithm design and optimization.

## 📖 Project Overview
The **Push Swap** project at **École 42** requires implementing a program that sorts integers using two stacks (referred to as `a` and `b`). The goal is to sort the stack `a` with the fewest operations possible, utilizing only a restricted set of commands:

- **sa**: Swap the first two elements on stack `a`.
- **sb**: Swap the first two elements on stack `b`.
- **ss**: Perform both `sa` and `sb` simultaneously.
- **pa**: Push the top element from stack `b` to stack `a`.
- **pb**: Push the top element from stack `a` to stack `b`.
- **ra**: Rotate stack `a` (shift all elements up by one).
- **rb**: Rotate stack `b` (shift all elements up by one).
- **rr**: Perform both `ra` and `rb` simultaneously.
- **rra**: Reverse rotate stack `a` (shift all elements down by one).
- **rrb**: Reverse rotate stack `b` (shift all elements down by one).
- **rrr**: Perform both `rra` and `rrb` simultaneously.

## 🔄 Sorting Algorithm: Radix Sort
To achieve efficient sorting, I implemented **Radix Sort**. Radix Sort is particularly effective for this project because it has a time complexity of **O(n log n)** and requires minimal stack operations. Here's how it works in the context of Push Swap:

1. **Binary Representation**: The integers are sorted based on their binary representation. Each bit in the binary form of the numbers is evaluated from the least significant bit (LSB) to the most significant bit (MSB).
2. **Bitwise Sorting**: For each bit position, numbers are either pushed to stack `b` or left in stack `a` based on whether that bit is 0 or 1.
3. **Reassembling**: After sorting based on each bit, the numbers are returned to stack `a` in the correct order, repeating the process for the next bit until the entire sequence is sorted.

This method is both effective and minimizes the number of operations, allowing Push Swap to handle larger numbers within the operation limit.

## 📝 Compilation & Usage
To compile the project, run:
```bash
make
```
This will generate the `push_swap` executable. You can then test the sorting algorithm on a set of integers:
```bash
./push_swap [list of integers]
```

## 📈 Learning Outcomes
Through the Push Swap project, I honed my understanding of stack manipulation, algorithm optimization, and bitwise operations. Implementing radix sort and adapting it for limited stack operations was both challenging and rewarding.

## 🔗 Connect with Me
If you’re interested in discussing this project or have any suggestions, feel free to connect with me on [LinkedIn](https://www.linkedin.com/in/sonam-crumiere/).

Happy sorting!
