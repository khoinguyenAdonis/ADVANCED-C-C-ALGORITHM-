#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C++_EXERCISE\RestaurantManagement\Header\menu.hpp"


/*
Funtion Name: menu
Function description : Select program functions
Input parameters: NONE
Output: None
*/
void menu(){
    int option;
    int numTable;
    Management tableArray;
    ManageDish dishArray;
    while(1){
        MENU
        switch (option)
        {
        case 1:
            MANAGEMENT
            switch (option)
            {
            case 1:
                    TABLENUMBER
                    tableArray.resizeArray(option);
                    break;
            case 2:
                    dishArray.addDish();
                    break;
            case 3:
                    dishArray.editDish();
                    break;
            case 4:
                    dishArray.eraseDish();
                    break;
            case 5:
                    dishArray.displayDish();
                    break;
            default:
                break;
            }
            break;
        case 2:
            tableArray.displayTable();
            CHOOSETABLE
            OPTION
            tableArray.editTable(numTable,option,dishArray);
            break;
        default:
            break;
        }
        
   }

}