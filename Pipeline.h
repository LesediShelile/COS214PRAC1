#ifndef PIPELINE_H
#define PIPELINE_H
#include <iostream>
#include <string>
#include <vector>
#include "ConnectorFactory.h"
#include "Transformation.h"
#include "RunCheckpoint.h"

class Pipeline{

    protected:
                    ConnectorFactory* factory;
                    std::vector<Transformation*> steps;
                    int stage;
                    std::vector<std::string> records;

    public:

                    Pipeline(ConnectorFactory*);
                    void run();
                    void addStep(Transformation*);
                    RunCheckpoint* createCheckpoint();
                    ~Pipeline();


    protected:

                    void connect();
                    virtual void extract() =0;
                    void transform();
                    virtual void load()=0;


};

class BatchPipeline: public Pipeline{

    protected:
                    void extract();
                    void load();

};

class StreamingPipeline : public Pipeline{

    protected:
                        void extract();
                        void load();
 };

 #endif