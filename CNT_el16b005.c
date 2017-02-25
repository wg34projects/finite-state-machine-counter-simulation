#include <stdio.h>
#include <stdlib.h>

void up(int *count);
void dw(int *count);

int reset = 0;
int count = 0;
int enable = 0;
int updown = 0;

int main()
{
    char input;
    printf("counter with (SR) RESET / (CE) CLOCK ENABLE / (UD) UP or DOWN\n");
    printf("r = set reset input - SR = 1 and the counter is set to 0\n");
    printf("e = set clock enable input - CE = 1 and the counter is starting\n");
    printf("u = set UD = 0 and we count up, this is also the clock\n");
    printf("d = set UD = 1 and we count up, this is also the clock\n");
    printf("pressing u or d after CE = 1 is the clock");
    printf("x = EXIT\n");
    printf("please enter only small letters and only 1 letter\n\n");
    printf("status - CNT %d / SR (press r) %d / CE (press e) %d / UD (press u or d) %d\n",count, reset, enable, updown);

    while(1)
    {
        input = getc(stdin);
        printf("\n");
        getchar();
        switch(input)
        {
        case 'r':
            {
                if(reset == 0)
                {
                    reset = 1;
                    count = 0;
                }
                else
                {
                    reset = 0;
                }
                count = 0;
                printf("status - CNT %d / SR (press r) %d / CE (press e) %d / UD (press u or d) %d\n",count, reset, enable, updown);
                break;
            }
        case 'e':
            {
                if(enable == 1)
                {
                    enable = 0;
                }
                else
                {
                    enable = 1;
                }
                printf("status - CNT %d / SR (press r) %d / CE (press e) %d / UD (press u or d) %d\n",count, reset, enable, updown);
                break;
            }


        case 'u':
            {
                updown = 0;
                if(enable == 1 && reset == 0)
                {
                    up(&count);
                }
                printf("status - CNT %d / SR (press r) %d / CE (press e) %d / UD (press u or d) %d\n",count, reset, enable, updown);
                break;
            }

        case 'd':
            {
                updown = 1;
                if(enable == 1 && reset == 0)
                {
                    dw(&count);
                }
                printf("status - CNT %d / SR (press r) %d / CE (press e) %d / UD (press u or d) %d\n",count, reset, enable, updown);
                break;
            }
        case 'x':
        {
            return -1;
        }
        }
    }
    printf("break\n");
    printf("status - CNT %d / SR (press r) %d / CE (press e) %d / UD (press u or d) %d\n",count, reset, enable, updown);
    return 0;
}


void up(int *count)
{
    *count = *count + 1;
}

void dw(int *count)
{
    *count = *count - 1;
}
