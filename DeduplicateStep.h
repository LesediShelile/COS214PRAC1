#ifndef DEDUPLICATESTEP_H
#define DEDUPLICATESTEP_H

#include "Transformation.h"

class DeduplicateStep: public Transformation{
    
    public:
            // constructor not in UML
            DeduplicateStep();

            Transformation* clone();
            std::vector<std::string> apply(std::vector<std::string>);
};

#endif