/** 
This file stores unique lexeme ID's with an array of Symbol structs

Author: Kenya Holland
Course: Programming Languages
File: analyzer.c

*/

#include "symbol.h"

void insert(char* w) {
	
	int pass = 0;
	
	for (int i = 0; i < ST_SIZE; i++) {
		if(strcmp(st[i].word, w) == 0){
			pass = 1;
		}
    }
	
	if(pass == 0){
		if(st[count].word == NULL){
			strcpy(st[count].word, w);
		}
		else{
			strcpy(st[count+1].word, w);
		}
		
		count++;
	}
}


void displayST(){
	
	for (int i = 0; i < ST_SIZE; i++) {
		if(st[i].word != NULL){
			printf("%s ", st[i].word);
		}
    }
	printf("\n\n");
}




	