#Result Checker
def checktoclose():
    close=str(input('Y for play again else N: '))
    if close=='Y':
        new_mat(get)
        return True
    elif close=='N':
        return False
    else:
        print('Invalid Command!!! try again...')
        return checktoclose()

#Assignment
active=True
repeat=True
a_player=True
get=[i+10 for i in range(9)]
j=1
check_invalidmoves=True

#Arena
def new_mat(x):
    for i in range(3):
        pos=0 if i==0 else 3 if i==1 else 6
        a = str(' ') + (x[pos] if x[pos] == 'x' or x[pos] == '0' else str(' ')) + str(' ')
        b = str(' ') + (x[pos + 1] if x[pos + 1] == 'x' or x[pos + 1] == '0' else str(' ')) + str(' ')
        c = str(' ') + (x[pos + 2] if x[pos + 2] == 'x' or x[pos + 2] == '0' else str(' ')) + str(' ')
        print(a,b,c,sep='||')
        if i<2:
            print(str('-')*13)

new_mat(get)

#logic of the game
while repeat:

    print('\n')
    if a_player==True:
        string='x'
        print('Cross turns!!!')
    else:
        string='0'
        print('Zero turns!!!')

    position=int(input('In which position, you want to mark: '))

    if get[position]=='x' or get[position]=='0':
        print("Invalid Move!!!")
        check_invalidmoves=False
    else:
        get[position]=string
        check_invalidmoves = True

    print('\n')

    new_mat(get)

    if j==9 or get[0]==get[1]==get[2] or  get[3]==get[4]==get[5] or get[6]==get[7]==get[8] or get[0]==get[3]==get[6] or get[1]==get[4]==get[7] or get[2]==get[5]==get[8] or get[0]==get[4]==get[8] or get[2]==get[4]==get[6]:

        if j==9:
            print("Draw")
        else:
            print(string+' wins!!!')

        a_player=True
        get=[i+10 for i in range(9)]
        j=1
        repeat=checktoclose()

    if check_invalidmoves==True:
        if active == True:
            a_player = False
            active = False
        else:
            a_player = True
            active = True
        j+=1