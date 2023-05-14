#ifndef __ITINERAIREFLAME__
#define __ITINERAIREFLAME__

#include "region.h"

typedef struct ItineraireFlame_t ItineraireFlame;

struct ItineraireFlame_t *new_itineraireflame(Region *start, Region *end);

unsigned int is_circuit(struct ItineraireFlame_t *way);

unsigned int count_region(struct ItineraireFlame_t *way); 

unsigned int count_resident(struct ItineraireFlame_t *way); 

unsigned int add_region(struct ItineraireFlame_t *way, Region *region); 

void remove_region(struct ItineraireFlame_t *way, Region *region); 

void destroy_itineraireflame(struct ItineraireFlame_t *way, unsigned int delete_regions);

#endif // !__ITINERAIREFLAME__