/**
 * PROCESS DATA STRUCTURE
 * ======================
 * Defines the Process structure that stores all information about a process.
 * 
 * This structure is the core data model for the scheduler, containing:
 * - Input data: arrival time, burst time, priority
 * - Runtime data: remaining time
 * - Output data: completion time, waiting time, turnaround time, response time
 */

#ifndef PROCESS_H
#define PROCESS_H

typedef struct {
    int pid;               // Process ID
    int arrival_time;      // When process arrives in ready queue
    int burst_time;        // Total CPU time needed
    int remaining_time;    // CPU time still needed (for preemption)

    int completion_time;   // When process finishes
    int waiting_time;      // Time spent waiting in queue
    int turnaround_time;   // Total time in system (arrival to completion)
    int response_time;     // Time until first execution
    int priority;          // Priority value (for future extensions)
} Process;

#endif
