#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//中缀表达式 转换为后缀表达式
//1+(2-3)*4+10/5
//1 2 3 - 4 * + 10 5 / + #
#define STACK_INIT_SIZE 20
#define STACK_INCREMENT 10
#define MAXBUFFER 10

typedef char ElemType;
typedef struct{
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;

void InitStack(sqStack *s){
	s->base = (ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!s->base){
		exit(0);
	}

	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack *s, ElemType e){
	if(s->top - s->base >= s->stackSize){
		s->base = (ElemType *)realloc(s->base, (s->stackSize + STACK_INCREMENT)*sizeof(ElemType));
		if (!s->base){
			exit(0);
		}
	}
	*(s->top) = e;
	s->top++;
}

void Pop(sqStack *s, ElemType *e){
	if(s->top == s->base){
		return;
	}
	*e = *--(s->top);
}

int StackLen(sqStack s){
	return (s.top - s.base);
}

int main(){
	sqStack s;
	char c, e;
	InitStack(&s);
	printf("please enter an infix expression, end with #\n");
	scanf("%c", &c);
	while(c != '#'){
		while(c>='0' && c <='9'){
			printf("%c", c);
			scanf("%c", &c);
			if(c<'0' || c >'9'){
				printf(" ");
			}
		}

		if(')' == c){
			Pop(&s, &e);
			while('(' != e){
				printf("%c ", e);
				Pop(&s, &e);
			}
		}
		else if('+' == c || '-' == c){
			if(!StackLen(s)){
				Push(&s, c);
			}
			else{
				do{
					Pop(&s, &e);
					if('(' == e){
						Push(&s, e);
					}
					else{
						printf("%c ", e);
					}
				}while(StackLen(s) && '(' != e);
				Push(&s, c);
			}
		}
		else if('*' == c || '/' == c || '(' == c){
			Push(&s, c);
		}
		else if('#' == c){
			break;
		}
		else{
			printf("\nERROR, the data you typed is wrong!\n");
			return -1;
		}
		scanf("%c", &c);
	}
	while(StackLen(s)){
		Pop(&s, &e);
		printf("%c ", e);
	}
	printf("\n");
	return 0;
}