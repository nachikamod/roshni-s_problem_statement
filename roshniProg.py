k = int(input("k : "))
m = int(input("m : "))

v = 2                                           # Value of initial tree

planted = []                                    # Array to store trees to be planted (XD consider it as pots ha ha ha...)

for toBeCutted in range(k):                     # Loop to start cutting specified trees i.e. k
    if not planted:                             # Ok I know this step was unnnecessary but it just checks if we already cutted down our first tree and planted new one i.e. if the array is empty or not
        pass
    else:                                       # If initial tree is already cutted down and we planted new trees
        v = planted.pop(0)                      # Cut the first tree and store its value
        print(v);
                                

    for toBePlanted in range((v+1)%m):          # This step calculates according to v how much trees needs to planted
        planted.append(toBePlanted)             # And after calculation plant this trees on their right places

#print(planted)                                  # And print the number of trees we planted




