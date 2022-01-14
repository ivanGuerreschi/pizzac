/* guile_pizzac.c
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

#include <libguile.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include "info.h"
#include "pizza.h"

char *file_name;

static SCM version ();
static SCM license ();
static SCM allpizzas ();

static void
inner_main (void *closure, int argc, char **argv)
{
  scm_c_define_gsubr ("version", 0, 0, 0, version);
  scm_c_define_gsubr ("license", 0, 0, 0, license);
  scm_c_define_gsubr ("allpizzas", 0, 0, 0, allpizzas);

  scm_shell (argc, argv);
}

int
main (int argc, char **argv)
{
  const char *file_pizza_txt = "/.pizza.txt";
  if ((file_name = getenv ("HOME")) == NULL)
    file_name = getpwuid (getuid())->pw_dir;

  strcat (file_name, file_pizza_txt);
  scm_boot_guile (argc, argv, inner_main, 0);
  return 0;
}

static SCM
version (void)
{
  SCM result = scm_from_utf8_string (print_version ());
  return result;
}

static SCM
license (void)
{
  SCM result = scm_from_utf8_string (print_license ());
  return result;
}

static SCM
allpizzas (void)
{
  FILE *file_pizza, *file_row;
  open_file (&file_pizza, file_name);
  open_file (&file_row, file_name);

  int row = count_row_file (file_row);
  pizza_t *pizza = all_pizzas (file_pizza, row);

  const char *header ="Flour type-Grams flour-Yeast type-Grams yeast-Grams water-"
                      "Grams salt-Grams sugar-Grams oil-Cooking time-Oven temperature-Condiment\n";

  char buffer[BUFSIZ];
  char pizzas[BUFSIZ];

  strcpy (pizzas, header);

  for (int i = 0; i < row; i++)
    {
      strcat (pizzas, pizza[i].ingrediants.flour_type);

      sprintf (buffer, " %dgr ", pizza[i].ingrediants.grams_flour);
      strcat (pizzas, buffer);

      strcat (pizzas, pizza[i].ingrediants.yeast_type);

      sprintf (buffer, " %dgr ", pizza[i].ingrediants.grams_yeast);
      strcat (pizzas, buffer);

      sprintf (buffer, "%dgr ", pizza[i].ingrediants.grams_water);
      strcat (pizzas, buffer);

      sprintf (buffer, "%dgr ", pizza[i].ingrediants.grams_salt);
      strcat (pizzas, buffer);

      sprintf (buffer, "%dgr ", pizza[i].ingrediants.grams_sugar);
      strcat (pizzas, buffer);

      sprintf (buffer, "%dgr ", pizza[i].ingrediants.grams_oil);
      strcat (pizzas, buffer);

      sprintf (buffer, "%dm ", pizza[i].preparation.cooking_time);
      strcat (pizzas, buffer);

      sprintf (buffer, "%d˚ ", pizza[i].preparation.oven_temperature);
      strcat (pizzas, buffer);

      strcat (pizzas, pizza[i].preparation.condiment);
      strcat (pizzas, "\n");
    }

  for (int i = 0; i < row; i++)
    {
      free (pizza[i].ingrediants.flour_type);
      free (pizza[i].ingrediants.yeast_type);
      free (pizza[i].preparation.condiment);
    }

  free (pizza);
  close_file (&file_pizza);
  close_file (&file_row);

  SCM result = scm_from_utf8_string (pizzas);
  return result;
}
