#ifndef __REGION_H__
#define __REGION_H__


typedef struct Region_t Region;

/**
 * @brief 
 * Cette fonction va creer et retourner un nouvel 
 * objet Region
 * 
 * @param x 
 * @param y 
 * @param name 
 * @return struct Region_t* 
*/
struct Region_t *new_region(double x, double y, char *name);

/**
 * @brief 
 * retourne la coordonné x de l'objet region
 * 
 * @pre region != NULL
 * @post get_coord_x contient la coordonnée x de l'objet region
 * 
 * @param region 
 * @return double 
*/
double get_coord_x(struct Region_t *region);

/**
 * @brief
 * retourne la coordonné y de l'objet region
 * 
 * @pre region != NULL
 * @post get_coord_y=la position y de la region
 * 
 * @param region 
 * @return double 
*/
double get_coord_y(struct Region_t *region);

/**
 * @brief 
 * cette fonction calcule la distance entre deux
 * régions
 * 
 * @pre region_1 != NULL && region_2 != NULL
 * @post distance_between_region= La distance entre les deux régions
 * 
 * @param region_1 
 * @param region_2 
 * @return double 
*/
double distance_between_region(struct Region_t *region_1, struct Region_t *region_2);

/**
 * @brief 
 * retourne le nom de la region
 * 
 * @pre region != NULL
 * @post get_region_name contient le nom de la region
 * 
 * @param region 
 * @return char* 
*/
char *get_region_name(struct Region_t *region);

/**
 * @brief 
 * retourne le chef lieu d'une region
 * 
 * @pre region != NULL
 * @post get_region_headquater=chef lieu de la region
 * 
 * @param region 
 * @return char* 
*/
char *get_region_headquater(struct Region_t *region);

/**
 * @brief 
 * retourne la spécialité de la region
 * 
 * @pre region != NULL
 * @post get_region_speciality=la spécialité de la region
 * 
 * @param region 
 * @return char* 
*/
char *get_region_speciality(struct Region_t *region);


/**
 * @brief 
 * retourne le nombre d'habitant de la region
 * 
 * @pre region != NULL
 * @post get_nb_people contient le nombre d'habitant de la region
 * 
 * @param region 
 * @return unsigned int 
*/
unsigned int get_nb_people(struct Region_t *region);

/**
 * @brief 
 * affecte un nombre d'habitant à une region
 * 
 * @pre region != NULL
 * @post nb_people est le nombre d'habitant de la region
 * 
 * @param region 
 * @param nb_people 
*/
void set_nb_people(struct Region_t *region, unsigned int nb_people);

/**
 * @brief 
 * affecte un chef lieu à une region
 * 
 * @pre region != NULL
 * @post headquater est le chef lieu de la region
 * 
 * @param region 
 * @param headquater 
*/
void set_region_headquater(struct Region_t *region, char *headquater);

/**
 * @brief
 * affecte une spécialité à la region
 * 
 * @pre region != NULL
 * @post speciality est la spécialité de la region
 * 
 * @param region 
 * @param speciality 
*/
void set_region_speciality(struct Region_t *region, char *speciality);

/**
 * @brief 
 * 
 * @pre region != NULL
 * @post l'espace mémoire de region a été libéré 
 * 
 * @param region 
*/
void destroy_region(struct Region_t *region);

#endif // !__REGION_H__