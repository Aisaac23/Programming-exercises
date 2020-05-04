import math
# Add any extra import statements you may need here

def findChars(s, t):
	l1 = list(t)
	found = -2
	positions = []
	for item in l1:
		found = s.find(item)
		while( found != -1 and (found in positions) ):
			found = s.find(item, found+1, len(s)-1)

		if found < 0:
			return found
		positions.append( found )
	print(positions)
	return ( max(positions) - min(positions) + 1 )

def min_length_substring(s, t):
	return findChars(s, t)
	











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
	s1 = "dcbefebce"
	t1 = "fd"
	expected_1 = 5
	output_1 = min_length_substring(s1, t1)
	check(expected_1, output_1)

	s2 = "bfbeadbcbcbfeaaeefcddcccbbbfaaafdbebedddf"
	t2 = "cbccfafebccdccebdd"
	expected_2 = -1
	output_2 = min_length_substring(s2, t2)
	check(expected_2, output_2)

	# Add your own test cases here
