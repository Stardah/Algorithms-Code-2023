#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    double x;
    double y;
} Point;

typedef struct {
    int length;
    struct Point *coords;
} Polygon;

typedef struct {
    int length;
    struct Point *coords;
} PolyLine;

typedef enum {
    POINT,
    POLY_LINE,
    POLYGON
} Type;

typedef struct Geometry_t {
    Type type;
    union {
        Polygon polygon;
        PolyLine poly_line;
        Point point;
    };
} Geometry;

void copy_points(const Point *src, size_t size, Point *dst) {
    for (size_t i = 0; i < size; i++) {
        dst[i] = src[i];
    }
}

Point *allocate_points(size_t length) {
    Point *points = malloc(sizeof(double) * length);
    if (points == NULL) {
        printf("Not enough RAM");
        exit(137);
    }

    return points;
}

void serialize(const Geometry *geoms, int length) {
    FILE *file = fopen("serialized", "wb");

    fwrite(&length, sizeof(int), 1, file);

    for (size_t i = 0; i < length; i++) {
        fwrite(&geoms[i].type, sizeof(Type), 1, file);

        if (geoms[i].type == POINT) {
            fwrite(&geoms[i].point, sizeof(Point), 1, file);
            // printf("%llu\n", sizeof(Point));
        } else {
            int length;
            Point *points;
            if (geoms[i].type == POLY_LINE) {
                length = geoms[i].poly_line.length;
                points = geoms[i].poly_line.coords;
            } else {
                length = geoms[i].polygon.length;
                points = geoms[i].polygon.coords;
            }

            fwrite(&length, sizeof(int), 1, file);
            fwrite(points, sizeof(Point), length, file);
        }
    }

    fclose(file);
}

struct Geometry_t *deserialize(const char *input) {
    int geoms_count = *(int *)input; // Первый int это количество геометрий в файле
    char offset = sizeof(int);

    Geometry *geoms = malloc(geoms_count * sizeof(Geometry));

    for (size_t i = 0; i < geoms_count; i++) {

        const Type type = *((Type *)(input + offset));
        offset += sizeof(int); // enum'ы занимают int
        geoms[i].type = type;

        if (type == POINT) {
            geoms[i].point = *(Point *)(input + offset);
            offset += sizeof(Point);
        } else {
            const int length = *(int *)(input + offset);
            offset += sizeof(int);

            Point *points = allocate_points(length);
            copy_points((Point *)(input + offset), length, points);
            offset += sizeof(Point) * length;

            if (type == POLY_LINE) {
                geoms[i].poly_line.length = length;
                geoms[i].poly_line.coords = points;
            } else if (type == POLYGON) {
                geoms[i].polygon.length = length;
                geoms[i].polygon.coords = points;
            }
        }
    }

    return geoms;
}

void print_geoms(Geometry *geoms, size_t length) {
    for (size_t i = 0; i < length; i++) {
        printf("Type: %d\n", geoms[i].type);
        if (geoms[i].type == POINT) {
            printf("x: %f; y: %f;\n", geoms[i].point.x, geoms[i].point.y);
        } else {
            int length;
            Point *points;
            if (geoms[i].type == POLY_LINE) {
                length = geoms[i].poly_line.length;
                points = geoms[i].poly_line.coords;
            } else {
                length = geoms[i].polygon.length;
                points = geoms[i].polygon.coords;
            }

            printf("Length: %d\nPoints: ", length);
            for (size_t i = 0; i < length; i++) {
                printf("x: %f, y: %f; ", points[i].x, points[i].y);
            }
            printf("\n");
        }
    }
}

int main(void) {
    const int LENGTH = 2;
    Geometry *test = malloc(LENGTH * sizeof(Geometry));
    test[0].type = POINT;
    test[0].point.x = 10;
    test[0].point.y = 15;
    test[1].type = POLY_LINE;
    test[1].poly_line.length = 1;
    test[1].poly_line.coords = malloc(sizeof(Point) * 1);
    test[1].poly_line.coords[0].x = 1;
    test[1].poly_line.coords[0].y = 2;

    serialize(test, LENGTH);
    free(test[1].poly_line.coords);
    free(test);

    const int MAX_FILE_SIZE = 100000;
    char input[MAX_FILE_SIZE];

    FILE *file = fopen("serialized", "rb");
    if (file != NULL) {
        fread(input, MAX_FILE_SIZE, 1, file);

        Geometry *geoms = deserialize((char *)input);
        print_geoms(geoms, 2);
        // Eсть утечка?
    }

    fclose(file);

    return 0;
}