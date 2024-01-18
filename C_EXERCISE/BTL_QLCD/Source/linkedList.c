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
long numberOfList(MemberNode **head){
    long lenght = 0;
    MemberNode *currence = *head;
    while (currence->next != NULL)
    {
        lenght ++;
        currence = currence->next;
    }
    return lenght;
    
}
// Hàm chèn một node vào cây tìm kiếm nhị phân
TreeNode *buildTree(MemberNode *head, long start, long end) {
    if (head == NULL || start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    MemberNode *node = head;
    for (int i = start; i < mid; i++) {
        if (node->next == NULL) {
            break;
        }
        node = node->next;
    }
    TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
    root->data.data = node->data;
    root->left = buildTree(head, start, mid - 1);
    root->right = buildTree(node->next, mid + 1, end);
    return root;
}
// Hàm để tìm node với giá trị uid trong cây
// TreeNode* findNode(TreeNode* root, const char* uid) {
//     if (root == NULL || compareStrings(uid, root->data.data.uid) == 0) {
//         return root;
//     }

//     if (compareStrings(uid, root->data.data.uid) < 0) {
//         return findNode(root->left, uid);
//     } else {
//         return findNode(root->right, uid);
//     }
// }
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

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
/*
    Function: deleteNote
    Description: This function use delete member for list 
    input :uid, pointer to poniter ptp
    output : none

*/
// TreeNode* deleteNode(TreeNode* root, const char* uid) {
//     if (root == NULL) {
//         return root;
//     }

//     if (compareStrings(uid, root->data.data.uid) < 0) {
//         root->left = deleteNode(root->left, uid);
//     } else if (compareStrings(uid, root->data.data.uid) > 0) {
//         root->right = deleteNode(root->right, uid);
//     } else {

//         if (root->left == NULL) {
//             TreeNode* temp = root->right;
//             free(root);
//             return temp;
//         } else if (root->right == NULL) {
//             TreeNode* temp = root->left;
//             free(root);
//             return temp;
//         }

//         TreeNode* temp = minValueNode(root->right);
//         root->data = temp->data;
//         root->right = deleteNode(root->right, temp->data.data.uid);
//     }
//     return root;
// }
void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("UID: %s, Room Number: %s, Name: %s, License Plate: %s\n",
               root->data.data.uid, root->data.data.roomNumber, root->data.data.name, root->data.data.licensePlate);
        inorderTraversal(root->right);
    }
}