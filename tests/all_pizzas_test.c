/* all_pizzas_test.c
   Copyright (C) 2021-2022 Ivan Guerreschi

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

#include "pizza.h"
#include "utility.h"

int
main (void)
{
  const char *file = file_name ();

  FILE *file_pizza, *file_row;
  open_file (&file_pizza, file);
  open_file (&file_row, file);

  int row = count_row_file (file_row);
  pizza_t *pizza = NULL;
  pizza = all_pizzas (file_pizza, row);

  if (pizza != NULL)
    return 0;
  else
    return 1;
}
