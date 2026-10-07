#include "../include/AStar.hpp"
#include <iostream>

bool AStarSolver::solve(Maze& maze, int startX, int startY, int goalX, int goalY) {
    auto startNode = maze.getNode(startX, startY);
    auto goalNode = maze.getNode(goalX, goalY);

    if (!startNode || !goalNode || startNode->isWall || goalNode->isWall) {
        return false;
    }

    std::vector<std::shared_ptr<Node>> openSet;
    std::vector<std::shared_ptr<Node>> closedSet;

    startNode->gCost = 0;
    startNode->hCost = calculateHeuristic(startNode, goalNode);
    openSet.push_back(startNode);

    // Directions: Up, Down, Left, Right
    const int dx[] = {0, 0, -1, 1};
    const int dy[] = {-1, 1, 0, 0};

    while (!openSet.empty()) {
        // Select node with the lowest fCost
        size_t currentIdx = 0;
        for (size_t i = 1; i < openSet.size(); ++i) {
            if (openSet[i]->fCost() < openSet[currentIdx]->fCost()) {
                currentIdx = i;
            }
        }

        auto current = openSet[currentIdx];

        // Goal reached check
        if (current->x == goalX && current->y == goalY) {
            std::cout << "\n[SUCCESS] A* Algorithm found the shortest path!\n" << std::endl;
            return true;
        }

        openSet.erase(openSet.begin() + currentIdx);
        closedSet.push_back(current);

        // Evaluate neighbors
        for (int i = 0; i < 4; ++i) {
            int newX = current->x + dx[i];
            int newY = current->y + dy[i];

            auto neighbor = maze.getNode(newX, newY);

            if (!neighbor || neighbor->isWall) continue;

            // Check if already in closed set
            bool inClosed = false;
            for (const auto& node : closedSet) {
                if (node->x == newX && node->y == newY) { inClosed = true; break; }
            }
            if (inClosed) continue;

            double tentativeGCost = current->gCost + 1.0;

            bool inOpen = false;
            for (const auto& node : openSet) {
                if (node->x == newX && node->y == newY) { inOpen = true; break; }
            }

            if (!inOpen || tentativeGCost < neighbor->gCost) {
                // Modern C++ Smart Pointer Parent Assignment
                neighbor->parent = current;
                neighbor->gCost = tentativeGCost;
                neighbor->hCost = calculateHeuristic(neighbor, goalNode);

                if (!inOpen) {
                    openSet.push_back(neighbor);
                }
            }
        }
    }

    std::cout << "\n[ERROR] Path to target not found!\n" << std::endl;
    return false;
}