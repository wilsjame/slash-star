#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>

void printUsage();
void printHelp();
int slash(FILE *fp, char *fileName);
int slashStar();

int main(int argc, char *argv[])
{

  /* Create a pointer to a file stream. */
  FILE *fp;

  /* Check command line arguments for bad syntax or
   * switch: help (h), slash (s), slash star (ss) */
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
    slash(fp, argv[2]);

  }
  else if(strcmp(argv[1], "-ss") == 0) 
  {

    /* Change all comments to slash star (block) style */
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
  printf("Usage ./slash-star -[switch] -[filename]\n");
  printf("Try   ./slash-star -h\n");
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

/* Change all comments to slash only (inline) style */ 
int slash(FILE *fp, char *fileName)
{

  /* Create temp variable to store the return value of fgetc() */
  int ch;

  /* Open file pointer for reading data */
  fp = fopen(fileName, "r");

  if( fp == NULL)
  {
    perror("Error opening file");
    return -1;
  }

  /* Create output file name with the pid */
  char outputName[421]; 
  char pid[10];
  memset(outputName, '\0', sizeof(outputName));
  memset(pid, '\0', sizeof(pid));
  strcat(outputName, fileName);
  snprintf(pid, 10, "%d", (int)(getpid()));
  strcat(outputName, pid);

  /* Read a character at a time from the file stream */
  do
  {
    ch = fgetc(fp);

    /* Leave loop at end of file */
    if(feof(fp))
    {
      break;
    }

    printf("%c", ch);

    /* Check for slash star comments */
    if(ch == '/')
    {
      ch = fgetc(fp);

      /* Check if a star follows the slash. Reset pointer otherwise  */
      if(ch == '*')
      {

        /* Found a block comment */
        ch = '/';
        printf("%c", ch);
      }
      else
      {
        fseek(fp, -2, SEEK_CUR);
        ch = fgetc(fp);
      }

    }

  }while(1);

  //todo:
  //use fgetc to write characters to output file
  //if the char sequence matches "/*" do stuff
  
  //consider scanning from beginning and end of file at the same time

  return 0;

}
  


