#include <cairo.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int width = 300, height = 300;
    cairo_surface_t *surface;
    cairo_t *cr;

    // PNG形式での出力を設定
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
    cr = cairo_create(surface);

    // 背景の色を設定
    cairo_set_source_rgb(cr, 1, 1, 1); // 白色
    cairo_paint(cr);

    // 猫の頭を描画（円）
    cairo_set_source_rgb(cr, 0.8, 0.8, 0.8); // 薄灰色
    cairo_arc(cr, width / 2, height / 2, 100, 0, 2 * M_PI);
    cairo_fill(cr);

    // 猫の耳を描画（三角形二つ）
    cairo_set_line_width(cr, 2);
    cairo_move_to(cr, width / 2 - 70, height / 2 - 70);
    cairo_line_to(cr, width / 2 - 100, height / 2 - 120);
    cairo_line_to(cr, width / 2 - 30, height / 2 - 120);
    cairo_close_path(cr);
    cairo_fill(cr);

    cairo_move_to(cr, width / 2 + 70, height / 2 - 70);
    cairo_line_to(cr, width / 2 + 100, height / 2 - 120);
    cairo_line_to(cr, width / 2 + 30, height / 2 - 120);
    cairo_close_path(cr);
    cairo_fill(cr);

    // 目を描画（二つの大きな黒い円）
    cairo_set_source_rgb(cr, 0, 0, 0); // 黒色
    cairo_arc(cr, width / 2 - 40, height / 2 - 20, 20, 0, 2 * M_PI);
    cairo_fill(cr);
    cairo_arc(cr, width / 2 + 40, height / 2 - 20, 20, 0, 2 * M_PI);
    cairo_fill(cr);

    // 鼻を描画（小さな黒い円）
    cairo_arc(cr, width / 2, height / 2 + 20, 5, 0, 2 * M_PI);
    cairo_fill(cr);

    // 口を描画（弧）
    cairo_set_line_width(cr, 2);
    cairo_move_to(cr, width / 2 - 20, height / 2 + 40);
    cairo_line_to(cr, width / 2, height / 2 + 50);
    cairo_line_to(cr, width / 2 + 20, height / 2 + 40);
    cairo_stroke(cr);

    // 描画をファイルに出力
    cairo_surface_write_to_png(surface, "cat_character.png");

    // リソースの解放
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return 0;
}
