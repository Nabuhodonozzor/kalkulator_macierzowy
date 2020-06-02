#include "matrix.hpp"

Matrix::Matrix(){
    
}

Matrix::Matrix(std::string setName, data_type setValues = {{0}}) :
    name_(setName),
    values_(setValues){

}

std::ostream &operator<<(std::ostream &os, Matrix &toPrint){
    os << toPrint.name_ << " =" << std::endl;
    os << std::showpoint;
    for(auto currentRow : toPrint.values_){
        for(auto currentValue : currentRow){
            os << std::setprecision(3) << std::setw(5) << currentValue << ' ';
        }
        os << std::endl;
    }
    return os;
}

Matrix & Matrix::operator+(const Matrix &addend){

    auto thisRows = this->values_.size();
    auto thisCols = this->values_.at(0).size();

    auto addendRows = addend.values_.size();
    auto addendCols = addend.values_.at(0).size();

    if((thisRows == addendRows) && (thisCols == addendCols)){

        auto newName = this->name_ + " + " + addend.name_;
        std::vector<double> rowVect;
        data_type values;

        for(auto i = 0; i < thisRows; i++){ 
            for(auto j = 0; j < thisCols; j++){
                rowVect.push_back(this->values_.at(i).at(j) + addend.values_.at(i).at(j));
            }
            values.push_back(rowVect);
            rowVect.clear();
        }
        static Matrix toReturn(newName, values);
        return toReturn;
    }
    else{

        std::vector<size_t> thisDimensions = {thisRows, thisCols};
        std::vector<size_t> addendDimensions = {addendRows, addendCols};

        throw unmatching_size(this->name_, thisDimensions, addend.name_, addendDimensions, '+');
    }
}

Matrix & Matrix::operator-(const Matrix &substractor){

    std::string newName = this->name_ + " - " + substractor.name_;
    std::vector<double> rowVect;
    data_type values;

    if((this->values_.size() == substractor.values_.size()) && (this->values_.at(0).size() == substractor.values_.at(0).size())){
        for(auto i = 0; i < this->values_.size(); i++){ 
            for(auto j = 0; j < this->values_.at(0).size(); j++){
                rowVect.push_back(this->values_.at(i).at(j) - substractor.values_.at(i).at(j));
            }
            values.push_back(rowVect);
            rowVect.clear();
        }
        static Matrix toReturn(newName, values);
        return toReturn;
    }
//   else throw unmatching_size(this -> name_, substractor.name_);
}