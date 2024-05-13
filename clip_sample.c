#include <cairo.h>
#include <math.h>
#include <stdio.h>

void draw(cairo_t *cr)
{
    // 描画領域を円形の領域にクリップする
    // つまり、円形の領域以外の部分は描画されない
    cairo_arc(cr, 128.0, 128.0, 76.8, 0, 2 * M_PI);
    cairo_clip(cr);

    // パスをクリアする
    cairo_new_path(cr);

    cairo_rectangle(cr, 0, 0, 256, 256);
    cairo_fill(cr);

    // ソースの色を緑に設定する
    cairo_set_source_rgb(cr, 0, 1, 0);

    // 左上から右下に対角線を描く
    cairo_move_to(cr, 0, 0);
    cairo_line_to(cr, 256, 256);

    // 右上から左下に対角線を描く
    cairo_move_to(cr, 256, 0);
    cairo_line_to(cr, 0, 256);

    // 線の幅を10.0に設定する
    cairo_set_line_width(cr, 10.0);

    // 現在のソースの色と線の幅でパスを描画する
    cairo_stroke(cr);
}

int main(int argc, char *argv[])
{
    cairo_surface_t *surface;
    cairo_t *cr;

    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 256, 256);
    cr = cairo_create(surface);

    cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
    cairo_paint(cr);

    draw(cr);

    cairo_destroy(cr);
    cairo_surface_write_to_png(surface, "sample.png");
    cairo_surface_destroy(surface);

    return 0;
}
