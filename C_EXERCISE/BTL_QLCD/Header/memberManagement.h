#ifndef __MEMBERMANAGEMENT_H__
#define __MEMBERMANAGEMENT_H__
#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C_EXERCISE\BTL_QLCD\Header\csvManagement.h"


void addMember(const char* filename, Member* member,MemberNode **ptp);
void deleteMember(const char* filename, const char* uid);
// void editMember(const char* filename, Member updatedMember);
// int searchByUID(const Member* member, const char* uid);
// int searchByLicensePlate(const Member* member, const char* licensePlate);

#endif