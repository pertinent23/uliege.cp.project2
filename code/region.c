#include "region.h"

#include <stdlib.h>
#include <assert.h>
#include <math.h>

/** @struct Region_t 
 * 
 * @param x
 * @param y
 * @param name
 * @param speciality
 * @param headquater
 * @param nb_people
*/
struct Region_t{
    double x, y;
    char *name;
    char *speciality;
    char *headquater;
    unsigned int nb_people;
};

struct Region_t *new_region(double x, double y, char *name)
{
    assert(name != NULL);

    struct Region_t *region = malloc(sizeof(struct Region_t));

    if (region == NULL)
        return NULL;
    

    region->x = x;
    region->y = y;
    region->name = name;
    region->nb_people = 0;

    return region;
}

double get_coord_x(struct Region_t *region)
{
    assert(region != NULL);
    return region->x;
}

double get_coord_y(struct Region_t *region)
{
    assert(region != NULL);
    return region->y;
}

char *get_region_name(struct Region_t *region)
{
    assert(region != NULL);
    return region->name;
}

char *get_region_headquater(struct Region_t *region)
{
    assert(region != NULL);
    return region->headquater;
}

char *get_region_speciality(struct Region_t *region)
{
    assert(region != NULL);
    return region->speciality;
}


unsigned int get_nb_people(struct Region_t *region)
{
    assert(region != NULL);
    return region->nb_people;
}

void set_nb_people(struct Region_t *region, unsigned int nb_people)
{
    assert(region != NULL);
    region->nb_people = nb_people;
}

void set_region_headquater(struct Region_t *region, char *headquater)
{
    assert(region != NULL);
    region->headquater = headquater;
}

void set_region_speciality(struct Region_t *region, char *speciality)
{
    assert(region != NULL);
    region->speciality = speciality;
}

double distance_between_region(struct Region_t *region_1, struct Region_t *region_2)
{
    assert(region_1 != NULL && region_2 != NULL);
    return sqrt(pow(region_2->x - region_1->x, 2) + pow(region_2->y - region_1->y, 2));
}

void destroy_region(struct Region_t *region)
{
    assert(region != NULL);
    free(region);
}