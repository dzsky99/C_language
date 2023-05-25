## 정보올림피아드 문제

http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=574&sca=20

```c
#include <stdio.h>

int main()
{   
    int s, e;

    while(1)
    {
        scanf("%d %d",&s, &e);

        if((s >= 2 && s <= 9) && (e >= 2 && e <= 9)) 
        {
            if(s>e)
            {
                for(int i=1; i<=9; i++)
                {
                    int big = s, small = e;

                    for(big; big>=small; big--)
                    {
                        printf("%d * %d = %2d   ",big, i, big*i);
                    }

                    printf("\n");
                }
            }

            else
            {
                for(int i=1; i<=9; i++)
                {
                    int big = e, small = s;

                    for(small; small<=big; small++)
                    {
                        printf("%d * %d = %2d   ",small, i, small*i);
                    }
                    
                    printf("\n");
                }
            }

        break;
        }

        else
        {
        printf("INPUT ERROR!\n");
        }
    }
}
```

https://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=706&sca=2030 
