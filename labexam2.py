import math
def do_twice(f,k,string):
    i=0
    while k>i:
        f(string)
        i=i+1
def do_four(f,string):
    j=0
    while j<4:
        f(string)
        j=j+1
def print_spam(string):
    print (string)
def grid():
    i=0
    while(i<2):
        i+=1
        j=0
        print('\t+ - - - - + - - - - +')
        while (j<3):
            print('\t|         |         |')
            j+=1
    print('\t+ - - - - + - - - - +')

def grid4():
    i=0
    while(i<4):
        i+=1
        j=0
        print('\t+ - - - - + - - - - + - - - - + - - - - +')
        while (j<3):
            print('\t|         |         |         |         |')
            j+=1
    print('\t+ - - - - + - - - - + - - - - + - - - - +')
def shut_down():
    name = input("Shutdown yes or no :")
    if name=='yes':
        print('Shutting down')
    elif name=='no':
        print('Stutdown aborted')
    else:
        print('wrong option')

def squreoot():
    print(math.sqrt(13689))
def distance_from_zero(value):
    i=0
    i=value
   
    if type(i)== int:
        if i<0:
            i=i*(-1)
            return i
        else:
            return i
        
        
    
    elif type(i)== float:
        return i
    else:
        return 'Nope'
def hotel_cost(days):
    nights=days
    return (nights*140)
def plane_rid_cost(city):
    
    if city == 'Charlotte':
        return 183
    elif city == 'Tampa':
        return 220
    elif city == 'Pittsburgh':
        return 222
    elif city == 'Los Angeles':
        return 475
    
def rental_car_cost(days):
    if days <3:
        return days*40
    elif days>=3 and days<7:
        cost=days*40
        cost -=20
        return cost
    elif days>=7:
        cost = days*40
        cost -= 50
        return cost
def trip_cost(city,days,spending_money):
    totalCost = hotel_cost(days) + plane_rid_cost(city)+rental_car_cost(days)
    print(totalCost)
    print(spending_money)
    totalCost = totalCost+spending_money
    print(totalCost)
    return totalCost+spending_money
    
    

print(distance_from_zero(-5.6))
print(distance_from_zero("what??"))
trip_cost('Charlotte',3,3000)

