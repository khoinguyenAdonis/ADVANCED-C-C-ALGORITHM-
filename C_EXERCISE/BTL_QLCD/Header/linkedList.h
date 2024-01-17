#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
 char uid[20]; 
 char roomNumber[10]; 
 char name[50]; 
 char licensePlate[20]; 
} Member;
typedef struct MemberNode {
    Member data;
    struct MemberNode* next;
} MemberNode;

typedef struct TreeNode {
    MemberNode data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;


MemberNode* createMemberNode(Member member);
void push_back(MemberNode **ptp, Member value);
void sortList(MemberNode **ptp);
TreeNode* findNode(TreeNode* root, const char* uid);
void addRemainingValuesToList(TreeNode* root, MemberNode** head);
TreeNode* deleteNode(TreeNode* root, const char* uid);
#endif 