#include "DeduplicateStep.h"
#include <iostream>
#include <string>

 DeduplicateStep::DeduplicateStep() :Transformation("dedup"){

    }

     Transformation* DeduplicateStep::clone(){

       return new DeduplicateStep(*this);


     }
     
     std::vector<std::string> DeduplicateStep::apply(std::vector<std::string> records){

        if(records.size() == 0) return records;

        // or 
        size_t i=0;
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