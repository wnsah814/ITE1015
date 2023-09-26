#include <stdio.h>

typedef struct {
	char name[15];
	int age;
} Person;

const int LEN = 3;

int main() {
	Person person[LEN];
	for (int i = 0; i < LEN; i++) {
		scanf("%s %d", person[i].name, &person[i].age);
	}

	for (int i = 0; i < LEN; i++) {
		printf("Name:%s, Age:%d\n", person[i].name, person[i].age);
	}
	return 0;
}
