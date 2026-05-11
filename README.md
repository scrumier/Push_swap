# Push_swap

A sorting algorithm using two stacks and a limited set of operations.

## What it does

Push_swap sorts a list of integers using two stacks, named `a` and `b`. The program receives a list of numbers as arguments and outputs the shortest sequence of operations needed to sort stack `a` in ascending order.

## Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the top two elements of stack a |
| `sb` | Swap the top two elements of stack b |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the top of b onto a |
| `pb` | Push the top of a onto b |
| `ra` | Rotate stack a upward |
| `rb` | Rotate stack b upward |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack a |
| `rrb` | Reverse rotate stack b |
| `rrr` | `rra` and `rrb` at the same time |

## Usage

```sh
./push_swap 4 2 7 1 5
```

The program prints the list of operations to standard output.

To check the result:

```sh
./push_swap 4 2 7 1 5 | ./checker 4 2 7 1 5
```

## Algorithm

Small lists (up to 3 elements) use hardcoded optimal solutions. Larger lists use a chunk-based algorithm that partitions numbers into groups and pushes them strategically to minimize the total number of moves.

## Project context

This is a School 42 project. The goal is to think about algorithmic complexity and to find an efficient sorting strategy under tight constraints.