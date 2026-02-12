// 이진검색트리
#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"

int MemberNocmp(const Member *x, const Member *y){
    if(*x > *y)
        return -1;
    else if(*x < *y)
        return 1;
    else
        return 0;
}
static BinNode* AllocBinNode(void){
    return calloc(1,sizeof(BinNode));
}
static void SetBinNode(BinNode *n,const Member *x, const BinNode * left, const BinNode * right){
    n->data = x;
    n->left = left;
    n->right = right;
}
//검색
BinNode* Search(BinNode *p,const Member *x){
    int cond;
    if(p == NULL){
        return NULL;
    }
    if((cond = MemberNocmp(&p->data,x))==0){
        return p;
    }else if(cond < 0){
        Search(p->left,x);
    }else if(cond > 0){
        Search(p->right,x);
    }
}
//추가
BinNode* Add(BinNode *p,const Member *x){
    int cond;
    if(p == NULL){
        p = AllocBinNode();
        SetBinNode(p,x,NULL,NULL);
    }
    if((cond = MemberNocmp(&p->data,x))== 0){
        printf("Error. %d is alreay exist in tree\n",p->data);
    }else if(cond < 0){
        p->left = Add(p->left,x);
    }else if(cond > 0){
        p->right = Add(p->right,x);
    }
    return p;
}
//삭제 
// 1. 삭제할 노드의 왼쪽서브에서 가장큰 노드를 검색
// 2. 검색한 노드를 삭제위치로 옮긴다(검색한 노드의 데이터를 삭제대상 노드위치로 복사)
// 3. 옮긴노드를 삭제 이때
//      3.1 옮긴노드에 자식이 없으면 = 자식노드가 없는 노드의 삭제순서에 따라 노드를 삭제
//      3.2 옮긴노드에 자식이 1개만 있으면 = 자식노드가 1개있는 노드의 삭제순서에 따라 노드를 삭제
int Remove(BinNode **root,const Member *x){
    BinNode *next, *temp;
    BinNode **left;
    BinNode **p = root;

    while(1){
        int cond;
        if(*p == NULL){
            printf("Error. %d is not in tree\n", *x);
            return -1;
        }
        if((cond = MemberNocmp((&(*p)->data),x))==0){
            break;
        }else if(cond < 0){
            p = &((*p)->left);
        }else if(cond > 0){
            p = &((*p)->right);
        }
    }

    if((*p)->left == NULL){
        next = (*p)->right;
    }else{
        left = &((*p)->left);
        while((*left)->right != NULL){
            left = &(*left)->right;
        }
        next = *left;
        *left = (*left)->left;
        next->left = (*p)->left;
        next->right = (*p)->right;
    }
    temp = *p;
    *p = next;
    free(temp);

    return 0;
}
void PrintLnMember(const Member *x){
    printf("%d\n",*x);
}
//출력
void PrintTree(const BinNode *p){
    if(p != NULL){
        PrintTree(p->left);
        PrintLnMember(&p->data);
        PrintTree(p->right);
    }
}
//모두해제
void FreeTree(BinNode *p){
    if(p!= NULL){
        FreeTree(p->left);
        FreeTree(p->right);
        free(p);
    }
}
int main(void){

    return 0;
}