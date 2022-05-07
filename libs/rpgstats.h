#pragma once
#include "entitys.h"
#include <stdio.h>
#include <stdlib.h>

struct specialStats {
	int fireDamage;
	int iceDamage;
	int electricDamage;
	struct rpgstats *rpgStats;
};
struct rpgstats {
	int level;
	int hp;
	int mp;
	int strength;
	int intelegence;
};
struct statMultipliers {
	int hpMul;
	int mpMul;
	int strengthMul;
	int intelegenceMul;
};
struct rpgstats *entitystats;
struct statMultipliers *Mul;

void storeEntity();
void initStats(struct entity *Entity)
{
	if(Entity != NULL){
		entitystats->hp = (entitystats->level * Mul->hpMul) + (entitystats->level * Mul->hpMul); 
		entitystats->mp = (entitystats->level * Mul->mpMul) + (entitystats->level * Mul->mpMul);
		entitystats->strength = (entitystats->level * Mul->strengthMul) + (entitystats->level * Mul->strengthMul);
		entitystats->intelegence = (entitystats->level * Mul->intelegenceMul) + (entitystats->level * Mul->intelegenceMul);
	}
	else {
		printf("ERROR: Entity not allocated ? >\"struct rpgstats *entitystats;\"<");
	}
}
void levelUpStats(struct entity *Entity) {

}

