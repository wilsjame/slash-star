#include <stdio.h>
#include <unistd.h>
#include <string.h>

void printUsage();
void printHelp();

int main(int argc, char *argv[])
{

  /* Check command line arguments for help option or bad syntax */
  if(argc >= 2)
  {

    if(strcmp(argv[1], "-h") == 0) 
    {
      printHelp();
    }

  }
  else if(argc != 3)
  {
    printUsage();
  }

  /* Check switch for slash (s) or slash star (ss) */
  




 

  return 0;

}

/* Print command line format */
void printUsage()
{
  printf("Usage ./slashstar -[switch] -[filename]\n");
  printf("Try   ./slashstar -h\n");
}

/* Print help menu */
void printHelp()
{
  printf("    *** Usage ***\n");
  printf("./slashstar -[switch] -[filename]\n");
  printf("\n    *** Switches ***\n");
  printf("-h        Show help menu\n");
  printf("-s        Slash comments only /* */ -->   //\n");
  printf("-ss       Slash star comments  //   --> /* */\n");
  printf("\n    *** Example ***\n");
}
  

