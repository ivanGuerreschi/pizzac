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

typedef struct
{
  char *flour_type;
  double grams_flour;
  char *yeast_type;
  double grams_yeast;
  double grams_water;
  double grams_salt;
  double grams_sugar;
  char *other;  
} ingrediants_t;

typedef struct
{
  double cooking_time;
  double oven_temperature;
} preparation_t;
  


void open_file (FILE **, const char *name_file);
void close_file (FILE **);

#endif /* LIBPIZZA_H */
