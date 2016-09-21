//
// pango-renderer.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pango-renderer.h: Base class for rendering
 *
 * Copyright (C) 2004, Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,  * Boston, MA 02111-1307, USA.
 *)

// #ifndef __PANGO_RENDERER_H_
// #define __PANGO_RENDERER_H_

// #include <pango/pango-layout.h>

// G_BEGIN_DECLS

//todo #define PANGO_TYPE_RENDERER            (pango_renderer_get_type())
//todo #define PANGO_RENDERER(object)         (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_RENDERER, PangoRenderer))
//todo #define PANGO_IS_RENDERER(object)      (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_RENDERER))
//todo #define PANGO_RENDERER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), PANGO_TYPE_RENDERER, PangoRendererClass))
//todo #define PANGO_IS_RENDERER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PANGO_TYPE_RENDERER))
//todo #define PANGO_RENDERER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), PANGO_TYPE_RENDERER, PangoRendererClass))

type
  PangoRendererPrivate = record
  end;
  PPangoRendererPrivate = ^PangoRendererPrivate;

(**
 * PangoRenderPart:
 * @PANGO_RENDER_PART_FOREGROUND: the text itself
 * @PANGO_RENDER_PART_BACKGROUND: the area behind the text
 * @PANGO_RENDER_PART_UNDERLINE: underlines
 * @PANGO_RENDER_PART_STRIKETHROUGH: strikethrough lines
 *
 * #PangoRenderPart defines different items to render for such
 * purposes as setting colors.
 *
 * Since: 1.8
 **)
(* When extending, note N_RENDER_PARTS #define in pango-renderer.c *)
type
  PangoRenderPart = (
    PANGO_RENDER_PART_FOREGROUND,
	PANGO_RENDER_PART_BACKGROUND,
	PANGO_RENDER_PART_UNDERLINE,
	PANGO_RENDER_PART_STRIKETHROUGH
  );

(**
 * PangoRenderer:
 * @matrix: (nullable): the current transformation matrix for
 *    the Renderer; may be %NULL, which should be treated the
 *    same as the identity matrix.
 *
 * #PangoRenderer is a base class for objects that are used to
 * render Pango objects such as #PangoGlyphString and
 * #PangoLayout.
 *
 * Since: 1.8
 **)
type
  PangoRenderer = record
    (*< private >*)
    parent_instance: GObject;
  
    underline: PangoUnderline;
    strikethrough: gboolean;
    active_count: cint;
  
    (*< public >*)
    matrix: PPangoMatrix;  (* May be NULL *)
  
    (*< private >*)
    priv: PPangoRendererPrivate;
  end;
  PPangoRenderer = ^PangoRenderer;

(**
 * PangoRendererClass:
 * @draw_glyphs: draws a #PangoGlyphString
 * @draw_rectangle: draws a rectangle
 * @draw_error_underline: draws a squiggly line that approximately
 * covers the given rectangle in the style of an underline used to
 * indicate a spelling error.
 * @draw_shape: draw content for a glyph shaped with #PangoAttrShape.
 *   @x, @y are the coordinates of the left edge of the baseline,  *   in user coordinates.
 * @draw_trapezoid: draws a trapezoidal filled area
 * @draw_glyph: draws a single glyph
 * @part_changed: do renderer specific processing when rendering
 *  attributes change
 * @begin: Do renderer-specific initialization before drawing
 * @end: Do renderer-specific cleanup after drawing
 * @prepare_run: updates the renderer for a new run
 * @draw_glyph_item: draws a #PangoGlyphItem
 *
 * Class structure for #PangoRenderer.
 *
 * Since: 1.8
 **)
type
  PangoRendererClass = record
    (*< private >*)
    parent_class: GObjectClass;

    (* vtable - not signals *)
    (*< public >*)

    (* All of the following have default implementations
     * and take as coordinates user coordinates in Pango units
     *)
    draw_glyphs: procedure(renderer: PPangoRenderer; font: PPangoFont; glyphs: PPangoGlyphString; x: cint; y: cint); cdecl;
    draw_rectangle: procedure(renderer: PPangoRenderer; part: PangoRenderPart; x: cint; y: cint; width: cint; height: cint); cdecl;
    draw_error_underline: procedure(renderer: PPangoRenderer; x: cint; y: cint; width: cint; height: cint); cdecl;

    (* Nothing is drawn for shaped glyphs unless this is implemented *)
    draw_shape: procedure(renderer: PPangoRenderer; attr: PPangoAttrShape; x: cint; y: cint); cdecl;

    (* These two must be implemented and take coordinates in
     * device space as doubles.
     *)
    draw_trapezoid: procedure(renderer: PPangoRenderer; part: PangoRenderPart; y1: cdouble; x11: cdouble; x21: cdouble; y2: cdouble; x12: cdouble; x22: cdouble); cdecl;
    draw_glyph: procedure(renderer: PPangoRenderer; font: PPangoFont; glyph: PangoGlyph; x: cdouble; y: cdouble); cdecl;

    (* Notification of change in rendering attributes
     *)
    part_changed: procedure(renderer: PPangoRenderer; part: PangoRenderPart); cdecl;

    (* Paired around drawing operations
     *)
    begin_: procedure (renderer: PPangoRenderer); cdecl;
    end_: procedure(renderer: PPangoRenderer); cdecl;

    (* Hooks into the details of layout rendering
     *)
    prepare_run: procedure(renderer: PPangoRenderer; run: PPangoLayoutRun); cdecl;

    (* All of the following have default implementations
     * and take as coordinates user coordinates in Pango units
     *)
    draw_glyph_item: procedure(renderer: PPangoRenderer; const text: pchar; glyph_item: PPangoGlyphItem; x: cint; y: cint); cdecl;

    (*< private >*)

    (* Padding for future expansion *)
    _pango_reserved2: procedure(); cdecl;
    _pango_reserved3: procedure(); cdecl;
    _pango_reserved4: procedure(); cdecl;
  end;
  PPangoRendererClass = ^PangoRendererClass;

function pango_renderer_get_type(): GType; cdecl; external LIB_PANGO;

procedure pango_renderer_draw_layout(renderer: PPangoRenderer; layout: PPangoLayout; x: cint; y: cint); cdecl; external LIB_PANGO;
procedure pango_renderer_draw_layout_line(renderer: PPangoRenderer; line: PPangoLayoutLine; x: cint; y: cint); cdecl; external LIB_PANGO;
procedure pango_renderer_draw_glyphs(renderer: PPangoRenderer; font: PPangoFont; glyphs: PPangoGlyphString; x: cint; y: cint); cdecl; external LIB_PANGO;
procedure pango_renderer_draw_glyph_item(renderer: PPangoRenderer; const text: pchar; glyph_item: PPangoGlyphItem; x: cint; y: cint); cdecl; external LIB_PANGO;
procedure pango_renderer_draw_rectangle(renderer: PPangoRenderer; part: PangoRenderPart; x: cint; y: cint; width: cint; height: cint); cdecl; external LIB_PANGO;
procedure pango_renderer_draw_error_underline(renderer: PPangoRenderer; x: cint; y: cint; width: cint; height: cint); cdecl; external LIB_PANGO;
procedure pango_renderer_draw_trapezoid(renderer: PPangoRenderer; part: PangoRenderPart; y1_: cdouble; x11: cdouble; x21: cdouble; y2: cdouble; x12: cdouble; x22: cdouble); cdecl; external LIB_PANGO;
procedure pango_renderer_draw_glyph(renderer: PPangoRenderer; font: PPangoFont; glyph: PangoGlyph; x: cdouble; y: cdouble); cdecl; external LIB_PANGO;

procedure pango_renderer_activate(renderer: PPangoRenderer); cdecl; external LIB_PANGO;
procedure pango_renderer_deactivate(renderer: PPangoRenderer); cdecl; external LIB_PANGO;

procedure pango_renderer_part_changed(renderer: PPangoRenderer; part: PangoRenderPart); cdecl; external LIB_PANGO;

procedure pango_renderer_set_color(renderer: PPangoRenderer; part: PangoRenderPart; const color: PPangoColor); cdecl; external LIB_PANGO;
function pango_renderer_get_color(renderer: PPangoRenderer; part: PangoRenderPart): PPangoColor; cdecl; external LIB_PANGO;

procedure pango_renderer_set_alpha(renderer: PPangoRenderer; part: PangoRenderPart; alpha: guint16); cdecl; external LIB_PANGO;
function pango_renderer_get_alpha(renderer: PPangoRenderer; part: PangoRenderPart): guint16; cdecl; external LIB_PANGO;

procedure pango_renderer_set_matrix(renderer: PPangoRenderer; const matrix: PPangoMatrix); cdecl; external LIB_PANGO;
function pango_renderer_get_matrix(renderer: PPangoRenderer): PPangoMatrix; cdecl; external LIB_PANGO;

function pango_renderer_get_layout(renderer: PPangoRenderer): PPangoLayout; cdecl; external LIB_PANGO;
function pango_renderer_get_layout_line(renderer: PPangoRenderer): PPangoLayoutLine; cdecl; external LIB_PANGO;

// G_END_DECLS

// #endif (* __PANGO_RENDERER_H_ *)
