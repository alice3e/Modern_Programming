#pragma once


namespace alicee {
    struct MenuItem {
        const char *const title;
        const char *const information_link;

        const MenuItem *(*itemfunction)(const MenuItem *current);

        const MenuItem *parent;
        const MenuItem *const *children; // always arr[ &child1 , &child2 etc]

        const int children_count;
    };
}