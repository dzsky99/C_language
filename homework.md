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
