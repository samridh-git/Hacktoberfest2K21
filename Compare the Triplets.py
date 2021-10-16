def compare(a,b):
    x=[0,0]
    for i in range(3):
        if a[i]>b[i]:
            x[0]+=1
        elif a[i]<b[i]:
            x[1]+=1
        else:
            pass
    return x
a=[int(n) for n in input().split()]
b=[int(n) for n in input().split()]
y = compare(a,b)
print(y[0],y[1])             

