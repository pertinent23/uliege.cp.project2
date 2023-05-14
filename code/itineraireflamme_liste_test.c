#include <stdio.h>
#include <math.h>
#include "seatest.h"

#include "region.h"
#include "itineraireflamme.h"

/**
 * @brief 
 * La premiere partie des test est faite
 * pour tester le comportement de l'objet 
 * et des methodes region
*/

static void test_create_region()
{
    Region *region = new_region(25, 30, "Gent");

    assert_int_equal(1, region != NULL);

    if (region != NULL)
    {
        set_nb_people(region, 39);

        assert_double_equal(25, get_coord_x(region), 0.0001);
        assert_double_equal(30, get_coord_y(region), 0.0001);
        assert_int_equal(1, get_region_name(region) != NULL);

        assert_int_equal(get_nb_people(region), 39);

        destroy_region(region);
    }
}

static void test_distance_region()
{
    Region
        *region1 = new_region(25, 45, "Liege"),
        *region2 = new_region(25, 23, "Bruxelles"),
        *region3 = new_region(75, 45, "Flandre");
    
    assert_true(region1 != NULL);
    assert_true(region2 != NULL);
    assert_true(region3 != NULL);

    double x1, y1, x2, y2, x3, y3;

    x1 = get_coord_x(region1);
    y1 = get_coord_y(region1);
    x2 = get_coord_x(region2);
    y2 = get_coord_y(region2);
    x3 = get_coord_x(region3);
    y3 = get_coord_y(region3);

    assert_double_equal(sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)), distance_between_region(region1, region2), 0.5);
    assert_double_equal(sqrt(pow(x3-x1, 2) + pow(y3-y1, 2)), distance_between_region(region1, region3), 0.5);
    assert_double_equal(sqrt(pow(x2-x3, 2) + pow(y2-y3, 2)), distance_between_region(region2, region3), 0.5);

    assert_double_equal(distance_between_region(region1, region2), distance_between_region(region2, region1), 0.01);
    assert_double_equal(distance_between_region(region3, region1), distance_between_region(region1, region3), 0.01);
    assert_double_equal(distance_between_region(region2, region3), distance_between_region(region3, region2), 0.01);
}

static void test_fixture_region()
{
    test_fixture_start();

    run_test(test_create_region);
    run_test(test_distance_region);

    test_fixture_end();
}

/**
 * @brief 
 * La seconde partie des tests est faites 
 * pour la gestion des itinéraires 
*/

static void test_create_itineraireflamme()
{
    ItineraireFlame *way;
    Region
        *departure = new_region(0, 0, ""),
        *arrival = new_region(0, 0, "");
    
    assert_true(departure != NULL);
    assert_true(arrival != NULL);

    if(departure && arrival)
    {   
        way = new_itineraireflame(departure, departure);
        assert_true(way == NULL);
        if (way != NULL) 
            destroy_itineraireflame(way, 0);
        
        way = new_itineraireflame(arrival, arrival);
        assert_true(way == NULL);
        if (way != NULL) 
            destroy_itineraireflame(way, 0);
        
        way = new_itineraireflame(departure, arrival);
        assert_false(way == NULL);

        if (way != NULL) 
            destroy_itineraireflame(way, 0);

        destroy_region(arrival);
        destroy_region(departure);
    }
}

static void test_add_and_count_region()
{
    ItineraireFlame *way;
    Region
        *departure = new_region(0, 0, "First"),
        *arrival = new_region(0, 0, "Second"),
        *other = new_region(0, 0, "Third");
    
    assert_true(departure != NULL);
    assert_true(arrival != NULL);
    assert_true(other != NULL);

    if(departure != NULL && arrival != NULL && other != NULL)
    {
        way = new_itineraireflame(departure, arrival);

        assert_true(way != NULL);

        if (way != NULL)
        {
            assert_int_equal(2, count_region(way));
            assert_int_equal(1, add_region(way, departure));
            assert_int_equal(2, count_region(way));
            assert_int_equal(1, add_region(way, other));
            assert_int_equal(3, count_region(way));

            remove_region(way, arrival);
            assert_int_equal(3, count_region(way));

            remove_region(way, departure);
            assert_int_equal(3, count_region(way));

            remove_region(way, other);
            assert_int_equal(2, count_region(way));

            destroy_itineraireflame(way, 0);

            destroy_region(other);
            destroy_region(arrival);
            destroy_region(departure);
        }
    }
}

static void test_fixture_itineraireflamme()
{
    test_fixture_start();

    run_test(test_create_itineraireflamme);
    run_test(test_add_and_count_region);

    test_fixture_end();
}

/**
 * @brief 
 * Ici nous allons lancer toute les 
 * test de region et intineraire 
*/

static void all_tests() 
{
    test_fixture_region();
    test_fixture_itineraireflamme();
}

int main()
{
    return run_tests(all_tests);
}