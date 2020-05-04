#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* no_rep(char* inputString);
long countOcurrences(char *scanned, char *target);

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

printf("\nno reps: %s\n", no_rep("abaaaaaaaxabaaaaaaaxabaaaaaaax") );

printf("\nno reps: %s\n", no_rep("77788abcabc77788abcabc") );

printf("\nno reps: %s\n", no_rep("") );

printf("\nno reps: %s\n", no_rep(NULL) );
*/	
}

char* no_rep(char* inputString)
{
	char *subString = NULL; //to store the result 
	unsigned long range = 0, length = 0, times = 0, subLength = 0, subtraction = 0; //range is used to move through the inputString
	
	if(inputString == NULL)
		return inputString;

	length = strlen(inputString);

	if(length == 0)
		return inputString;

	subString = malloc( length*sizeof(char) + 1 ); //allocate memory considering null termination char '\0'
	subtraction = length;//initially subtraction is equals length but the goal is for it to be zero.

	/* we move range character by character concatenating each one to the new substring and then testing whether the string appears 
	an exact number of times such that: (length - times*subLength) equals zero*/
	for(range = 0; range < length && subtraction > 0; range++) 
	{
		subString[range] = inputString[range];
		subString[range+1] = '\0';

		times = countOcurrences(inputString, subString);
		subLength = strlen(subString);

		subtraction = length - (times*subLength);
	}
	/*For all the ideal cases subtraction will yield zero and for loop will end. And for cases where the only substring is the whole inputString the loop will continue adding characters until substring is the whole string and then times will be 1, subLength == length and subtraction = 0*/

	/* we can always return a separate instance but this will save some space on memory (only when inputString and subString are the same)*/
	if(subLength == length)
	{
		free(subString);
		return inputString;
	}
	else
		subString = realloc(subString, subLength*sizeof(char)+1);

	return subString;
}

/*whith this function we count the number of occurrences of target in scanned*/
long countOcurrences(char *scanned, char *target)
{
	unsigned long times = 0, lastFound = 0, targetLength;
	char *limit = NULL;

	targetLength = strlen(target);
	limit = strstr( scanned+(lastFound), target );

	while(limit != NULL)
	{
		times++;
		// if limit's addres was 7004 and scanned's 7000, then (unsigned long)(limit - scanned) = 4
		lastFound = ( (unsigned long)( limit - scanned ) ) + targetLength;
		limit = strstr(scanned+(lastFound), target);
	}

	return times;
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

./noRep abaaaaaaaxabaaaaaaaxabaaaaaaax
no reps: abaaaaaaax

/noRep 77788abcabc77788abcabc
no reps: 77788abcabc

./noRep ""
no_reps:

./noRep
no_reps: (null)

*/
