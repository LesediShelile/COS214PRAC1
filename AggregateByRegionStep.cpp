#include "AggregateByRegionStep.h"

AggregateByRegionStep::AggregateByRegionStep() : Transformation("aggregate") {}

Transformation* AggregateByRegionStep::clone() {
    return new AggregateByRegionStep(*this);
}

std::vector<std::string> AggregateByRegionStep::apply(std::vector<std::string> records) {
    return {"COUNT=" + std::to_string(records.size())};
}