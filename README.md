# pizzac

Management of pizzas

The program is divided into three parts, a GUI in GTK, a CLI, and a wrapper in Guile Scheme.

## Dependencies for the build

GCC, GTK4, Autotools, GLib >= 2.66.0

## Autotools Dance

sh autogen.sh

mkdir build && cd build

../configure && make

## Exec

./src/gtk_pizzac/gtkpizzac

./src/terminal_pizzac/terminalpizzac

./src/guile_pizzac/guilepizzac

## Package project (tar.gz)

make distcheck
