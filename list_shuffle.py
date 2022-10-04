# Python3 code to demonstrate
# shuffle a list
# using Fisher–Yates shuffle Algorithm

import random

# initializing list
test_list = [1, 4, 5, 6, 3]

# Printing original list
print ("The original list is : " + str(test_list))

# using Fisher–Yates shuffle Algorithm
# to shuffle a list
for i in range(len(test_list)-1, 0, -1):
	
	# Pick a random index from 0 to i
	j = random.randint(0, i + 1)

	# Swap arr[i] with the element at random index
	test_list[i], test_list[j] = test_list[j], test_list[i]
	
# Printing shuffled list
print ("The shuffled list is : " + str(test_list))
