/* pizza.h
   Copyright (C) 2021 Ivan Guerreschi

This file is part of pizzac.

Author: Ivan Guerreschi <ivanguerreschi86@gmail.com>
Maintainer: Ivan Guerreschi <ivanguerreschi86@gmail.com>

pizzac is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

pizzac is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with pizzac. If not, see <http://www.gnu.org/licenses/>. */

#ifndef LIBPIZZA_H
#define LIBPIZZA_H

#include <stdio.h>

struct ingrediants_s
{
  char *flour_type;
  int grams_flour;
  char *yeast_type;
  int grams_yeast;
  int grams_water;
  int grams_salt;
  int grams_sugar;
  int grams_oil;
};

struct preparation_s
{
  int cooking_time;
  int oven_temperature;
  char *condiment;
};

typedef struct
{
  struct ingrediants_s ingrediants;
  struct preparation_s preparation;
} pizza_t;

void open_file (FILE **, const char *name_file);
void close_file (FILE **);
int count_row_file (FILE *);
pizza_t *all_pizzas (FILE *, int);
void create_pizza (FILE *, pizza_t);

#endif /* LIBPIZZA_H */
