#pragma once
#include <vector>
using namespace std;
#include "WWW.h"

struct Node {
public:
    virtual groupByRegionData& process(groupByRegionData& data);
};