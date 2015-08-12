#include "environment.h"
#include "term.h"

environment make_environment()
{
    environment env;
    env.map = make_string_term_map();
    return env;
}

void set_environment(environment env, term *t)
{
    term *copy = copy_term(t);
    string_term_map_set(env.map, copy->left->name, copy);
}

term *get_environment(environment env, char *s)
{
    term *t = string_term_map_get(env.map, s);
    if(!t) return 0;
    return t->right;
}
