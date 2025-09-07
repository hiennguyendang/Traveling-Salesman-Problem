# Travelling Salesman Problem (TSP) Solver

![C++](https://img.shields.io/badge/language-C++-blue.svg)
![Algorithm](https://img.shields.io/badge/algorithm-DP%20%2B%20Bitmasking-green.svg)
![Status](https://img.shields.io/badge/status-completed-success.svg)

## 📌 Introduction
This is a academic project for the **Discrete Structures** course focuses on implementing and solving the **Travelling Salesman Problem (TSP)** using a combination of **Dynamic Programming (DP)** and **Bitmasking** 

## 🚀 Idea and Methodology
- **Language:** C++  
- **Dynamic Programming (DP):** breaks the problem into smaller subproblems and stores intermediate results to avoid redundant computations.  
- **Bitmasking:** uses bits to represent the set of visited cities, allowing efficient state management.  

General recursive formula:

g(i, S) = min( C(i,k) + g(k, S - {k}) ) với k ∈ S
- `i`: current city  
- `S`: set of remaining cities to visit  
- `C(i, k)`: cost of traveling from `i` to `k`  

## 📂 Source Code Structure
- `tsm.h` : Declaration of the `TravelingSalesman` class and helper methods.  
- `tsm.cpp` : Implementation details of the methods.  

Main components:
- `recursiveCalculate(pos, mask)`: core recursive function to compute the optimal cost.  
- `TravelingOutString()`: generates the optimal path string.  
- Arrays `valueCity` and `nextCity` are used to store costs and route information.  

## ⚡ Complexity
- Time complexity: **O(n² × 2ⁿ)**  
- More efficient than brute force **O(n!)**, making it feasible to solve medium-sized TSP instances.  

## 🖥️ How to Run
1. Compile:
   ```bash
   g++ -o main main.cpp bellman.cpp tsm.cpp
2. Run:
   ```bash
   main
