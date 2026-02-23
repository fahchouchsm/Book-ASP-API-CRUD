nombres = list(range(11))
result = [x + 1 for x in nombres]
nombres.append(11)

# nombres.extend(12,13)
print(nombres[0])
print(nombres[0:2])
print(nombres[-1])
print(nombres[-2:])

# surpprimer la valeur 5
nombres.remove(5)

# inverse
nombres.reverse()
print(nombres)

print("saisie un nombre au hasard:")
nbr = int(input())

if nbr in nombres:
    print("le nombre est dans la liste")
else:
    print("le nombre n'est pas dans la liste")