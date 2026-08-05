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

   



     