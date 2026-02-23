def reduction(age):
    if age < 10:
        return 0.5
    elif age > 11 and age <19:
        return 0.3
    elif age > 59:
        return 0.2
    else:
        return 0
    
    
def montant(montant, age):
    red = reduction(age)
    return montant - montant * red 
print("entrer l'age de voyageur :")
age = int(input())

print("entrer le montant a payer")
num = float(input())
print("------------------------\n","votre age est ", age, "\n" ,"vous avez une reduction de ", reduction(age) * 100,"%\n")
print("le montant total a payer avec la reduction est " , montant(num, age), "dh")