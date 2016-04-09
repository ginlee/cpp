#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//利用栈的结构写逆波兰计算器
//能实现对逆波兰输入的表达式进行计算
//支持带小数点的计算
//正常表达式到逆波兰表达式
//a+(b-c)*d -> abc-d*+
//a+d*(b-c) -> adbc-*+
#define STACK_INIT_SIZE 20
#define STACK_INCREMENT 10
#define MAXBUFFER 10

typedef double ElemType;
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
	char c;
	double d, e;
	char str[MAXBUFFER];
	int i = 0;

	InitStack(&s);

	printf("Please enter the Reverse Polish Notation, divide data and equation notation by space\n");
	scanf("%c", &c);

	while(c!= '#'){
		while(isdigit(c)){
			str[i++] = c;
			str[i] = '\0';
			if(i >= 10){
				printf("the value you typed is too large");
				return -1;
			}
			scanf("%c", &c);
			if(c == ' '){
				d = atof(str);
				Push(&s, d);
				i = 0;
				break;
			}
		}
		switch(c){
			case '+':
				Pop(&s, &e);
				Pop(&s, &d);
				Push(&s, d+e);
				break;
			case '-':
				Pop(&s, &e);
				Pop(&s, &d);
				Push(&s, d-e);
				break;
			case '*':
				Pop(&s, &e);
				Pop(&s, &d);
				Push(&s, d*e);
				break;
			case '/':
				Pop(&s, &e);
				Pop(&s, &d);
				if(e != 0){
					Push(&s, d/e);
				}
				else{
					printf("ERROR");
					return -1;
				}
				break;

		}
		scanf("%c", &c);
	}
	Pop(&s, &d);
	printf("The final result is %f\n", d);
	getchar();
}
