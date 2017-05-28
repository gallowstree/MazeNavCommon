//
// Created by Alvarado, Alejandro on 5/27/17.
//

#include "Search.h"
#include "Stack.h"
#include "Queue.h"
void Search::dfs(Maze * maze, Queue<int> * route)
{
    Stack <Tile *> tiles;
    tiles.push(maze->startTile);
    while(!tiles.isEmpty())
    {
        Tile * currentTile = tiles.pop();
        currentTile->visited = true;
        if(currentTile == maze->goalTile)
        {
            currentTile->route->copyQueue(route);
            break;
        }

        auto successors = new Tile*[4]();
        maze->getSuccessors(currentTile->row,currentTile->col,successors);

        for(int i = 0; i < 4; i++)
        {
            if (successors[i] != nullptr && !successors[i]->visited)
            {
                delete successors[i]->route;
                successors[i]->route = new Queue<int>;
                if(!currentTile->route->isEmpty()) {
                    currentTile->route->copyQueue(successors[i]->route);
                }

                successors[i]->route->enqueue(i);
                tiles.push(successors[i]);
            }
        }
        delete[] successors;
    }
}

void Search::bfs(Maze * maze, Queue<int> * route)
{
    Queue <Tile *> tiles;
    tiles.enqueue(maze->startTile);
    while(!tiles.isEmpty())
    {
        Tile * currentTile = tiles.dequeue();
        currentTile->visited = true;
        if(currentTile == maze->goalTile)
        {
            currentTile->route->copyQueue(route);
            break;
        }

        auto successors = new Tile*[4]();
        maze->getSuccessors(currentTile->row,currentTile->col,successors);

        for(int i = 0; i < 4; i++)
        {
            if (successors[i] != nullptr && !successors[i]->visited)
            {
                delete successors[i]->route;
                successors[i]->route = new Queue<int>;
                if(!currentTile->route->isEmpty()) {
                    currentTile->route->copyQueue(successors[i]->route);
                }

                successors[i]->route->enqueue(i);
                tiles.enqueue(successors[i]);
            }
        }
        delete[] successors;
    }
}