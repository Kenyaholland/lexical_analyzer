/** 
This file is the header file for Symbol struct and its related functions. 

Author: Kenya Holland
Course: Programming Languages
File: symbol.h

*/

#ifndef SYMBOL_H
#define SYMBOL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ST_SIZE 50
#define SIZE_WORD 10

typedef struct Symbol{
    char word[SIZE_WORD];
} Symbol;

int count;
struct Symbol st[ST_SIZE];

void initST();
void insert(char *w);
void displayST();

#endif