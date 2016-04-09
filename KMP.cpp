#include <string.h>
#include <stdio.h>

//i is postfix
//j is prefix
//ababa
void get_next(string T, int *next){
	j = 0;
	i = 1;
	next[1] = 0;
	while(i < T[0]){
		if(T[i] == T[j] || 0 == j){
			i++;
			j++;
			if (T[i] != T[j]){
				next[i] = j;
			}
			else{
				next[i] = next[j]
			}

		}
		else{
			//j recall
			//because prefix is same
			j = next[j];

		}
	}
}

//retrun the position of substring T in string S
//if it does not exist, return 0
int KMP(string S, string T, int pos){
	int i = pos;
	int j = 1;
	int next[255];
	get_next(T, next);
	while(i <= S[0], && j <= T[0]){
		if(S[i] == T[i]){
			i++;
			j++;
		}
		else{
			j = next[j];
		}
	}
	if(j > T[0]){
		retrun i - T[0];
	}
	else{
		return 0;
	}

}