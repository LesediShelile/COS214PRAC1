
#include <iostream>
#include <string>
#include "BatchPipeline.h"

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