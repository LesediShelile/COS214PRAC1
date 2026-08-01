#include "Connector.h"

Connector::Connector(std::string source) : source(source) {}

std::string Connector::getSource() const {
    return source;
}

Connector::~Connector() {}