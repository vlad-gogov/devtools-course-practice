// Copyright 2021 Gogov Vladislav

#ifndef MODULES_30_RULE_INCLUDE_CELLULAR_STATE_APPLICATION_H_
#define MODULES_30_RULE_INCLUDE_CELLULAR_STATE_APPLICATION_H_

#include <string>

class CellularStateApplication {
    std::string help(const std::string& filename) const;

public:
    CellularStateApplication() = default;
    std::string operator()(int argc, const char* argv[]) const;
};

#endif  // MODULES_30_RULE_INCLUDE_CELL_CELLULAR_APPLICATION_H_
