#include <stdlib.h>
#include <stdio.h>
#include "ftg.h"
// return min + rand() % (max+1 - min);

typedef struct character
{
    int exp;
    int pv;
    int min_stat;
    int max_stat;
} game;

void win(int *exp, int *pv, int *min_stat, int *max_stat)
{
    int exp_gain = 30 + rand() % (50 + 1 - 30);
    printf("Tu as battu le monstre bravo, tu a gagné %d points d'expérience qui pour le moment ne te servent à rien\n", exp_gain);
    *exp = exp + exp_gain;
    // if exp > 80:
    //     print("Tu viens de passer au niveau 2, félicitation ! (+ 2 d'attaque)")
    //     atk_boost = 2
    printf("On recommence ? [yes/no]");
    char reset = scanf("%c");
    if (reset == "yes")
    {
        fight(&pv, &min_stat, &max_stat, &exp);
    }
    else
    {
        print("Bye bye");
        exit(0);
    }
}

void run(void)
{
    if ((1 + rand() % (10 + 1 - 1)) % 2 == 0)
    {
        printf("Tu réussi à fuir");
        exit(0);
    }
    else
    {
        printf("Tu n'a pas réussi à fuir...");
        sleep(2);
        return;
    }
}
void inventory(int *pv)
{
    printf("Tu utilises une magie de soin, tu récupères 10 pv\n");
    if (pv + 10 > 20)
        *pv = 20;
    else
    {
        *pv = pv + 10;
    }
    sleep(2);
    return;
}
void weapon(int *min_stat, int *max_stat)
{
    char *arme = NULL;
    while (arme == NULL)
    {
        printf("1 - Epée, 2 - Dague, 3 - Gun 9mm, 4 - Revolver, 5 - Bombe, 0 - Annuler : \n");
        scanf("%c", &arme);
        print("");
        switch ('arme')
        {
        case '1':
            printf("Tu t'équipes de ton épée, classique\n");
            sleep(2);
            *min_stat = 1, *max_stat = 5;
            return;
        case '2':
            printf("Tu t'équipes de ta dague, petit calible mais reste efficace\n");
            sleep(2);
            *min_stat = 2, *max_stat = 3;
            return;
        case '3':
            printf("Tu t'équipes de ton 9mm, ça rigole plus\n");
            sleep(2);
            *min_stat = 5, *max_stat = 8;
            return;
        case '4':
            printf("Tu t'équipes d'un révolver\n");
            sleep(1);
            printf("Bizarre, il a une odeur de vodka..\n");
            sleep(2);
            *min_stat = 0, *max_stat = 10;
            return;
        case '5':
            printf("Tu t'équipes d'une bombe, c'est marqué \"Danger extrême\" sur l'étiquette...\n");
            sleep(2);
            *min_stat = 50, *max_stat = 100;
            return;
        case '0':
            return;
        default:
            printf("%c n'est pas un argument valide\n", arme);
            arme = NULL;
        }
    }
}

void monster_attack(int *pv)
{
    printf("Le monstre attaque...");
    sleep(1);
    int m_atk = rand() % (3 + 1);
    if (m_atk == 0)
    {
        print("Il rate son coup.");
        sleep(2);
    }
    else
    {
        printf("Tu prend %d dégats.\n", m_atk);
        *pv = pv - m_atk;
        sleep(2);
    }
    return;
}

void attack(int *m_pv, int *min_stat, int *max_stat)
{
    int atk = min_stat + rand() % (max_stat + 1 - min_stat);
    printf("Tu utilises ton arme et inflige %d dégats");
    *m_pv = m_pv - atk;
    sleep(2);
    if (m_pv <= 0)
        win();
    return;
}

void fight(game *g)
{
    int *m_pv = rand() % 50 + 1, turn = 1;
    printf("Un combat contre un monstre sauvage avec %c PV se lance:", m_pv);
    while (pv > 0 && m_pv > 0)
    {
        printf("");
        printf("Tour %d", turn);
        printf("Que fais tu ? Il te reste %d PV. Le monstre en a %d \n\n", pv, m_pv);
        printf("1: Attaquer, 2: Changer d'arme, 3: Soin, 4: Fuir :\n");
        char choice = scanf("%c");
        switch ('choice')
        {
        case '1': // Attaquer
            attack(&m_pv, &min_stat, &max_stat);
            monster_attack(&pv);
            turn += 1;

        case '2': // Changer d'arme
            weapon(&min_stat, &max_stat);
            monster_attack(&pv);
            turn += 1;

        case '3': // Soin
            inventory(&pv);
            monster_attack(&pv);
            turn += 1;

        case '4': // Fuite
            run();
            monster_attack(&pv);
            turn += 1;

        default:
            printf("%c n'est pas un argument valide", choice);
            choice = NULL;
        }
        if (pv < 0)
        {
            printf("T'es mort");
            exit(0);
        }
        if (m_pv <= 0)
        {
            win(&exp, &pv, &min_stat, &max_stat);
            fight(&pv, &min_stat, &max_stat, &exp);
        }
    }
}

void initStats(void)
{
    int *pv = 20, *min_stat = 1, *max_stat = 5, *exp = 0;
    fight(&pv, &min_stat, &max_stat, &exp);
}

void name(void)
{
    printf("Bonjour, tu es ici pour tester un combat tout ce qu'il y a de plus basique, rien de spécial va se passer, juste de taper un monstre\n");
    sleep(2);
    printf("Mais avant toute chose, comment t'appelles tu ?\n");
    char nom = scanf("%c");
    printf("...\n");
    sleep(2);
    printf("Bonjour %c tu as choisi ton nom mais ça ne servira pas pour la suite\n", nom);
    sleep(1);
    print("Merci, alors la suite donc..\n");
    sleep(2);
    initStats();
}

int main(void)
{
    name();
    return EXIT_SUCCESS;
}