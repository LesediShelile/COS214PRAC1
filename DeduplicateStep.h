#include <iostream>
#include <string>
#include <vector>
#include "Transformation.h"


class DeduplicateStep{
    
    public:
    Transformation* clone();
    std::vector<std::string> apply(...);
};