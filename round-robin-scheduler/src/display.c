/**
 * DISPLAY MODULE
 * ==============
 * Handles output formatting and visualization of scheduling results.
 * 
 * Features:
 * - Process metrics table (AT, BT, CT, TAT, WT, RT)
 * - Dynamic Gantt chart with auto-sizing
 * - Average statistics display
 */

#include <stdio.h>
#include "display.h"
#include "metrics.h"

#define MAX 100

// Global variables for Gantt chart data (shared with round_robin.c)
int gProcess[MAX];
int gStart[MAX];
int gEnd[MAX];
int gSize = 0;

/**
 * Count digits in a number for formatting
 * 
 * @param value Number to analyze
 * @return Number of digits
 */
static int digitCount(int value) {
    int digits = 1;

    while (value >= 10) {
        value /= 10;
        digits++;
    }

    return digits;
}

/**
 * Display Gantt chart visualization of process execution
 * 
 * Shows timeline of which process ran when:
 * | P1    | P2    | P3    |
 * 0       4       8       12
 * 
 * Features:
 * - Dynamic column width based on largest numbers
 * - Handles consecutive executions of same process
 */
void displayGanttChart(void) {
    int cellWidth = 6;  // Minimum column width

    if (gSize == 0) {
        printf("\nGantt Chart: No data\n\n");
        return;
    }

    // Calculate optimal column width to fit all data
    for (int i = 0; i < gSize; i++) {
        int processWidth = digitCount(gProcess[i]) + 3;
        int timeWidth = digitCount(gEnd[i]) + 2;

        if (processWidth > cellWidth) {
            cellWidth = processWidth;
        }

        if (timeWidth > cellWidth) {
            cellWidth = timeWidth;
        }
    }

    printf("\nGantt Chart:\n");

    // Print process row
    for (int i = 0; i < gSize; i++) {
        printf("| P%-*d", cellWidth - 3, gProcess[i]);
    }
    printf("|\n");

    // Print timeline row
    for (int i = 0; i < gSize; i++) {
        printf("%-*d", cellWidth, gStart[i]);
    }
    printf("%d\n\n", gEnd[gSize - 1]);
}

/**
 * Display process scheduling results in table format
 * 
 * Shows all metrics for each process and averages:
 * - AT: Arrival Time
 * - BT: Burst Time
 * - CT: Completion Time
 * - TAT: Turnaround Time
 * - WT: Waiting Time
 * - RT: Response Time
 * 
 * @param p Array of processes
 * @param n Number of processes
 */
void displayResults(Process p[], int n) {

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid,
            p[i].arrival_time,
            p[i].burst_time,
            p[i].completion_time,
            p[i].turnaround_time,
            p[i].waiting_time,
            p[i].response_time);
    }

    // Display average metrics
    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaroundTime(p, n));
    printf("Average Waiting Time: %.2f\n", avgWaitingTime(p, n));
    printf("Average Response Time: %.2f\n", avgResponseTime(p, n));
}
