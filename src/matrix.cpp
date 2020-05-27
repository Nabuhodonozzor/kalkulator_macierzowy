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

    std::string newName = this->name_ + " + " + addend.name_;
    std::vector<double> rowVect;
    data_type values;

    if((this->values_.size() == addend.values_.size()) && (this->values_.at(0).size() == addend.values_.at(0).size())){
        for(auto i = 0; i < this->values_.size(); i++){ 
            for(auto j = 0; j < this->values_.at(0).size(); j++){
                rowVect.push_back(this->values_.at(i).at(j) + addend.values_.at(i).at(j));
            }
            values.push_back(rowVect);
            rowVect.clear();
        }
        static Matrix toReturn(newName, values);
        return toReturn;
    }
    else throw unmatching_size();
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
    else throw unmatching_size();
}