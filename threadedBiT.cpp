#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

//thread tag
//link(0), pointer to children
//Thread(1), pointer to predecessor and successor
typedef enum {Link, Thread} PointerTag;

typedef struct BiThrNode{
	char data;
	struct BiThrNode *lchild, *rchild;
	PointerTag ltag;
	PointerTag rtag;
}BiThNode, *BiThrTree;


//global variable, pointer to the last node
BiThrTree pre;



//create a binary tree, using preorder.
void CreateThrTree(BiThrTree *T){
	char c;

	scanf("%c", &c);
	if(' ' == c){
		*T = NULL;
	}
	else{
		*T = (BiThrNode *)malloc(sizeof(BiThrNode));
		(*T)->data = c;
		(*T)->ltag = Link;
		(*T)->rtag = Link;

		CreateThrTree(&(*T)->lchild);
		CreateThrTree(&(*T)->rchild);
	}
}

void InThreading(BiThrTree T){
	if(T){
		InThreading(T->lchild); //recursion the left child
		
		//node operation
		if(!T->lchild){
			T->ltag = Thread;
			T->lchild = pre;
		}
		if(!pre->rchild){
			pre->rtag = Thread;
			pre->rchild = T;
		}
		pre = T;

		InThreading(T->rchild);	//recursion the right child

	}
}

void InOrderThreading(BiThrTree *p, BiThrTree T){
	*p = (BiThrTree)malloc(sizeof(BiThrNode));
	(*p)->ltag = Link;
	(*p)->rtag = Thread;
	(*p)->rchild = *p;
	if(!T){
		(*p)->lchild = *p;
	}
	else{
		(*p)->lchild = T;
		pre = *p;

		InThreading(T);
		pre->rchild = *p;
		pre->rtag = Thread;
		(*p)->rchild = pre;
	}
}

void visit(char c){
	printf("%c", c);
}
//Inorder traversal
void InOrderTraverse(BiThrTree T){
	BiThrTree p;
	p = T->lchild;

	while(p != T){
		while(p->ltag == Link){
			p = p->lchild;
		}
		visit(p->data);

		while(p->rtag == Thread && p->rchild != T){
			p = p->rchild;
			visit(p->data);
		}
	}
	p = p->rchild;
}

int main(){
	BiThrTree P, T = NULL;

	CreateThrTree(&T);

	InOrderThreading(&P, T);

	printf("In Order traversal result is:\n");
	InOrderTraverse(P);

	return 0;
}