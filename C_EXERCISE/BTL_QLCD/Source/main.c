#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C_EXERCISE\BTL_QLCD\Header\memberManagement.h"

#define FILEPATH "D:\\c_c++\\ADVANCED-C-C-ALGORITHM-\\C_EXERCISE\\BTL_QLCD\\10000_Members.csv"


MemberNode *array = NULL;
int main(){
    linkFileCSV(FILEPATH,&array);
    long number = numberOfList(&array);
    TreeNode *bstRoot = buildTree(array,0,number);// xay dung build tree
    Member a = {.uid = "000354478", 
                .roomNumber= "A-732", 
                .name = "nguyen van c", 
                .licensePlate = "00N-714.65"};
    editMember(FILEPATH,a,bstRoot,"000354478",&array);
   // deleteMember(FILEPATH,"000353056",bstRoot,&array);
 //   inorderTraversal(bstRoot);
    // Member a = {.uid = "129862789", 
    //             .roomNumber= "A-732", 
    //             .name = "nguyen van c", 
    //             .licensePlate = "00N-714.65"};
    // addMember("D:\\c_c++\\ADVANCED-C-C-ALGORITHM-\\C_EXERCISE\\BTL_QLCD\\10000_Members.csv",&a,&array);
    return 0;
}

