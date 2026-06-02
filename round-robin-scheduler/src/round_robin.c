/**
 * ROUND-ROBIN SCHEDULER MODULE
 * ============================
 * Core implementation of the Round-Robin CPU scheduling algorithm.
 * 
 * Algorithm Overview:
 * 1. Maintains a ready queue of processes
 * 2. Each process runs for at most 'quantum' time units
 * 3. Preempts processes that exceed quantum
 * 4. Completed processes are removed, others go to back of queue
 * 
 * Key Features:
 * - Prevents starvation (all processes get CPU time)
 * - Fair time-sharing among processes
 * - Configurable time quantum for tuning performance
 */

#include <stdio.h>
#include "round_robin.h"

#define MAX 100

/**
 * Execute Round-Robin scheduling algorithm
 * 
 * @param processes Array of processes to schedule
 * @param n Number of processes
 * @param quantum Time slice (max CPU time per turn)
 */
void roundRobin(Process processes[], int n, int quantum) {

    int time = 0;         // Current simulation time (CPU clock)
    int completed = 0;    // Number of completed processes

    // Ready queue implementation (circular queue)
    int queue[MAX];
    int front = 0, rear = 0;
    int visited[MAX] = {0};  // Track which processes are in queue

    // Gantt chart data storage (local buffers)
    int ganttProcess[MAX];
    int startTime[MAX];
    int endTime[MAX];
    int gIndex = 0;

    // External global variables (defined in display.c)
    // Used to share Gantt chart data between modules
    extern int gProcess[MAX];
    extern int gStart[MAX];
    extern int gEnd[MAX];
    extern int gSize;

    // Initialize response time to -1 (sentinel: "not yet executed")
    for (int j = 0; j < n; j++) {
        processes[j].response_time = -1;
    }

    // Add processes that have already arrived at time 0
    for (int j = 0; j < n; j++) {
        if (processes[j].arrival_time <= time) {
            queue[rear++] = j;
            visited[j] = 1;
        }
    }

    // Main scheduling loop - continues until all processes complete
    while (completed < n) {

        // If queue is empty, CPU is idle
        if (front == rear) {
            time++;  // Advance time
            // Check for newly arrived processes
            for (int j = 0; j < n; j++) {
                if (!visited[j] && processes[j].arrival_time <= time) {
                    queue[rear++] = j;
                    visited[j] = 1;
                }
            }
            continue;  // Recheck queue
        }

        // Dequeue next process
        int i = queue[front++];

        int start = time;
        
        // Calculate execution time: minimum of quantum and remaining time
        int execTime = (processes[i].remaining_time <= quantum)
                        ? processes[i].remaining_time
                        : quantum;

        // Record response time on first execution
        if (processes[i].response_time == -1) {
            processes[i].response_time = start - processes[i].arrival_time;
        }

        // Execute process
        processes[i].remaining_time -= execTime;
        time += execTime;

        // Optimize Gantt chart: merge consecutive blocks of same process
        if (gIndex > 0 &&
            ganttProcess[gIndex - 1] == processes[i].pid &&
            endTime[gIndex - 1] == start) {
            endTime[gIndex - 1] = time;  // Extend previous block
        } else {
            // Create new Gantt chart entry
            ganttProcess[gIndex] = processes[i].pid;
            startTime[gIndex] = start;
            endTime[gIndex] = time;
            gIndex++;
        }

        // Check if process completed
        if (processes[i].remaining_time == 0) {
            processes[i].completion_time = time;
            completed++;
        }

        // Add newly arrived processes to queue
        for (int j = 0; j < n; j++) {
            if (!visited[j] && processes[j].arrival_time <= time) {
                queue[rear++] = j;
                visited[j] = 1;
            }
        }

        // Re-add current process to queue if not finished (preemption)
        if (processes[i].remaining_time > 0) {
            queue[rear++] = i;
        }
    }

    // Export Gantt chart data to global variables for display module
    for (int i = 0; i < gIndex; i++) {
        gProcess[i] = ganttProcess[i];
        gStart[i] = startTime[i];
        gEnd[i] = endTime[i];
    }

    gSize = gIndex;
}
