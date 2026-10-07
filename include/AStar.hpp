#pragma once

#include "Maze.hpp"
#include <vector>
#include <memory>
#include <cmath>
#include <algorithm>

class AStarSolver {
private:
    // Manhattan Distance Calculation (Heuristic Function)
    static double calculateHeuristic(std::shared_ptr<Node> a, std::shared_ptr<Node> b) {
        return std::abs(a->x - b->x) + std::abs(a->y - b->y);
    }

public:
    static bool solve(Maze& maze, int startX, int startY, int goalX, int goalY);
};
