#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <stack>

using namespace std;

struct Node {
    string NodeID;
    int CostFromPrev;
};

string MinDistNode(map<string, int> CostFromStart, map<string, bool> isVisited);

string DijkstasAlgorithm(map<string, list<Node>> _City, string _Start, string _End);

void ReadFile(string _FileName,map<string,list<Node>> &_Graph);

#endif // ALGORITHM_H
