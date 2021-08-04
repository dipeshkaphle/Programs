def powerset(U):
    if(len(U)==0):
        return [[]]
    oneLess=U[:-1]
    LastOne=U[-1:]
    PSofOneLess=powerset(oneLess)
    for elem in range(len(PSofOneLess)):
        PSofOneLess.append(PSofOneLess[elem]+LastOne)

    return PSofOneLess



print(list(filter((lambda x: len(x)==2) ,powerset([1,2,3,4]))))
