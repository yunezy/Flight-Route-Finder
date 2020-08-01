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

This shows that the program successfully calculates the cheapest flight route from airport of Honolulu, Hawaii to airport of Denver, Colorado.

And it states the non-stop ticket price that goes directly from HNL to DEN, and the amount you can save by choosing the cheapest flight rather than the non-stop one.
