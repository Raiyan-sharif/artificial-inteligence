
n=int(input("Enter the board size of N Queen :"))
Queen=[False]*n
r=0



def FindQueenSolution(Queen,r):
    
    
    if r==n: print(Queen);
    else:
        for j in range(n):            
            Flag=True
            for i in range(r):
                if(Queen[i]==j) | (Queen[i]==j+r-i) | (Queen[i]==j-r+i):
                    Flag=False
                    
                    
                    
                    
            if Flag:
                Queen[r]=j
                FindQueenSolution(Queen,r+1)
    

FindQueenSolution(Queen,r)

