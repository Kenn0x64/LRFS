#This python python version is not working well debug is needed
from numpy.random.mtrand import rand
import pandas as pd
import matplotlib.pyplot as plt
import time
#Reading The Data
data=pd.read_csv("data.csv")
#All the Algorithm 
def model(m,b,data,a):
    for i in range(r):
        p1=0
        p0=0
        n=len(data)
        for i in range(n):
            x=data.iloc[i].x
            y=data.iloc[i].y
            p1=p1+(-(2/n)*x*(y-(m*x+b)))
            p0=p0+(-(2/n)*(y-(m*x+b)))
        m=m-a*p1
        b=b-a*p0
        print("m:"+str(m)+" b:"+str(b))
    return m,b
print("Enter Information:\nm=")
m=float(input())
print("b=")
b=float(input())
print("BECAREFUL!!!!\nLearning Rate:")
a=float(input())
print("BECAREFUL!!!!\nNumber Of Iritation:")
r=int(input())
print("Enter x To Pridict y:")
x_user=float(input())
t1=time.time()
m,b= model(m,b,data,a)
t2=time.time()
yp=m*x_user+b
print("\nIf x Is "+str(x_user),"Then y Is "+str(yp))
print("Training Time is "+str(t2-t1)+" seconds")
plt.scatter(data.x,data.y,)
plt.scatter(x_user,yp,c="black")
plt.plot(list(range(10,100)),[m*x+b for x in range(10,100)],color='red')
plt.show()

