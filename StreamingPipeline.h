
#ifndef STREAMINGPIPELINE_H
#define STREAMINGPIPELINE_H
#include <iostream>
#include <string>
#include <vector>
#include "Pipeline.h"
class StreamingPipeline : public Pipeline{
    public:
    using Pipeline::Pipeline;
    protected:
                        void extract();
                        void load();
 };

  #endif