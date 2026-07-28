#include <iostream>
#include <string>
#include <vector>
class Transformation{

    protected:
        std::string name;

    public:

    Transformation(std::string);
    Transformation* clone();
    virtual std::vector<std::string> apply(std::vector<std::string>) = 0;
    std::string getName();
    ~Transformation();






};