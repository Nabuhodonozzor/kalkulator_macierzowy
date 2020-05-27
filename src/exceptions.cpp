#include "exceptions.hpp"

const std::string unmatching_size::what(){
    return "Matrices are not fit to perform this operation";
}