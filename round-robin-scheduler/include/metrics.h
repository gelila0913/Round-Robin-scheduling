#ifndef METRICS_H
#define METRICS_H

#include "process.h"

void calculateMetrics(Process processes[], int n);

float avgWaitingTime(Process processes[], int n);
float avgTurnaroundTime(Process processes[], int n);
float avgResponseTime(Process processes[], int n);

#endif
