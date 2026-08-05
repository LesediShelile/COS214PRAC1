#ifndef AGGREGATEBYREGIONSTEP_H
#define AGGREGATEBYREGIONSTEP_H

#include "Transformation.h"

class AggregateByRegionStep: public Transformation{


    public:
            AggregateByRegionStep();
            Transformation* clone();
            std::vector<std::string> apply(std::vector<std::string>);
};

#endif