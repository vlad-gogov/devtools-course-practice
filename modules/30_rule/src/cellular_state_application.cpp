// Copyright 2021 Gogov Vladislav

#include "include/cellular_state_application.h"

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>

#include "include/30_rule.h"

std::string CellularStateApplication::operator()(int argc, const char* argv[]) const {
    if (argc == 1) {
        return help(argv[0]);
    }
    else if (argc != 4) {
        return "ERROR: Should be 4 arguments.\n";
    }

    int count_iteration, rows;
    try {
        count_iteration = std::stoi(argv[1]);
        if (count_iteration <= 0)
            throw std::runtime_error(" invalid arguments");
    } catch (std::exception& e) {
        return "ERROR " + std::string(argv[1]) + e.what() + ".\n";
    }

    try {
        rows = std::stoi(argv[2]);
        if (rows <= 0)
            throw std::runtime_error(" invalid arguments");
    } catch (std::exception& e) {
        return "ERROR " + std::string(argv[2]) + e.what() + "\n";
    }

    unsigned int cols = static_cast<unsigned int>(strlen(argv[3]));
    std::vector<CellState> states(cols);
    for (unsigned int i = 0; i < cols; i++) {
        if (argv[3][i] != 'A' && argv[3][i] != 'D')
            return "ERROR: Incorrect state.\n";
        states[i] = argv[3][i] == 'A' ? CellState::ALIVE : CellState::DEAD;
    }
    CellularAuto automat(rows, cols, states);
    /*
    try {
        automat = CellularAuto(rows, cols, states);
    } catch (const char* e) {
        return "ERROR: " + std::string(e) + "\n";
    }
    */

    automat.iterate(count_iteration);

    std::ostringstream stream;
    for (int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            stream << (automat.get_state()[i][j] == CellState::ALIVE ? "A" : "D");
        }
        stream << "\n";
    }
    return stream.str();
}

std::string CellularStateApplication::help(const std::string& filename) const {
    return "This is a celluar state application.\n\nPlease provide arguments in the following format:\n\n$ " +

          filename + " <count_iterations> <rows> " + "<state>\n\n" +

          "Where all arguments are positive integer numbers, " +
          "and <state> is string of characters 'A'(ALIVE), 'D'(DEAD).\n" +

          "Example: " + filename + " 2 5 DDDADDD.\n\n";
}
