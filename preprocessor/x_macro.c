#include <stdio.h>

#define LIST_VARIABLES \
        X(top) \
        X(mid) \
        X(bot)

#define X(value) int value;
LIST_VARIABLES
#undef X

void print_variables(){
#define X(value) printf("%s %d\n", #value, value);
LIST_VARIABLES
#undef X  
}

/*  To check the expantion:

gcc x_macro.c -E | grep "printf"

printf("%s %d\n", "top", top); 
printf("%s %d\n", "mid", mid); 
printf("%s %d\n", "bot", bot);

*/

int top = 1;
int mid = 5;
int bot = 10;
  
int main(int argc, char *argv[]){

  printf("First call\n");
  print_variables();
  
  top = 8;
  mid = 0;
  bot = 94;
  
  printf("\nSecond call\n");
  print_variables();

  return 0;
}

/*  Output:

First call
top 1
mid 5
bot 10

Second call
top 8
mid 0
bot 94

*/