/**
 * METRICS MODULE
 * ==============
 * This module calculates performance metrics for CPU scheduling algorithms.
 * 
 * Key Metrics:
 * - Turnaround Time (TAT): Total time from arrival to completion
 * - Waiting Time (WT): Time spent in ready queue (not executing)
 * - Response Time (RT): Time from arrival to first execution
 * 
 * These metrics help evaluate scheduler efficiency and user experience.
 */

#include "metrics.h"

/**
 * Calculate turnaround time and waiting time for all processes
 * 
 * Formulas:
 * - Turnaround Time = Completion Time - Arrival Time
 * - Waiting Time = Turnaround Time - Burst Time
 * 
 * @param processes Array of all processes
 * @param n Number of processes
 */
void calculateMetrics(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        // TAT = Total time in system (arrival to completion)
        processes[i].turnaround_time =
            processes[i].completion_time - processes[i].arrival_time;

        // WT = Time not executing (TAT - actual CPU time used)
        processes[i].waiting_time =
            processes[i].turnaround_time - processes[i].burst_time;
    }
}

/**
 * Calculate average waiting time across all processes
 * 
 * Lower values indicate better scheduler performance.
 * This metric directly impacts user satisfaction.
 * 
 * @param processes Array of all processes
 * @param n Number of processes
 * @return Average waiting time
 */
float avgWaitingTime(Process processes[], int n) {
    float total = 0;

    for (int i = 0; i < n; i++)
        total += processes[i].waiting_time;

    return total / n;
}

/**
 * Calculate average turnaround time across all processes
 * 
 * Measures overall system efficiency (end-to-end process lifecycle).
 * Balances throughput and responsiveness.
 * 
 * @param processes Array of all processes
 * @param n Number of processes
 * @return Average turnaround time
 */
float avgTurnaroundTime(Process processes[], int n) {
    float total = 0;

    for (int i = 0; i < n; i++)
        total += processes[i].turnaround_time;

    return total / n;
}

/**
 * Calculate average response time across all processes
 * 
 * Critical for interactive systems (web servers, GUIs, games).
 * Measures "time to first response" - key for user experience.
 * 
 * @param processes Array of all processes
 * @param n Number of processes
 * @return Average response time
 */
float avgResponseTime(Process processes[], int n) {
    float total = 0;

    for (int i = 0; i < n; i++)
        total += processes[i].response_time;

    return total / n;
}
