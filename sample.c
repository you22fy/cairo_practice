#include <cairo.h>
#include <math.h>
#include <stdio.h>
// gcc sample.c -o sample -I/opt/homebrew/opt/cairo/include/cairo -L/opt/homebrew/opt/cairo/lib -lcairo

void draw_face(cairo_t *cr) {
    cairo_arc(cr, 128.0, 128.0, 100.0, 0, 2 * M_PI);
    cairo_set_source_rgb(cr, 0.9, 0.9, 0.8);
    cairo_fill_preserve(cr);
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_stroke(cr);

    cairo_arc(cr, 100.0, 100.0, 10.0, 0, 2 * M_PI);
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_fill(cr);

    cairo_arc(cr, 156.0, 100.0, 10.0, 0, 2 * M_PI);
    cairo_fill(cr);

    cairo_arc(cr, 128.0, 150.0, 36.0, M_PI / 4, 3 * M_PI / 4);
    cairo_stroke(cr);
}

int main(int argc, char *argv[]) {
    cairo_surface_t *surface;
    cairo_t *cr;

    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 256, 256);
    cr = cairo_create(surface);

    draw_face(cr);

    cairo_destroy(cr);
    cairo_surface_write_to_png(surface, "sample.png");
    cairo_surface_destroy(surface);

    return 0;
}
