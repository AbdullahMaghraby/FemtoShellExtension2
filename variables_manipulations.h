extern unsigned char var_index;      /*index for Local Variables 2 Arrays .. it is Global as it will be used in multiple files using extern */

/*Description:
 *it is a function that return variable index if it is exist and -1 if not
 * */
int varIndex(char *varNameArray[], char *varName, char maxIndex);

/*Descrption:
 *it is a function for variable declaration and values assignment
 * */
void varDeclearation(char *varName[], char *varValue[], char *n_argv[]);
