def is_substring(src, substr):
    len_src = len(src)
    len_substr = len(substr)
    if (len_substr > len_src):
        return False
    
    for i in range(0, len_src-len_substr +1):
        test_str = src[i:i+len_substr]
        #print("test " + test_str)
        if test_str == substr:
            return True
    return False

# print (is_substring("abc", "ab"))
# print (is_substring("abc", "abc"))
# print (is_substring("abc", "abcd"))
# print (is_substring("dabc", "abc"))

def is_string_rotation(s1, s2):
    if len(s1) != len(s2):
        return False
    test = s1+s1
    #return is_substring(test, s2)
    return s2 in test

