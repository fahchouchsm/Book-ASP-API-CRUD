dict = {'filiere': 'GI', 'annee':'quatrieme', 'matiere': 'informatique'}

dict["matière"] = "Machine learning"
# afficher les cle
print(list(dict.keys()))
print(list(dict.values()))

print(f"{dict['filiere']}SI {dict['annee']} annee, matiere {dict['matiere']}.")
