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

static int compareStrings(const char* str1, const char* str2) {
    if (atoll(str1) < atoll(str2) )
    {
        return -1;
    }
    else if(atoll(str1) > atoll(str2)) return 1;
    return 0;
}
// Hàm chèn một node vào cây tìm kiếm nhị phân
static TreeNode* insertTreeNode(TreeNode* root, MemberNode data) {
    if (root == NULL) {
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (compareStrings(data.data.uid, root->data.data.uid) < 0) {
        root->left = insertTreeNode(root->left, data);
    } else if (compareStrings(data.data.uid, root->data.data.uid) > 0) {
        root->right = insertTreeNode(root->right, data);
    }

    return root;
}

TreeNode* buildTreeFromList(MemberNode* head) {
    TreeNode* root = NULL;
    MemberNode* current = head;

    while (current != NULL) {
        root = insertTreeNode(root, *current);
        current = current->next;
    }

    return root;
}
// Hàm để tìm node với giá trị uid trong cây
TreeNode* findNode(TreeNode* root, const char* uid) {
    if (root == NULL || compareStrings(uid, root->data.data.uid) == 0) {
        return root;
    }

    if (compareStrings(uid, root->data.data.uid) < 0) {
        return findNode(root->left, uid);
    } else {
        return findNode(root->right, uid);
    }
}
// Hàm để thêm các giá trị của các node còn lại vào danh sách liên kết
void addRemainingValuesToList(TreeNode* root, MemberNode** head) {
    if (root) {
        addRemainingValuesToList(root->left, head);

        // Thêm giá trị vào danh sách liên kết
        MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
        newNode->data = root->data.data;
        newNode->next = *head;
        *head = newNode;

        addRemainingValuesToList(root->right, head);
    }
}
/*
    Function: deleteNote
    Description: This function use delete member for list 
    input :uid, pointer to poniter ptp
    output : none

*/
TreeNode* deleteNode(TreeNode* root, const char* uid) {
    if (root == NULL) {
        return root;
    }

    if (compareStrings(uid, root->data.data.uid) < 0) {
        root->left = deleteNode(root->left, uid);
    } else if (compareStrings(uid, root->data.data.uid) > 0) {
        root->right = deleteNode(root->right, uid);
    } else {

        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data.data.uid);
    }
    return root;
}
