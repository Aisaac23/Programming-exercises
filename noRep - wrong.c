#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* no_rep(char* inputString);

int main(int argc, char* argv[])
{

	printf("\nno reps: %s\n", no_rep(argv[1]) );
	
/*
printf("\nno reps: %s\n", no_rep("78abc78ab78abc") );

printf("\nno reps: %s\n", no_rep("78abc78abc78abc") );

printf("\nno reps: %s\n", no_rep("axytfgvd") );

printf("\nno reps: %s\n", no_rep("aaaabbbaaaabbbaaaabbb") );

printf("\nno reps: %s\n", no_rep("aaaabbbaaaabbbaaaabbbx") );

printf("\nno reps: %s\n", no_rep("[[[[****[[[[***") );

printf("\nno reps: %s\n", no_rep("aaaaaaaaa") );

printf("\nno reps: %s\n", no_rep("ab *ab *ab *") );

printf("\nno reps: %s\n", no_rep("ab") );

printf("\nno reps: %s\n", no_rep("abababababab") );

printf("\nno reps: %s\n", no_rep("") );

printf("\nno reps: %s\n", no_rep(NULL) );
*/	
}

char* no_rep(char* inputString)
{
	char *subString = NULL, *limit; // subString to store the result and limit to use it in the strchr() function 
	char ch; //to store the first character of the string
	unsigned long range = 0, length = 0; //range is used to move forward the string pointer
	
	if(inputString == NULL)
		return inputString;

	ch = inputString[0];
	length = strlen(inputString);

	if(length == 0)
		return inputString;
	/* we move range until we have a different character than the first one*/
	for(range = 0; range < length && inputString[range] == ch; range++) 
		;

	//if all the characters are the same range will be equal length
	if(range == length)
		range = 1;//so we set range at one.

	// we look for the next occurrence of the first character starting at: range
	limit = strchr(inputString+range, ch);
	if(limit == NULL)
		return inputString; //if we could't find the first character again the we return the input as the only posible substring would be the whole str
	else
		range = (unsigned long)(limit - inputString); //we calculate the length of our subString

	subString = malloc( range*sizeof(char) + 1 ); //allocate memory considering null termination char '\0' 
	memmove(subString, inputString, range*sizeof(char)); //move from inputString, to subString range characters.
	
	subString[range] = '\0'; //add the null termination char at the end
	
	unsigned long times = 0, subLength;

	subLength = strlen(subString);
	limit = strstr(inputString, subString);
	
	//the following loop's porpuse is to avoid cases like "78abc78ab78abc"  
	while(limit != NULL)
	{
		limit = strstr(inputString+(times*subLength), subString);
		if(limit != NULL)
			times++;
	}
	// the length of the input string inputString minus the number of times subString appeared in inputString multiplied by subString's length should be zero. 
	if( (length-times*subLength) > 0)
		return inputString;//otherwise we return the original string.
	else
		return subString;
}

/*
./noRep 78abc78ab78abc
no reps: 78abc78ab78abc

./noRep 78abc78abc78abc
no reps: 78abc

./noRep axytfgvd
no reps: axytfgvd

./noRep aaaabbbaaaabbbaaaabbb
no reps: aaaabbb

./noRep aaaabbbaaaabbbaaaabbbx
no reps: aaaabbbaaaabbbaaaabbbx

./noRep [[[[****[[[[***
no reps: [[[[****[[[[***

./noRep aaaaaaaaa
no reps: a

./noRep "ab *ab *ab *"
no reps: ab *

./noRep "ab"
no reps: ab

./noRep abababababab
no reps: ab

./noRep ""
no_reps:

./noRep
no_reps: (null)

*/
