# Josephus Problem Simulation in C++

## Description

This project implements the classic **Josephus Problem** using a **circular singly linked list** in C++.

Each soldier is represented as a node in the list, and the game eliminates every *k-th soldier* until only one remains. The program prints the **winner's ID** at the end.

The solution emphasizes:

- Dynamic memory management with proper destructor
- Circular linked list operations (add, traverse, delete)
- Clean and readable code with English comments

---

## Features

- Add `n` soldiers to a circular linked list
- Simulate the Josephus elimination process
- Print the winner
- Optional debug function to display the list (`printList()`)

---

## Notes

- The `printList()` function is for **debugging purposes only**; not required for game logic.
- Memory is properly managed in the destructor to avoid leaks.
- The program is fully commented in English for clarity.

---

## Example


-----------Problem of Josephus-----------
Enter the number of soldiers: 5
Enter the steps number: 3
The Winner: 4


