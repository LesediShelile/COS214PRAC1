
#include <iostream>
#include <string>
#include "StreamingPipeline.h"


//streamingpipeline

void StreamingPipeline::extract(){

     Connector* connector = factory->createConnector();
    records = connector->extract();
    std::cout<<"Streaming extract: " << records.size() << " records" <<std::endl;
    this->stage = 2;
    delete connector;

    

}


void StreamingPipeline::load(){

     std::cout << "Streaming load: " << records.size() << " records streamed" <<std::endl;

    this->stage = 4;

}