#include <cairo.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int width = 400, height = 300;
    cairo_surface_t *surface;
    cairo_t *cr;

    // PNG形式での出力を設定
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
    cr = cairo_create(surface);

    // 背景の色を設定
    cairo_set_source_rgb(cr, 1, 1, 1); // 白色
    cairo_paint(cr);

    // 車体を描画
    // 赤色を設定する。これは車体の色
    cairo_set_source_rgb(cr, 0.9, 0.1, 0.1); // 赤色
    // 長方形を描画し、塗りつぶす
    cairo_rectangle(cr, width / 2 - 100, height / 2, 200, 50); // 車体の下部
    cairo_fill(cr);
    // 円弧を作成し、塗りつぶす
    cairo_arc(cr, width / 2 - 75, height / 2, 25, M_PI, 2 * M_PI);
    cairo_fill(cr);
    cairo_arc(cr, width / 2 + 75, height / 2, 25, M_PI, 2 * M_PI);
    cairo_fill(cr);

    // 車の屋根を描画
    cairo_move_to(cr, width / 2 - 100, height / 2);
    cairo_line_to(cr, width / 2 - 75, height / 2 - 30);
    cairo_line_to(cr, width / 2 + 75, height / 2 - 30);
    cairo_line_to(cr, width / 2 + 100, height / 2);
    cairo_close_path(cr);
    cairo_fill(cr);

    // タイヤを描画
    cairo_set_source_rgb(cr, 0, 0, 0); // 黒色
    cairo_arc(cr, width / 2 - 60, height / 2 + 50, 20, 0, 2 * M_PI);
    cairo_fill(cr);
    cairo_arc(cr, width / 2 + 60, height / 2 + 50, 20, 0, 2 * M_PI);
    cairo_fill(cr);

    // タイヤの中心に灰色の円を描画
    cairo_set_source_rgb(cr, 0.5, 0.5, 0.5); // 灰色
    cairo_arc(cr, width / 2 - 60, height / 2 + 50, 10, 0, 2 * M_PI);
    cairo_fill(cr);
    cairo_arc(cr, width / 2 + 60, height / 2 + 50, 10, 0, 2 * M_PI);
    cairo_fill(cr);

    // 前後の窓を描画（再配置）
    cairo_set_source_rgb(cr, 0.53, 0.81, 0.92); // 水色

    // border_radiusの値
    double corner_radius = 5.0;

    // 運転席の窓
    cairo_move_to(cr, width / 2 - 95 + corner_radius, height / 2 - 10);
    cairo_line_to(cr, width / 2 - 35 - corner_radius, height / 2 - 10);
    cairo_arc(cr, width / 2 - 35 - corner_radius, height / 2 - 10 + corner_radius, corner_radius, 1.5 * M_PI, 2 * M_PI);
    cairo_line_to(cr, width / 2 - 35, height / 2 + 10 - corner_radius);
    cairo_arc(cr, width / 2 - 35 - corner_radius, height / 2 + 10 - corner_radius, corner_radius, 0, 0.5 * M_PI);
    cairo_line_to(cr, width / 2 - 95 + corner_radius, height / 2 + 10);
    cairo_arc(cr, width / 2 - 95 + corner_radius, height / 2 + 10 - corner_radius, corner_radius, 0.5 * M_PI, M_PI);
    cairo_line_to(cr, width / 2 - 95, height / 2 - 10 + corner_radius);
    cairo_arc(cr, width / 2 - 95 + corner_radius, height / 2 - 10 + corner_radius, corner_radius, M_PI, 1.5 * M_PI);
    cairo_close_path(cr);
    cairo_fill(cr);

    // 通常の窓（2つ）
    double window_start_x = width / 2 - 25;
    for (int i = 0; i < 2; i++)
    {
        cairo_move_to(cr, window_start_x + corner_radius, height / 2 - 10);
        cairo_line_to(cr, window_start_x + 40 - corner_radius, height / 2 - 10);
        cairo_arc(cr, window_start_x + 40 - corner_radius, height / 2 - 10 + corner_radius, corner_radius, 1.5 * M_PI, 2 * M_PI);
        cairo_line_to(cr, window_start_x + 40, height / 2 + 10 - corner_radius);
        cairo_arc(cr, window_start_x + 40 - corner_radius, height / 2 + 10 - corner_radius, corner_radius, 0, 0.5 * M_PI);
        cairo_line_to(cr, window_start_x + corner_radius, height / 2 + 10);
        cairo_arc(cr, window_start_x + corner_radius, height / 2 + 10 - corner_radius, corner_radius, 0.5 * M_PI, M_PI);
        cairo_line_to(cr, window_start_x, height / 2 - 10 + corner_radius);
        cairo_arc(cr, window_start_x + corner_radius, height / 2 - 10 + corner_radius, corner_radius, M_PI, 1.5 * M_PI);
        cairo_close_path(cr);
        cairo_fill(cr);
        window_start_x += 65;
    }

    // 描画をファイルに出力
    cairo_surface_write_to_png(surface, "car.png");

    // リソースの解放
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return 0;
}
