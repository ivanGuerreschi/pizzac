/* gtk_pizzac.c
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
#include "utility.h"
#include "include/interface_pizza.h"
#include "include/entry_widgets.h"

static void
activate (GtkApplication *app, gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *label_flour_type;
  GtkWidget *label_grams_flour;
  GtkWidget *label_yeast_type;
  GtkWidget *label_grams_yeast;
  GtkWidget *label_grams_water;
  GtkWidget *label_grams_salt;
  GtkWidget *label_grams_sugar;
  GtkWidget *label_grams_oil;
  GtkWidget *label_cooking_time;
  GtkWidget *label_oven_temperature;
  GtkWidget *label_condiment;
  GtkWidget *button_all_pizzas;
  GtkWidget *button_new_pizza;
  GtkWidget *textview_all_pizzas;
  EntryWidgets *entrys = g_slice_new (EntryWidgets);

  const gchar *title = "Pizzac";
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), title);

  grid = gtk_grid_new ();
  gtk_grid_set_column_spacing (GTK_GRID (grid), 5);
  gtk_grid_set_row_spacing (GTK_GRID (grid), 5);

  label_flour_type = gtk_label_new ("Flour Type");
  gtk_grid_attach (GTK_GRID (grid), label_flour_type, 0, 0, 1, 1);

  entrys->entry_flour_type = gtk_entry_new ();
  gtk_grid_attach (GTK_GRID (grid), entrys->entry_flour_type, 1, 0, 1, 1);

  label_grams_flour = gtk_label_new ("Grams Flour");
  gtk_grid_attach (GTK_GRID (grid), label_grams_flour, 2, 0, 1, 1);

  entrys->entry_grams_flour = gtk_entry_new ();
  gtk_grid_attach (GTK_GRID (grid), entrys->entry_grams_flour, 3, 0, 1, 1);

  label_yeast_type = gtk_label_new ("Yeast Type");
  gtk_grid_attach (GTK_GRID (grid), label_yeast_type, 0, 1, 1, 1);

  entrys->entry_yeast_type = gtk_entry_new ();
  gtk_grid_attach (GTK_GRID (grid), entrys->entry_yeast_type, 1, 1, 1, 1);

  label_grams_yeast = gtk_label_new ("Grams Yeast");
  gtk_grid_attach (GTK_GRID (grid), label_grams_yeast, 2, 1, 1, 1);

  entrys->entry_grams_yeast = gtk_entry_new ();
  gtk_grid_attach (GTK_GRID (grid), entrys->entry_grams_yeast, 3, 1, 1, 1);

  label_grams_water = gtk_label_new ("Grams Water");
  gtk_grid_attach (GTK_GRID (grid), label_grams_water, 0, 2, 1, 1);

  entrys->entry_grams_water = gtk_entry_new ();
  gtk_grid_attach (GTK_GRID (grid), entrys->entry_grams_water, 1, 2, 1, 1);

  label_grams_salt = gtk_label_new ("Grams Salt");
  gtk_grid_attach (GTK_GRID (grid), label_grams_salt, 2, 2, 1, 1);

  entrys->entry_grams_salt = gtk_entry_new ();
  gtk_grid_attach (GTK_GRID (grid), entrys->entry_grams_salt, 3, 2, 1, 1);

  label_grams_sugar = gtk_label_new ("Grams Sugar");
  gtk_grid_attach (GTK_GRID (grid), label_grams_sugar, 0, 3, 1, 1);

  entrys->entry_grams_sugar = gtk_entry_new ();
  gtk_grid_attach (GTK_GRID (grid), entrys->entry_grams_sugar, 1, 3, 1, 1);

  label_grams_oil = gtk_label_new ("Grams Oil");
  gtk_grid_attach (GTK_GRID (grid), label_grams_oil, 2, 3, 1, 1);

  entrys->entry_grams_oil = gtk_entry_new ();
  gtk_grid_attach (GTK_GRID (grid), entrys->entry_grams_oil, 3, 3, 1, 1);

  label_cooking_time = gtk_label_new ("Cooking Time");
  gtk_grid_attach (GTK_GRID (grid), label_cooking_time, 0, 4, 1, 1);

  entrys->entry_cooking_time = gtk_entry_new ();
  gtk_grid_attach (GTK_GRID (grid), entrys->entry_cooking_time, 1, 4, 1, 1);

  label_oven_temperature = gtk_label_new ("Oven Temperature");
  gtk_grid_attach (GTK_GRID (grid), label_oven_temperature, 2, 4, 1, 1);

  entrys->entry_oven_temperature = gtk_entry_new ();
  gtk_grid_attach (GTK_GRID (grid), entrys->entry_oven_temperature, 3, 4, 1, 1);

  label_condiment = gtk_label_new ("Condiment");
  gtk_grid_attach (GTK_GRID (grid), label_condiment, 0, 5, 1, 1);

  entrys->entry_condiment = gtk_entry_new ();
  gtk_grid_attach (GTK_GRID (grid), entrys->entry_condiment, 1, 5, 1, 1);

  textview_all_pizzas = gtk_text_view_new ();
  gtk_grid_attach (GTK_GRID (grid), textview_all_pizzas, 0, 7, 4, 1);

  button_all_pizzas = gtk_button_new_with_label ("All Pizzas");
  gtk_grid_attach (GTK_GRID (grid), button_all_pizzas, 0, 6, 1, 1);
  g_signal_connect (button_all_pizzas, "clicked", G_CALLBACK (on_btn_all_pizzas_clicked), textview_all_pizzas);

  button_new_pizza = gtk_button_new_with_label ("New Pizza");
  gtk_grid_attach (GTK_GRID (grid), button_new_pizza, 1, 6, 1, 1);
  g_signal_connect (button_new_pizza, "clicked", G_CALLBACK (on_btn_create_pizza_clicked), entrys);

  gtk_window_set_child (GTK_WINDOW (window), grid);
  gtk_window_present (GTK_WINDOW (window));
}

int
main (int argc, char **argv)
{
  file_pizza ();

  GtkApplication *app;
  int status;

  app = gtk_application_new ("de.givan.gtkpizzac", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
