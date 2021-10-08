/**
 * @file sms.c
 * @brief Mission 04: ���� ���� ���α׷�(Score Management System, SMS)
 *
 * '3��' �� �л��� ���� ����ü �迭�� ������ ������ �� �ִ� ���α׷��� �ۼ��մϴ�.
 * �־��� �ڵ��� TODO: �κ��� �� �а� �ڵ带 �ۼ��ϼ���.
 *
 * @author CoRock
 */
#include <stdio.h>

#define STUDENT_COUNT 3

 /** @struct Student
  * @brief �л��� ���� ������ ������ �ִ� �ڷ���
  * TODO: ������ ���� ��� ������ ������ Student ����ü�� �����ϼ���.
  * @var name (20 bytes)
  * @var kor
  * @var eng
  * @var math
  * @var total
  * @var mean
  */


typedef struct Student
{
    char name[20];
    int kor, eng, math;
    int total;
    double mean;

} Student;





void input(Student* students, const char(*categories)[10]);
void operate(Student* students);
void print(Student* students, const char(*categories)[10]);


int main()
{
    /**
     * TODO: ���� ���α׷����� ������ ����ü�� �̿��Ͽ� ����ü �迭�� �����մϴ�.
     * Student Ÿ���� 3��¥�� students �迭�� �����ϰ� ����ϼ���.
     */
    const char categories[5][10] = { "�� ��", "�� ��", "�� ��", "�� ��", "�� ��" };
    Student students[3];
    /**
     * TODO: �Լ��� ���ڷ� ������ �����ؾ� �� �� ����غ��� �� ĭ�� ä�켼��.
     */
    input(students, categories);
    operate(students);
    print(students, categories);

    return 0;
}


/**
 * @brief ������ �Ű����� Ÿ���� �����ϰ�, �׿� ���� �Է� �Լ��� �����ϼ���.
 */
void input(Student* students, const char(*categories)[10])
{

    for (int i = 0; i < STUDENT_COUNT; i += 1) {
        puts("\n�л��� �̸��� �Է��ϼ���.");
        printf(">>> ");
        rewind(stdin);
        scanf("%[^\n]s", students[i].name);

        printf("\n%s ������ �Է��ϼ���.\n", categories[0]);
        printf(">>> ");
        scanf("%d", &students[i].kor);

        printf("\n%s ������ �Է��ϼ���.\n", categories[1]);
        printf(">>> ");
        scanf("%d", &students[i].eng);

        printf("\n%s ������ �Է��ϼ���.\n", categories[2]);
        printf(">>> ");
        scanf("%d", &students[i].math);
        puts("");
        getchar();
    }
}


void operate(Student* students)
{
    for (int i = 0; i < STUDENT_COUNT; i += 1) {
        /**
         * TODO: �л� 3�� ���� ������ ����� �����Ͽ� ����ϰ� �����ϼ���.
         */

        students[i].total = students[i].kor + students[i].eng + students[i].math;

        students[i].mean = students[i].total / 3.0;

    }
}


void print(Student* students, const char(*categories)[10])
{
    int count = 1;

    puts("\n================= Score Management Systems =================");
    puts("+-------+----------+-------+-------+-------+-------+-------+");
    printf("| �� ȣ | �� �� �� | %s | %s | %s | %s | %s |\n",
        categories[0], categories[1], categories[2], categories[3], categories[4]);
    puts("+-------+----------+-------+-------+-------+-------+-------+");

    for (int i = 0; i < STUDENT_COUNT; i += 1) {
        /**
         * TODO: �л� ������ �̸��� ��/��/��/����, �׸��� ����� ����ϼ���.
         */
        printf("| %5d | %-8s ", count++, students[i].name);
        printf("| %5d | %5d | %5d | %5d ",
            students[i].kor, students[i].eng, students[i].math, students[i].total);
        printf("| %5.2f |\n", students[i].mean);
    }

    puts("+-------+----------+-------+-------+-------+-------+-------+");
}
