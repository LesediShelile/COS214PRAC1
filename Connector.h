#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <string>
#include <vector>


class Connector{

    protected:
                std::string source;

    public:
                Connector(std::string source);
                virtual std::vector<std::string> extract() = 0;
                std::string getSource() const;
                virtual ~Connector();



    




};

#endif