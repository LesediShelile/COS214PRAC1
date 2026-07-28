#include <iostream>
#include <string>
#include "Transformation.h"


    Transformation::Transformation(std::string name){

        this->name = name;
        


    }
   
    std::string Transformation::getName(){

        return name;


    }

    Transformation::~Transformation(){

        //does nothing 


    }

    DeduplicateStep::DeduplicateStep() :Transformation("dedup"){

    }

     Transformation* DeduplicateStep::clone(){

       return new DeduplicateStep(*this);


     }
     
     std::vector<std::string> DeduplicateStep::apply(std::vector<std::string> records){

        if(records.size() == 0) return records;

        // or 
        int i=0;
        while(i < records.size() -1 ){

            std::string current = records[i];
            std::string next = records[i+1];

            if(current == next){
                records.erase(records.begin() + i+1);
                
            }else {

                i++;
            }
        }
  
        return records;


     }



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


