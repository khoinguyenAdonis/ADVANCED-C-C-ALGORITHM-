#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C_EXERCISE\BTL_QLCD\Header\memberManagement.h"

/*
    Function: addMember
    Description: This function use add member for list and file csv  
    input :filename,member, pointer to poniter ptp
    output : none

*/
void addMember(const char* filename, Member* member,MemberNode **ptp){

    FILE* file = fopen(filename, "a");  // Mở file ở chế độ append (nối thêm vào cuối file)
    if (file == NULL) {
        perror("Khong the mo file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s,%s,%s,%s\n", member->uid, member->roomNumber, member->name,member->licensePlate);
    fclose(file);
    push_back(ptp,*member);
}

/*
    Function: addMember
    Description: This function use delete member for list and file csv  
    input :filename,uid, pointer to poniter ptp
    output : none

*/
void deleteMember(const char* filename, const char* uid, MemberNode **ptp){

    MemberNode* current = *ptp;
    MemberNode* prev = NULL;
    while (current != NULL && strcmp(current->data.uid, uid) != 0) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {
        if (prev == NULL) {
            *ptp = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}