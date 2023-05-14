#ifndef __REGION_H__
#define __REGION_H__


typedef struct Region_t Region;

struct Region_t *new_region(double x, double y, char *name);

double get_coord_x(struct Region_t *region);
double get_coord_y(struct Region_t *region);
double distance_between_region(struct Region_t *region_1, struct Region_t *region_2);

char *get_region_name(struct Region_t *region);
char *get_region_headquater(struct Region_t *region);
char *get_region_speciality(struct Region_t *region);

unsigned int get_nb_people(struct Region_t *region);

void set_nb_people(struct Region_t *region, unsigned int nb_people);
void set_region_headquater(struct Region_t *region, char *headquater);
void set_region_speciality(struct Region_t *region, char *speciality);
void destroy_region(struct Region_t *region);

#endif // !__REGION_H__