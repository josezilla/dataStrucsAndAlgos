# python program performs a quicksort
# reading the program from bottom to top makes sense since
# the variables and functions used by the parent function are defined
# as the program executes


"""
quickSort() function takes a list (array) called 'alist' as its argument.
quickSort() calls the quickSortHelper function, which takes three arguments
"""
def quickSort(alist):
	quickSortHelper(alist, 0, len(alist)-1)
	
"""
divide and conquer...
quickSortHelper() function is called by quickSort()
- first argument is the same 'alist' as before
- second argument is named 'first' and represents the first index of the
  'alist,' after it goes through the upcoming partition() function
- final argument is named 'last' and represents the last index of the
  'alist,' after it goes through the upcoming partition() function
  
the if statement in quickSortHelper() creates a variable called splitpoint
based on the upcoming partition() function, then it uses splitpoint, which is based on the partition()
function returning the value of rightmark


"""
	
def quickSortHelper(alist, first, last):
	if first < last:
		splitpoint = partition(alist, first, last)
		
		quickSortHelper(alist, first, splitpoint-1)
		quickSortHelper(alist, splitpoint+ 1, last)
		
"""
the partition() function also takes in the 'alist' array of numbers as its 
first argument.  It's return value is 'rightmark'
the variable pivotvalue assigns 'first' as the index of a number in 'alist' by its index, which 'first represents'
the variable 'leftmark' increments 'first'
the variable 'rightmark 'represents the last index in 'alist'
the variable 'done' set to False, sets a variable for the upcoming while loop

the while loop increments leftmark each time it sees that leftmark <= rightmark 
and when the leftmark index of alist is <= pivotvalue

the while loop decrements rightmark when the rightmark index of alist >= pivotvalue
and when rightmark >= leftmark

the while loop finishes if and when rightmark is less than leftmark, and stops

but if rightmark !< leftmark, it does three more things
- creates the variable 'temp' with the leftmark index of 'alist'
- then reassigns the leftmark index of 'alist' to the same as the rightmark index of 'alist'
- the reassigns the rightmark index of 'alist' to the variable temp

partition() resumes by assigning the 'first' index of 'alist' to 'temp,'
then reassigns the first index of alist to the rightmark index of alist,
then reassigns the rightmark index of alist to the value of temp,
and finally returns the value of rightmark 
"""

def partition(alist, first, last):
	pivotvalue = alist[first]
	leftmark = first +1
	rightmark = last
	
	done = False
	while not done:
		while leftmark <= rightmark and alist[leftmark]<= pivotvalue:
			leftmark = leftmark+1
			
		while alist[rightmark] >= pivotvalue and rightmark >= leftmark:
			rightmark = rightmark-1
	
		if rightmark < leftmark:
			done = True
		else:
			temp = alist[leftmark]
			alist[leftmark] = alist[rightmark]
			alist[rightmark] = temp
	
	temp = alist[first]
	alist[first] = alist[rightmark]
	alist[rightmark] = temp
	
	return rightmark
	
"""
this defines the numbers that the quicksort will sort	
"""
alist = [17, 85, 57, 55, 99, 25, 14, 86, 14, 5]

"""
call the quicksort() function and print the results			
"""
quickSort(alist)
print (alist)


