#include <stdio.h>

void rotateLeft(int* pa, int* pb, int* pc) {
	int temp = *pa;
	*pa = *pb;
	*pb = *pc;
	*pc = temp;
}

void rotateRight(int* pa, int* pb, int* pc) {
	int temp = *pc;
	*pc = *pb;
	*pb = *pa;
	*pa = temp;
}

int main() {
	int a = 10, b = 20, c = 30;
	printf("%d:%d:%d\n", a, b, c);
	
	int order;
	scanf("%d" ,&order);
	while(1) {
		if (order == 1) {
			rotateLeft(&a, &b, &c);
		} else if (order == 2) {
			rotateRight(&a, &b, &c);
		} else {
			break;
		}
		printf("%d:%d:%d\n", a, b, c);
		scanf("%d", &order);
	}
	return 0;
}
