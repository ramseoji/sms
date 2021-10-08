/**
 * @file sms.c
 * @brief Mission 04: 성적 관리 프로그램(Score Management System, SMS)
 *
 * '3명' 의 학생에 대해 구조체 배열로 성적을 관리할 수 있는 프로그램을 작성합니다.
 * 주어진 코드의 TODO: 부분을 잘 읽고 코드를 작성하세요.
 *
 * @author CoRock
 */
#include <stdio.h>

#define STUDENT_COUNT 3

 /** @struct Student
  * @brief 학생에 대한 정보를 가지고 있는 자료형
  * TODO: 다음과 같은 멤버 변수를 포함한 Student 구조체를 선언하세요.
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
     * TODO: 기존 프로그램에서 선언한 구조체를 이용하여 구조체 배열을 생성합니다.
     * Student 타입의 3개짜리 students 배열을 생성하고 사용하세요.
     */
    const char categories[5][10] = { "국 어", "영 어", "수 학", "총 점", "평 균" };
    Student students[3];
    /**
     * TODO: 함수의 인자로 무엇을 전달해야 할 지 고민해보고 빈 칸을 채우세요.
     */
    input(students, categories);
    operate(students);
    print(students, categories);

    return 0;
}


/**
 * @brief 적절한 매개변수 타입을 설정하고, 그에 따른 입력 함수를 구현하세요.
 */
void input(Student* students, const char(*categories)[10])
{

    for (int i = 0; i < STUDENT_COUNT; i += 1) {
        puts("\n학생의 이름을 입력하세요.");
        printf(">>> ");
        rewind(stdin);
        scanf("%[^\n]s", students[i].name);

        printf("\n%s 성적을 입력하세요.\n", categories[0]);
        printf(">>> ");
        scanf("%d", &students[i].kor);

        printf("\n%s 성적을 입력하세요.\n", categories[1]);
        printf(">>> ");
        scanf("%d", &students[i].eng);

        printf("\n%s 성적을 입력하세요.\n", categories[2]);
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
         * TODO: 학생 3명에 대한 총점과 평균을 참조하여 계산하고 저장하세요.
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
    printf("| 번 호 | 학 생 명 | %s | %s | %s | %s | %s |\n",
        categories[0], categories[1], categories[2], categories[3], categories[4]);
    puts("+-------+----------+-------+-------+-------+-------+-------+");

    for (int i = 0; i < STUDENT_COUNT; i += 1) {
        /**
         * TODO: 학생 각각의 이름과 국/영/수/총점, 그리고 평균을 출력하세요.
         */
        printf("| %5d | %-8s ", count++, students[i].name);
        printf("| %5d | %5d | %5d | %5d ",
            students[i].kor, students[i].eng, students[i].math, students[i].total);
        printf("| %5.2f |\n", students[i].mean);
    }

    puts("+-------+----------+-------+-------+-------+-------+-------+");
}
