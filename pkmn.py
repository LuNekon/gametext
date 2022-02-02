type = {"Flingouste": "Eau", "Aflamanoir": "Feu", "Maracachi": "Plante"}

def combat(pkmn):
	

def main():
	compteur = 1
	for i in type:
		print(compteur, "pour", i)
		compteur += 1
	choice = int(input("Choisi un pokémon en retrant un chiffre\n"))
	combat(choice)

	#print(type["Flingouste"])


main()
