#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ftg.h"
// return min + rand() % (max+1 - min);

bool win(game g)
{
    int exp_gain = 30 + rand() % (50 + 1 - 30);
    printf("Tu as battu le monstre bravo, tu a gagné %d points d'expérience qui pour le moment ne te servent à rien\n", exp_gain);
    g->exp = g->exp + exp_gain;
    // if exp > 80:
    //     print("Tu viens de passer au niveau 2, félicitation ! (+ 2 d'attaque)")
    //     atk_boost = 2
    printf("On recommence ? [yes/no]\n");
    char reset = scanf("%c");
    if (reset == 'yes'){ return true; }
    else { return false; }
}

void run(game g){
    if ((1 + rand() % (10 + 1 - 1)) % 2 == 0)
    {
        printf("Tu réussi à fuir\n");
        free(g);
        exit(0);
    }
    else
    {
        printf("Tu n'a pas réussi à fuir...\n");
        sleep(2);
        return;
    }
}
void inventory(game g)
{
    printf("Tu utilises une magie de soin, tu récupères 10 pv\n");
    if (g->pv + 10 > 20) { g->pv = 20; }
    else { g->pv = g->pv + 10; }
    sleep(2);
    return;
}
void weapon(game g)
{
    char arme = NULL;
    while (arme == NULL)
    {
        printf("1 - Epée, 2 - Dague, 3 - Gun 9mm, 4 - Revolver, 5 - Bombe, 0 - Annuler : \n");
        scanf("%c", &arme);
        printf(" ");
        switch ('arme')
        {
        case '1':
            printf("Tu t'équipes de ton épée, classique\n");
            sleep(2);
            g->min_stat = 1, g->max_stat = 5;
            return;
        case '2':
            printf("Tu t'équipes de ta dague, petit calible mais reste efficace\n");
            sleep(2);
            g->min_stat = 2, g->max_stat = 3;
            return;
        case '3':
            printf("Tu t'équipes de ton 9mm, ça rigole plus\n");
            sleep(2);
            g->min_stat = 5, g->max_stat = 8;
            return;
        case '4':
            printf("Tu t'équipes d'un révolver\n");
            sleep(1);
            printf("Bizarre, il a une odeur de vodka..\n");
            sleep(2);
            g->min_stat = 0, g->max_stat = 10;
            return;
        case '5':
            printf("Tu t'équipes d'une bombe, c'est marqué \"Danger extrême\" sur l'étiquette...\n");
            sleep(2);
            g->min_stat = 50, g->max_stat = 100;
            return;
        case '0':
            return;
        default:
            printf("%c n'est pas un argument valide\n", arme);
            arme = NULL;
        }
    }
}

void monster_attack(game g)
{
    printf("Le monstre attaque...\n");
    sleep(1);
    //int m_atk = rand() % (3 + 1);
    int m_atk = 3;
    if (m_atk == 0)
    {
        printf("Il rate son coup.\n");
        sleep(2);
    }
    else
    {
        printf("Tu prend %d dégats.\n", m_atk);
        g->pv = g->pv - m_atk;
        sleep(2);
    }
    return;
}

bool attack(int * m_pv, game g)
{
    //int atk = g->min_stat + rand() % (g->max_stat + 1 - g->min_stat);
    int atk = 5;
    printf("Tu utilises ton arme et inflige %d dégats\n");
    *m_pv = m_pv - atk;
    sleep(2);
    if (m_pv <= 0) return true;
    return false;
}

void fight(game g)
{
    int m_pv = rand() % 50 + 1, turn = 1;
    printf("Un combat contre un monstre sauvage avec %d PV se lance:\n", m_pv);
    while (g->pv > 0 && m_pv > 0)
    {
        printf("\n", turn);
        printf("Tour %d\n", turn);
        printf("Que fais tu ? Il te reste %d PV. Le monstre en a %d \n\n", g->pv, m_pv);
        printf("1: Attaquer, 2: Changer d'arme, 3: Soin, 4: Fuir :\n");
        char choice = "NULL";
        scanf("%c", &choice);
        bool m_death = false;
        switch(choice)
        {
        case '1': // Attaquer
            m_death = attack(&m_pv, g);
            if(m_death){
                break;
            }
            monster_attack(g);
            turn += 1;
            break;

        case '2': // Changer d'arme
            weapon(g);
            monster_attack(g);
            turn += 1;
            break;

        case '3': // Soin
            inventory(g);
            monster_attack(g);
            turn += 1;
            break;

        case '4': // Fuite
            run(g);
            monster_attack(g);
            turn += 1;
            break;

        default:
            printf("%c n'est pas un argument valide\n", choice);
            choice = "NULL";
        }
        if (g->pv < 0)
        {
            printf("T'es mort\n");
            free(g);
            exit(0);
        }
        if (m_pv <= 0) return;
    }
}


void name(game g)
{
    printf("Bonjour, tu es ici pour tester un combat tout ce qu'il y a de plus basique, rien de spécial va se passer, juste de taper un monstre\n");
    sleep(2);
    printf("Mais avant toute chose, comment t'appelles tu ?\n");
    char nom;
    scanf("%c", &nom);
    printf("...\n");
    sleep(2);
    printf("Bonjour %c tu as choisi ton nom mais ça ne servira pas pour la suite\n", nom);
    sleep(1);
    printf("Merci, alors la suite donc..\n");
    sleep(2);
    g->name = nom;
    return;
}

game initStats(void)
{
    game g = (game)malloc(sizeof(struct character));
    g-> pv = 20, g-> min_stat = 1, g->max_stat = 5;
    return g;
}

int main(void)
{
    game g = initStats();
 //   name(g);
    bool end = false;
    while(!end){
        fight(g);
        end = win(g);
    }
    printf("Bye bye\n");
    free(g);
    return EXIT_SUCCESS;

}