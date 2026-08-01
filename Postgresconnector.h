#ifndef POSTGRESCONNECTOR_H
#define POSTGRESCONNECTOR_H

#include "Connector.h"

// ConcreteProduct
class PostgresConnector : public Connector {
public:
    PostgresConnector();
    std::vector<std::string> extract() override;
};

#endif