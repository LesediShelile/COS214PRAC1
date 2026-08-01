#ifndef CSVFACTORY_H
#define CSVFACTORY_H

#include "ConnectorFactory.h"

// ConcreteCreator
class CsvFactory : public ConnectorFactory {
public:
    Connector* createConnector() override;
};

#endif