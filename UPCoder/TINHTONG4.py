#n = 1 KQ =1
#n = 2 KQ = 1*2+2*1 = 4 = 1 + 1 + 2
#n = 3 KQ = 1*3 + 2*2 + 3*1 = 10 = 1 + (1 + 2) + (1 + 2 + 3)
#=> sn = 1 + (1+2) + (1+2+3) + ... +(1+2+3+..+n)
#mà 1+2+3...n = (n*(n+1))/2 = (n^2 + n)/2
#mà k = 1 to n của k^2 = (k*(k+1)*(2k+1))/6 
#mà k = 1 to n của k = (k*(k+1))/2
#KQ = ((k*(k+1)*(2k+1))/6 + (k*(k+1))/2)/2
#=> KQ = k*(k+1)*(k+2)/6
#Vậy Sn = n*(n+1)*(n+2)/6
n = int(input())
q = (n*(n+1)*(n+2))//6
print(q)
