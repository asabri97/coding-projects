fileName = input("Enter file name: ")
fp = open(fileName,"r")
values = []
integers = []
for line in fp:
    values = line.strip().split(' ')
    for el in values:
        integers.append(int(el))

def find_subsequence(integers,n,inputparam):
    currentHigh = 0
    highestSum = 0
    absint = []
    n = abs(n)
    if inputparam == "values":
        if (len(integers) <= n):
            n = len(integers)-1
        for i in range(0,len(integers)-n):
            highestSum = 0
            for j in range(i,i+n):
                highestSum = highestSum + integers[j]
                if highestSum < 0:
                    highestSum = 0
                elif (currentHigh < highestSum):
                    currentHigh = highestSum
        return currentHigh
    elif inputparam == "differences":
        for k in range(0,len(integers)-1):
            absint.append(abs(integers[k+1]-integers[k]))
        if(len(absint)<=(n-1)):
            n = len(absint)
        for i in range(0,len(integers)-(n-1)):
            highestSum = 0
            for j in range(i,i+(n-1)):
                highestSum = highestSum + absint[j]
                if highestSum < 0:
                    highestSum = 0
                elif (currentHigh < highestSum):
                    currentHigh = highestSum
        return currentHigh

n = int(input("Enter max length of subsequence: "))
inputparam = input("Third parameter: ")
print(find_subsequence(integers,n,inputparam))