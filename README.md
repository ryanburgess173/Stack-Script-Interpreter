# Stack-Script-Interpreter
# Created by Johnathan R. Burgess, Alan Choi, and Patrick Love of Guilford Technical Community College
Example Problem #1 for 2018 Triad Programming Contest:

Write a program that will interpret a simple stack oriented script language.  The script language starts with data declarations followed by commands.  Data declarations are one to a line in the format:
variablename number
where variablename is the name of a program variable.  Program variables are case insensitive and may contain only letters.  The number is an integer value.  There may be up to 16 variables.  The end of the variable list is denoted by a line containing only “program”.  Following the program line are executable statements.  There are seven possible statement types:

push var	Push the value of the specified variable onto the stack.
pop var	Remove the top of stack value and store it in the specified variable.
add	Add the top two values on the stack.  Remove the two values on top of the stack and store the addition result on the top of the stack.
sub	Subtract the top of the stack value from the value immediately below the top of the stack.  Remove the two values on top of the stack and store the subtraction result on the stack.
mult	Multiply the top of the stack value with the value immediately below the top of the stack.  Remove the two values on top of the stack and store the product result on the stack.
div	Divide the top of the stack value by the value immediately below the top of the stack.  Remove the two values on top of the stack and store the division result on the stack.
display	Display “Top of stack:” followed by the value of the top of the stack. The value on the top of the stack is not changed or removed.

There may be up to 256 program statements.  The end of the program statements is denoted by a line containing only “end”.  All variable names and commands are case insensitive, so ADD, add and Add are all the same.

Your program is to execute a program written in this stack script language.  The script programs are written by Computer Science faculty, so there are no errors in them.  There will be no undeclared variables and no stack overflows or underflows.  The script program should be read from script.txt

 
Example input from script.txt
Markup : * dog 5
* cat 3
* bird 11
* program
* push bird
* push cat
* push dog
* display
* sub
* add
* display
* end

Example output

Top of stack: 5
Top of stack: 9 
 
