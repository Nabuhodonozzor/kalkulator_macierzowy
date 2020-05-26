#include "matrix.hpp"
#include "menu.hpp"


int main(){
    std::vector<Matrix> matrixVector; 
    Menu mainMenu;

    Matrix matrix1("adada", {{1,2,3},
                             {4,5,6},
                             {7,8,9}});

    Matrix matrix2("dabowanie", {{5,2,7},
                                 {7,5,3},
                                 {5,6,7}});

    matrixVector.push_back(matrix1);
    matrixVector.push_back(matrix2);

    try{
        matrixVector.push_back(matrix2 + matrix1);
    }
    catch(const int){ std::cout << "rozmiar" << std::endl;}

    try{
        matrixVector.push_back(matrix2 - matrix1);
    }
    catch(const int){ std::cout << "rozmiar" << std::endl;}

    mainMenu.initMenu(matrixVector);

    return 0;

}