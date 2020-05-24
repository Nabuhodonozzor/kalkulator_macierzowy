#include "matrix.h"

Matrix::Matrix(){

}

Matrix::Matrix(std::string setName, data_type setValues = {{0}}) :
    name(setName),
    values(setValues){

}

Matrix::~Matrix(){

}

std::ostream &operator<<(std::ostream &os, Matrix &toPrint){
    os << toPrint.name << '=' << std::endl;
    os << std::showpoint;
    for(auto currentRow : toPrint.values){
        for(auto currentValue : currentRow){
            os << std::setprecision(3) << std::setw(5) << currentValue << ' ';
        }
        os << std::endl;
    }
    return os;
}

Matrix & Matrix::operator+(const Matrix &addend){

    std::string newName = this->name + " + " + addend.name;
    static Matrix toReturn(newName);
    toReturn.values.clear();
    std::vector<double> rowVect;

    if((this->values.size() == addend.values.size()) && (this->values.at(0).size() == addend.values.at(0).size())){
        for(auto i = 0; i < this->values.size(); i++){ 
            for(auto j = 0; j < this->values.at(0).size(); j++){
                rowVect.push_back(this->values.at(i).at(j) + addend.values.at(i).at(j));
            }
            toReturn.values.push_back(rowVect);
            rowVect.clear();
        }
        return toReturn;
    }
    else throw 1;
}

Matrix & Matrix::operator-(const Matrix &substractor){
    std::string newName = this->name + " - " + substractor.name;
    static Matrix toReturn(newName);
    toReturn.values.clear();
    std::vector<double> rowVect;

    if((this->values.size() == substractor.values.size()) && (this->values.at(0).size() == substractor.values.at(0).size())){
        for(auto i = 0; i < this->values.size(); i++){ 
            for(auto j = 0; j < this->values.at(0).size(); j++){
                rowVect.push_back(this->values.at(i).at(j) - substractor.values.at(i).at(j));
            }
            toReturn.values.push_back(rowVect);
            rowVect.clear();
        }
        return toReturn;
    }
    else throw 1;
}