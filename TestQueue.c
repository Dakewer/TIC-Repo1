/*
 * main.c
 *
 *  Created on: 14 oct. 2024
 *      Author: hpiza
 */

#include "Queue.h"
#include "Stack.h"
#include <stdio.h>

Bool isOpenSymbol(char c) {
	return c == '(' || c == '[' || c == '{';
}

Bool isCloseSymbol(char c) {
	return c == ')' || c == ']' || c == '}';
}

Bool symbolsMatch(char c1, char c2) {
	return (c1 == '(' && c2 == ')') ||
		   (c1 == '[' && c2 == ']') ||
		   (c1 == '{' && c2 == '}');
}

Bool isValid(char expression[]) {
	Stack st = stack_create();
	char* c = expression;
	while(*c != '\0') {
//		Estrategia:
//		Si es un símbolo de apertura, insertarlo a la pila
//		Si es un símbolo de cierre, extraer el tope de la pila (la pila no debe estar vacía)
//		Si no corresponde --> ERROR
		if(isOpenSymbol(*c)){
			stack_push(st, c);
		}else if(isCloseSymbol(*c)){
			if(stack_isEmpty(st)) return False;
			char* c2= stack_pop(st);
			if(!symbolsMatch(*c2, *c)) return False;
		}
		c ++;
	}
//	La pila debe estar vacía en este punto
	return stack_isEmpty(st);
}

void print_txt(Type t){
	printf("%s", (char*) t);
}

int main() {
	printf("%s\n", isValid("")? "YES": "NO");
	printf("%s\n", isValid("()")? "YES": "NO");
	printf("%s\n", isValid("()[]{}")? "YES": "NO");
	printf("%s\n", isValid("(]")? "YES": "NO");
	printf("%s\n", isValid("([)]")? "YES": "NO");
	printf("%s\n", isValid("{[]}")? "YES": "NO");
	printf("%s\n", isValid("(({[]})[])")? "YES": "NO");
	printf("%s\n", isValid("((([)]))")? "YES": "NO");
	printf("%s\n", isValid("((([({()})])")? "YES": "NO");

	Queue q1= queue_create();
	queue_offer(q1,"Luis Fernando");
	queue_offer(q1,"Luis Francisco");
	queue_offer(q1,"Luis Alberto");
	queue_print(q1,print_txt);
	printf("Polled: %s\n", (char*) queue_poll(q1));
	queue_print(q1,print_txt);
	printf("Polled: %s\n", (char*) queue_poll(q1));
	queue_print(q1,print_txt);
	printf("Polled: %s\n", (char*) queue_poll(q1));
	queue_print(q1,print_txt);
	printf("Size: %d\n", queue_size(q1));
	queue_destroy(q1);
	return 0;
}
