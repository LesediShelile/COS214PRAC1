#include <iostream>
#include <string>
#include <vector>
#include "Transformation.h"

class AggregateByRegionStep{

    public:
    Transformation* clone();
    std::vector<std::string> apply(...);
};