# BrainFrick
This is a very small and annoying programming language. 
It is a modified version of the programming language BrainFuck. This language, like the original, is not actually supposed to be used and is
purely for fun.
## How It Works

### Settings Cell Values
Variables are stored in cells. The cells within a big array of bytes. You start on the first cell and can increase it or decrease it by one
using the command + or -
you can than print the value of the current cell with the command ^.
**Example**
`++^%`
This will print 2 to the console.
the % is at the end to tell the program that it has reached the end.

### Changing Active Cell
You can change the active cell by using greater or lesser symbols
**Example**
`++^>+^%`
This will print 2 first then 1. so the output would be: 21

### Looping
Loops are used with brackets. If you reach an open bracket, what is within will be run until it both reaches the close bracket and the current cell equals zero.
**Example**
`+[^+]%`
This example loops printing 1 to -1.

### Printing
If you want to print a character to the console, just use . to print the char version of the text. And by writing a char in the code the current cell will turn
to that chars value. The . operator will print the active cell, the next cell, and so on until it reaches a cell with the value 0 in it.
**Example**
`h.i.%`
This prints hi to the console.

### Registers
BrainFrick has two registers. One using the @ symbol and the other using the $ symbol. Whenever these commands are used, it will store the active cell value
in the register.
**Example**
`---$%`
This stores the value -3 in the $ register

### If Statment
The only use for registers is in the if statment. If's format looks like this: (X|Y). Once the program reaches (, it compares the registers and if they are equal
then it does x. Otherwise, it does y.
**Example**
`+@+$(h.i.|b.y.e.)%`
`+@$(h.i.|b.y.e.)%`
The first example prints bye because @ is 1 and $ is two. The second example prints hi because both @ and $ are 1.

### Get Input
to get input, just use the , command. The result stores the input char in the active cell.
`,.%`
Just prints whatever char was entered. To see how to read all the inputed char, look at example 1 in the example section.

## How To Run
Running the program is simple. Just drag a text file onto the application. It can be any file type as long as it has the commands in it as Ascii.

## Examples
1. This first example reads the inputed text and prints it back out. if you just want the inputed text, remove the . at the end.
`>>>>++[<+++++>-]<@>+[-,$([-]|>+)]+[-$([-]|<+)]>.%`
