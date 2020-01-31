def is_palindrome_perm(string):
    #print(string)
    counts = [False]*128
    for i in range(0, len(string)):
        index = ord(string[i])
        counts[index] = not counts[index]

    oddFound = False
    for i in range(0, 128):
        if counts[i] and oddFound:
            return False

        if counts[i]:
            oddFound = True

    return True


print(is_palindrome_perm("abba")) #true
print(is_palindrome_perm("abcba")) # true
print(is_palindrome_perm("abbac"))#true
print(is_palindrome_perm("ab")) #false
print(is_palindrome_perm("a")) #true
print(is_palindrome_perm("abcde")) #false
print(is_palindrome_perm("abcda")) #false