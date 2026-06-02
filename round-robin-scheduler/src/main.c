/**
 * ROUND-ROBIN CPU SCHEDULER
 * =========================
 * A complete implementation of the Round-Robin scheduling algorithm.
 * 
 * Features:
 * - Configurable time quantum
 * - Process metrics calculation (TAT, WT, RT)
 * - Visual Gantt chart display
 * - Modular, maintainable code structure
 * 
 * Build Instructions:
 * - Windows (MinGW): mingw32-make
 * - Linux/Mac: make
 * 
 * Run: build/rr.exe (Windows) or ./build/rr (Linux/Mac)
 */

#include <stdio.h>
#include "process.h"
#include "input.h"
#include "round_robin.h"
#include "metrics.h"
#include "display.h"

int main() {
    Process processes[100];  // Support up to 100 processes
    int n, quantum;

    // Step 1: Get user input
    getInput(processes, &n, &quantum);

    // Step 2: Run Round-Robin scheduling algorithm
    roundRobin(processes, n, quantum);

    // Step 3: Calculate performance metrics
    calculateMetrics(processes, n);

    // Step 4: Display results
    displayResults(processes, n);

    // Step 5: Display Gantt chart visualization
    displayGanttChart();

    return 0;
}
