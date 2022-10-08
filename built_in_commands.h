/*Description:
 * it is a function to print Local Variables that is excute as aresponse t0 built-in command
 * */
void setFunction(char *varNameArray[], char *varValueArray[],
                 int var_index);

/*Description:
 * it is a function to export a variable from being local to be global
 * and you could search on it using (env) command
 * */
void exportFunction(char *varNameArray[], char *varValueArray[],
                    char *var_name, int export_index);
