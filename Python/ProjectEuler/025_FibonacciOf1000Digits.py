import math

memo =  [0]*100000 

def fib(n):
    
    if memo[n] != 0:
        return memo[n];

    if n == 1:
        memo[1] = 1
        return 1
    if n == 2:
        memo[2] = 1
        return 1

    retval = fib(n-1) + fib(n-2)
    memo[n] = retval
    return retval

def numDigits(n):
    return int(math.log(n,10)) + 1


def findFibonacciOfLength(minDigits):

    count=1
    while(True):

        fib_n = fib(count)

        digits = numDigits(fib_n)
        if digits >= minDigits:
            return count
        count += 1

if __name__ == "__main__":
    print(str(findFibonacciOfLength(1000)))