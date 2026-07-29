#ifndef CONNECTORFACTORY_H
#define CONNECTORFACTORY_H
#include <string>
#include <vector>
#include "Connector.h"




class ConnectorFactory{

    public: 
            virtual Connector* createConnector()=0;
            ~ConnectorFactory();

};


#endif