# cairo メモ

## cairo_fill と cairo_stroke の違い

- cairo_fill()
  - 現在のパスにある図形を塗りつぶす
- cairo_stroke()
  - 現在のパスにある図形の輪郭を描画する

## cairo_line_to と cairo_move_to の違い

- cairo_line_to
  - 現在の位置から指定した座標まで直線を引く
  - 「どこまで線を引くか」を決定する
- cairo_move_to
  - 現在の位置を指定した座標に移動する.実際の描画は行わない
  - 「どこから描き始めるか」を決定する
