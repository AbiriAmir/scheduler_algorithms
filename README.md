# Page Replacement Algorithms

This repository contains C++ implementations of various page replacement algorithms, developed as part of an operating systems course project. Page replacement algorithms are crucial in managing a computer's memory by deciding which memory pages to swap out when new pages are needed, thereby optimizing system performance.

## Implemented Algorithms

The repository includes the following page replacement algorithms:

- **First-In-First-Out (FIFO)**: Replaces the oldest page in memory.
- **Least Recently Used (LRU)**: Replaces the page that hasn't been used for the longest period.
- **Optimal (OPT)**: Replaces the page that won't be used for the longest time in the future.
- **Random**: Randomly selects a page to replace.
- **Second Chance**: Gives pages a "second chance" before replacement, based on a reference bit.
- **Enhanced Second Chance**: An improvement over the Second Chance algorithm, considering both reference and modification bits.

## Repository Structure

- `Algorithm.cpp` / `Algorithm.h`: Base classes defining the structure for page replacement algorithms.
- `FifoAlgorithm.cpp` / `FifoAlgorithm.h`: Implementation of the FIFO algorithm.
- `LruAlgorithm.cpp` / `LruAlgorithm.h`: Implementation of the LRU algorithm.
- `OptimalAlgorithm.cpp` / `OptimalAlgorithm.h`: Implementation of the Optimal algorithm.
- `RandomAlgorithm.cpp` / `RandomAlgorithm.h`: Implementation of the Random algorithm.
- `SecondChanceAlgorithm.cpp` / `SecondChanceAlgorithm.h`: Implementation of the Second Chance algorithm.
- `EnhancedSecondChanceAlgorithm.cpp` / `EnhancedSecondChanceAlgorithm.h`: Implementation of the Enhanced Second Chance algorithm.
- `MemoryReference.cpp` / `MemoryReference.h`: Handles memory reference operations.
- `PageEntity.cpp` / `PageEntity.h`: Defines the structure of a memory page.
- `utils.cpp` / `utils.h`: Utility functions supporting the algorithms.
- `main.cpp`: Entry point of the program, facilitating testing and demonstration of the algorithms.
- `Makefile`: Instructions for building the project.
- `run.sh`: Script to execute the compiled program.
- `.gitignore`: Specifies files to be ignored by Git.
- `LICENSE`: Details the licensing information.
- `README.md`: This file, providing an overview of the project.

## Getting Started

To compile and run the project:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/AbiriAmir/scheduler_algorithms.git
   ```
2. **Navigate to the repository directory**:
   ```bash
   cd scheduler_algorithms
   ```
3. **Compile the code**:
   ```bash
   make
   ```
4. **Run the program**:
   ```bash
   ./run.sh
   ```

Ensure you have a C++ compiler and `make` installed on your system.

## License

This project is licensed under the GNU General Public License v3.0. For more details, refer to the `LICENSE` file in the repository.

For further information or questions, please contact the repository owner. 
