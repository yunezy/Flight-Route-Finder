#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include "Graph.hpp"
using namespace std;
void usage(char* program_name) {
 cerr << program_name << " called with incorrect arguments." << endl;
 cerr << "Usage: " << program_name
 << " friendship_pairs_file test_pairs_file output_file"
 << endl;
 exit(-1);
}
/*
*This is the main method to load in a file contains the airport names, and
ticket prices, build the graph and
*then use the pathfinder method with Dijkstra Alg. in Graph.cpp to find the
cheapest path between two
*Nodes. Finally we output the path to a file.
*/
int main(int argc, char* argv[]) {
 if (argc != 4) {
 usage(argv[0]);
 }
  char* graph_filename = argv[1];
 char* pairs_filename = argv[2];
 char* output_filename = argv[3];

 /* You can call the pathfinder function from here */
 Graph myGraph;
 //path to store the shortest path
 stack<string> path;
 //build the graph by reading in the file
 myGraph.loadFromFile(graph_filename);
 if(myGraph.loadFromFile(graph_filename) == false){
 cerr<<"fail to build the graph"<<endl;
 }
 //read from pairs file and find path
 ifstream pairFile(pairs_filename);
 ofstream outFile(output_filename);
 while(pairFile){
 string s;
 if (!getline(pairFile, s)) break;

 istringstream ss(s);
 vector<string> record;

 while (ss) {
 string s;
 if (!getline(ss, s, ' ')) break;
 record.push_back(s);
 }

 if (record.size() != 2) {
 continue;
 }
 string fromAirport = record[0];
 string toAirport = record[1];
 outFile << "\n" << "From " << fromAirport << " To " << toAirport << ":"
<< '\n';
 GraphNode *from = nullptr;
 GraphNode *to = nullptr;
 //check if the souce node is present in the graph
 if(myGraph.map.find(fromAirport) != myGraph.map.end()){
 from = myGraph.map.at(fromAirport);
 }
 //check if the destination node is in the graph
 if(myGraph.map.find(toAirport) != myGraph.map.end()){
 to = myGraph.map.at(toAirport);
 }
 int totalPrice = 0;
 //check if any of them are null pointer
 if( !from || !to ){
 outFile << "Cheapest Route Found: Not Available" << '\n';
 if(!from && to){
 outFile << "Source Airport (" << fromAirport;
 outFile << ") does not exist!";
 }
 else if (!to && from){
 outFile << "Destination Airport (" << toAirport;
 outFile << ") does not exist!";
 }
 else{
 outFile << "Both Airports (" << fromAirport <<", ";
 outFile << toAirport << ") do not exist!";
 }
 outFile << '\n';
 outFile << "Total Cost : $0" << '\n';
 }
 //if the source node and destination node is the same
 else if (from->name == to->name){
 outFile << "Source and Dest Airport are the same!" <<'\n';
 outFile << "Total Cost : $0" << '\n';
 }
 //after dealing with edge cases, output the path

 else if(totalPrice = myGraph.pathfinder(from, to, path)){
 bool nonStop = true;
 if(path.size() != 2){
 nonStop = false;
 int stopSize = path.size()-2;
 outFile << "Cheapest Route Found (" << stopSize;
 if(stopSize == 1){
 outFile << " stop): ";
 }
 else{
 outFile << " stops): ";
 }
 }
 else{
 outFile << "Cheapest Route Found (Non-stop) : ";
 }
 
 if(!path.empty()){
 outFile << path.top();
 path.pop();
 }
 while(!path.empty()){
 outFile << "->" << path.top();
 path.pop();
 }
 outFile << '\n' << "Total Cost: $" << totalPrice << '\n';
 if(!nonStop){
 int nonStopPrice = 0;
 if(from->connectedAirport.find(to) !=
 from->connectedAirport.end())
 {
 nonStopPrice = from->connectedAirport.find(to)->second;
 }
 if(nonStopPrice != 0){
 outFile << "Non-Stop Ticket Price: $" << nonStopPrice;
 outFile << '\n';
 outFile << "You Saved: $" << (nonStopPrice-totalPrice);
 outFile << '\n';
 }
 }
 outFile << '\n';
 }
 //if no path found, output a newline
 else{
 outFile << "Cheapest Route Found: Not Available ";
 outFile << "No Path found";
 outFile << '\n';
 outFile << "Total Cost : $0" << '\n' << '\n';
 }
 }
 outFile << '\n';
 outFile.close();
 pairFile.close();
}