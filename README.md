Simple Shell

This repository containes a progressive implementation of a Simple UnixShell done in C. It uses POSIX to implement maney of the same functionalities of the Ken Thompson's Shell. It carries the 0x16. C- 
Simple Shell project as part of the ALX Software Engineering Programme.

Among the mostly used calls and functions are read, write, free, malloc, realloc, perror, strtok, wait, execvp, chdir, getpid, isatty, kill among others.

This Simple Shell is wrriten in C programming language. It is implemented progressively as per the various tasks and requirements in the project. The variuos tasks are outlined below:

Task 0.Betty would be proud.

Write a beautiful code that passes the Betty checks

Task 1.Simple shell 0.1
Write a UNIX command line interpreter.

Usage: simple_shell
Your Shell should:
Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)

You don’t have to:
use the PATH
implement built-ins
handle special characters : ", ', `, \, *, &, #
be able to move the cursor
handle commands with arguments

execve will be the core part of your Shell, don’t forget to pass the environ to it…

