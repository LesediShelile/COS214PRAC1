#ifndef POSTGRESFACTORY_H
#define POSTGRESFACTORY_H

#include "ConnectorFactory.h"

// ConcreteCreator
class PostgresFactory : public ConnectorFactory {
public:
    Connector* createConnector() override;
};

#endif