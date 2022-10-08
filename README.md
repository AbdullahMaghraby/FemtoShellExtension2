# FemtoShellExtension2
It is a simple UNIX Shell that executes bash commands parsing their multiple arguments and support different variable type declearation

# Shell architecture
## Modules
###There are 3 modules 

### 1-Parser
split shell command line into arguments putting them in array of strings so could be passed to different modules and functions

### 2-Variables Manipulations
putting decleared variables in suitable arrays for their names and values
it also has ability of calculating variable index

### 3-Built-in Commands
there are 2 built-in commands 
1-set: to print local variables
2-export: to convert local variable into global one

## simpleFemtoShell
This is the file of the main which control programm flow 

# Compilation and Programm Running 


    ```` bash
    $ gcc -o simpleFemtoShell simpleFemtoShell.c parser.c built_in_commands.c variables_manipulations.c
    $ ./ simpleFemtoShell
       ````
       
# Output Examples

## Multiple Arguments Command Execution

![](/1.png "Multiple Arguments Command Execution")

## Local Variable Declearation and first built-in command (set) execution

![](/2.png "Local Variable Declearation and first built-in command (set) execution")

## Exporting local variable to global one (second built-in command)

![](/3.png "Exporting local variable to global one")

## Test Exporting using (env) command

![](/4.png "Test Exporting using (env) command")
