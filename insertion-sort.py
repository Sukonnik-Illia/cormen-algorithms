import random
import pdb

l = list(range(5))
random.shuffle(l)
print('\nmixed', l)

for j in range(1, len(l)):
    key = l[j]
    i = j-1
    while i > -1 and l[i] > key: #to reverse just change second > to <
        l[i+1] = l[i]
        i = i-1
        print('while',l)
    l[i+1] = key
    print(l)
