#ifndef FTG_H

void win(int * exp, int * pv, int * min_stat, int * max_stat);
void run(void);
void inventory(int * pv);
void weapon(int * min_stat, int * max_stat);
void monster_attack(int * pv);
void attack(int * m_pv, int * min_stat, int * max_stat);
void fight(int *pv, int *min_stat, int* max_stat, int* exp);
void initStats(void);
void name(void);

#endif