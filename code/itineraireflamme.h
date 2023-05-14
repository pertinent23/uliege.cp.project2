#ifndef __ITINERAIREFLAME__
#define __ITINERAIREFLAME__

#include "region.h"

typedef struct ItineraireFlame_t ItineraireFlame;

/**
 * @brief 
 * Va créer un objet itinéraireflame
 * 
 * @pre start != NULL && end != NULL
 * @post new_itineraireflame est de type  struct ItineraireFlame_t ou NULL
 * 
 * @param start 
 * @param end 
 * @return struct ItineraireFlame_t* 
*/
struct ItineraireFlame_t *new_itineraireflame(Region *start, Region *end);

/**
 * @brief 
 * Va vérifier si l'itinéraire forme un circuit
 * 
 * @pre way != NULL
 * @post is_circuit = 1 si l'itinéraire est un circuit et 0 dans le cas contraire
 * 
 * @param way 
 * @return unsigned int 
*/
unsigned int is_circuit(struct ItineraireFlame_t *way);

/**
 * @brief 
 * cette fonction va compter le nombre de 
 * region différente présente sur l'itinéraire
 * 
 * @pre way != NULL
 * @post count_region = nombre de region de l'itinéraire 
 * 
 * @param way 
 * @return unsigned int 
*/
unsigned int count_region(struct ItineraireFlame_t *way); 

/**
 * @brief 
 * compte le nombre d'habitant sur l'itinéraire
 * 
 * @pre way != NULL
 * @post count_resident = nombre d'habitant de l'itinéraire
 * 
 * @param way 
 * @return unsigned int 
*/
unsigned int count_resident(struct ItineraireFlame_t *way); 


/**
 * @brief 
 * ajoute une region sur l'itinéraire
 * 
 * @pre way != NULL && region != NULL
 * @post region est inclue sur l'itinéraire
 * 
 * @param way 
 * @param region 
 * @return unsigned int 
*/
unsigned int add_region(struct ItineraireFlame_t *way, Region *region); 

/**
 * @brief 
 * supprime une region de l'itinéraire
 * 
 * @pre way != NULL && region != NULL
 * @post region n'appartient plus à l'itinéraire
 * 
 * @param way 
 * @param region 
*/
void remove_region(struct ItineraireFlame_t *way, Region *region); 


/**
 * @brief 
 * 
 * @pre way != NULL
 * @post l'espace mémoire de way a été libéré.
 * 
 * @param way 
 * @param delete_regions 
*/
void destroy_itineraireflame(struct ItineraireFlame_t *way, unsigned int delete_regions);

#endif // !__ITINERAIREFLAME__