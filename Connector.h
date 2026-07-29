#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <string>
#include <vector>


class Connector{

    protected:
                std::string source;

    public:
                Connector(std::string);
                std::vector<std::string> extract();
                std::string getSource();
                ~Connector();



    




};

#endif