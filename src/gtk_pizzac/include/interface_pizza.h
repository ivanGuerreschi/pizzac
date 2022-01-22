/* interface_pizza.h
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

#ifndef INTERFACE_PIZZA_H
#define INTERFACE_PIZZA_H

#include <gtk/gtk.h>
#include "include/entry_widgets.h"

void on_btn_all_pizzas_clicked (GtkWidget *button, gpointer data);
void on_btn_create_pizza_clicked (GtkWidget    *button,
                                  EntryWidgets *entrys);

#endif /* INTERFACE_PIZZA_H  */
