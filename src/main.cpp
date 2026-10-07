#include <iostream>
#include <set>
#include "../include/Maze.hpp"
#include "../include/AStar.hpp"
#include "../include/Benchmark.hpp"

Maze::Maze(int w, int h) : width(w), height(h) {
    grid.resize(height);
    for (int y = 0; y < height; ++y) {
        grid[y].resize(width);
        for (int x = 0; x < width; ++x) {
            grid[y][x] = std::make_shared<Node>(x, y, false);
        }
    }
}

void Maze::addDefaultWalls() {
    for (int i = 1; i < width - 1; ++i) {
        grid[1][i]->isWall = true;
        if (i % 2 == 0) grid[3][i]->isWall = true;
    }
}

std::shared_ptr<Node> Maze::getNode(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return grid[y][x];
    }
    return nullptr;
}

void Maze::printMaze(int startX, int startY, int goalX, int goalY) const {
    std::set<std::pair<int, int>> pathCoords;
    auto curr = getNode(goalX, goalY);
    
    if (curr && curr->parent) {
        curr = curr->parent;
        while (curr && !(curr->x == startX && curr->y == startY)) {
            pathCoords.insert({curr->x, curr->y});
            curr = curr->parent;
        }
    }

    std::cout << "\n=== CEN315: Solved Maze Grid (" << width << "x" << height << ") ===" << std::endl;
    std::cout << " [S]: Start | [G]: Goal | [#]: Wall | [*]: Shortest Path | [.]: Open Path\n" << std::endl;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (x == startX && y == startY) std::cout << "S ";
            else if (x == goalX && y == goalY) std::cout << "G ";
            else if (pathCoords.count({x, y})) std::cout << "* ";
            else if (grid[y][x]->isWall) std::cout << "# ";
            else std::cout << ". ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "====================================================" << std::endl;
    std::cout << " CEN315 C++ Pathfinding & Performance Benchmark Engine" << std::endl;
    std::cout << "====================================================\n" << std::endl;
    
    // Large-scale benchmark test (100x100 Grid)
    int size = 100;
    int startX = 0, startY = 0;
    int goalX = size - 1, goalY = size - 1;

    std::cout << "[INFO] Constructing " << size << "x" << size << " large maze grid..." << std::endl;
    
    Maze largeMaze(size, size);
    largeMaze.addDefaultWalls();

    {
        BenchmarkTimer timer("A* Pathfinding Algorithm (100x100 Grid)");
        AStarSolver::solve(largeMaze, startX, startY, goalX, goalY);
    }

    // Small demonstration test (10x10 Grid)
    Maze demoMaze(10, 10);
    demoMaze.addDefaultWalls();
    if (AStarSolver::solve(demoMaze, 0, 0, 9, 9)) {
        demoMaze.printMaze(0, 0, 9, 9);
    }

    return 0;
}
