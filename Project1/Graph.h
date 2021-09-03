#pragma once
#include <vector>
using namespace std;
#include "WWW.h"
#include "Node.h"

class Graph {
private:
    //nodes array
    vector<Node*> node;
public:
    void addNode(Node& nodes)
    {
        node.push_back(&nodes);
    }
    void process(groupByRegionData& idata)
    {
        //initial data
        groupByRegionData* data = &idata;
        for (int i = 0; i < node.size(); i++) {
           // data = (node.process(*data);
        }
    }

};

