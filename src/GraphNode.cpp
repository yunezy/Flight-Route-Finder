#include <fstream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <limits>
#include <unordered_map>
#include "GraphNode.hpp"
using namespace std;
/*GraphNode Class Header
This class implements the GraphNode, which represented by
a single Node(airport name) in the graph. Important fields are defined.
Name is the three letter representation of an airport.
Cost is the ticket price needed to get to this airport.
prev represent this node's previous node.
visited records whether this node has been visited or not.
*/
//initialize graph node
GraphNode::GraphNode(string airport){
 name = airport;
 cost = numeric_limits<int>::max();
 prev = nullptr;
 visited = false;
}
//add the connected airport to the connected airport list
void GraphNode::addAirport(GraphNode * dest, int price){
 connectedAirport.insert(make_pair(dest, price));
}
