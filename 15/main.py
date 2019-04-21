print("Enter no of lines in code")
n=int(input())
l=[]
deadcode = []
for i in range(0,n):
    s= str(raw_input())
    l.append(s)
    
for i in range(0,len(l)):
    cur = l[i].split('=')[0]
    flag=0
    print(cur)
    for j in range(i+1,len(l)):
        if(cur in l[j]):
            flag=1
    if(flag==0 and i!=len(l)-1): #dead code
        #print(l[i])
        deadcode.append(l[i])
        
        
print("list of deadcodes : ",deadcode)
for i in range(0,len(deadcode)):
    l.remove(deadcode[i])
    
print("optimised code :")
for i in range(0,len(l)):
    print(l[i])
    
'''
output

Enter no of lines in code
3
x=a+b
y=10
z=y+b
x
y
z
('list of deadcodes : ', ['x=a+b'])
optimised code :
y=10
z=y+b

'''
