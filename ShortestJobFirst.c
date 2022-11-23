#include <stdio.h>

int main(void)
{
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;
    printf("Enter thenumber of processes!!");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        p[i] = i;
        printf("Enter the number of burst Time of P = %d: ", i);
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (k = 1; k < n; k++)
        {
            if (bt[i] > bt[k])
            {
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
            wt[0] = wtavg = 0;
            tat[0] = tatavg = bt[0];
            for (i = 1; i < n; i++)
            {
                wt[i] = wt[i - 1] + bt[i - 1];
                tat[i] = tat[i - 1] + wt[i - 1];
                wtavg = wtavg + wt[i];
                tatavg = tatavg + tat[i];
            }
        }
    }
    printf("\n\n P \t B \t WT \t TAT");
    for (i = 0; i < n; i++)
    {
        printf("\n\n %d \t %d \t %d \t %d", i, bt[i], wt[i], tat[i]);
    }
    printf("\n\nAvg Waiting time: %f \n", wtavg);
    printf("\n\nAvg Turn Around time: %f \n\n\n", tatavg);
}
