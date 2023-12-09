#include <bits/stdc++.h>
using namespace std;

#include "AdjacencyList.h"


class BFS {
private:
    set<int> visited;
    queue<int> discovered;

public:
    BFS(AdjacencyList* graph, int startingNode, function<void(int)> discovered_touch, function<void(int)> visited_touch){
        discovered.push(startingNode);

        while (discovered.size() > 0){
            int node = discovered.front();
            discovered.pop();

            if (visited.find(node) != visited.end()){
                continue;
            }

            visited.insert(node);
            visited_touch(node);

            for (auto i : graph->adjacencylist[node]){
                discovered.push(i);
                discovered_touch(i);
            }
        }
    }
};