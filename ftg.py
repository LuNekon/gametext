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

def monster_attack(pv, m_pv):
    print("Le monstre attaque")
    time.sleep(1)
    m_atk = random.randint(0,4)
    if m_atk == 0:
        print("Il rate son coup.")
        time.sleep(2)
    else:
        pv = pv - m_atk
        print("Tu prend", m_atk, "dégats.\n")
        time.sleep(2)
    return pv, m_pv

def attack(pv, m_pv, min_stat, max_stat):
    atk = random.randint(min_stat, max_stat)
    if atk == 0:
        print("Le revolver se braque tout seul sur ta tempe.., \n")
        time.sleep(2)
        print("Un clic se fait entendre..\n")
        time.sleep(2)
        print("Une balle sort, c'est un coup critique")
        time.sleep(2)
        return 0, m_pv

    print("Tu utilises ton arme et inflige", atk, "dégats.")
    time.sleep(2)
    m_pv = m_pv - atk
    if m_pv <= 0:
        return pv, m_pv
    pv, m_pv = monster_attack(pv, m_pv)
    return pv, m_pv
    

def weapon(min_stat, max_stat):
    end = True
    while end:
        arme = input("1 - Epée, 2 - Dague, 3 - Gun 9mm, 4 - Revolver, 5 - Bombe, 0 - Annuler : ")
        print("")
        if arme == "1":
            print("Tu t'équipes de ton épée, classique\n")
            time.sleep(2)
            return 1, 5
        if arme == "2":
            print("Tu t'équipes de ta dague, petit calible mais reste efficace\n")
            time.sleep(2)
            return 2, 3
        if arme == "3":
            print("Tu t'équipes de ton 9mm, ça rigole plus\n")
            time.sleep(2)
            return 5, 8
        if arme == "4":
            print("Tu t'équipes d'un révolver")
            time.sleep(1)
            print("Bizarre, il a une odeur de vodka..\n")
            time.sleep(2)
            return 0, 10
        if arme == "5":
            print("Tu t'équipes d'une bombe, c'est marqué \"Tré dangé\" sur l'étiquette...")
            time.sleep(1)
            print("C'est ce que j'aurais dis si tu en avais une.")
            time.sleep(2)
        if arme == "0":
            return min_stat, max_stat
        else:
            print(arme,"n'est pas un argument valide")
            arme = None
            

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
def win():
    exp = 0
    exp_gain = random.randint(30,50)
    print("Tu as battu le monstre bravo, tu a gagné", exp_gain, "points d'expérience qui pour le moment ne te servent à rien")
    exp = exp + exp_gain
    #if exp > 80:
    #    print("Tu viens de passer au niveau 2, félicitation ! (+ 2 d'attaque)")
    #    atk_boost = 2
    reset = str(input("On recommence ? [yes/no]"))
    if reset == "yes":
        main()
    else:
        print("Bye bye")
        quit()

def main():
    pv = 20
    m_pv = random.randint(10,50)
    min_stat = 1
    max_stat = 5
    turn = 1
    print("Un combat contre un monstre sauvage avec",m_pv ,"PV se lance:")
    #weap = "Sword", inv = [popo]
    while pv > 0 and m_pv > 0:
        print("")
        print("Tour", turn)
        print("Que fais tu ? Il te reste",pv ,"PV. Le monstre en a", m_pv, "\n")
        choice = int(input("1: Attaquer, 2: Changer d'arme, 3: Soin, 4: Fuir : "))
        if choice == 1:
            pv, m_pv = attack(pv, m_pv, min_stat, max_stat) 
        elif choice == 2:
            min_stat, max_stat = weapon(min_stat, max_stat)
            pv, m_pv = monster_attack(pv, m_pv)
        elif choice == 3:
            inventory()
            print("Tu utilises une magie de soin, tu récupères 10 pv\n")
            if pv + 10 > 20:
               pv = 20
            else:
                pv = pv + 10
            time.sleep(2)
            pv, m_pv = monster_attack(pv, m_pv)
        elif choice == 4:
            run()
        choice = None
        turn = turn + 1
    if pv <= 0:
        print("T'es mort")
    if m_pv <= 0:
        win()

def name():
    print("Bonjour, tu es ici pour tester un combat tout ce qu'il y a de plus basique, rien de spécial va se passer, juste de taper un monstre")
    time.sleep(2)
    nom = input("Mais avant toute chose, comment t'appelles tu ? ")
    print("...")
    time.sleep(2)
    print("Bonjour",nom,"tu as choisi ton nom mais ça ne servira pas pour la suite")
    time.sleep(1)
    print("Merci, alors la suite donc..\n")
    time.sleep(2)
    main()

name()