#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Description:
 *It is a function used to calculate number of arguments in one command line so save space of using fixed size array
 * */
int argc(char buf[])
{
    int i = 0;			/*counter for whole buffer string length */
    int j = 0;			/*counter for arguments array elements */
    char sp_flag = 1;		/*space flag to parse space characters */
    while (strlen(buf) > i) {

	while ((buf[i] != ' ') && (strlen(buf) > i)) {
	    sp_flag = 0;
	    i++;
	}
	if (sp_flag == 0) {
	    j++;		/*new element at arguments array */
	    sp_flag = 1;
	}
	while ((buf[i] == ' ') && (strlen(buf) > i)) {
	    i++;
	}
    }
    return (j + 1);		/*arguments array size which equal to argc (arguments counter)  note: +1 for NULL ending element */
}


/*Description:
 * It is a parser function to split command line to arguments in an array of strings
 * It has 2 main cases : 1- is variable declearation 
 *                       2- is commands excution
 * */
int parser(char buf[], char *argv[])
{
    unsigned char var_flag = 0;	/*flag to check if command line for variable declearation or for command execution */

    for (int cntr = 1; cntr < strlen(buf); cntr++) {	/*counter starts from 1 as equal operator can not be at the beginning */
	if (buf[cntr] == '=') {
	    var_flag = 1;	/* that is variable declearation */
	    cntr = strlen(buf);	/*to terminate from for loop */
	}
    }

    char *arg;			/*string to store current argument */
    int index = 0;

    if (var_flag == 1) {
	arg = strtok(buf, "=");
	argv[index++] = arg;
	argv[index] = strtok(NULL, "=");	/*variable seclearation has only 2 arguments so no need to while loop */
	return 1;		/*to check in the main program that is variable declearation*/
    } else {

	arg = strtok(buf, " ");	/*split string of command line into arguments to the argv seperated by space characters */
	while (arg != NULL) {
	    argv[index++] = arg;
	    arg = strtok(NULL, " ");	/*note from second stroke of parsing string that passes to function must be NULL pointer */
	}
	argv[index] = NULL;	/*argv array must end with NULL pointer */
    }
    return 2;		/*to check on the main program that is command execution*/
}
