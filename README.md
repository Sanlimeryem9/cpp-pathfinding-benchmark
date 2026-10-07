# CEN315 - C++ Pathfinding & Memory Benchmark Project

**Student Name:** Cennet Meryem Şanlı  
**Course:** CEN315 - Programming Languages  
**Topic:** Modern C++ Smart Pointer & Memory Benchmark with A* Pathfinding  

---

## 📌 Overview

This project was developed for the **CEN315 Programming Languages** course to evaluate C++ memory management paradigms, type safety, and execution performance. The project implements the **A* (A-Star) Pathfinding Algorithm** over generated grid structures to measure execution efficiency and memory safety.

By replacing legacy C-style raw pointers with Modern C++ **Smart Pointers (`std::shared_ptr`)** and applying **RAII (Resource Acquisition Is Initialization)** principles, the application eliminates potential memory leaks and dangling pointer hazards.

---

## 🧠 Programming Languages Evaluation Criteria (CEN315 Concepts)

### 1. Reliability & RAII
* Manual dynamic allocation keywords (`new` and `delete`) are strictly avoided.
* Node hierarchy and parent tracking in the A* algorithm rely on `std::shared_ptr<Node>`. Memory allocated on the heap is automatically reclaimed once objects fall out of scope.

### 2. Readability & Abstraction
* Standard Template Library (`std::vector`, `std::chrono`) abstractions enhance overall code clarity and writability.
* Object-Oriented Design separates duties into clean abstractions (`Maze`, `Node`, `AStarSolver`, `BenchmarkTimer`).

### 3. Cost & Performance
* High-resolution timing metrics (`std::chrono`) measure execution latency down to microsecond precision across 100x100 grid environments.
* Continuous array layouts via nested `std::vector` structures minimize cache misses and mitigate von Neumann bottleneck constraints.

---

## 📊 Benchmark Execution Output

```text
====================================================
 CEN315 C++ Pathfinding & Performance Benchmark Engine
====================================================

[INFO] Constructing 100x100 large maze grid...
[SUCCESS] A* Algorithm found the shortest path!
[BENCHMARK] A* Pathfinding Algorithm (100x100 Grid) Execution Time: 1374739 microseconds (us) [1374.74 ms]

=== CEN315: Solved Maze Grid (10x10) ===
 [S]: Start | [G]: Goal | [#]: Wall | [*]: Shortest Path | [.]: Open Path

S . . . . . . . . . 
* # # # # # # # # . 
* . . . . . . . . . 
* . # . # . # . # . 
* . . . . . . . . . 
* . . . . . . . . . 
* . . . . . . . . . 
* . . . . . . . . . 
* . . . . . . . . . 
* * * * * * * * * G