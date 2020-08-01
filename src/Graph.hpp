#ifndef GRAPH_HPP
#define GRAPH_HPP
//#include "Graph.cpp"
#include <iostream>
#include <unordered_map>
#include "GraphNode.hpp"
using namespace std;


/*Graph Class Header
This class implements a undirected and weighted graph,
which has its GraphNodes representing one airport.
The field map is a hashmap used to store each airport node and quickly
found whether a random airport node is in this map.
*/
class Graph {
public:
 Graph(void);
 ~Graph(void);
 //map to store the airport name and corresponding Node in the map
 unordered_map<string,GraphNode*> map;
 //method to load data form input file
 bool loadFromFile(const char* in_filename);
 //pathfinder method that takes in from node and to node and record the cheapest
path into stack
 int pathfinder(GraphNode* from, GraphNode* to, stack<string> &path);

};
//lessthan class to help constructing the priority queue used in pathfinder
method in Graph.cpp
class lessthan {
public:
 bool operator()(GraphNode *left, GraphNode *right) const {
 return right->cost < left->cost;
 }
};
#endif // GRAPH_HPP