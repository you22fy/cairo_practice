#include <cairo.h>
#include <stdio.h>
#include <math.h>

int main() {
    int width = 300, height = 300;
    cairo_surface_t *surface;
    cairo_t *cr;

    // PNG形式での出力を設定
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
    cr = cairo_create(surface);

    // 背景の色を設定
    cairo_set_source_rgb(cr, 1, 1, 1); // 白色
    cairo_paint(cr);

    // 缶の本体を描画（円筒形）
    cairo_set_source_rgb(cr, 0.7, 0.7, 0.7); // グレー
    cairo_rectangle(cr, width / 2 - 50, height / 2 - 80, 100, 160); // 缶の形
    cairo_fill(cr);

    // 上部のリムを描画
    cairo_set_source_rgb(cr, 0.6, 0.6, 0.6); // やや暗めのグレー
    cairo_rectangle(cr, width / 2 - 50, height / 2 - 80, 100, 10); // 上のリム
    cairo_fill(cr);

    // プルタブを描画
    cairo_set_line_width(cr, 4);
    cairo_set_source_rgb(cr, 0.5, 0.5, 0.5); // さらに暗めのグレー
    cairo_move_to(cr, width / 2, height / 2 - 70);
    cairo_line_to(cr, width / 2, height / 2 - 90);
    cairo_stroke(cr);

    cairo_arc(cr, width / 2, height / 2 - 100, 10, 0, 2 * M_PI);
    cairo_stroke(cr);

    // 描画をファイルに出力
    cairo_surface_write_to_png(surface, "can.png");

    // リソースの解放
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return 0;
}
