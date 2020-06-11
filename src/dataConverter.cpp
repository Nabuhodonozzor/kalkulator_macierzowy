#include "dataConverter.hpp"

Matrix & DataConverter::fillBlank(Matrix & toAdjust){

    std::vector<size_t> rowSize;
    auto adjustedData = toAdjust.getValues();

    for(auto currentRow : toAdjust.getValues()) rowSize.push_back(currentRow.size());
    auto maxRow = std::max_element(rowSize.begin(), rowSize.end());

    for(auto currentRow : adjustedData){
        while(currentRow.size() - *maxRow < 0) currentRow.push_back(0);
    }

    static Matrix toReturn(toAdjust.getName(), adjustedData);
    return toReturn;
}