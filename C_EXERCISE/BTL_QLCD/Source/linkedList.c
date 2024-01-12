#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C_EXERCISE\BTL_QLCD\Header\linkedList.h"
/*
    struct : MemberNode
    Description: This function use create member
    input : member
    output : MemberNode

*/
MemberNode* createMemberNode(Member member) {
    MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
    newNode->data = member;
    newNode->next = NULL;
    return newNode;
}

/*
    Function: push_back
    Description: This function use add new member list 
    input : pointer to ponter list Membernode, member
    output : none

*/

void push_back(MemberNode **ptp, Member member){
    MemberNode *temp = createMemberNode(member);    //0xc9
    if(*ptp == NULL){
        *ptp = temp;
    }else{
        MemberNode *p = *ptp;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

/*
    Function: sortList
    Description: This function use sort list 
    input : pointer to ponter list Membernode
    output : none

*/

void sortList(MemberNode **ptp){
    for (MemberNode *i = *ptp ; i != NULL; i = i->next)
    {
        MemberNode *minNode = i;
        for (MemberNode *j =  i->next ; j != NULL; j = j->next)
        {
            if (atoll(minNode->data.uid)>atoll(j->data.uid))
            {
                minNode = j;
            }
            
        }
        Member temp =  minNode->data;
        minNode->data = i->data;
        i->data = temp;      
    }
    
}
