#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C_EXERCISE\BTL_QLCD\Header\memberManagement.h"



MemberNode *array = NULL;
int main(){
    linkFileCSV("D:\\c_c++\\ADVANCED-C-C-ALGORITHM-\\C_EXERCISE\\BTL_QLCD\\10000_Members.csv",&array);
    TreeNode* bstRoot = buildTreeFromList(array); // xay dung build tree
    
    Member a = {.uid = "129862789", 
                .roomNumber= "A-732", 
                .name = "nguyen van c", 
                .licensePlate = "00N-714.65"};
    addMember("D:\\c_c++\\ADVANCED-C-C-ALGORITHM-\\C_EXERCISE\\BTL_QLCD\\10000_Members.csv",&a,&array);
    return 0;
}

