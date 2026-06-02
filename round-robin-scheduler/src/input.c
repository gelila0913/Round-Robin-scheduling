/**
 * INPUT MODULE
 * ============
 * Handles all user input for the Round-Robin scheduler simulation.
 * Collects process details and time quantum configuration.
 */

#include <stdio.h>
#include "input.h"

/**
 * Get scheduling input from user
 * 
 * Collects:
 * - Number of processes
 * - For each process: arrival time, burst time, priority
 * - Time quantum for Round-Robin scheduling
 * 
 * @param processes Array to store process data
 * @param n Pointer to store number of processes
 * @param quantum Pointer to store time quantum value
 */
void getInput(Process processes[], int *n, int *quantum) {
    printf("Enter number of processes: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        // Assign process ID (1-indexed for user friendliness)
        processes[i].pid = i + 1;

        printf("\nProcess P%d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);

        printf("Burst (Service) Time: ");
        scanf("%d", &processes[i].burst_time);

        printf("Priority: ");
        scanf("%d", &processes[i].priority);

        // Initialize remaining time to full burst time (process hasn't run yet)
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", quantum);
}