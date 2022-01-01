#include "helper.h"

int power(int base, unsigned int exp) {
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
}

// Used euclidean distance formula (between two points) to calculate distance between two cities
int calculate_distance(struct City current, struct City other){
    int x_coords = power((other.x_coord - current.x_coord), 2);
    int y_coords = power((other.y_coord - current.y_coord), 2);

    double final_dist = sqrt(x_coords + y_coords);

    int final = final_dist;

    return final;
}

int closest_neighbour(int current_city, struct City list_of_cities[MAX_CITIES], int cities_visited[MAX_CITIES]){

    int sml_dist = INT_MAX;
    int closest_city = current_city;

    for(int i = 0; i < MAX_CITIES; i++){
        if(i != current_city){ //Ensures we don't calculate distance to itself
            int distance = calculate_distance(list_of_cities[current_city], list_of_cities[i]);
            if(distance < sml_dist && cities_visited[i] == -1){
                sml_dist = distance;
                closest_city = i;
            }
        }
    }

    cities_visited[closest_city] = 1;
    return closest_city;
}

int main(){
    srand(time(NULL));

    struct City list_of_cities[MAX_CITIES];
    int cities_visited[MAX_CITIES];
    
    for(int i = 0; i < MAX_CITIES; i++){
        struct City city;
        city.id = i;
        city.x_coord = rand() % 20;
        city.y_coord = rand() % 20;
        list_of_cities[i] = city;

        cities_visited[i] = -1;
    }

    for(int i = 0; i < MAX_CITIES; i++){
        struct City c = list_of_cities[i];
        printf("City: %d, X: %d, Y: %d\n", c.id, c.x_coord, c.y_coord);
    }

    for(int i = 0; i < MAX_CITIES; i++){
        printf("%d\n", closest_neighbour(i, list_of_cities, cities_visited));
    }

    printf("%d\n", closest_neighbour(0, list_of_cities, cities_visited));
    // printf("%d\n", closest_neighbour(closest_neighbour(0, list_of_cities), list_of_cities));
    // printf("%d\n", closest_neighbour(3, list_of_cities));

    return 0;
}