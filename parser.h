/*Description:
 *It is a function used to calculate number of arguments in one command line so save space of using fixed size array
 * */
int argc(char buf[]);

/*Description:
 * It is a parser function to split command line to arguments in an array of strings
 * It has 2 main cases : 1- is variable declearation 
 * 			 2- is commands excution
 * */
int parser(char buf[], char *argv[]);
