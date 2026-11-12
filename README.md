# Student Record Search System (C)

## Project overview
This project compares three data structures for storing and searching student records:
1. Binary Search Tree (BST)
2. AVL Tree
3. Hash Table using Linear Probing

Each record contains a unique student ID, name, department and CGPA. The same fixed dataset of 40 records, in the same insertion order, is loaded into all three structures.

## Features
- Insert a student record into all three structures
- Search by student ID using BST, AVL and Hashing
- Inorder traversal of BST and AVL
- Display occupied hash table slots
- Run a mini experiment for successful and unsuccessful searches
- Measure tree heights, insertion comparisons and hash collisions/probes

## Requirements
- GCC compiler (MinGW-w64 on Windows, or GCC on Linux/macOS)
- Any C editor, including Visual Studio Code

## Compile on Windows (PowerShell / VS Code terminal)
```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c bst.c avl.c hashing.c dataset.c experiment.c -o student_search.exe
.\student_search.exe
```

## Compile on Linux/macOS
```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c bst.c avl.c hashing.c dataset.c experiment.c -o student_search
./student_search
```

## Menu
1. Insert a new student
2. Search using BST
3. Search using AVL Tree
4. Search using Hashing (Linear Probing)
5. Display BST inorder traversal
6. Display AVL inorder traversal
7. Display occupied hash table slots
8. Run mini experiment and comparison
9. Exit

## Experiment notes
- Successful search uses the 20th record in the initial dataset.
- Unsuccessful search uses ID 9999, which is not in the initial dataset.
- BST/AVL search comparisons count visited tree nodes.
- Hash search probes count each table slot inspected, including the final empty slot for an unsuccessful search.
- Hash insertion collisions count each occupied slot encountered before placing a new key.
- BST/AVL insertion comparison counts are key comparisons against existing nodes.
- Tree height is measured in number of nodes on the longest root-to-leaf path (empty tree = 0).

## Important academic note
Run the program yourself and use the values printed by your own execution in your report. Do not copy assumed or fabricated experimental results. If you insert additional records through the menu before running the experiment, note that the experiment itself rebuilds the structures from the original fixed 40-record dataset.
