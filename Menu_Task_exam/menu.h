#pragma once


namespace alicee {
    struct MenuItem {
        const char *const title;

        const MenuItem *(*itemfunction)(const MenuItem *current);

        const MenuItem *parent;

        const MenuItem *const *children;
        const int children_count;

    };
}