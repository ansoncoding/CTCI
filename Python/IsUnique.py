#1.1 is string made of unique characters?
def is_unique(string):
    #start = time.clock()
    string.lower()
    for i in range(0, len(string)):
        for j in range(i+1, len(string)):
            if string[i] == string[j]:
                #end = time.time()
                #print(end - start)
                return False
    #end = time.clock()
    #print(end - start)
    return True

def is_unique_2(string):
    string.lower()
    counts = {} # use a dictionary instead of array in python
    for i in range(0, len(string)):
        if string[i] not in counts:
            counts[string[i]] = 1
        else:
            return False
    return True

def is_unique_3(string):
    string.lower()
    counts = 0 # using integer 
    for i in range(0, len(string)):
        index = ord(string[i]) - ord('a')
        #print(index)
        if (counts & (1 << index)):
            return False
        else:
            counts = (counts | (1 << index))
    return True