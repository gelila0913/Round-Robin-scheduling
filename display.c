#include <stdio.h>
#include "display.h"
#include "metrics.h"

#define MAX 100

int gProcess[MAX];
int gStart[MAX];
int gEnd[MAX];
int gSize = 0;

static int digitCount(int value)
{
    int digits = 1;

    while (value >= 10)
    {
        value /= 10;
        digits++;
    }

    return digits;
}

void displayGanttChart(void)
{
    int cellWidth = 6;

    if (gSize == 0)
    {
        printf("\nGantt Chart: No data\n\n");
        return;
    }

    for (int i = 0; i < gSize; i++)
    {
        int processWidth = digitCount(gProcess[i]) + 3;
        int timeWidth = digitCount(gEnd[i]) + 2;

        if (processWidth > cellWidth)
        {
            cellWidth = processWidth;
        }

        if (timeWidth > cellWidth)
        {
            cellWidth = timeWidth;
        }
    }

    printf("\nGantt Chart:\n");

    for (int i = 0; i < gSize; i++)
    {
        printf("| P%-*d", cellWidth - 3, gProcess[i]);
    }
    printf("|\n");

    for (int i = 0; i < gSize; i++)
    {
        printf("%-*d", cellWidth, gStart[i]);
    }
    printf("%d\n\n", gEnd[gSize - 1]);
}

void displayResults(Process p[], int n)
{

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival_time,
               p[i].burst_time,
               p[i].completion_time,
               p[i].turnaround_time,
               p[i].waiting_time,
               p[i].response_time);
    }

    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaroundTime(p, n));
    printf("Average Waiting Time: %.2f\n", avgWaitingTime(p, n));
    printf("Average Response Time: %.2f\n", avgResponseTime(p, n));
}
