//
// pangocairo.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pangocairo.h:
 *
 * Copyright (C) 1999, 2004 Red Hat, Inc.
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

unit pangocairo;

{$mode objfpc}{$H+}

interface

uses
  ctypes,
  pango,
  cairo,
  glib2;

const
  LIB_PANGOCAIRO = 'libpangocairo-1.0-0.dll';


// #include <pango/pango.h>
// #include <cairo.h>

// G_BEGIN_DECLS

(**
 * PangoCairoFont:
 *
 * #PangoCairoFont is an interface exported by fonts for
 * use with Cairo. The actual type of the font will depend
 * on the particular font technology Cairo was compiled to use.
 *
 * Since: 1.18
 **)
type
  PangoCairoFont = record
  end;
  PPangoCairoFont = ^PangoCairoFont;
//todo #define PANGO_TYPE_CAIRO_FONT       (pango_cairo_font_get_type ())
//todo #define PANGO_CAIRO_FONT(object)    (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_CAIRO_FONT, PangoCairoFont))
//todo #define PANGO_IS_CAIRO_FONT(object) (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_CAIRO_FONT))

(**
 * PangoCairoFontMap:
 *
 * #PangoCairoFontMap is an interface exported by font maps for
 * use with Cairo. The actual type of the font map will depend
 * on the particular font technology Cairo was compiled to use.
 *
 * Since: 1.10
 **)
type
  PangoCairoFontMap = record
  end;
  PPangoCairoFontMap = ^PangoCairoFontMap;
//todo #define PANGO_TYPE_CAIRO_FONT_MAP       (pango_cairo_font_map_get_type ())
//todo #define PANGO_CAIRO_FONT_MAP(object)    (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_CAIRO_FONT_MAP, PangoCairoFontMap))
//todo #define PANGO_IS_CAIRO_FONT_MAP(object) (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_CAIRO_FONT_MAP))

(**
 * PangoCairoShapeRendererFunc:
 * @cr: a Cairo context with current point set to where the shape should
 * be rendered
 * @attr: the %PANGO_ATTR_SHAPE to render
 * @do_path: whether only the shape path should be appended to current
 * path of @cr and no filling/stroking done.  This will be set
 * to %TRUE when called from pango_cairo_layout_path() and
 * pango_cairo_layout_line_path() rendering functions.
 * @data: user data passed to pango_cairo_context_set_shape_renderer()
 *
 * Function type for rendering attributes of type %PANGO_ATTR_SHAPE
 * with Pango's Cairo renderer.
 *)
type
  PangoCairoShapeRendererFunc = procedure (cr: Pcairo_t; attr: PPangoAttrShape; do_path: gboolean; data: gpointer); cdecl;

(*
 * PangoCairoFontMap
 *)
function pango_cairo_font_map_get_type(): GType; cdecl; external LIB_PANGOCAIRO;

function pango_cairo_font_map_new(): PPangoFontMap; cdecl; external LIB_PANGOCAIRO;
function pango_cairo_font_map_new_for_font_type(fonttype: cairo_font_type_t): PPangoFontMap; cdecl; external LIB_PANGOCAIRO;
function pango_cairo_font_map_get_default(): PPangoFontMap; cdecl; external LIB_PANGOCAIRO;
procedure pango_cairo_font_map_set_default(fontmap: PPangoCairoFontMap); cdecl; external LIB_PANGOCAIRO;
function pango_cairo_font_map_get_font_type(fontmap: PPangoCairoFontMap): cairo_font_type_t; cdecl; external LIB_PANGOCAIRO;

procedure pango_cairo_font_map_set_resolution(fontmap: PPangoCairoFontMap; dpi: cdouble); cdecl; external LIB_PANGOCAIRO;
function pango_cairo_font_map_get_resolution(fontmap: PPangoCairoFontMap): cdouble; cdecl; external LIB_PANGOCAIRO;
{$ifndef PANGO_DISABLE_DEPRECATED}
// G_DEPRECATED_FOR(pango_font_map_create_context)
function pango_cairo_font_map_create_context(fontmap: PPangoCairoFontMap): PPangoContext; cdecl; external LIB_PANGOCAIRO;
{$endif}

(*
 * PangoCairoFont
 *)
function pango_cairo_font_get_type(): GType; cdecl; external LIB_PANGOCAIRO;

function pango_cairo_font_get_scaled_font(font: PPangoCairoFont): Pcairo_scaled_font_t; cdecl; external LIB_PANGOCAIRO;

(* Update a Pango context for the current state of a cairo context
 *)
procedure pango_cairo_update_context(cr: Pcairo_t; context: PPangoContext); cdecl; external LIB_PANGOCAIRO;

procedure pango_cairo_context_set_font_options(context: PPangoContext; const options: Pcairo_font_options_t); cdecl; external LIB_PANGOCAIRO;
function pango_cairo_context_get_font_options(context: PPangoContext): Pcairo_font_options_t; cdecl; external LIB_PANGOCAIRO;

procedure pango_cairo_context_set_resolution(context: PPangoContext; dpi: cdouble); cdecl; external LIB_PANGOCAIRO;
function pango_cairo_context_get_resolution(context: PPangoContext): cdouble; cdecl; external LIB_PANGOCAIRO;

procedure pango_cairo_context_set_shape_renderer(context: PPangoContext; func: PangoCairoShapeRendererFunc; data: gpointer; dnotify: GDestroyNotify); cdecl; external LIB_PANGOCAIRO;
function pango_cairo_context_get_shape_renderer(context: PPangoContext; data: pgpointer): PangoCairoShapeRendererFunc; cdecl; external LIB_PANGOCAIRO;

(* Convenience
 *)
function pango_cairo_create_context(cr: Pcairo_t): PPangoContext; cdecl; external LIB_PANGOCAIRO;
function pango_cairo_create_layout(cr: Pcairo_t): PPangoLayout; cdecl; external LIB_PANGOCAIRO;
procedure pango_cairo_update_layout(cr: Pcairo_t; layout: PPangoLayout); cdecl; external LIB_PANGOCAIRO;

(*
 * Rendering
 *)
procedure pango_cairo_show_glyph_string(cr: Pcairo_t; font: PPangoFont; glyphs: PPangoGlyphString); cdecl; external LIB_PANGOCAIRO;
procedure pango_cairo_show_glyph_item(cr: Pcairo_t; const text: pchar; glyph_item: PPangoGlyphItem); cdecl; external LIB_PANGOCAIRO;
procedure pango_cairo_show_layout_line(cr: Pcairo_t; line: PPangoLayoutLine); cdecl; external LIB_PANGOCAIRO;
procedure pango_cairo_show_layout(cr: Pcairo_t; layout: PPangoLayout); cdecl; external LIB_PANGOCAIRO;

procedure pango_cairo_show_error_underline(cr: Pcairo_t; x: cdouble; y: cdouble; width: cdouble; height: cdouble); cdecl; external LIB_PANGOCAIRO;

(*
 * Rendering to a path
 *)
procedure pango_cairo_glyph_string_path(cr: Pcairo_t; font: PPangoFont; glyphs: PPangoGlyphString); cdecl; external LIB_PANGOCAIRO;
procedure pango_cairo_layout_line_path(cr: Pcairo_t; line: PPangoLayoutLine); cdecl; external LIB_PANGOCAIRO;
procedure pango_cairo_layout_path(cr: Pcairo_t; layout: PPangoLayout); cdecl; external LIB_PANGOCAIRO;

procedure pango_cairo_error_underline_path(cr: Pcairo_t; x: cdouble; y: cdouble; width: cdouble; height: cdouble); cdecl; external LIB_PANGOCAIRO;

// G_END_DECLS


implementation


end.

