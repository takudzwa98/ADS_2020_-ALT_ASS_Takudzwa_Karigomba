#pragma once
#include <vector>
using namespace std;
#include "WWW.h"
#include "Node.h"
#include "Graph.h"
#include <sstream>

class InputFromFileNode : public Node {
public:
    groupByRegionData& process(groupByRegionData& data)

    {
        groupByRegion gbr;
        gbr.name = "all";

        //file into src vector
        string filename = data.src;
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            vector<string> lines;
            int i = 0;
            while (getline(file, line)) {
                if (i != 0)
                    lines.push_back(line);
                i++;
            }
};