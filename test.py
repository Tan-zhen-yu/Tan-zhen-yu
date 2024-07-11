a = eval(input("输入a"))
n = eval(input("输入n"))
count = 0

for i in range(1,n+1):
    count+=a
    a=a*10+a
print(count)