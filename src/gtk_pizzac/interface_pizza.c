/* interface_pizza.c
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
#include "pizza.h"
#include "utility.h"
#include "include/interface_pizza.h"
#include "include/entry_widgets.h"

void
on_btn_all_pizzas_clicked (GtkWidget *button, gpointer data)
{
  GtkTextBuffer *buffer;
  FILE *file_pizza, *file_row;

  char *file = file_name ();

  open_file (&file_pizza, file);
  open_file (&file_row, file);

  int row = count_row_file (file_row);
  pizza_t *pizza = all_pizzas (file_pizza, row);

  gchar *text_view_pizzas = (gchar *) g_malloc (row * (250 * sizeof (gchar)));
  int pos = 0;

  for (int i = 0; i < row; i++)
    pos += g_snprintf (&text_view_pizzas[pos], 250, "%s    %dgr    %s    %dgr    %dgr    %dgr    "
                       "%dgr    %dgr    %dm    %d°    %s\n",
                       pizza[i].ingrediants.flour_type, pizza[i].ingrediants.grams_flour,
                       pizza[i].ingrediants.yeast_type, pizza[i].ingrediants.grams_yeast,
                       pizza[i].ingrediants.grams_water,
                       pizza[i].ingrediants.grams_salt,
                       pizza[i].ingrediants.grams_sugar,
                       pizza[i].ingrediants.grams_oil,
                       pizza[i].preparation.cooking_time,
                       pizza[i].preparation.oven_temperature,
                       pizza[i].preparation.condiment);

  if (!g_utf8_validate (text_view_pizzas, -1, NULL))
    {
      g_printerr ("%s\n %s", "Invalid UTF-8 filename", text_view_pizzas);
      return;
    }

  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (data));
  gtk_text_buffer_set_text (buffer, text_view_pizzas, -1);

  for (int i = 0; i < row; i++)
    {
      free (pizza[i].ingrediants.flour_type);
      free (pizza[i].ingrediants.yeast_type);
      free (pizza[i].preparation.condiment);
    }

  free (pizza);
  pizza = NULL;
  g_free (text_view_pizzas);
  text_view_pizzas = NULL;
  close_file (&file_pizza);
  close_file (&file_row);
}

void
on_btn_create_pizza_clicked (GtkWidget    *button,
                             EntryWidgets *entrys)
{
  GtkEntryBuffer *buffer;
  pizza_t pizza;
  const gchar *flour_type;
  const gchar *grams_flour;
  const gchar *yeast_type;
  const gchar *grams_yeast;
  const gchar *grams_water;
  const gchar *grams_salt;
  const gchar *grams_sugar;
  const gchar *grams_oil;
  const gchar *cooking_time;
  const gchar *oven_temperature;
  const gchar *condiment;

  char *file = file_name ();

  buffer = gtk_entry_get_buffer (GTK_ENTRY (entrys->entry_flour_type));
  flour_type = gtk_entry_buffer_get_text (buffer);
  pizza.ingrediants.flour_type = (gchar *) calloc (strlen (flour_type) + 1, sizeof (char));
  g_stpcpy (pizza.ingrediants.flour_type, flour_type);

  buffer = gtk_entry_get_buffer (GTK_ENTRY (entrys->entry_grams_flour));
  grams_flour = gtk_entry_buffer_get_text (buffer);
  pizza.ingrediants.grams_flour = g_ascii_strtoll (grams_flour, NULL, 10);

  buffer = gtk_entry_get_buffer (GTK_ENTRY (entrys->entry_yeast_type));
  yeast_type = gtk_entry_buffer_get_text (buffer);
  pizza.ingrediants.yeast_type = (gchar *)calloc (strlen (yeast_type) + 1, sizeof (char));
  g_stpcpy (pizza.ingrediants.yeast_type, yeast_type);

  buffer = gtk_entry_get_buffer (GTK_ENTRY (entrys->entry_grams_yeast));
  grams_yeast = gtk_entry_buffer_get_text (buffer);
  pizza.ingrediants.grams_yeast = g_ascii_strtoll (grams_yeast, NULL, 10);

  buffer = gtk_entry_get_buffer (GTK_ENTRY (entrys->entry_grams_water));
  grams_water = gtk_entry_buffer_get_text (buffer);
  pizza.ingrediants.grams_water = g_ascii_strtoll (grams_water, NULL, 10);

  buffer = gtk_entry_get_buffer (GTK_ENTRY (entrys->entry_grams_salt));
  grams_salt = gtk_entry_buffer_get_text (buffer);
  pizza.ingrediants.grams_salt = g_ascii_strtoll (grams_salt, NULL, 10);

  buffer = gtk_entry_get_buffer (GTK_ENTRY (entrys->entry_grams_sugar));
  grams_sugar = gtk_entry_buffer_get_text (buffer);
  pizza.ingrediants.grams_sugar = g_ascii_strtoll (grams_sugar, NULL, 10);

  buffer = gtk_entry_get_buffer (GTK_ENTRY (entrys->entry_grams_oil));
  grams_oil = gtk_entry_buffer_get_text (buffer);
  pizza.ingrediants.grams_oil = g_ascii_strtoll (grams_oil, NULL, 10);

  buffer = gtk_entry_get_buffer (GTK_ENTRY (entrys->entry_cooking_time));
  cooking_time = gtk_entry_buffer_get_text (buffer);
  pizza.preparation.cooking_time = g_ascii_strtoll (cooking_time, NULL, 10);

  buffer = gtk_entry_get_buffer (GTK_ENTRY (entrys->entry_oven_temperature));
  oven_temperature = gtk_entry_buffer_get_text (buffer);
  pizza.preparation.oven_temperature = g_ascii_strtoll (oven_temperature, NULL, 10);

  buffer = gtk_entry_get_buffer (GTK_ENTRY (entrys->entry_condiment));
  condiment = gtk_entry_buffer_get_text (buffer);
  pizza.preparation.condiment = (gchar *) calloc (strlen (condiment) + 1, sizeof (char));
  g_stpcpy (pizza.preparation.condiment, condiment);

  FILE *file_pizza;
  open_file (&file_pizza, file);
  create_pizza (file_pizza, pizza);
  close_file (&file_pizza);

  g_free (pizza.ingrediants.flour_type);
  g_free (pizza.ingrediants.yeast_type);
  g_free (pizza.preparation.condiment);
}
