def is_one_edit(s1, s2):
    len1 = len(s1)
    len2 = len(s2)
    abs_len_diff = abs(len1-len2)
    if (abs_len_diff > 1):
        return False

    if (abs_len_diff == 0):
        diffFound = False
        for i in range(0, len1):
            if s1[i] != s2[i]:
                if diffFound:
                    return False
                diffFound = True
        return True
    else:
        skipped = False
        shorter_len = len1 if (len1 < len2) else len2
        j = 0
        i = 0
        while i < shorter_len:
            if (s1[i] != s2[j]):
                if skipped:
                    return False
                skipped = True
                if len1 < len2:
                    j += 1
                else:
                    i += 1
            else:
                j+=1
                i+=1
        return True
