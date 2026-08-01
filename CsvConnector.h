#ifndef CSVCONNECTOR_H
#define CSVCONNECTOR_H

#include "Connector.h"

// ConcreteProduct
class CsvConnector : public Connector {
public:
    CsvConnector();
    std::vector<std::string> extract() override;
};

#endif