#include <iostream>
#include <string>
#include "TransformationRegistry.h"

//std::map<std::string, Transformation*> prototypes;

void TransformationRegistry::registerStep(std::string key, Transformation* prototype){

 if(prototypes[key] != nullptr){
   delete prototypes[key];
 }

 prototypes[key] = prototype;



}


Transformation* TransformationRegistry::create(std::string key){

   if(prototypes.count(key) > 0){

      return prototypes[key]->clone();
      
   }else{
       return nullptr;

   }

   
   }






TransformationRegistry::~TransformationRegistry(){

   for(auto&it :prototypes){
      delete prototypes[it.first];

      // or delete it.second; 
   }



   }


