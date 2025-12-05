#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 연결 스택 연산 */

typedef int element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

void init(LinkedStackType* s) {
	s->top = NULL;
}

int is_empty(LinkedStackType* s) {
	return s->top == NULL;
}

int is_full(LinkedStackType* s) {
	return 0;
}

void push(LinkedStackType* s, element data) {
	StackNode* new_item = (StackNode*)malloc(sizeof(StackNode));
	new_item->data = data;
	new_item->link = s->top;
	s->top = new_item;
}

element pop(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음 \n");
		exit(1);
	} else {
		StackNode* popped = s->top;
		element data = popped->data;
		s->top = popped->link;
		free(popped);
		return data;
	}
}

element peek(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음 \n");
		exit(1);
	} else {
		return s->top->data;
	}
}

/* 문제 연산 */

int prec(char op) {
	switch (op) {
		case '(':
		case ')':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	}
	return -1;
}

void infix_to_postfix(char exp[], LinkedStackType* s) {
	char ch, top_op;
	for (int i = 0; i < strlen(exp); i++) {
		ch = exp[i];
		switch (ch) {
			case '+':
			case '-':
			case '*':
			case '/':
				while (!is_empty(s) && (prec(ch) <= prec(peek(s))))
					printf("%c", pop(s));
				push(s, ch);
				break;
			case '(':
				push(s, ch);
				break;
			case ')':
				top_op = pop(s);
				while (top_op != '(') {
					printf("%c", top_op);
					top_op = pop(s);
				}
				break;
			default:
				printf("%c", ch);
				break;
		}
	}
	while (!is_empty(s))
		printf("%c", pop(s));
}

/* 주함수 */

int main(void) {
	LinkedStackType s;
	init(&s);

	char str[100];
	scanf("%s", str);
	infix_to_postfix(str, &s);

	return 0;
}