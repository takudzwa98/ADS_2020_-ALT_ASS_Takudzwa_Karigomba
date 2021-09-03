#pragma once
#include <vector>
using namespace std;
#include "WWW.h"

class Node {
public:
    virtual groupByRegionData& process(groupByRegionData& data);
};