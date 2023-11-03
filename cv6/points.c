#include <stdio.h>

typedef struct {
    int x;
    int y;
    int z;
} point_t;

void createPoint(point_t pointA, point_t pointB, point_t *newPoint) {
    newPoint->x = (pointA.x + pointB.x) / 2;
    newPoint->y = (pointA.y + pointB.y) / 2;
    newPoint->z = (pointA.z + pointB.z) / 2;
}

int main() {
    point_t pointA, pointB, newPoint;
    
    printf("Provide coords for first point (x y z):");
    scanf("%d %d %d", &pointA.x, &pointA.y, &pointA.z);
    
    printf("Provide coords for second point (x y z):");
    scanf("%d %d %d", &pointB.x, &pointB.y, &pointB.z);
    
    createPoint(pointA, pointB, &newPoint);
    
    printf("New point coords: x:%d y:%d z:%d\n", newPoint.x, newPoint.y, newPoint.z);
}
