#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char var_index=0;      /*index for Local Variables 2 Arrays .. it is Global as it will be used in multiple files using extern */

/*Description:
 *it is a function that return variable index if it is exist and -1 if not
 * */
int varIndex(char *varNameArray[], char *varName, unsigned char maxIndex)
{
    for (int i = 0; i < maxIndex; i++) {
	if (strcmp(varName, varNameArray[i]) == 0) {
	    return i;
	}
    }
    return -1;			/*variable does not exist */
}

/*Descrption:
 *it is a function for variable declaration and values assignment
 * */
void varDeclearation(char *varName[], char *varValue[], char *n_argv[])
{
    varName[var_index] = malloc(strlen(n_argv[0]));	/*variable name declearation */
    strcat(varName[var_index], n_argv[0]);	/*Variable Name assignment */
    varValue[var_index] = malloc(strlen(n_argv[1]));	/*variable value declearation */
    strcat(varValue[var_index], n_argv[1]);	/*Variable Value assignment */
    var_index++;
}
