#include "DeduplicateStep.h"

DeduplicateStep::DeduplicateStep() : Transformation("dedup") {}

Transformation* DeduplicateStep::clone() {
    // Copy constructor only copies the (small, value-typed) name member,
    // so the clone is fully independent of the prototype it came from.
    return new DeduplicateStep(*this);
}

std::vector<std::string> DeduplicateStep::apply(std::vector<std::string> records) {
    std::vector<std::string> result;
    for (size_t i = 0; i < records.size(); ++i) {
        if (result.empty() || result.back() != records[i]) {
            result.push_back(records[i]);
        }
    }
    return result;
}