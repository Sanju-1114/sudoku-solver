# Sudoku Solver

## Overview
This repository contains a C++ implementation of a Sudoku solver for LeetCode problem 37. The solver uses a backtracking algorithm to solve a 9x9 Sudoku puzzle by filling in the empty cells (denoted by '.') with digits from 1 to 9, ensuring that the solution adheres to standard Sudoku rules.

## Features
- Solves a 9x9 Sudoku puzzle using backtracking.
- Checks for valid placements of digits by verifying:
  - No duplicate digits in the same row.
  - No duplicate digits in the same column.
  - No duplicate digits in the same 3x3 sub-box.
- Includes a sample Sudoku board for testing.

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/Sanju-1114/sudoku-solver.git
   ```
2. Navigate to the project directory:
   ```bash
   cd sudoku-solver
   ```
3. Compile the C++ code:
   ```bash
   g++ sudoku-solver.cpp -o sudoku-solver
   ```
4. Run the executable:
   ```bash
   ./sudoku-solver
   ```

## Usage
- The `sudoku-solver.cpp` file contains the solver implementation and a sample Sudoku board in the `main` function.
- To test with a different Sudoku puzzle, modify the `board` vector in the `main` function with your own 9x9 grid, using '.' for empty cells and digits '1' to '9' for filled cells.
- Run the program to see the solved Sudoku board printed to the console.


## Example
The sample board in the code is:
```
8 2 7 1 5 4 3 9 6
9 . 3 . . . . . .
. . . 8 . . . 6 .
5 . . . . . . . .
. 6 . . 3 . 5 1 .
. . . . . . . . 4
. . . . . 6 2 8 .
. . . . . . . 3 .
. . 1 9 . 5 . . 7
```
Running the program will output the solved board.


## Contributing
Contributions are welcome! Please feel free to submit a Pull Request or open an Issue for any bugs, improvements, or feature requests.

## License
This project is licensed under the MIT License.

## Contact
For any questions or feedback, please reach out via GitHub Issues or contact the repository owner, [Sanju-1114](https://github.com/Sanju-1114).