/*
	���� ���� ���α׷�(Score Management System, SMS)

*/
#include <stdio.h>



int main()
{
	char name[20];
	int scores[3] = { 0 , };
	char categories[3][10] = { "����", "����", "����" };
	//	1�� �л��� ��, ��, ��, ����, ���



	puts("\n�л� �̸��� �Է��ϼ���.");
	printf("\t>>> ");
	fgets(name, 20, stdin);		//20����Ʈ �ȿ����� ��� ���ڸ� ��� ����Ѵ�;
	for (int i = 0; i < 3; i++) {
	printf("\n%s ������ �Է��ϼ���.\n",categories[i]);
	printf("\t>>> ");
	scanf("%d", &scores[i]);

	}
	// TODO : ������ ��հ��
	int sum = scores[0] + scores[1] + scores[2];
	float mean = sum / 3.0;
	//��ºκ�
	printf("%s", name);

	for (int i = 0; i < 3; i++) {
	printf("%d ", scores[i]);
	
	}
	puts("");
	printf("%d\n", sum);
	printf("%f", mean);


	

	return 0;
}
