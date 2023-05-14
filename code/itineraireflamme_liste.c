#include "itineraireflamme.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node_t Node;

struct ItineraireFlame_t
{
    Region *departure, *arrival;
    Node *head;
};

struct Node_t
{
    Region *value;
    struct Node_t *next;
    struct Node_t *prev;
};

static struct Node_t *new_node(Region *value)
{
    assert(value != NULL);
    struct Node_t *result = malloc(sizeof(struct Node_t));

    if (result == NULL)
        return NULL;
    
    result->value = value;
    result->next = NULL;
    result->prev = NULL;

    return result;
}

static void destroy_node(struct Node_t *node)
{
    assert(node != NULL);
    free(node);
}

static unsigned int in_list(struct Node_t *last, Region *value)
{
    struct Node_t *head = last;
    if (head != NULL)
    {
        if (head->value == value)
            return 1;
        return in_list(head->prev, value);
    }
    
    return 0;
}



struct ItineraireFlame_t *new_itineraireflame(Region *start, Region *end)
{
    assert(start != NULL && end != NULL);

    if (start == end)
        return NULL;

    struct ItineraireFlame_t *way = malloc(sizeof(struct ItineraireFlame_t));

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
        return 2;
    
    unsigned int counter = 2;
    
    Node *head = way->head;

    while (head != NULL)
    {
        if (head->value != way->departure && head->value != way->arrival)
        {
            if (!in_list(head->prev, head->value))
                counter++;
        }
        head = head->next;
    }

    return counter;
}

unsigned int count_resident(struct ItineraireFlame_t *way)
{
    assert(way != NULL);

    if(way->head == NULL)
        return get_nb_people(way->departure) + get_nb_people(way->arrival);
    
    unsigned int residents = get_nb_people(way->departure) + get_nb_people(way->arrival);
    
    Node *head = way->head;

    while (head != NULL)
    {
        if (head->value != way->departure && head->value != way->arrival && !in_list(head->prev, head->value))
            residents += get_nb_people(head->value);
        head = head->next;
    }

    return residents;   
}

unsigned int add_region(struct ItineraireFlame_t *way, Region *region)
{
    assert(way != NULL && region != NULL);

    Node *node = new_node(region);

    if (node == NULL)
        return 0;

    if (way->head != NULL)
        way->head->prev = node;

    node->next = way->head;
    way->head = node;

    return 1;
}

void remove_region(struct ItineraireFlame_t *way, Region *region)
{
    assert(way != NULL && region != NULL);

    Node *head = way->head;
    Node *tmp = NULL;

    do
    {
        if (head != NULL)
        {
            if (head->value == region)
            {
                if(head->prev != NULL)
                    head->prev->next = head->next;

                if(head->next != NULL)
                    head->next->prev = head->prev;

                tmp = head;
            }

            if(head->next != NULL)
                head = head->next;

            if (tmp != NULL)
            {
                destroy_node(tmp);
                tmp = NULL;
            }
        }
    } while (head != NULL && head->next != NULL);

    while (head != NULL && head->prev != NULL)
        head = head->prev;
    
    way->head = head;
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