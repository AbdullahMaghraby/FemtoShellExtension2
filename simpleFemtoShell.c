#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "parser.h"
#include "variables_manipulations.h"
#include "built_in_commands.h"

#define MAX_LOCAL_VARIABLE_NUMBER 20

extern char **environ;		/*array of global variable defined in stdlibc */

int main()
{
    char buf[100];		/*Max Number of Characters in one command line is 99 */
    int str_len;		/*string length to manipulate with  ending NULL */
    int ret_pid;		/*returned process ID */
    int status;			/*to check the child process status */
    char *varName[MAX_LOCAL_VARIABLE_NUMBER];	/*string Array for Local Variabls Names */
    char *varValue[MAX_LOCAL_VARIABLE_NUMBER];	/*string Array for Local Varaiables Values */
    int export_index;		/*for manipilating while exporting variable */
    int num;			/*for argc function output */
    int checker;		/*to check if it is built in command or not */

    while (1) {

	printf("Maghraby_simpleFemtoShell >");
	fgets(buf, 100, stdin);
	str_len = strlen(buf);
	buf[str_len - 1] = 0;	/*offset the ending null so do not take enter char "\n" at buffer consideration */

	if (strlen(buf) == 0) {
	    continue;		/*return to the beginning of the super loop */
	}

	ret_pid = fork();	/*ret_pid to check on fork */

	if (ret_pid < 0)
	    printf("Fork Failed \n");
	else if (ret_pid > 0) {	/*that is parent process */
	    wait(&status);	/*check on child */
	    /*  printf("Hi from Parent\n"); */
	} else if (ret_pid == 0) {	/*that is child process */
	    num = argc(buf);
	    char *n_argv[num];	/*that will be created every time */
	    checker = parser(buf, n_argv);	/*to check if it is variable delearation or command execution */


	    if (checker == 1) {	/*variable declearation */
		varDeclearation(varName, varValue, n_argv);
	    } else if (checker == 2) {	/*command excution */

		if (strcmp(n_argv[0], "set") == 0) {		    
		    setFunction(varName, varValue, var_index);
		} else if (strcmp(n_argv[0], "export") == 0) {

		    export_index = varIndex(varName, n_argv[1], var_index);
		    exportFunction(varName, varValue, n_argv[1],
				   export_index);
		}

		else {

		    execvpe(n_argv[0], n_argv, environ);
		    printf("ECEC Failed \n");	/*checking on exec if that is printted so exec failed */
		    return -1;
		}
	    }
	}
    }


    return 0;

}
