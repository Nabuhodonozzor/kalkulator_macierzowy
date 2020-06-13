#include "matrix.hpp"


Matrix::Matrix(std::string setName, data_type setValues = {{0}}) :
    name_(setName),
    values_(setValues){
        
}

data_type Matrix::getValues(){
    return values_;
}

std::string Matrix::getName(){
    return name_;
}

Matrix sub_add(const Matrix &leftElement, const Matrix &rightElement, unsigned operation){

    auto leftRows = leftElement.values_.size();
    auto leftCols = leftElement.values_.at(0).size();

    auto rightRows = rightElement.values_.size();
    auto rightCols = rightElement.values_.at(0).size();

    std::string operation_char;
    if(operation == 0) operation_char = '+';
    else if(operation == 1) operation_char = '-';

    if((leftRows == rightRows) && (leftCols == rightCols)){

        auto newName = leftElement.name_ + " " + operation_char + " " + rightElement.name_;
        std::vector<double> rowVect;
        data_type values;

        for(auto i = 0; i < leftRows; i++){ 
            for(auto j = 0; j < leftCols; j++){
                if(operation_char == "+")      rowVect.push_back(leftElement.values_.at(i).at(j) + rightElement.values_.at(i).at(j));
                else if(operation_char == "-") rowVect.push_back(leftElement.values_.at(i).at(j) - rightElement.values_.at(i).at(j));
            }
            values.push_back(rowVect);
            rowVect.clear();
        }
        
        return Matrix(newName, values);
    }
    else{

        std::array<size_t, 2> leftDimensions = {leftRows, leftCols};
        std::array<size_t, 2> rightDimensions = {rightRows, rightCols};

        throw unmatching_size(leftElement.name_, leftDimensions, rightElement.name_, rightDimensions, operation_char);
    }
}

