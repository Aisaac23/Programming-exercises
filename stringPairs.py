import math
# Add any extra import statements you may need here

def countMatches(s, t):
	count = 0
	for index in range( 0, len(s)):
		if ( s[index] == t[index] ):
			count = count+1
	return count;

def swapChars(s, indexA, indexB):
	l = list(s)
	temp = l[indexA]
	l[indexA] = l[indexB]
	l[indexB] = temp
	return "".join(l)

def matching_pairs(s, t):
	# Write your code here
	matches = []
	for indexA in range(len(s)):
		for indexB in range(indexA+1, len(s)):
			newString = swapChars(s, indexA, indexB)
			matches.append( countMatches(newString, t) )
	return max(matches)
	











# These are the tests we use to determine if the solution is correct.
# You can add your own at the bottom, but they are otherwise not editable!

def printInteger(n):
	print('[', n, ']', sep='', end='')

test_case_number = 1

def check(expected, output):
	global test_case_number
	result = False
	if expected == output:
		result = True
	rightTick = '\u2713'
	wrongTick = '\u2717'
	if result:
		print(rightTick, 'Test #', test_case_number, sep='')
	else:
		print(wrongTick, 'Test #', test_case_number, ': Expected ', sep='', end='')
		printInteger(expected)
		print(' Your output: ', end='')
		printInteger(output)
		print()
	test_case_number += 1

if __name__ == "__main__":
	n_1, s_1, t_1 = 5, "abcde", "adcbe"
	expected_1 = 5
	output_1 = matching_pairs(s_1, t_1)
	check(expected_1, output_1)

	s_2, t_2 = "abcd", "abcd"
	expected_2 = 2
	output_2 = matching_pairs(s_2, t_2)
	check(expected_2, output_2)

	# Add your own test cases here
