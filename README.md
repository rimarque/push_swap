# **Push_swap**

## :speech_balloon: **About**
Implementation of a data sorting algorithm, that sorts data on a stack, with a limited set of instructions, using the lowest possible number of actions. 
The push_swap program sorts the stack given as an argument and prints the actions performed by the algorithm. 
As a bonus a tester was developed that checks if the stack is sorted by the actions performed and counts them.

## 🙋‍♀️ **Authorship**
- [Rita Marques](https://github.com/rimarque)

## :inbox_tray: **Cloning the repository**

```shell
git clone git@github.com:rimarque/FDF.git 
```

# Mandatory Part

## 💎 **Features**
```
- Executes the commands provided as arguments usinge the execve() and fork() functions
- Establishes a pipe between the commands using the pipe() function
- Supports overwrite redirections:
	- redirects input from the file specified as first argument
	- redirects output to the file specified as last argument
- Supports accurate exit codes and error messages
- Supports the use of one pair of single quotes per command
```
</tbody>
	<td><image src="img/mandatory.png"></td>
	<td><image src="img/single_quotes.png"></td>	
	<td><image src="img/file_error.png"></td>
	<td><image src="img/command_error.png"></td>
</tbody>

## :link: **Compilation**
To compile the program you should run `make`.
This rule will generate an executable file named `pipex`.

To launch the executable you should follow this syntax:

```sh
$ ./pipex infile cmd1 cmd2 outfile
```

# Bonus Part

## 💎 **Features**
```
- Supports multiple pipes, enabling users to chain multiple commands together
- Supports append redirections (including here document)
```

<tbody>
			<td><image src="img/bonus_overwrite.png"></td>
			<td><image src="img/bonus_append.png"></td>
</tbody>

## :link: **Compilation**
To compile the program you should run `make bonus`.
This rule will generate an executable file named `bonus`.

To launch the executable you should follow this syntax:

Executes overwrite redirections:

```sh
$ ./bonus infile cmd1 cmd2 cmd3 ... cmdn outfile
```
