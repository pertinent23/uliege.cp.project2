#include "itineraireflamme.h"

#include <stdlib.h>
#include <assert.h>

typedef struct Node_t
{
    Region *value;
    struct Node_t *next;
    struct Node_t *prev;
} Node;


struct ItineraireFlame_t{
    Region *departure, *arrival;
    Node *head;
};

static struct Node_t *new_node(Region *value)
{
    assert(value != NULL);
    struct Node_t *result = malloc(sizeof(struct Node_t *));

    if (result == NULL)
        return NULL;
    
    result->value = value;

    return result;
}

static unsigned int in_list(struct Node_t *last, Region *value)
{
    if (last != NULL)
    {
        if (last->value == value)
            return 1;
        return in_list(last->prev, value);
    }
    
    return 0;
}



struct ItineraireFlame_t *new_itineraireflame(Region *start, Region *end)
{
    assert(start != NULL && end != NULL);

    if (start == end)
        return NULL;

    struct ItineraireFlame_t *way = malloc(sizeof(struct ItineraireFlame_t *));

    if (way == NULL)
        return NULL;

    way->departure = start;
    way->arrival = end;
    way->head = NULL;
    
    return way;
}

unsigned int is_circuit(struct ItineraireFlame_t *way)
{
    assert(way != NULL);

    if(way->head == NULL)
        return 0;
    
    Node *head = way->head;

    while (head != NULL)
    {
        if (head->value == way->departure || head->value == way->arrival || in_list(head->prev, head->value))
            return 1;
        
        head = head->next;
    }

    return 0;
}

unsigned int count_region(struct ItineraireFlame_t *way)
{
    assert(way != NULL);

    if(way->head == NULL)
        return 0;
    
    unsigned int counter = 2;
    
    Node *head = way->head;

    while (head != NULL)
    {
        if (head->value != way->departure && head->value != way->arrival && !in_list(head, head->value))
            counter++;
        head = head->next;
    }

    return 0;
}

unsigned int count_resident(struct ItineraireFlame_t *way)
{
    assert(way != NULL);

    if(way->head == NULL)
        return 0;
    
    unsigned int residents = 0;
    
    Node *head = way->head;

    while (head != NULL)
    {
        if (head->value != way->departure && head->value != way->arrival && !in_list(head, head->value))
            residents += get_nb_people(head->value);
        head = head->next;
    }

    return 0;   
}

unsigned int add_region(struct ItineraireFlame_t *way, Region *region)
{
    assert(way != NULL && region != NULL);

    Node *node = new_node(region);

    if (node == NULL)
        return 0;

    if (way->head != NULL)
    {
        node->next = way->head;
        way->head->prev = node;
    }

    way->head = node;

    return 1;
}

void remove_region(struct ItineraireFlame_t *way, Region *region)
{
    assert(way != NULL && region != NULL);

    Node *tmp = NULL, *head = way->head;

    while (head != NULL)
    {   
        if (head->value == region)
        {
            tmp = head;

            if(head->prev)
                head->prev->next = tmp->next;
            
            if(tmp->next)
                tmp->next->prev = tmp->prev;
        }

        head = head->next;

        if (tmp != NULL)
        {
            free(tmp);
            tmp = NULL;
        }
    }
}

void destroy_itineraireflame(struct ItineraireFlame_t *way, unsigned int delete_regions)
{
    assert(way != NULL);

    Node *tmp, *head = way->head;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;

        if (tmp->value != NULL && delete_regions)
            destroy_region(tmp->value);
        free(tmp);
    }

    if (delete_regions)
    {
        destroy_region(way->departure);
        destroy_region(way->arrival);
    }

    free(way);
}