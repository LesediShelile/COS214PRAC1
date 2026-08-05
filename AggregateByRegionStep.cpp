#include "AggregateByRegionStep.h"
#include <iostream>
#include <string>

AggregateByRegionStep::AggregateByRegionStep() : Transformation("aggregate"){

     }

     Transformation* AggregateByRegionStep::clone(){

        return new AggregateByRegionStep(*this);

     }


    std::vector<std::string> AggregateByRegionStep::apply(std::vector<std::string> records ){

        std::string count = std::to_string(records.size());

        std::string output = "COUNT=";
       std::string combined = output + count;

       std::vector<std::string> result;
       result.push_back(combined);

        return result;


    }


