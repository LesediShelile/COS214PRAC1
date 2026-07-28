#include <iostream>
#include <string>
#include <vector>
#include "ConnectorFactory.h"
#include "Transformation.h"

class Pipeline{

    protected:

    ConnectorFactory* factory;
    std::vector<Transformation*> steps;
    int stage;
    std::vector<std::string> records;

    public:

    Pipeline(ConnectorFactory*);
    static void run();
    void addStep(Transformation*);
    RunCheckpoint* createCheckpoint();
    ~Pipeline();


    protected:

    void connect();
   virtual void extract() =0;
   void transform();
   virtual void load();


   


};