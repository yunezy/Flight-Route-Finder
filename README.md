# Flight-Route-Finder

This project is a C++ program to find the cheapest route from one airport to another within United States using Dijkstra's Algorithm. Additionally, it can also calculate the amount saved in USD by choosing the cheapest flight instead of non-stop flight.

## Getting Started

In Linux terminal, direct to the project root directory and run

```
make
```

This will execute the makefile and compile the project.

##Run Project

To execute the complied project, type

```
./build ./data/airlines.txt ./data/routes.txt out
```

And the terminal will output results similar to below

```
From HNL TO DEN:
Cheapest Route Found (2 stops): HNL->LAX->LAS->DEN
Total Cost: $337
Non-Stop Ticket Price: $1221
You Saved:$824
```
