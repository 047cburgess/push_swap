# push_swap

*This project has been created as part of the 42 curriculum.*

## Description

**push_swap** is a sorting algorithm project in the 42 curriculum that challenges students to sort a stack of integers using a limited set of operations and the smallest number of moves possible. The program must use two stacks (a and b) and a specific set of operations to sort the data.

The project is divided into two main parts:
- **Mandatory part**: Implementation of the push_swap program that sorts integers using stack operations
- **Bonus part**: Implementation of a checker program that validates if a sequence of operations correctly sorts a stack

### Key Features

- Efficient sorting algorithm for stacks of any size
- Optimized solution using the Turk algorithm approach
- Support for both positive and negative integers
- Comprehensive error handling for invalid inputs
- Bonus checker program to verify sorting operations
- Fully compliant with 42's norminette coding standards

### Algorithm

The program uses an optimized sorting strategy:
- **3 or fewer elements**: Direct sorting with minimal operations
- **Larger stacks**: Uses a cost-based algorithm that:
  - Pushes elements to stack b (except 3)
  - Assigns target positions and calculates push costs
  - Moves the cheapest element back to stack a
  - Rotates to final sorted position

## Instructions

### Prerequisites

- C compiler (cc)
- Make
- A Unix-based operating system

### Installation

Clone the repository:

```bash
git clone https://github.com/caburges/push_swap.git
cd push_swap
```

### Compilation

To compile the program, run:

```bash
make
```

This will generate the `push_swap` executable.

To compile with the bonus checker:

```bash
make bonus
```

This will generate both `push_swap` and `checker` executables.

### Usage

#### Push_swap

Run the program with a list of integers as arguments:

```bash
./push_swap 3 2 5 1 4
```

The program will output the sequence of operations needed to sort the stack:

```
pb
pb
sa
pa
pa
```

You can also pass arguments as a single quoted string:

```bash
./push_swap "3 2 5 1 4"
```

#### Checker (Bonus)

The checker program reads operations from standard input and verifies if they correctly sort the stack:

```bash
./push_swap 3 2 5 1 4 | ./checker 3 2 5 1 4
```

Output:
- `OK` - if the operations successfully sort the stack
- `KO` - if the stack is not sorted or operations are invalid
- `Error` - if input is invalid

### Available Make Rules

- `make` or `make all` - Compiles the push_swap program
- `make bonus` - Compiles push_swap + checker
- `make clean` - Removes object files
- `make fclean` - Removes object files and executables
- `make re` - Recompiles the entire project

## Operations

The program uses the following operations to manipulate the stacks:

### Swap Operations
- `sa` - Swap the first 2 elements at the top of stack a
- `sb` - Swap the first 2 elements at the top of stack b
- `ss` - `sa` and `sb` at the same time

### Push Operations
- `pa` - Push the top element from stack b to stack a
- `pb` - Push the top element from stack a to stack b

### Rotate Operations
- `ra` - Rotate stack a (shift all elements up by 1)
- `rb` - Rotate stack b (shift all elements up by 1)
- `rr` - `ra` and `rb` at the same time

### Reverse Rotate Operations
- `rra` - Reverse rotate stack a (shift all elements down by 1)
- `rrb` - Reverse rotate stack b (shift all elements down by 1)
- `rrr` - `rra` and `rrb` at the same time

## Error Handling

The program handles various error cases and outputs `Error` to stderr for:
- Non-integer arguments
- Numbers outside the integer range (INT_MIN to INT_MAX)
- Duplicate numbers
- Invalid syntax

## Project Structure

### Source Files

**Main program**: `main.c`

**Stack management**: `build_stack.c`, `clear_stack.c`, `last_node.c`, `stack_size.c`

**Input validation**: `manage_input_errors.c`

**Operations**: `swap.c`, `push.c`, `rotate.c`, `reverse_rotate.c`

**Sorting algorithm**: `sort.c`, `sort_utils.c`, `is_sorted.c`, `set_min_max.c`, `bring_nodes_to_top.c`, `bring_nodes_to_top_end.c`, `above_med.c`

### Bonus Files

**Checker program**: `checker_bonus/main.c`

**Input handling**: `checker_bonus/get_next_line.c`, `checker_bonus/get_next_line_utils.c`

**Operations**: `checker_bonus/swap.c`, `checker_bonus/push.c`, `checker_bonus/rotate.c`, `checker_bonus/reverse_rotate.c`

## Testing

Test the program with different stack sizes:

```bash
# Small stack (3 numbers)
./push_swap 2 1 3

# Medium stack (5 numbers)
./push_swap 2 1 3 6 5 8

# Large stack (100 random numbers)
ARG=$(shuf -i 0-5000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test with checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

### Performance Benchmarks

- 3 numbers: ≤ 3 operations
- 5 numbers: ≤ 12 operations
- 100 numbers: ≤ 700 operations (5 points), ≤ 900 operations (4 points)
- 500 numbers: ≤ 5500 operations (5 points), ≤ 7000 operations (4 points)
