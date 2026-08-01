#ifndef RESTAPIFACTORY_H
#define RESTAPIFACTORY_H

#include "ConnectorFactory.h"

// ConcreteCreator
class RestApiFactory : public ConnectorFactory {
public:
    Connector* createConnector() override;
};

#endif