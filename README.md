# Data Structures & Algorithms in C++: A Learning Journey 🚀

Welcome to my personal project repository for Data Structures and Algorithms implemented in C++. This project serves as a chronicle of my learning journey and is designed to share my work and detailed notes with the programming community.

> ***Disclaimer***
> Please note that the code in this repository is intended for educational purposes. It prioritizes clarity and illustration of concepts over creating a production-ready, highly-optimized library. My goal is to support anyone who wants to learn DSA and could benefit from these implementations and notes.

## 🏛️ Repository Structure

Here is an overview of the repository's layout:

``` bash
.
├── consecutive/
│   ├── Vector.hpp
│   ├── Stack.hpp
│   ├── Queue.hpp
│   └── ...
├── scattered/
│   ├── LinkedList.hpp
│   ├── BinaryTree.hpp
│   ├── AVLTree.hpp
│   └── ...
├── Mini Project/
│   ├── SpareArray.hpp
│   └── SpareMatrix.hpp
├── Obsidian Notes/
│   ├── Asymptotic Analysis/
│   ├── Binary Tree/
│   ├── Linked Lists/
│   └── ...
└── README.md
```

- `📁 consecutive`: Contains C++ implementations of data structures typically based on contiguous memory (e.g., Vector, Stack, Queue).
- `📁 scattered`: Contains C++ implementations of data structures using node-based, non-contiguous memory (e.g., Linked Lists, Trees).
- `📁 Mini Project`: Includes smaller projects like SparseArray and SparseMatrix.
- `📁 Obsidian Notes`: A comprehensive Obsidian vault with detailed notes on every topic.

## 📚 Topics & Data Structures Covered

This repository includes implementations and notes for a wide range of fundamental topics:

- **Linear Structures:** Vector, Singly & Doubly Linked Lists, Stack, Queue, Deque.
- **Trees:** Binary Tree, Binary Search Tree (BST), AVL Tree.
- **Heaps:** Max Heap, Min Heap.
- **Other Structures:** Hash Tables (notes), Tries (Prefix Trees).
- **Core Concepts:** Asymptotic Analysis (Big O, Omega, Theta), Time/Space Complexity, Recursion.

## 🛠️ How to Use This Repository

**1. Running the C++ Code**
   You will need a C++ compiler (like `g++` or `Clang`) and a development environment.

**Visual Studio Code Setup**
If you are using **VS Code**, you will likely use a `tasks.json` file to build and run your code. To compile all related `.cpp` source files in a folder together, you need to modify your build task.

In your `.vscode/tasks.json` file, add `"${workspaceFolder}/*.cpp"` to the `args` array. This wildcard tells the compiler to include all `.cpp` files in the current directory during compilation, which is necessary for linking the header implementations with your main driver file.

**Example tasks.json configuration:**

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++ build all cpp files",
            "command": "/usr/bin/g++",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${workspaceFolder}/consecutive/*.cpp", // Include all .cpp files in the consecutive folder
                "-o",
                "${fileDirname}/output"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "Compiler: /usr/bin/g++"
        }
    ]
}
```

**2. Viewing the Notes 📝**
The notes are best viewed using Obsidian.

1. **Download** and install Obsidian from the official website: obsidian.md.
2. **Launch** Obsidian and select "Open folder as vault".
3. **Navigate** to this repository and select the Obsidian Notes folder.

### Required Obsidian Plugins

To ensure the notes render correctly, especially the diagrams and drawings, you will need to install the following community plugin from within Obsidian:

- **Excalidraw:** Many visual explanations and diagrams (.excalidraw.md files) were created with this plugin.

You can install it by navigating to `Settings > Community plugins > Browse` and searching for "**Excalidraw**".

## 🤝 Contributing

Since this is a personal learning project, I am not actively seeking pull requests. However, if you find a bug, spot a typo, or have a suggestion for improvement, please feel free to open an issue! All feedback is welcome.

***Happy coding! 😁***
