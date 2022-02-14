/** 
This file contains the main of the program. utilizes functions across all classes.

Author: Kenya Holland
Course: Programming Languages
File: main.c

*/

#include <stdio.h>
#include <stdlib.h>

#include "symbol.h"
#include "parser.h"
#include "analyzer.h"
 
void initAnalyzer(char *argv);
void initSymbolTable(); 
void parse();

int main(int argc, char *argv[]) {
	
	printf("Compiling %s\n", argv[1]);
	
	initAnalyzer(argv[1]);
	
	parse();
	
	printf("Success.\n");
	
	displayST();
	
	closeFile();
	
	return 0;
}

void initAnalyzer(char *argv){
	openFile(argv);
}

void parse(){
	p.lookahead = lexan();
	assignStmt();
}