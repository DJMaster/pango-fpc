//
// pango-matrix.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pango-matrix.h: Matrix manipulation routines
 *
 * Copyright (C) 2002, 2006 Red Hat Software
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *)

// #ifndef __PANGO_MATRIX_H__
// #define __PANGO_MATRIX_H__

// #include <glib.h>
// #include <glib-object.h>

// G_BEGIN_DECLS

(**
 * PangoMatrix:
 * @xx: 1st component of the transformation matrix
 * @xy: 2nd component of the transformation matrix
 * @yx: 3rd component of the transformation matrix
 * @yy: 4th component of the transformation matrix
 * @x0: x translation
 * @y0: y translation
 *
 * A structure specifying a transformation between user-space
 * coordinates and device coordinates. The transformation
 * is given by
 *
 * <programlisting>
 * x_device = x_user * matrix->xx + y_user * matrix->xy + matrix->x0;
 * y_device = x_user * matrix->yx + y_user * matrix->yy + matrix->y0;
 * </programlisting>
 *
 * Since: 1.6
 **)
type
  PangoMatrix = record
    xx: cdouble;
    xy: cdouble;
    yx: cdouble;
    yy: cdouble;
    x0: cdouble;
    y0: cdouble;
  end;
  PPangoMatrix = ^PangoMatrix;

(**
 * PANGO_TYPE_MATRIX:
 *
 * The GObject type for #PangoMatrix
 **)
//todo #define PANGO_TYPE_MATRIX (pango_matrix_get_type ())

(**
 * PANGO_MATRIX_INIT:
 *
 * Constant that can be used to initialize a PangoMatrix to
 * the identity transform.
 *
 * <informalexample><programlisting>
 * PangoMatrix matrix = PANGO_MATRIX_INIT;
 * pango_matrix_rotate (&amp;matrix, 45.);
 * </programlisting></informalexample>
 *
 * Since: 1.6
 **)
//todo #define PANGO_MATRIX_INIT { 1., 0., 0., 1., 0., 0. }

(* for PangoRectangle *)
// #include <pango/pango-types.h>

function pango_matrix_get_type(): GType; cdecl; external LIB_PANGO;

function pango_matrix_copy(const matrix: PPangoMatrix): PPangoMatrix; cdecl; external LIB_PANGO;
procedure pango_matrix_free(matrix: PPangoMatrix); cdecl; external LIB_PANGO;

procedure pango_matrix_translate(matrix: PPangoMatrix; tx: double; ty: double); cdecl; external LIB_PANGO;
procedure pango_matrix_scale(matrix: PPangoMatrix; scale_x: double; scale_y: double); cdecl; external LIB_PANGO;
procedure pango_matrix_rotate(matrix: PPangoMatrix; degrees: double); cdecl; external LIB_PANGO;
procedure pango_matrix_concat(matrix: PPangoMatrix; const new_matrix: PPangoMatrix); cdecl; external LIB_PANGO;
procedure pango_matrix_transform_point(const matrix: PPangoMatrix; x: Pdouble; y: Pdouble); cdecl; external LIB_PANGO;
procedure pango_matrix_transform_distance(const matrix: PPangoMatrix; dx: Pdouble; dy: Pdouble); cdecl; external LIB_PANGO;
procedure pango_matrix_transform_rectangle(const matrix: PPangoMatrix; rect: PPangoRectangle); cdecl; external LIB_PANGO;
procedure pango_matrix_transform_pixel_rectangle(const matrix: PPangoMatrix; rect: PPangoRectangle); cdecl; external LIB_PANGO;
function pango_matrix_get_font_scale_factor(const matrix: PPangoMatrix): double; cdecl; external LIB_PANGO;
procedure pango_matrix_get_font_scale_factors(const matrix: PPangoMatrix; xscale: Pdouble; yscale: Pdouble); cdecl; external LIB_PANGO;


// G_END_DECLS

// #endif (* __PANGO_MATRIX_H__ *)
