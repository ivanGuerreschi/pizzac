/* entry_widgets.h
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

#include <gtk/gtk.h>

#ifndef ENTRY_WIDGETS_H
#define ENTRY_WIDGETS_H

typedef struct _EntryWidget
{
  GtkWidget *entry_flour_type;
  GtkWidget *entry_grams_flour;
  GtkWidget *entry_yeast_type;
  GtkWidget *entry_grams_yeast;
  GtkWidget *entry_grams_water;
  GtkWidget *entry_grams_salt;
  GtkWidget *entry_grams_sugar;
  GtkWidget *entry_grams_oil;
  GtkWidget *entry_cooking_time;
  GtkWidget *entry_oven_temperature;
  GtkWidget *entry_condiment;
} EntryWidgets;

#endif /* ENTRY_WIDGETS_H */
