project(
    lbase
    DESCRIPTION "Base of project belonging to 'Light'."
    LANGUAGES C
)

add_library(lbase STATIC err.c)
