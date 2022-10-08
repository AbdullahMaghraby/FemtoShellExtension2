#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Description:
 * it is a function to print Local Variables that is excute as aresponse t0 built-in command
 * */
void setFunction(char *varNameArray[], char *varValueArray[],
		 unsigned char var_index)
{

    int offset = 0;		/*variabe to avoid printing global variable which have been freed */
    for (int ind = 0; ind < var_index; ind++) {
	if (((getenv(varNameArray[ind])) != NULL)) {
	    offset++;
	    /*let name do not free to check with it again in case of using (set) command */
	}
	if (((ind + offset) < var_index)) {
	    printf("Local Variable [%d]: %s = %s\n", (ind),
		   varNameArray[ind + offset],
		   varValueArray[ind + offset]);
	}
    }
}

/*Description:
 * it is a function to export a variable from being local to be global 
 * and you could search on it using (env) command
 * */
void exportFunction(char *varNameArray[], char *varValueArray[],
		    char *var_name, int export_index)
{
    if (export_index == -1)
	printf("Variable (%s) does not exist\n", var_name);
    else {
	setenv(varNameArray[export_index], varValueArray[export_index], 1);
	/*Do not free Variable Name to check with it if Variable is Local or Global*/
	free(varValueArray[export_index]);
    }
}
