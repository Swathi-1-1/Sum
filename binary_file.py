f=open('python.txt')  
f1=open('transfer.txt','a')
for a in f.readlines():
    f1.write(a)
f.close()
f1.close()
