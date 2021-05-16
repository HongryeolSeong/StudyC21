#include <stdio.h>
#include "ex19_10_point.h"
#include "ex19_10_line.h"

int main()
{
	Line a = { {1, 2}, {5, 6} };
	// line.h를 인클루드하며
	// 이미 인클루드 된 point.h를
	// 한 번 더 인클루드 하게 됨 -> 중복 발생
	Point b;

	b.x = (a.first.x + a.second.x) / 2;
	b.y = (a.first.y + a.second.y) / 2;
	printf("선의 가운데 점의 좌표 : (%d, %d)\n", b.x, b.y);

	return 0;
}