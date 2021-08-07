/*
	성적 관리 프로그램(Score Management System, SMS)

*/
#include <stdio.h>



int main()
{
	char name[20];
	int scores[3] = { 0 , };
	char categories[3][10] = { "국어", "영어", "수학" };
	//	1명 학생의 국, 영, 수, 총점, 평균



	puts("\n학생 이름을 입력하세요.");
	printf("\t>>> ");
	fgets(name, 20, stdin);		//20바이트 안에서는 모든 문자를 출력 허용한다;
	for (int i = 0; i < 3; i++) {
	printf("\n%s 성적을 입력하세요.\n",categories[i]);
	printf("\t>>> ");
	scanf("%d", &scores[i]);

	}
	// TODO : 총점과 평균계산
	int sum = scores[0] + scores[1] + scores[2];
	float mean = sum / 3.0;
	//출력부분
	printf("%s", name);

	for (int i = 0; i < 3; i++) {
	printf("%d ", scores[i]);
	
	}
	puts("");
	printf("%d\n", sum);
	printf("%f", mean);


	

	return 0;
}
