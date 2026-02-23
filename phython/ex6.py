import random

nbMystere = random.randint(1,100)
tentative = 0

print("devine le nombre mystere entre 1 et 100 !")

prop = 0

while prop != nbMystere:
    prop = int(input("ton nombre : "))

    if prop < 1 or prop > 100:
        print("le nombre doit etre entre 1 et 100")
        continue
    tentative += 1

    if prop < nbMystere:
        print(prop, "est trop petit")
    elif prop > nbMystere:
        print(prop, "est trop grand")
    else:
        print("felicitation le nombre mystere etait", nbMystere)
        print("trouvé en", tentative, "coups")
