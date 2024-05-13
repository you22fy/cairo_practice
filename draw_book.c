#include <cairo.h>
#include <stdio.h>

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

    // 本の表紙を描画
    cairo_set_source_rgb(cr, 0.9, 0.5, 0.1); // 茶色
    cairo_rectangle(cr, width / 2 - 50, height / 2 - 80, 100, 160); // 本の表紙
    cairo_fill(cr);

    // 本の背表紙を描画
    cairo_set_source_rgb(cr, 0.8, 0.4, 0.1); // 暗めの茶色
    cairo_rectangle(cr, width / 2 - 60, height / 2 - 80, 10, 160); // 背表紙
    cairo_fill(cr);

    // 本の側面を描画
    cairo_set_source_rgb(cr, 0.7, 0.35, 0.05); // より暗めの茶色
    cairo_rectangle(cr, width / 2 + 50, height / 2 - 80, 10, 160); // 側面
    cairo_fill(cr);

    // 本のタイトルを描画
    cairo_move_to(cr, width / 2 - 45, height / 2); // タイトルの位置
    cairo_set_font_size(cr, 16);
    cairo_set_source_rgb(cr, 1, 1, 1); // 白色でタイトル
    cairo_show_text(cr, "Title of the Book");

    // 描画をファイルに出力
    cairo_surface_write_to_png(surface, "book.png");

    // リソースの解放
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return 0;
}
