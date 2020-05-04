#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int strnumcmp(const void * a, const void * b)
{
  //const char *key = b;
  //printf("*%s*\n", b );
  return ( atoi( a ) - atoi( b) );
}

void FindIntersection(char * strArr[]) {
  
  int lens[2], tempLen = 0, longest = 0;
  char *arraysToWrite[2], *token, numbers[2][1000][1000], *output, *found = NULL;

  lens[0] = strlen( strArr[0] );
  lens[1] = strlen( strArr[1] );

  longest = lens[0] < lens[1] ? lens[0] : lens[1];

  arraysToWrite[0] = malloc( (lens[0]+1 )*sizeof(char) );
  arraysToWrite[1] = malloc( (lens[1]+1 )*sizeof(char) );

  output = malloc( ( longest+1 )*sizeof(char) );

  //numbers = malloc( 2*sizeof(char**)  );
  for(int index = 0; index < 2; index++)
  {

    strcpy(arraysToWrite[index], strArr[index]);

    token = strtok(arraysToWrite[index], " ,");
    lens[index] = 0;
    while(token != NULL)
    {
        lens[index]++;
        token = strtok(NULL, " ,");
    }

    //numbers[index] = malloc( lens[index]*sizeof(char*)  );
    
    strcpy(arraysToWrite[index], strArr[index]);

    token = strtok(arraysToWrite[index], " ,");
    int nums = 0;
    while(token != NULL)
    {
        tempLen = 1000;
        //numbers[index][nums] = malloc( tempLen*sizeof(char) );
        strcpy(numbers[index][nums], token);
        nums++;

        token = strtok(NULL, " ,");
    }

  }
  char p[][2] = {"0", "3", "5," ,"8", "9"};
  for(int index = 0; index < lens[0]; index++)
  {
    found = (char*)bsearch( *(numbers[0]+index), numbers[1][0]\
    ,lens[1], tempLen, strnumcmp );
    if(found != NULL)
    {
      strcat(output, *(numbers[0]+index));
      strcat(output, ",");
    }
  }
  if(strlen(output) == 0)
    printf("false");
  else
  {
    output[strlen(output) -1] = '\0';
    printf("%s", output);
    
  }

}

int main(void) { 
   
  // keep this function call here
  /* Note: In C you first have to initialize an array and set 
     it equal to the stdin to test your code with arrays. */
     
  char * A[] = gets(stdin);
  FindIntersection(A);
  return 0;
    
}
