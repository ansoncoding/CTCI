#1.2 is one string a permutation of another string?
def is_permutation(str1, str2):
    if len(str1) != len(str2):
        return False

    counts = {}
    for i in range(0, len(str1)):
        if str1[i] not in counts:
            counts[str1[i]] = 1
            #print(counts)
        else:
            counts[str1[i]] = counts[str1[i]] + 1
            #print(counts)
    for i in range(0, len(str1)):
        if ((str2[i] not in counts) or (counts[str2[i]] <= 0)):
            #print(counts)
            return False
        else:
            counts[str2[i]] = counts[str2[i]] - 1
            #print(counts)
    return True


# use sorting to save space
def is_permutation_2(str1, str2):
    if len(str1) != len(str2):
        return False
    str1_sorted = sorted(str1)
    str2_sorted = sorted(str2)
    for i in range(0, len(str1)):
        if (str1_sorted[i] != str2_sorted[i]):
            return False
    return True


# instead of dictionary use list
# this will save some space
# assume ascii charset of 128
def is_permutation_3(str1, str2):
    if len(str1) != len(str2):
        return False

    counts = [0]*128

    for i in range(0, len(str1)):
        index = ord(str1[i])
        #print(index)
        counts[index] += 1

    for i in range(0, len(str2)):
        index = ord(str2[i])
        #print(index)
        counts[index] -= 1
        if counts[index] < 0:
            return False
    return True


#================================================================================
print(is_permutation_3("str", "")) #false
print(is_permutation_3("str", "st")) #false
print(is_permutation_3("str", "Str")) #false
print(is_permutation_3("str", "srt")) #true
print(is_permutation_3("strr", "rtrt")) #false
print(is_permutation_3("abcdd", "dbcad")) #true
