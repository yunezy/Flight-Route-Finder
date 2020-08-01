#ifndef GRAPHNODE_HPP
#define GRAPHNODE_HPP
#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;
/*GraphNode Class Header
This class implements the GraphNode, which represented by
a single Node(airport name) in the graph. Important fields are defined.
Name is the three letter representation of an airport.
Cost is the ticket price needed to get to this airport.
prev represent this node's previous node.
visited records whether this node has been visited or not.
*/
class GraphNode {
public:
 string name;
 bool visited;
 GraphNode* prev;
 int cost;
 //the vector that records list of airport along with price
 unordered_map<GraphNode*, int> connectedAirport;
 //constructor
 GraphNode(string airport);
 //add airport method to add airport Node to connectedAirport list along with
ticket price
 void addAirport(GraphNode *friend_node, int price);
};
#endif