#include "dataConverter.hpp"

Matrix & DataConverter::fillBlank(Matrix & toAdjust){

    std::vector<size_t> rowSize;
    auto adjustedData = toAdjust.getValues();

    for(auto currentRow : adjustedData) rowSize.push_back(currentRow.size());

    auto const maxItemIter = std::max_element(rowSize.begin(), rowSize.end());
    auto const maxItem = *maxItemIter;

    for(int i = 0; i < adjustedData.size(); i++){
        while(adjustedData.at(i).size() < maxItem) adjustedData.at(i).push_back(0);
    }

    static Matrix toReturn(toAdjust.getName(), adjustedData);
    return toReturn;
}