/** 
This file opens a file to parse through, iterated through file character by character and validates input.
Also adds idLexemes to symbol table

Author: Kenya Holland
Course: Programming Languages
File: analyzer.c

*/

#include "analyzer.h"

void openFile(char *argv){
	
	a.fp = fopen(argv, "r");
	
	if (a.fp == NULL) {
		perror(argv);
		exit(EXIT_FAILURE);
	}
	
	a.lineNo = 1;
}

int lexan(){
		
	while(1){
		a.ch = fgetc(a.fp);
		
		if(a.ch == ' ' || a.ch == '\t'){
			//skip
		}
		else if(a.ch == '\n'){
			a.lineNo++;
		}
		else if(a.ch == '~'){
			ignoreComment();
		}
		else if(isdigit(a.ch)){
			if(getValidNum() == NUM){
				return NUM;
			}
		}
		else if(isalpha(a.ch)){
			int result = getLexeme();
			
			if(result == BEGIN){
				//skip
			}
			else if(result == END){
				return END;
			}
			else{
				return result;
			}
		}
		else if(a.ch == '.'){
			return DONE;
		}
		else{
			return (int)a.ch;
		}
	}
}


int getLexeme(){
	
	char idLexeme[SIZE];
	int pos;
	
	idLexeme[0] = a.ch;   // write the first char to idLexeme
	pos = 1;   // set position of next char to store in idLexeme
	a.ch = fgetc(a.fp);  // get the next character
	
	while(isalpha(a.ch) || isdigit(a.ch) || a.ch == '_') // while ch is part of an <ID> or reserved word
	{
		idLexeme[pos] = a.ch; // store the char and increment the position
		pos++;
		a.ch = fgetc(a.fp);  // get the next char
	}
	
	idLexeme[pos] = '\0';
	ungetc(a.ch, a.fp);  // put the char that is not part of the item back on input
	
	
	if(idLexeme[pos - 1] == '_'){ //if word ends in underscore it is invalid
		printf("Line %i contains error, identifier ends in underscore\n\n", a.lineNo);
		exit(1);
	}
	else if(strcmp(idLexeme, "began") == 0){
		printf("Line %i contains error, expecting 'begin'\n\n", a.lineNo);
		exit(1);
	}
	else if(strcmp(idLexeme, "begin") == 0){
		return BEGIN;
	}
	else if(strcmp(idLexeme, "end") == 0){
		return END;
	}
	else{
		insert(idLexeme);
		
		memset(idLexeme, 0, pos); //null terminate char array
		
		return ID;
	}
}

void ignoreComment(){
	while(a.ch != '\n'){
		a.ch = fgetc(a.fp);
	}
	ungetc(a.ch, a.fp);
}

int getValidNum(){
	a.ch = fgetc(a.fp);  // get the next character
	
	while(isdigit(a.ch)) // while ch is part of an <ID> or reserved word
	{
		a.ch = fgetc(a.fp); // get the next char 
	}
	
	if(isalpha(a.ch)){ //if made it to new line or space then whole number was read
		printf("Line %i contains error, invalid number\n\n", a.lineNo);
		exit(1);
	}
	ungetc(a.ch, a.fp);
	return NUM;
}
 
void closeFile(){
	fclose(a.fp);
}