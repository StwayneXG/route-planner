#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <stack>
#include "Algorithm.h"

using namespace std;


string MinDistNode(map<string, int> CostFromStart, map<string, bool> isVisited) // O(N)
{
    string MinNode = "g@rB@gE";
    for (auto it = CostFromStart.begin(); it!=CostFromStart.end(); ++it) // O(N)
    {
        if (!isVisited[it->first] && (MinNode == "g@rB@gE" || it->second < CostFromStart[MinNode]))
        {
            MinNode = it->first;
        }
    }
    return MinNode;
}

string DijkstasAlgorithm(map<string, list<Node>> _City, string _Start, string _End)
{
    map<string, int> CostFromStart;
    map<string, string> PrevNode;
    map<string, bool> isVisited;

    for (auto place = _City.begin();place!=_City.end();++place) //O(N)
    {
        CostFromStart[place->first] = INT_MAX;
        isVisited[place->first] = false;
    }

    CostFromStart[_Start] = 0;
    PrevNode[_Start] = "g@rB@gE";

    for(auto place = _City.begin(); place != _City.end(); ++place) //O(N)
    {
        string minNode = MinDistNode(CostFromStart, isVisited); //O(N)
        isVisited[minNode] = true;
        for (auto neighbor = _City[minNode].begin();neighbor!= _City[minNode].end(); ++neighbor) //O(E)
        {
            if (!isVisited[neighbor->NodeID])
            {
                int dist = CostFromStart[minNode] + neighbor->CostFromPrev;
                if (dist < CostFromStart[neighbor->NodeID])
                {
                    CostFromStart[neighbor->NodeID] = dist;
                    PrevNode[neighbor->NodeID] = minNode;
                }
            }
        }
    }
    stack<pair<string, int>> s;
    string curr = _End;
    while (curr != "g@rB@gE")
    {
        string prev = PrevNode[curr];
        s.push(make_pair(curr, CostFromStart[curr] - CostFromStart[prev]));
        curr = prev;
    }
    string out;
    out = "Path to take:\n\n";

    while (!s.empty())
    {
        out += s.top().first + " " + to_string(s.top().second) + "km\n";
        s.pop();
    }
    out += "\nTotal Distance = " + to_string(CostFromStart[_End]) + "km\n";
    return out;
}

void ReadFile(string _FileName,map<string,list<Node>> &_Graph)
{
    ifstream readFile;
    list<Node> _tempAdjacencies;
    Node _tempNode;
    readFile.open(_FileName);
    if (readFile.is_open())
    {
        string line;
        while (getline(readFile, line))
        {
            if (line.find("~/") == 0)
            {
                string currNode = line.substr(2);
                while (getline(readFile, line))
                {
                    if (line.size() == 0)
                    {
                        break;
                    }
                    else
                    {
                        string currAdjacency = line.substr(0, line.find("\t"));
                        int currDist = stoi(line.substr(line.find("\t")));
                        _tempNode.NodeID = currAdjacency;
                        _tempNode.CostFromPrev = currDist;
                        _tempAdjacencies.push_back(_tempNode);
                    }
                }
                _Graph[currNode] = _tempAdjacencies;
                _tempAdjacencies.clear();
            }
        }
    }
    else
    {
        cerr << _FileName << " not found.";
        return;
    }
}
