#pragma once
#include <stdio.h>
#include <stdlib.h>


struct entity {
    int id;
    int *components;
    int componentCount;
};
struct entity *entities;
int entityCount;
int componentCount;
int *componentBitmap;
int *componentBitmapCount;
int *componentBitmapSize;
int *componentBitmapIndex;


void initEntityComponentSystem() {
    entities = (struct entity *)malloc(sizeof(struct entity) * 100);
    entityCount = 0;
    componentCount = 0;
    componentBitmap = (int *)malloc(sizeof(int) * 100);
    componentBitmapCount = (int *)malloc(sizeof(int) * 100);
    componentBitmapSize = (int *)malloc(sizeof(int) * 100);
    componentBitmapIndex = (int *)malloc(sizeof(int) * 100);
}
void addComponent(int component) {
    if (componentCount == 0) {
        componentBitmap[componentCount] = 1 << component;
        componentBitmapCount[componentCount] = 1;
        componentBitmapSize[componentCount] = 1;
        componentBitmapIndex[componentCount] = component;
    } else {
        int i = 0;
        for (i = 0; i < componentCount; i++) {
            if (componentBitmap[i] == 1 << component) {
                componentBitmapCount[i]++;
                break;
            }
        }
        if (i == componentCount) {
            componentBitmap[componentCount] = 1 << component;
            componentBitmapCount[componentCount] = 1;
            componentBitmapSize[componentCount] = 1;
            componentBitmapIndex[componentCount] = component;
            componentCount++;
        }
    }
}
void removeComponent(int component) {
    int i = 0;
    for (i = 0; i < componentCount; i++) {
        if (componentBitmap[i] == 1 << component) {
            componentBitmapCount[i]--;
            if (componentBitmapCount[i] == 0) {
                componentBitmap[i] = 0;
                componentBitmapCount[i] = 0;
                componentBitmapSize[i] = 0;
                componentBitmapIndex[i] = 0;
                for (int j = i; j < componentCount - 1; j++) {
                    componentBitmap[j] = componentBitmap[j + 1];
                    componentBitmapCount[j] = componentBitmapCount[j + 1];
                    componentBitmapSize[j] = componentBitmapSize[j + 1];
                    componentBitmapIndex[j] = componentBitmapIndex[j + 1];
                }
                componentCount--;
            }
            break;
        }
    }
}
void addEntity(int id, int *components, int componentCount) {
    entities[entityCount].id = id;
    entities[entityCount].components = components;
    entities[entityCount].componentCount = componentCount;
    entityCount++;
}
void removeEntity(int id) {
    int i = 0;
    for (i = 0; i < entityCount; i++) {
        if (entities[i].id == id) {
            for (int j = i; j < entityCount - 1; j++) {
                entities[j] = entities[j + 1];
            }
            entityCount--;
            break;
        }
    }
}
void printEntities() {
    for (int i = 0; i < entityCount; i++) {
        printf("%d ", entities[i].id);
        for (int j = 0; j < entities[i].componentCount; j++) {
            printf("%d ", entities[i].components[j]);
        }
        printf("\n");
    }
}
void printComponents() {
    for (int i = 0; i < componentCount; i++) {
        printf("%d ", componentBitmapIndex[i]);
    }
    printf("\n");
}
void printComponentBitmap() {
    for (int i = 0; i < componentCount; i++) {
        printf("%d ", componentBitmap[i]);
    }
    printf("\n");
}
void printComponentBitmapCount() {
    for (int i = 0; i < componentCount; i++) {
        printf("%d ", componentBitmapCount[i]);
    }
    printf("\n");
}
void printComponentBitmapSize() {
    for (int i = 0; i < componentCount; i++) {
        printf("%d ", componentBitmapSize[i]);
    }
    printf("\n");
}
void printComponentBitmapIndex() {
    for (int i = 0; i < componentCount; i++) {
        printf("%d ", componentBitmapIndex[i]);
    }
    printf("\n");
}
