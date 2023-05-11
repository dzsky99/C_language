# C_language
C language practice

<br>

## [과제 바로가기](homework.md)

<br><br>


4주차 나머지 연산자

```C
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define CHUNWON 1000
#define OBEKWON 500
#define BEKWON 100

int main(void)

{
int Cost, UsedMoney, change;

printf("물건 값을 입력하시요");
scanf("%d", &Cost);

printf("투입한 금액을 입력하시요");
scanf("%d", &UsedMoney);

printf("거스름돈은 다음과 같습니다.\n");

change = UsedMoney - Cost;

printf("천원권: %d장\n", change / CHUNWON);
change = change % CHUNWON;

printf("오백원 동전: %d개\n", change / OBEKWON);
change = change % OBEKWON;

printf("백원 동전: %d개", change / BEKWON);

return 0;
}
```

5주차 스위치 케이스 산술 계산기

```C
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)

{
    char op;
    int x, y, result;
    printf("수식을 입력하시오(예: 2 + 5) >> ");
    scanf("%d %c %d", &x, &op, &y);

    switch (op)
    {
    case '+':
        result = x + y;
        break;
    case '-':
        result = x - y;
        break;
    case '*':
        result = x * y;
        break;
    case '/':
        result = x / y;
        break;
    }

    printf("%d %c %d = %d", x, op, y, result);
    return 0;
}
```

5주차 중첩 if문

```C
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)

{
    char ch;
    printf("문자를 입력하시오: ");

    ch = getchar();
    if( ch >= 65 && ch <= 90 )
        printf("%c는 대문자입니다.\n", ch);
    else if( ch >= 97 && ch <= 122 )
        printf("%c는 소문자입니다.\n", ch);
    else if( ch >= 48 && ch <= 57 )
        printf("%c는 숫자입니다.\n", ch);
    else
        printf("%c는 기타문자입니다.\n", ch);

    return 0;
}
```

if문 홀짝

```C
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)

{
    int number;

    printf("정수를 입력하시오.");
    scanf("%d", &number);

    if(number % 2 == 1 || -1)
        printf("입력된 정수는 홀수입니다.");
    else
        printf("입력된 정수는 짝수입니다.");
    
    return 0;
}
```

6주차 while 구구단 출력
```C
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)

{
    int n;
    int i = 1;

    printf("출력하고 싶은 단: ");
    scanf("%d", &n);

    while (i <= 9)
    {
        printf("%d*%d = %d\n", n, i, n*i);
        i++;
    }

    return 0;
}
```
무한루프일때 if break로 끊기

```C
while (i > 0)
    {
        printf("%d*%d = %d\n", n, i, n*i);
        i++;

        if (i == 10)
        {
            break;
        }
    }
```

6주차 1부터 n까지의 합
```C
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)

{
    int n;
    int i = 1;
    int sum = 0;

    printf("정수를 입력하시오: ");
    scanf("%d", &n);

    while (i <= n)
    {
        sum = sum + i;
        i++;
    }
    
    printf("1부터 %d까지의 합은 %d입니다", n, sum);
    return 0;
}
```
짝수값만 더하기
```C
 while (i <= n)
    {
        if(i % 2 == 0)
        {
            sum = sum + i;
            printf("%d\n", i); /*i값 확인용*/
        }
        i++;
    }
```
while로 n번 입력받아 출력하기
```c
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)

{
    int A, B;
    int T, i = 1;
    int sum;

    scanf("%d", &T); /*입력받을 횟수*/

    while (i <= T)
    {
        scanf("%d %d", &A, &B);
        sum = A + B;
        printf("%d\n", sum);
        i++;
    }

    return 0;
}
```
do while 문

```c
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)

{
    int i = 0;
    do /* do...while문: while의 조건과 상관없이 루프 바디를 무조건 한번은 실행한다*/
    {
        printf("1---새로만들기\n");
        printf("2---파일열기\n");
        printf("3---파일닫기\n");
        printf("하나를 선택하시오");
        scanf("%d", &i);
    } while (i < 1 || i > 3);
    
    printf("선택된 메뉴=%d\n", i);
    return 0;
}
```
6주차 숫자맞추기

```c
#include <stdio.h>
#include <stdlib.h> /*스탠다드 라이브러리*/
#define _CRT_SECURE_NO_WARNINGS

int main(void)

{
    srand((unsigned)time(NULL)); // 난수 발생기 시드 설정
    int answer = rand()%100; // 정답을 난수로 발생한다. 
    int guess;
    int tries = 0;
    
    do {
        printf("정답을 추측하시오: ");
        scanf("%d", &guess);
        tries++;
        if (guess > answer)
            printf("LOW\n");
        else if (guess < answer)
            printf("HIGH\n");
    } while (guess != answer);

    printf("정답=%d\n", answer);
    printf("축하합니다. 시도횟수=%d", tries);
    return 0;
}
```
오른쪽부터 채워지는 계단만들기 for문으로

```c
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    int g;
    scanf("%d", &g);

    for (int i = 1; i <= g; i++)
    {
        for (int j = 1; j <= g-i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }

    printf("\n");
    }

}
```
7주차 사용자 정의 함수 및 조건 수식 연산자 

```c
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int max(int x, int y)
{
    return (x>y)? x : y; // 조건 수식 연산자
}


int main(void)
{
    int x, y, larger;
    printf("정수 2개를 입력하시오.");
    scanf("%d %d", &x, &y);

    larger = max(x, y);
    printf("더 큰 값은 %d입니다. \n", larger);
    return 0;
}
```
전역변수랑 지역변수 차이 알기

9주차
기호 상수

---
기호 상수의 장점: 
1. 숫자 그대로의 상수를 사용하는 경우에 상수의 값이 바뀌면 그 상수가 쓰인 곳을 일일이 찾아가서 바꿔야한다.
하지만 기호 상수를 쓰는 경우 기호 상수가 정의되는 곳에서 한번만 바꿔주면 된다. (값을 수정하기 쉽다)

2. 가독성이 좋아진다.
---

기호상수 정의 방법
```C
/*전처리에서*/ #define 기호상수이름 값

/*함수에서*/ const 자료형 기호상수이름 = 값

// + 기호상수는 자료형이 바뀔 수있다
```

예시
```C
#include <stdio.h>
#define TAX_RATE 0.2 //기호상수 선언
int main(void)
{
    const int MONTHS = 12; // 기호상수 선언
    int m_salary, y_salary; 
    printf( "월급을 입력하시요: "); 
    scanf("%d", &m_salary);
    y_salary = MONTHS * m_salary; 
    printf("연봉은 %d입니다.", y_salary);
    printf("세금은 %f입니다.", y_salary*TAX_RATE);
}
```

# 10주차
## 함수의 원형
(설명)
```C
#include <stdio.h>

int get_integer();
int add(int x, int y); // 컴파일러가 알아듣도록 함수의 원형을 써준다
int multi(int x, int y);
int div(int x, int y);
int factorial(int x);

int main()
{
    int x = get_integer();
    int y = get_integer();

    printf("합은 %d입니다.\n", add(x, y)); // 함수의 원형이 없다면 오류
    printf("곱은 %d입니다.\n", multi(x, y));
    printf("분은 %d입니다.\n", div(x, y));
    printf("%d! = %d", x, factorial(x));
}


int get_integer()
{
    int value;

    printf("정수를 입력하시오: ");
    scanf("%d", &value);

    return value;
}

int add(int x, int y)
{
    return x + y;
}

int multi(int x, int y)
{
    return x * y;
}

int div(int x, int y)
{
    return x / y;
}

/* int factorial(int x)     //for문 팩토리얼
{
    int sum = 1;

    for(int i=1; i<=x; i++)
    {
        sum *= i;
    }

    return sum;
} */

int factorial(int x)     //재귀함수 팩토리얼
{
    if(x == 1)
    {
        return 1;
    }
    else
    {
        return x * factorial(x-1);     // x * ... 4 * 3 * 2 * 1 
    }
}
```

# 11주차

소수찾기
```C
include <stdio.h>

int is_prime(int n);

int main()
{
    int n = 0;
    printf("정수를 입력하세요.\n");
    scanf("%d", &n);

    is_prime(n);  
}

int is_prime(int n)
{
    int counter = 0;

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            if(i % j == 0)
            {
                counter += 1;
            }
        }
        if(counter == 2)
        {
            printf("%d ", i);
        } 
    counter = 0;
    }
}
```
