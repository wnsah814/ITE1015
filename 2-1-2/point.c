#include <stdio.h>

typedef struct {
	int xpos;
	int ypos;
} Point;

Point getScale2xPoint(const Point* p) {
	Point p2 = {2 * p->xpos, 2 * p->ypos };
	return p2;
}

void swapPoints(Point* p1, Point* p2) {
	Point tmp_p = {p1->xpos, p1->ypos};
	p1->xpos = p2->xpos;
	p1->ypos = p2->ypos;
	
	p2->xpos = tmp_p.xpos;
	p2->ypos = tmp_p.ypos;
}

void showPoint(Point p1, Point p2) {
	printf("P1 : %d %d\n", p1.xpos, p1.ypos);
	printf("P2 : %d %d\n", p2.xpos, p2.ypos);
}
int main() {
	Point p1, p2;

	scanf("%d %d", &p1.xpos, &p1.ypos);
	p2 = getScale2xPoint(&p1);

	printf("Calling getScale2xPoint()\n");
	showPoint(p1, p2);
	
	swapPoints(&p1, &p2);
	printf("Calling swapPoint()\n");
	showPoint(p1, p2);

	return 0;
}
