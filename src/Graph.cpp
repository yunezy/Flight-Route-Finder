#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <set>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <unordered_map>
#include "Graph.hpp"
#include "GraphNode.hpp"
using namespace std;
//initiallizer
Graph::Graph(void){}
//destructor, delete all items in unordered_map
Graph::~Graph(void) {
 for (unordered_map<string, GraphNode*>::iterator it = map.begin(); it !=
map.end();++it){
 delete(it->second);
 }
}
/* Read in flight information from an inputfile to create a weighted undirected
graph */
bool Graph::loadFromFile(const char* in_filename) {
 ifstream infile(in_filename);
 //read in inputfile data
 while (infile) {
 string s;
 if (!getline(infile, s)) break;
 istringstream ss(s);
 vector<string> record;
 while (ss) {
 string s;
 if (!getline(ss, s, ' ')) break;
 record.push_back(s);
 }

 if (record.size() != 3) {
 continue;
 }
 //initiliaze source airport and destination ariport
 GraphNode *source = nullptr;
  GraphNode *dest = nullptr;
 int price = stoi(record[2]);
 //if source airport does not exist yet, create one and insert it to map
 if(map.find(record[0]) == map.end()){
 source = new GraphNode(record[0]);
 map.insert(make_pair(record[0],source));
 }
 //else find the corresponding airport
 else{
 source = map[record[0]];
 }
 //if destination airport does not exist yet, create one and insert it to
map
 if(map.find(record[1]) == map.end()){
 dest = new GraphNode(record[1]);
 map.insert(make_pair(record[1], dest));
 }
 //else find the corresoponding airport
 else{
 dest = map[record[1]];
 }
 //add each other in their connected airport list
 source->addAirport(dest, price);
 dest ->addAirport(source, price);
 }
 if (!infile.eof()) {
 cerr << "Failed to read " << in_filename << "!\n";
 return false;
 }
 infile.close();
 return true;
}
/* Implement pathfinder*/
/* This method uses Dijkstra Algorithm to calculate the cheapest path from one
airport to another
 @return: int value of the ticket price, if cheapest path is found
@param: GraphNode* from, GraphNode* to, stack<string>
*/
int Graph::pathfinder(GraphNode* from, GraphNode* to, stack<string> &path) {
 //if both airport are not present, return
 if(map.find(from->name) == map.end() || map.find(to->name) == map.end()){
 return 0;
 }
 //iterate through map, assigning prev to 0, visited to false and cost to
INT_MAX
 for(auto it = map.begin(); it != map.end(); it++){
 it->second->visited = false;
 it->second->prev= 0;
 it->second->cost = numeric_limits<int>::max();
 }
 //initialize priority queue, set cost to 0 and push from node to queue
 priority_queue<GraphNode*,vector<GraphNode*>,lessthan> q;
 from->cost = 0;
 q.push(from);
 while(!q.empty()){
 GraphNode *curr = q.top();
 q.pop();
 //if curr name equals the to name, we found the path
 if(curr->name == to->name){
 int total = curr->cost;
 GraphNode *toReturn = curr;
 while(toReturn){
 path.push(toReturn->name);
 toReturn = toReturn->prev;
 }
 //return the price, which is the cost of current node
 return total;
 }
 // if curr is not visited
 if(curr->visited == false){
 curr->visited = true;
 for(auto it = curr->connectedAirport.begin(); it !=
curr->connectedAirport.end(); it++){
 //connected airport name stored as temp
 string temp = it->first->name;
 //connected airport weight stored as int weight here
 int weight = it->second;

 //if temp airport's cost is larger than current cost plus weight,
then update the cost and prev
 if(map.find(temp)->second->cost > weight + curr->cost){
 map.find(temp)->second->cost = weight + curr->cost;
 map.find(temp)->second->prev = curr;
 //push the corresponding airport to queue
 q.push(map.find(temp)->second);
 }
 }
 }
 }
 return 0;
}