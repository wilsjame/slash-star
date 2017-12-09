#include <stdio.h>
#include <unistd.h>
#include <string.h>

void printUsage();
void printHelp();

int main(int argc, char *argv[])
{

  /* Check command line arguments for bad syntax and
   * help, slash (s), or slash star (ss) switches. */
  if(argc == 1 || argc > 3 )
  {
    printUsage();
  }
  else if(strcmp(argv[1], "-h") == 0) 
  {
    printHelp();
  }
  else if(strcmp(argv[1], "-s") == 0) 
  {
    /* Change all comments to slash only (inline) style */ 

  }
  else if(strcmp(argv[1], "-ss") == 0) 
  {
    /* Change all comments to slash star (block) style, */
  }
  else
  {
    printUsage();
  }

  return 0;

}

/* Print command line argument format and hint */
void printUsage()
{
  printf("Usage ./slashstar -[switch] -[filename]\n");
  printf("Try   ./slashstar -h\n");
}

/* Print help menu */
void printHelp()
{
  printf("    *** Switches ***\n");
  printf("-h        Show help menu\n");
  printf("-s        Slash comments only /* */ -->   //\n");
  printf("-ss       Slash star comments  //   --> /* */\n");
  printf("    *** Example ***\n");
}
