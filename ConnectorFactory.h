#ifndef CONNECTORFACTORY_H
#define CONNECTORFACTORY_H

#include "Connector.h"

// Creator (Factory Method)
// Declares the factory method. Calling code depends only on this
// interface and never names a concrete Connector class.
class ConnectorFactory {
public:
    virtual Connector* createConnector() = 0;
    virtual ~ConnectorFactory();
};

#endif