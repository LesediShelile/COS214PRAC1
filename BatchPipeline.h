
#ifndef BATCHPIPELINE_H
#define BATCHPIPELINE_H
#include <iostream>
#include <string>
#include <vector>
#include "Pipeline.h"

class BatchPipeline: public Pipeline{
    public:
    using Pipeline::Pipeline;

    protected:
                    void extract();
                    void load();

};

#endif