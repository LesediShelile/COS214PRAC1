#include <iostream>
#include <string>
#include "Pipeline.h"

    Pipeline::Pipeline(ConnectorFactory* factory){

        this->factory = factory;
        this->stage = 0;
       // do nothing with records because it is already empty



    }
    void Pipeline::run(){

        this->connect();
        this->extract();
        this->transform();
        this->load();



    }
    void Pipeline::addStep(Transformation* step){

        steps.push_back(step);




    }
    RunCheckpoint* Pipeline::createCheckpoint(){




    }
    Pipeline::~Pipeline(){



        for(Transformation* ptr : steps ){
            delete ptr;
        }

        steps.clear();
        delete factory;
        factory = nullptr;


    }


    void Pipeline::connect(){

        Connector* connector = factory->createConnector();
        std::cout << "Connecting to "<< connector->getSource() << std::endl;
        this->stage = 1;
        delete connector;




    }
   
   void Pipeline::transform(){

   

    for(auto& item: steps){
       records = item->apply(records);

    }


    this->stage = 3;


   }
   



   //batch pipeline

void BatchPipeline::extract(){

    Connector* connector = factory->createConnector();
    records = connector->extract();
    std::cout<<"Batch extract: " << records.size() << " records" <<std::endl;
    this->stage = 2;
    delete connector;


}


void BatchPipeline::load(){

    std::cout << "Batch load: " << records.size() << " records written" <<std::endl;

    this->stage = 4;


    
}


//streamingpipeline

void StreamingPipeline::extract(){

     Connector* connector = factory->createConnector();
    records = connector->extract();
    std::cout<<"Streaming extract: " << records.size() << " records" <<std::endl;
    this->stage = 2;
    delete connector;

    

}


void StreamingPipeline::load(){

     std::cout << "Streaming load: " << records.size() << " records written" <<std::endl;

    this->stage = 4;

}
