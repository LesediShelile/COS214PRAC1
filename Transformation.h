#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include <iostream>
#include <string>
#include <vector>
class Transformation{

    protected:
        std::string name;

    public:

    Transformation(std::string);
    virtual Transformation* clone()=0;
    virtual std::vector<std::string> apply(std::vector<std::string>) = 0;
    std::string getName();
    virtual ~Transformation();

};



class DeduplicateStep: public Transformation{
    
    public:
            // constructor not in UML
            DeduplicateStep();

            Transformation* clone();
            std::vector<std::string> apply(std::vector<std::string>);
};


class AggregateByRegionStep: public Transformation{


    public:
            AggregateByRegionStep();
            Transformation* clone();
            std::vector<std::string> apply(std::vector<std::string>);
};

#endif