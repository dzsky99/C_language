# C_language
C language practice

```C
```

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
