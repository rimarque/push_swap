# **Push_swap**

## :speech_balloon: **About**
Push_swap is about implementing a data sorting algorithm, that sorts data on a stack, with a limited set of instructions, using the lowest possible number of actions. 
The program sorts the stack given as an argument and prints the actions performed by the algorithm. 
As a bonus a tester was developed that checks if the stack is sorted by the actions performed.

## 🙋‍♀️ **Authorship**
- [Rita Marques](https://github.com/rimarque)

## :inbox_tray: **Cloning the repository**

```shell
git clone git@github.com:rimarque/push_swap.git 
```

# Mandatory Part

## 💎 **Features**
```
- Sorts the stack given as argument (stack a), using an empty stack (stack b) and a limited set of instructions:
	- swap: swaps the 2 elements of the top of the stack
	- push: pushes an element from the top of a stack to another
	- rotate: the first element of the stack becomes the last one
	- reverse rotate: the last element becomes the first one
- The instructions used to sort the stack are printed in the terminal
	- sa (swap a), sb (swap b), ss (sa e sb at the same time)
	- pa (push from b to a), pb (push from a to b)
	- ra (rotate a), rb (rotate b), rr (ra e rb at the same time)
	- rra (reverse rotate a), rrb (reverse rotate b), rrr (ra e rb at the same time)
- Uses circular double linked lists to implement the Turk Algorithm: https://medium.com/@ayogun/push-swap-c1f5d2d41e97
- Sorts a stack of 5 numbers in 12 moves or less
- Sorts a stack of 100 numbers in less than 700 moves
- Sorts a stack of 500 values in less than 5500
```
</tbody>
	<td><image src="img/mandatory.png"></td>
	<td><image src="img/5numbers.png"></td>
	<td><image src="img/100numbers.png"></td>
	<td><image src="img/500numbers.png"></td>
</tbody>

## :link: **Compilation**
To compile the program you should run `make`.
This rule will generate an executable file named `push_swap`.

To launch the executable you should follow this syntax:

```sh
$ ./push_swap 7 -1 100 3 -30 8 49
```

# Bonus Part

## 💎 **Features**
```
- Checks if the instructions written in the terminal sort the stack given as argument
- Works as a tester for push_swap
- Returns OK (number of operations performed) if the stack is sorted correctly
- Returns KO if the stack isn't sorted
```
<td><image src="img/checker_instructions.png"></td>
<td><image src="img/checker_push_swap.png"></td>

## :link: **Compilation**
To compile the program you should run `make bonus`.
This rule will generate an executable file named `checker`. To launch the executable you should follow this syntax:

To check if the instructions written in the terminal sort the stack:

```sh
$ ./checker 3 2 1
```
Or, if you want to test your push_swap:

```sh
$ ./push_swap 7 -1 100 3 -30 8 49 | ./checker 7 -1 100 3 -30 8 49
```
