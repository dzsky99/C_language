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