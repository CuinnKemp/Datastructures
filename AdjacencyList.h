// Implementation of unweighted and undirected adjacnecy list.

// Inclusions
#include <bits/stdc++.h>
using namespace std;

// Edge structure contains x and y values
struct Edge {
    int x, y;
    Edge(int x, int y){
        this->x = x; 
        this->y = y;
    }
};

// Adjacency List datastructure using map and set
class AdjacencyList {
public:
    map<int, set<int>> adjacencylist;
    AdjacencyList(){

    }
    AdjacencyList(vector<Edge> edges){
        for (auto edge : edges){
            adjacencylist[edge.x].insert(edge.y);
            adjacencylist[edge.y].insert(edge.x);
        }
    }

    AdjacencyList(vector<vector<int>> edges){
        for (auto edge : edges){
            adjacencylist[edge[0]].insert(edge[1]);
            adjacencylist[edge[1]].insert(edge[0]);
        }
    }
    
    void insert_edge(Edge edge){
        adjacencylist.at(edge.x).insert(edge.y);
        adjacencylist.at(edge.y).insert(edge.x);
    }

    void remove_edge(Edge edge){
        adjacencylist.at(edge.x).erase(edge.y);
        adjacencylist.at(edge.y).erase(edge.x);
    }

    void print_graph(){
        cout << "printing" << endl;
        for (auto i : this->adjacencylist){
            cout << i.first << ": ";
            for (auto j : i.second){
                cout << j << ", ";
            }
            cout << endl;
        }
    }

};