#define MAX_TREE_SIZE 100

typedef char Elemtype;

//树的双亲孩子表示法
typedef struct CTNode{
	int child;	//chile node notation
	struct CTNode *next; //point to next node
} *ChildPtr;

//head table
typedef struct{
	Elemtype data;	//data in nodes
	int parent;	//parent postion
	ChildPrt firstchild;
}CTBox;

//tree
typedef struct
{
	CTBox nodes[MAX_TREE_SIZE]; //node array
	int r, n;
};
