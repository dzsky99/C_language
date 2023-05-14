## 동전 던지기
```c
#include <stdlib.h> // srand 함수 등을 불러온다
#include <stdio.h>
#include <time.h> // time 함수 등을 불러온다

int coin_toss(void); // 함수의 원형 선언

int main(void)
{
    int toss;
    int heads = 0;
    int tails = 0;
    srand((unsigned)time(NULL)); // 시드 값이 계속 변하도록 srand 함수를 통해 time 함수를 시드로 설정한다.

    for (toss = 0; toss < 100; toss++) // for 블럭을 100번 반복한다.
    {
        if(coin_toss() == 1) // 함수 coin_toss의 반환 값이 1이면 앞면(heads)가 증가 0이면 뒷면(tails)이 증가
            heads++;
        else
            tails++;
    }

    printf("동전의 앞면: %d \n", heads);
    printf("동전의 뒷면: %d \n", tails);
    return 0;
}

int coin_toss(void)
{
    int head = rand() % 2; // 2로 나눈 나머지는 1과 0만을 반환한다.
    return head;
}

```

## 자동차 게임 
```c
#include <stdlib.h>
#include <stdio.h>
#include <conio.h> // _getch() 사용
#include <time.h>

void disp_car(int car_number, int distance)
{
    int i;
    printf("CAR #%d:", car_number);
    for( i = 0; i < distance/10; i++ ) // 너무 많은 별을 방지하기 위해 값을 간소화한다.
    {
        printf("*");
    }
    printf("\n");
}

int main(void)
{ 
    int i;
    int car1_dist=0, car2_dist=0, car3_dist=0;
    srand( (unsigned)time( NULL ) );
    for( i = 0; i < 6; i++ ) 
    {
        car1_dist += rand() % 100; // 난수의 값을 %를 통하여 0~99로 제한한다 % 10은 0~9
        car2_dist += rand() % 100;
        car3_dist += rand() % 100;
        disp_car(1, car1_dist);
        disp_car(2, car2_dist);
        disp_car(3, car3_dist);
        printf("---------------------\n");
        _getch(); // 키보드에서 하나의 입력을 받는다. 받을 때 까지 다음 코드가 실행되지 않음.
    }             // 키보드를 누를 때 마다 for 문이 실행되는 효과
    return 0;
}
```

## 시간 맞추기 게임
```c
#include <time.h>
#include <stdio.h>

int main(void)
{
    time_t start, end; // time_t는 unsigned long과 동일하다.
    start = time(NULL);
    printf("10초가 되면 아무 키나 누르세요\n");
    while(1) 
    {
        if (getchar()) // 엔터 입력 받을 시 break에 의해 종료된다
        break;
    }
    printf("종료되었습니다.\n");
    end = time(NULL); 
    printf("경과된 시간은 %ld 초입니다. \n", end - start); // time 함수는 1970년 1월 1일 0시 0분 0초에서부터 흐른 시간을 초 단위로 나타내기 때문에
    return 0;                                            // end에서 start를 빼주면 흐른 시간을 알 수 있다.                      
}
```

## 삼각함수 그리기

```c
#include <stdio.h>
#include <math.h>
#define PI 3.141592 // 기호상수 선언


double rad(double degree)
{
    return PI * degree / 180.0;
}

void drawbar(int height)
{
    for (int i = 0; i < height; i++)
        {
            printf("*"); // height만큼 *출력
        }
    printf("\n");
}


int main(void)
{
    int degree, x, y;
    for (degree = 0; degree <= 180; degree += 10) // sin(0) 에서 sin(pi)까지 rad를 pi/18씩 증가시킴 
    {                                                   // 싸인값은 -1.0에서 1.0이므로 정수로 반올림하여서 증폭한다.
        y = (int)(60 * sin(rad((double)degree)) + 0.5); // *60, +0.5는 값을 크게하기 위한 장치
        drawbar(y); // (int), (double)로 형변환
    }
return 0;
}
```

## 공학용 계산기

```c
#include <stdio.h>
#include <math.h> //수학 관련 함수 사용


int menu(void)
{
    int n;
    printf("1.팩토리얼\n");
    printf("2.싸인\n");
    printf("3.로그(base 10)\n");
    printf("4.제곱근\n");
    printf("5.순열(nPr)\n");
    printf("6.조합(nCr)\n");
    printf("7.종료\n");
    printf("선택해주세요: ");
    scanf("%d", &n); 
    return n; 
}

void factorial() 
{
    long long n, result=1, i;
    printf("정수를 입력하시오: ");
    scanf("%lld", &n);
    for (i = 1; i <= n; i++) 
        result = result * i;
    printf("결과 = %lld\n\n", result);
}

void sine() 
{
    double a, result;
    printf("각도를 입력하시오: ");
    scanf("%lf", &a);
    result = sin(a);
    printf("결과 = %lf\n\n", result);
}

void logBase10()
{
    double a, result;
    printf("실수값을 입력하시오: ");
    scanf("%lf", &a);
    if (a <= 0.0) 
        printf("오류\n");
    else 
    {
        result = log10(a);
        printf("결과 = %lf\n\n", result);
    }
}
// 제곱근을 구하는 함수 sqrt()
int main(void)
{
    while (1) // while문에서 0이 반환되면 반복을 멈춘다.
    {
        switch (menu()) // menu()의 반환값에 따라 case를 실행한다.
        {
            case 1:
                factorial();
                break;
            case 2:
                sine();
                break;
            case 3:
                logBase10();
                break;
            case 7:
                printf("종료합니다.\n");
                return 0;
            default:
                printf("잘못된 선택입니다.\n");
                break;
        }
    }
}

```
