// ConsoleApplication12.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "malloc.h"

static int n = 0;
void push(short input, short *q) {
	*q = input;
}

short pop(short *q) {
	short result;
	result = *q;
	*q = NULL;
	return result;
}

int main() {
	short **pp, *semip;
	int k, command, input, output;
	printf("스택의 최대값을 몇개로 정하시겠습니까?");
	scanf_s("%d", &k);
	pp = (short **)malloc(sizeof(short *) * k);
	for (int i = 0;i < k;i++) *(pp + i) = (short *)malloc(sizeof(short));
	while (1) {
		printf("===== 메뉴 =====\n");
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.종료\n");
		scanf_s("%d", &command);
		if (command == 1 && n < k) {
			semip = *(pp + n);
			printf("숫자를 입력해주세요.\n");
			scanf_s("%d", &input);
			input = (short)input;
			push(input, semip);
			n++;
		}
		else if (command == 2 && n > 0) {
			n--;
			semip = *(pp + n);
			output = pop(semip);
			printf("%d\n", (int)output);
		}
		else if (command == 3) {
			break;
		}
		else {
			printf("잘못된 입력입니다.\n");
		}
	}
	for (int i = 0;i < k;i++) free(*(pp + i));
	free(pp);
	return 0;
}