/* main.c
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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pizza.h"
#include "include/menu.h"

int
main (void)
{
  printf ("%s\n", print_version ());
  printf ("%s\n", print_license ());

  FILE *file_pizza = NULL;
  char *file = NULL;
  const char *file_name = "/.pizza.dat";

  file = malloc (strlen (getenv ("HOME") + strlen (file_name) + 1));
  strcpy (file, getenv ("HOME"));
  strcat (file, file_name);
  
  open_file (&file_pizza, file);
  close_file (&file_pizza);
 
  return 0;
}
