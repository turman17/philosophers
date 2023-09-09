
# Philosophers 42 Project

## Overview

The Philosophers project is an exploration into multithreading and synchronization in programming. It is designed to tackle the classic dining philosophers' problem, a demonstration of a synchronization issue in concurrent programming.

## Problem Statement

Several philosophers are sitting around a circular table with a bowl of spaghetti. Forks are placed between each pair of adjacent philosophers, and every philosopher must alternately think and eat. However, a philosopher can only eat spaghetti when they have both left and right forks. Philosophers pick up the forks closest to them when they are about to eat and put them down after eating. The challenge is to design a protocol that ensures no philosopher will starve.

## Project Structure

- `philo.c`: Contains functions that define the actions of the philosophers (eating, thinking, sleeping).
- `actions.c`: Main source file that initializes the simulation.
- `utils.c`: Utility functions to help with time, parsing arguments, etc.

## Requirements

- The program takes several arguments: the number of philosophers, the time it takes to die without eating, the time it takes to eat, and optionally, the number of times each philosopher must eat.
- Each philosopher is represented as a thread.
- The program should avoid deadlock situations where no philosopher can proceed.
- The program should avoid race conditions.

## Compilation and Execution

Compile the program using:

```
gcc -pthread -o philo *.c
```

Run the program:

```
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

For example:

```
./philo 5 800 200 200 5
```

## Acknowledgments

This project is part of the 42 School curriculum.
