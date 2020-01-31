def compress(string):
    length = len(string)
    if (length < 2):
        return string

    result = ""
    i = 0

    while i < length:
        count = 0
        char = string[i]
        result += char
        while ((i < length) and (char == string[i])):
            count += 1
            i += 1

        result += str(count)

    if (len(result) > length):
        return string

    return result

def compress_efficient(string):
    result_list = []

    length = len(string)
    if (length < 2):
        return string

    i = 0

    while i < length:
        count = 0
        char = string[i]
        result_list.append(char)
        while ((i < length) and (char == string[i])):
            count += 1
            i += 1

        result_list.append(str(count))

    result = ''.join(result_list)
    if (len(result) > length):
        return string

    return result

print(compress_efficient("abb")) #abb
print(compress_efficient("abc")) #abc
print(compress_efficient("aabb")) #a2b2
print(compress_efficient("ab")) #ab
print(compress_efficient("aaaabb")) #a4b2
print(compress_efficient("aaaab")) #a4b1
print(compress_efficient("aab")) #aab
print(compress_efficient("aabbcc")) #a2b2c2
print(compress_efficient("aabbcccdddd")) #a2b2c3d4
print(compress_efficient("abcabdaca")) #abcabdaca))