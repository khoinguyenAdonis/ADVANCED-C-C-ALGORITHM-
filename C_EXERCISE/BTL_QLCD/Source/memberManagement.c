#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C_EXERCISE\BTL_QLCD\Header\memberManagement.h"


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

void deleteMember(const char* filename, const char* uid){




}