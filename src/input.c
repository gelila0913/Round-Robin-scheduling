#include <stdio.h>
#include "input.h"

void getInput(Process processes[], int *n, int *quantum){
    printf("Enter number of processes: ");
    scanf("%d", n);

    for (int i=0; i< *n;i++){
        processes[i].pid = i + 1;
        printf("\nProcess P%d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);

        printf("Burst (Service) Time: ");
        scanf("%d", &processes[i].burst_time);

        printf("Priority: ");
        scanf("%d", &processes[i].priority);

        processes[i].remaining_time = processes[i].burst_time;
    }
    printf("\nEnter Time Quantum: ");
    scanf("%d", quantum);
}