#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <cstring>

int main() {
	unsigned short instructions;
	scanf("%hd", &instructions);

	int* stack = (int*)malloc(instructions * sizeof(*stack));
	short top = -1;

	unsigned short index = 0;
	char operation[6];
	int operand;

	for (index; index < instructions; index++) {
		scanf("%s", &operation);

		if (strcmp(operation, "push") == 0) {
			scanf("%d", &operand);
			stack[++top] = operand;
		}
		else if (strcmp(operation, "pop") == 0) {
			if (top == -1)
				printf("-1\n");
			else
				printf("%d\n", stack[top--]);
		}
		else if (strcmp(operation, "empty") == 0) {
			printf("%d\n", top == -1);
		}
		else if (strcmp(operation, "size") == 0) {
			printf("%d\n", top + 1);
		}
		else if (strcmp(operation, "top") == 0) {
			if (top == -1)
				printf("-1\n");
			else
				printf("%d\n", stack[top]);
		}
	}

	return 0;
}