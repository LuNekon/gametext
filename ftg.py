import random
import time
#liste
a = ['bite','chatte']
#tuples
t = ("bite","chatte")
#dictionaire
d = {1:"bite", 2:"chatte"}
d2 = {5:25,3:"salope"}

#d2 {5}-> 25
# d {1} -> bite
#a [0] -> bite
#un dictionaire plutot classique:


def attack(pv, m_pv, min_stat, max_stat):
    atk = random.randint(min_stat, max_stat)
    if atk == 0:
        print("Le revolver se braque sur ta tempe, et tir, c'est un coup critique\n")
        time.sleep(2)
        return 0, m_pv

    print("Tu utilises ton arme et inflige", atk, "dégats.")
    time.sleep(2)
    m_pv = m_pv - atk
    if m_pv <= 0:
        return pv, m_pv
    print("Le monstre attaque")
    m_atk = random.randint(0,4)
    if m_atk == 0:
        print("Il rate son coup.")
        time.sleep(2)
    else:
        pv = pv - m_atk
        print("Tu prend", m_atk, "dégats.\n")
        time.sleep(2)
    return pv, m_pv

def weapon(min_stat, max_stat):
    arme = int(input("1 - Epée, 2 - Dague, 3 - Gun 9mm, 4 - Revolver, 5 - Bombe, 0 - Annuler\n"))
    if arme == 1:
        print("Tu t'équipes de ton épée, classique\n")
        return 1, 5
    if arme == 2:
        print("Tu t'équipes de ta dague, petit calible mais reste efficace\n")
        return 2, 3
    if arme == 3:
        print("Tu t'équipes de ton 9mm, ça rigole plus\n")
        return 5, 8
    if arme == 4:
        print("Tu t'équpies d'un révolver, bizarre, il a une odeur de vodka\n")
        return 0, 10
    if arme == 5:
        print("Tu t'équipes d'une bombe, c'est marqué \"Tré dangé\" sur l'étiquette\n")
    if arme == 0:
        return min_stat, max_stat

def inventory():
    return

def run():
    if random.randint(1,10)%2 == 0:
        print("Tu réussi à fuir")
        quit()
    else:
        print("Tu n'a pas réussi à fuir")    
        time.sleep(2)
        return

if __name__ == "__main__":
    pv = 20
    m_pv = 10
    exp = 0
    min_stat = 1
    max_stat = 5
    print("Un combat contre un monstre sauvage avec",m_pv ,"PV se lance:\n")
    #weap = "Sword", inv = [popo]
    while pv > 0 and m_pv > 0:
        print("Que fais tu ? Il te reste",pv ,"PV. Le monstre en a", m_pv, "\n")
        choice = int(input("1: Attaquer, 2: Changer d'arme, 3: Utiliser potion, 4: Fuir\n"))
        if choice == 1:
            pv, m_pv = attack(pv, m_pv, min_stat, max_stat) 
        elif choice == 2:
            min_stat, max_stat = weapon(min_stat, max_stat)
        elif choice == 3:
            inventory()
            print("Tu utilises une potion, tu récupères 10 pv\n")
            if pv + 10 > 20:
               pv = 20
            else:
                pv = pv + 10
            time.sleep(2)
        elif choice == 4:
            run()
        choice = None
    if pv <= 0:
        print("T'es mort")
    if m_pv <= 0:
        print("Tu as battu le monstre, bravo.")
