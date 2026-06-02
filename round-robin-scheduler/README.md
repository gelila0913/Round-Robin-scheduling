# Round-Robin CPU Scheduler

A complete implementation of the **Round-Robin CPU scheduling algorithm** in C, featuring process metrics calculation, Gantt chart visualization, and modular architecture.

## 🎯 Features

- ✅ **Round-Robin Scheduling Algorithm**
  - Configurable time quantum
  - Preemptive scheduling
  - Circular ready queue
  - Starvation prevention

- 📊 **Performance Metrics**
  - Waiting Time (WT)
  - Turnaround Time (TAT)
  - Response Time (RT)
  - Average statistics

- 📈 **Visual Gantt Chart**
  - Dynamic column sizing
  - Process execution timeline
  - Merged consecutive blocks

- 🏗️ **Clean Architecture**
  - Modular design
  - Separation of concerns
  - Well-documented code
  - Easy to extend

## 📁 Project Structure

```
round-robin-scheduler/
├── include/              # Header files
│   ├── process.h        # Process data structure
│   ├── round_robin.h    # Scheduler interface
│   ├── input.h          # Input handling
│   ├── metrics.h        # Metrics calculation
│   └── display.h        # Output formatting
├── src/                 # Source files
│   ├── main.c           # Program entry point
│   ├── round_robin.c    # Core algorithm
│   ├── input.c          # User input
│   ├── metrics.c        # Performance analysis
│   └── display.c        # Result visualization
├── build/               # Compiled executable
├── makefile             # Build configuration
└── README.md            # This file
```

## 🚀 Getting Started

### Prerequisites

- **GCC Compiler** (MinGW for Windows, GCC for Linux/Mac)
- **Make** utility

### Building the Project

#### Windows (MinGW)
```bash
mingw32-make
```

#### Linux/Mac
```bash
make
```

### Running the Program

#### Windows
```bash
build\rr.exe
```

#### Linux/Mac
```bash
./build/rr
```

### Cleaning Build Files

```bash
mingw32-make clean  # Windows
make clean          # Linux/Mac
```

## 📝 Usage Example

```
Enter number of processes: 3

Process P1
Arrival Time: 0
Burst (Service) Time: 10
Priority: 1

Process P2
Arrival Time: 1
Burst (Service) Time: 5
Priority: 2

Process P3
Arrival Time: 2
Burst (Service) Time: 7
Priority: 3

Enter Time Quantum: 4
```

### Output

```
Process AT   BT   CT   TAT  WT   RT
P1      0    10   22   22   12   0
P2      1    5    17   16   11   3
P3      2    7    20   18   11   5

Average Turnaround Time: 18.67
Average Waiting Time: 11.33
Average Response Time: 2.67

Gantt Chart:
| P1    | P2    | P3    | P1    | P2 | P3  | P1  |
0       4       8       12      16  17   20   22
```

## 📊 Understanding the Metrics

### Turnaround Time (TAT)
**Formula:** `Completion Time - Arrival Time`

Total time from process arrival to completion. Measures overall efficiency.

### Waiting Time (WT)
**Formula:** `Turnaround Time - Burst Time`

Time spent in ready queue (not executing). Lower is better for user experience.

### Response Time (RT)
**Formula:** `First Execution Start - Arrival Time`

Time until process first gets CPU. Critical for interactive systems.

## 🔧 How It Works

### Algorithm Overview

1. **Initialization**
   - Create ready queue
   - Add processes that have arrived at time 0

2. **Main Loop** (while processes remain)
   - If queue empty → CPU idle, check for arrivals
   - Dequeue next process
   - Execute for min(quantum, remaining_time)
   - Update metrics
   - Check for new arrivals
   - Re-queue if process not complete

3. **Completion**
   - Calculate derived metrics (TAT, WT)
   - Display results and Gantt chart

### Time Quantum Selection

- **Too Small:** High context-switching overhead
- **Too Large:** Becomes First-Come-First-Served
- **Recommended:** 10-100ms in real systems, 4-10 units in simulation

## 🧩 Module Breakdown

### `process.h`
Defines the Process structure containing all process attributes.

### `input.c`
Handles user input for process details and time quantum.

### `round_robin.c`
Core scheduling algorithm implementation with ready queue management.

### `metrics.c`
Calculates performance metrics (WT, TAT, RT) and averages.

### `display.c`
Formats and displays results including Gantt chart visualization.

## 🎓 Educational Value

This project demonstrates:
- CPU scheduling algorithms
- Data structures (queues, arrays, structs)
- C programming concepts (pointers, modular design)
- Operating system fundamentals
- Performance analysis techniques

## 🔮 Future Enhancements

- [ ] Priority-based Round-Robin
- [ ] Multi-level queue scheduling
- [ ] File input support
- [ ] Comparison with other algorithms (FCFS, SJF, Priority)
- [ ] Interactive GUI
- [ ] Export results to CSV

## 📚 References

- Operating System Concepts by Silberschatz, Galvin, and Gagne
- Modern Operating Systems by Andrew S. Tanenbaum

## 📄 License

This project is open source and available for educational purposes.

## 👨‍💻 Author

Created as an educational project to demonstrate CPU scheduling concepts.

---

**⭐ If you found this helpful, please star the repository!**
