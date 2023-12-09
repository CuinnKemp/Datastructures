#include <bits/stdc++.h>
using namespace std;

#include "AdjacencyList.h"

class DFS {
private:
    set<int> visited;
    bool finished;

    void do_DFS(AdjacencyList* graph, int node, function<void(int)> first_touch, function<void(int)> last_touch){
        visited.insert(node);
        first_touch(node);
        for (auto node : graph->adjacencylist[node]){
            if (visited.find(node) == visited.end()){
                do_DFS(graph, node, first_touch, last_touch);
            }
        }
        last_touch(node);
    }

public:
    DFS(AdjacencyList* graph, int startingNode, function<void(int)> first_touch, function<void(int)> last_touch){
        finished = false;
        
        do_DFS(graph, startingNode, first_touch, last_touch);
    }
};