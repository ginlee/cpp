#include <stdio.h>
#include <stdlib.h>

typedef char Elemtype;

typedef struct BiTNode
{
	/* data */
	Elemtype data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//create a binary tree. preorder tree traversal
void CreateBiTree(BiTree *T){
	char c;

	scanf("%c", &c);
	if(' ' == c){
		*T = NULL;
	}
	else{
		*T = (BiTNode *)malloc(sizeof(BiTNode));
		(*T)->data = c;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

//The operation visit the tree node
void visit(char c, int level){
	printf("%c is on the %d level\n", c, level);
}


//tree traversal
void PreOrderTraversal(BiTree T, int level){
	if(T){
		visit(T->data, level);
		PreOrderTraversal(T->lchild, level+1);
		PreOrderTraversal(T->rchild, level+1);
	}
}

int main(){
	int level = 1;
	BiTree T = NULL;

	CreateBiTree(&T);
	PreOrderTraversal(T, level);
	return 0;
}