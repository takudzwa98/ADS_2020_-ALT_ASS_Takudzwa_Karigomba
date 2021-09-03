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
    void process(groupByRegionData& gbrdata)
    {
        //initial data
        groupByRegionData* data = &gbrdata;
        for (int i = 0; i < node.size(); i++) {
           // data = (node.process(*data);
        }
    }

};

