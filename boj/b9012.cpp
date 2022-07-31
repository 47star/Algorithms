#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

int main() {
	unsigned short tests, i, j;
	scanf("%hd", &tests);

	char ps[51];
	unsigned short* opened = (unsigned short*) malloc(1);
	unsigned short* closed = (unsigned short*) malloc(1);

	for (i = 0; i < tests; i++) {
		opened = 0;
		closed = 0;

		scanf("%s", &ps);

		for (j = 0; j < 51; j++) {
			if (ps[j] == '\0')
				break;
			else if (ps[j] == '(')
				opened++;
			else if (ps[j] == ')')
				closed++;

			if (opened < closed) {
				break;
			}
		}

		if (opened == closed)
			printf("YES\n");
		else
			printf("NO\n");
	}
}