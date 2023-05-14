#include "itineraireflamme.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ARRAY_SIZE 100

struct ItineraireFlame_t
{
    Region *departure, *arrival;
    Region **map;
    int indicator;
};

struct ItineraireFlame_t *new_itineraireflame(Region *start, Region *end)
{
    assert(start != NULL && end != NULL);

    if (start == end)
        return NULL;

    struct ItineraireFlame_t *way = malloc(sizeof(struct ItineraireFlame_t));

    if (way == NULL)
        return NULL;

    way->map = malloc(sizeof(Region *) * ARRAY_SIZE);

    if (way->map == NULL)
    {
        free(way);
        return NULL;
    }

    way->departure = start;
    way->arrival = end;
    way->indicator = 0;
    
    return way;
}

unsigned int is_circuit(struct ItineraireFlame_t *way)
{
    assert(way != NULL);

    if (way->indicator == 0)
        return 0;

    for (int i = 0; i < way->indicator; i++)
    {
        if(way->map[i] == way->departure || way->map[i] == way->arrival)
            return 1;
        
        for(int y=i-1; y>=0; y--)
        {
            if(way->map[y] == way->map[i])
                return 1;
        }
    }

    return 0;
}

unsigned int count_region(struct ItineraireFlame_t *way)
{
    assert(way != NULL);

    Region *tmp[ARRAY_SIZE];
    unsigned int is_counted, counter = 2;

    tmp[0] = way->departure;
    tmp[1] = way->arrival;

    for (int i = 0; i < way->indicator; i++)
    {
        is_counted = 0;
        for(int y = counter-1; y >= 0 && !is_counted; y--)
            is_counted = (tmp[y] == way->map[i]);
        
        if(!is_counted)
            tmp[counter++] = way->map[i];
    }
    
    return counter;
}

unsigned int count_resident(struct ItineraireFlame_t *way)
{
    assert(way != NULL);

    Region *tmp[ARRAY_SIZE];
    unsigned int is_counted, counter = 2, residents = 0;

    tmp[0] = way->departure;
    tmp[1] = way->arrival;

    residents += get_nb_people(tmp[0]);
    residents += get_nb_people(tmp[1]);

    for (int i = 0; i < way->indicator; i++)
    {
        is_counted = 0;
        for(int y = counter-1; y >= 0; y--)
            is_counted = (tmp[y] == way->map[i]);
        
        if(!is_counted)
        {
            residents += get_nb_people(way->map[i]);
            tmp[counter++] = way->map[i];
        }
    }
    
    return residents;
}

unsigned int add_region(struct ItineraireFlame_t *way, Region *region)
{
    assert(way != NULL && region != NULL);

    if (way->indicator >= ARRAY_SIZE)
        return 0;

    way->map[way->indicator++] = region;

    return 1;
}

void remove_region(struct ItineraireFlame_t *way, Region *region)
{
    assert(way != NULL && region != NULL);

    int i = way->indicator;
    while (i >= 0)
    {
        if (way->map[i] == region)
        {
            for (int y = i+1; i < way->indicator; i++)
                way->map[y-1] = way->map[y];
            way->indicator--;
        }
        i--;
    }
}

void destroy_itineraireflame(struct ItineraireFlame_t *way, unsigned int delete_regions)
{
    assert(way != NULL);

    if (delete_regions)
    {
        for (int i = 0; i < way->indicator; i++) 
        {
            if (way->map[i] != NULL)
                destroy_region(way->map[i]);
        }

        destroy_region(way->departure);
        destroy_region(way->arrival);
    }

    free(way->map);
    free(way);
}