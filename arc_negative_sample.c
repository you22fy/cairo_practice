#include <cairo.h>
#include <math.h>
#include <stdio.h>

void draw(cairo_t *cr)
{
    double xc = 128.0;
    double yc = 128.0;
    double radius = 100.0;
    double angle1 = 45.0 * (M_PI / 180.0);  /* angles are specified */
    double angle2 = 180.0 * (M_PI / 180.0); /* in radians           */

    // 線の太さを設定する
    cairo_set_line_width(cr, 10.0);

    // 線の色を設定する
    // cairo_set_source_rgb(cr, red, green, blue);
    cairo_set_source_rgb(cr, 0, 0, 0);

    // 円弧を描画する
    // 中心(xc, yc)
    // 半径radius
    // 開始角度angle1, 終了角度angle2
    // cairo_arc_negative: 反時計回りの円弧を描画する.
    cairo_arc_negative(cr, xc, yc, radius, angle1, angle2);

    // 現在のパスを描画する
    // パスとは、直線や曲線などの図形を描画するための情報を保持するオブジェクト
    // [cairo_arc]関数ではパスを設定するのみで実際の描画は行なっていない.
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
