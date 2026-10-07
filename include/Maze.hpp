#pragma once

#include <vector>
#include <iostream>
#include <memory>

// Structure representing each cell in the maze grid
struct Node {
    int x, y;
    bool isWall;
    
    // A* Algorithm Metrics
    double gCost; // Distance cost from start node
    double hCost; // Estimated heuristic cost to goal node
    double fCost() const { return gCost + hCost; }

    // Modern C++ Smart Pointer:
    // Replaced raw pointer (Node*) with std::shared_ptr for automatic memory management (RAII).
    std::shared_ptr<Node> parent;

    Node(int x_val = 0, int y_val = 0, bool wall = false)
        : x(x_val), y(y_val), isWall(wall), gCost(1e9), hCost(0), parent(nullptr) {}
};

class Maze {
private:
    int width;
    int height;
    std::vector<std::vector<std::shared_ptr<Node>>> grid;

public:
    Maze(int w, int h);
    void addDefaultWalls();
    void printMaze(int startX, int startY, int goalX, int goalY) const;
    std::shared_ptr<Node> getNode(int x, int y) const;
    int getWidth() const { return width; }
    int getHeight() const { return height; }
};