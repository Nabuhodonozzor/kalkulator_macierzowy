#include "matrix.hpp"
#include "menu.hpp"


int main(){
    std::vector<Matrix> matrixVector; 

    Matrix matrix1("adada", {{1,2,3},
                             {4,5,6},
                             {7,8,9}});

    Matrix matrix2("dabowanie", {{5,2,7},
                                 {7,5,3}});

    Matrix matrix3("essa", {{2,6,8},
                            {4,7,2},
                            {9,6,4}});

    matrixVector.push_back(matrix1);
    matrixVector.push_back(matrix2);

    try{
        matrixVector.push_back(matrix2 + matrix1);
    }
    catch(unmatching_size &us_add){ std::cout << us_add.what() << std::endl;}

    try{
        matrixVector.push_back(matrix1 + matrix3);
    }
    catch(unmatching_size &us_add){ std::cout << us_add.what() << std::endl;}

   // try{
   //     matrixVector.push_back(matrix2 - matrix1);
   // }
   // catch(unmatching_size &us_sub){ std::cout << us_sub.what() << std::endl;}

    Menu(matrixVector).initMenu();

    return 0;
}