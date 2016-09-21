//
// pango-layout.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pango-layout.h: High-level layout driver
 *
 * Copyright (C) 2000 Red Hat Software
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

// #ifndef __PANGO_LAYOUT_H__
// #define __PANGO_LAYOUT_H__

// #include <pango/pango-attributes.h>
// #include <pango/pango-context.h>
// #include <pango/pango-glyph-item.h>
// #include <pango/pango-tabs.h>

// G_BEGIN_DECLS

type
  PangoLayout = record
  end;
  PPangoLayout = ^PangoLayout;

  PangoLayoutClass = record
  end;
  PPangoLayoutClass = ^PangoLayoutClass;


(**
 * PangoLayoutRun:
 *
 * The #PangoLayoutRun structure represents a single run within
 * a #PangoLayoutLine; it is simply an alternate name for
 * #PangoGlyphItem.
 * See the #PangoGlyphItem docs for details on the fields.
 *)
type
  PangoLayoutRun = PangoGlyphItem;
  PPangoLayoutRun = ^PangoLayoutRun;

(**
 * PangoAlignment:
 * @PANGO_ALIGN_LEFT: Put all available space on the right
 * @PANGO_ALIGN_CENTER: Center the line within the available space
 * @PANGO_ALIGN_RIGHT: Put all available space on the left
 *
 * A #PangoAlignment describes how to align the lines of a #PangoLayout within the
 * available space. If the #PangoLayout is set to justify
 * using pango_layout_set_justify(), this only has effect for partial lines.
 *)
type
  PangoAlignment = (
    PANGO_ALIGN_LEFT,
    PANGO_ALIGN_CENTER,
    PANGO_ALIGN_RIGHT
  );

(**
 * PangoWrapMode:
 * @PANGO_WRAP_WORD: wrap lines at word boundaries.
 * @PANGO_WRAP_CHAR: wrap lines at character boundaries.
 * @PANGO_WRAP_WORD_CHAR: wrap lines at word boundaries, but fall back to character boundaries if there is not
 * enough space for a full word.
 *
 * A #PangoWrapMode describes how to wrap the lines of a #PangoLayout to the desired width.
 *)
type
  PangoWrapMode = (
    PANGO_WRAP_WORD,
    PANGO_WRAP_CHAR,
    PANGO_WRAP_WORD_CHAR
  );

(**
 * PangoEllipsizeMode:
 * @PANGO_ELLIPSIZE_NONE: No ellipsization
 * @PANGO_ELLIPSIZE_START: Omit characters at the start of the text
 * @PANGO_ELLIPSIZE_MIDDLE: Omit characters in the middle of the text
 * @PANGO_ELLIPSIZE_END: Omit characters at the end of the text
 *
 * The #PangoEllipsizeMode type describes what sort of (if any)
 * ellipsization should be applied to a line of text. In
 * the ellipsization process characters are removed from the
 * text in order to make it fit to a given width and replaced
 * with an ellipsis.
 *)
type
  PangoEllipsizeMode = (
    PANGO_ELLIPSIZE_NONE,
    PANGO_ELLIPSIZE_START,
    PANGO_ELLIPSIZE_MIDDLE,
    PANGO_ELLIPSIZE_END
  );

(**
 * PangoLayoutLine:
 * @layout: (allow-none): the layout this line belongs to, might be %NULL
 * @start_index: start of line as byte index into layout->text
 * @length: length of line in bytes
 * @runs: (allow-none) (element-type: Pango.LayoutRun): list of runs in the
 *        line, from left to right
 * @is_paragraph_start: #TRUE if this is the first line of the paragraph
 * @resolved_dir: #Resolved PangoDirection of line
 *
 * The #PangoLayoutLine structure represents one of the lines resulting
 * from laying out a paragraph via #PangoLayout. #PangoLayoutLine
 * structures are obtained by calling pango_layout_get_line() and
 * are only valid until the text, attributes, or settings of the
 * parent #PangoLayout are modified.
 *
 * Routines for rendering PangoLayout objects are provided in
 * code specific to each rendering system.
 *)
type
  PangoLayoutLine = record
    layout: PPangoLayout;
    start_index: gint; (* start of line as byte index into layout->text *)
    length: gint; (* length of line in bytes *)
    runs: PGSList;
    is_paragraph_start: guint; //todo is_paragraph_start: guint = 1;  (* TRUE if this is the first line of the paragraph *)
    resolved_dir: guint; //todo resolved_dir: guint = 3;  (* Resolved PangoDirection of line *)
  end;
  PPangoLayoutLine = ^PangoLayoutLine;

//todo #define PANGO_TYPE_LAYOUT              (pango_layout_get_type ())
//todo #define PANGO_LAYOUT(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_LAYOUT, PangoLayout))
//todo #define PANGO_LAYOUT_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), PANGO_TYPE_LAYOUT, PangoLayoutClass))
//todo #define PANGO_IS_LAYOUT(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_LAYOUT))
//todo #define PANGO_IS_LAYOUT_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), PANGO_TYPE_LAYOUT))
//todo #define PANGO_LAYOUT_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), PANGO_TYPE_LAYOUT, PangoLayoutClass))

(* The PangoLayout and PangoLayoutClass structs are private; if you
 * need to create a subclass of these, file a bug.
 *)

function pango_layout_get_type(): GType; cdecl; external LIB_PANGO;
function pango_layout_new(context: PPangoContext): PPangoLayout; cdecl; external LIB_PANGO;
function pango_layout_copy(src: PPangoLayout): PPangoLayout; cdecl; external LIB_PANGO;

function pango_layout_get_context(layout: PPangoLayout): PPangoContext; cdecl; external LIB_PANGO;

procedure pango_layout_set_attributes(layout: PPangoLayout; attrs: PPangoAttrList); cdecl; external LIB_PANGO;
function pango_layout_get_attributes(layout: PPangoLayout): PPangoAttrList; cdecl; external LIB_PANGO;

procedure pango_layout_set_text(layout: PPangoLayout; const text: Pchar; length: cint); cdecl; external LIB_PANGO;
function pango_layout_get_text(layout: PPangoLayout): Pchar; cdecl; external LIB_PANGO;

function pango_layout_get_character_count(layout: PPangoLayout): gint; cdecl; external LIB_PANGO;

procedure pango_layout_set_markup(layout: PPangoLayout; const markup: Pchar; length: cint); cdecl; external LIB_PANGO;

procedure pango_layout_set_markup_with_accel(layout: PPangoLayout; const markup: Pchar; length: cint; accel_marker: gunichar; accel_char: Pgunichar); cdecl; external LIB_PANGO;

procedure pango_layout_set_font_description(layout: PPangoLayout; const desc: PPangoFontDescription); cdecl; external LIB_PANGO;

function pango_layout_get_font_description(layout: PPangoLayout): PPangoFontDescription; cdecl; external LIB_PANGO;

procedure pango_layout_set_width(layout: PPangoLayout; width: cint); cdecl; external LIB_PANGO;
function pango_layout_get_width(layout: PPangoLayout): cint; cdecl; external LIB_PANGO;
procedure pango_layout_set_height(layout: PPangoLayout; height: cint); cdecl; external LIB_PANGO;
function pango_layout_get_height(layout: PPangoLayout): cint; cdecl; external LIB_PANGO;
procedure pango_layout_set_wrap(layout: PPangoLayout; wrap: PangoWrapMode); cdecl; external LIB_PANGO;
function pango_layout_get_wrap(layout: PPangoLayout): PangoWrapMode; cdecl; external LIB_PANGO;
function pango_layout_is_wrapped(layout: PPangoLayout): gboolean; cdecl; external LIB_PANGO;
procedure pango_layout_set_indent(layout: PPangoLayout; indent: cint); cdecl; external LIB_PANGO;
function pango_layout_get_indent(layout: PPangoLayout): cint; cdecl; external LIB_PANGO;
procedure pango_layout_set_spacing(layout: PPangoLayout; spacing: cint); cdecl; external LIB_PANGO;
function pango_layout_get_spacing(layout: PPangoLayout): cint; cdecl; external LIB_PANGO;
procedure pango_layout_set_justify(layout: PPangoLayout; justify: gboolean); cdecl; external LIB_PANGO;
function pango_layout_get_justify(layout: PPangoLayout): gboolean; cdecl; external LIB_PANGO;
procedure pango_layout_set_auto_dir(layout: PPangoLayout; auto_dir: gboolean); cdecl; external LIB_PANGO;
function pango_layout_get_auto_dir(layout: PPangoLayout): gboolean; cdecl; external LIB_PANGO;
procedure pango_layout_set_alignment(layout: PPangoLayout; alignment: PangoAlignment); cdecl; external LIB_PANGO;
function pango_layout_get_alignment(layout: PPangoLayout): PangoAlignment; cdecl; external LIB_PANGO;

procedure pango_layout_set_tabs(layout: PPangoLayout; tabs: PPangoTabArray); cdecl; external LIB_PANGO;

function pango_layout_get_tabs(layout: PPangoLayout): PPangoTabArray; cdecl; external LIB_PANGO;

procedure pango_layout_set_single_paragraph_mode(layout: PPangoLayout; setting: gboolean); cdecl; external LIB_PANGO;
function pango_layout_get_single_paragraph_mode(layout: PPangoLayout): gboolean; cdecl; external LIB_PANGO;

procedure pango_layout_set_ellipsize(layout: PPangoLayout; ellipsize: PangoEllipsizeMode); cdecl; external LIB_PANGO;
function pango_layout_get_ellipsize(layout: PPangoLayout): PangoEllipsizeMode; cdecl; external LIB_PANGO;
function pango_layout_is_ellipsized(layout: PPangoLayout): gboolean; cdecl; external LIB_PANGO;

function pango_layout_get_unknown_glyphs_count(layout: PPangoLayout): cint; cdecl; external LIB_PANGO;

procedure pango_layout_context_changed(layout: PPangoLayout); cdecl; external LIB_PANGO;
function pango_layout_get_serial(layout: PPangoLayout): guint; cdecl; external LIB_PANGO;

procedure pango_layout_get_log_attrs(layout: PPangoLayout; attrs: PPPangoLogAttr; n_attrs: pgint); cdecl; external LIB_PANGO;

function pango_layout_get_log_attrs_readonly(layout: PPangoLayout; n_attrs: Pgint): PPangoLogAttr; cdecl; external LIB_PANGO;

procedure pango_layout_index_to_pos(layout: PPangoLayout; index_: cint; pos: PPangoRectangle); cdecl; external LIB_PANGO;
procedure pango_layout_index_to_line_x(layout: PPangoLayout; index_: cint; trailing: gboolean; line: pcint; x_pos: pcint); cdecl; external LIB_PANGO;
procedure pango_layout_get_cursor_pos(layout: PPangoLayout; index_: cint; strong_pos: PPangoRectangle; weak_pos: PPangoRectangle); cdecl; external LIB_PANGO;
procedure pango_layout_move_cursor_visually(layout: PPangoLayout; strong: gboolean; old_index: cint; old_trailing: cint; direction: cint; new_index: pcint; new_trailing: pcint); cdecl; external LIB_PANGO;
function pango_layout_xy_to_index(layout: PPangoLayout; x: cint; y: cint; index_: pcint; trailing: pcint): gboolean; cdecl; external LIB_PANGO;
procedure pango_layout_get_extents(layout: PPangoLayout; ink_rect: PPangoRectangle; logical_rect: PPangoRectangle); cdecl; external LIB_PANGO;
procedure pango_layout_get_pixel_extents(layout: PPangoLayout; ink_rect: PPangoRectangle; logical_rect: PPangoRectangle); cdecl; external LIB_PANGO;
procedure pango_layout_get_size(layout: PPangoLayout; width: pcint; height: pcint); cdecl; external LIB_PANGO;
procedure pango_layout_get_pixel_size(layout: PPangoLayout; width: pcint; height: pcint); cdecl; external LIB_PANGO;
function pango_layout_get_baseline(layout: PPangoLayout): cint; cdecl; external LIB_PANGO;

function pango_layout_get_line_count(layout: PPangoLayout): cint; cdecl; external LIB_PANGO;
function pango_layout_get_line(layout: PPangoLayout; line: cint): PPangoLayoutLine; cdecl; external LIB_PANGO;
function pango_layout_get_line_readonly(layout: PPangoLayout; line: cint): PPangoLayoutLine; cdecl; external LIB_PANGO;
function pango_layout_get_lines(layout: PPangoLayout): PGSList; cdecl; external LIB_PANGO;
function pango_layout_get_lines_readonly(layout: PPangoLayout): PGSList; cdecl; external LIB_PANGO;


//todo #define PANGO_TYPE_LAYOUT_LINE (pango_layout_line_get_type ())

function pango_layout_line_get_type(): GType; cdecl; external LIB_PANGO;

function pango_layout_line_ref(line: PPangoLayoutLine): PPangoLayoutLine; cdecl; external LIB_PANGO;
procedure pango_layout_line_unref(line: PPangoLayoutLine); cdecl; external LIB_PANGO;

function pango_layout_line_x_to_index(line: PPangoLayoutLine; x_pos: cint; index_: pcint; trailing: pcint): gboolean; cdecl; external LIB_PANGO;
procedure pango_layout_line_index_to_x(line: PPangoLayoutLine; index_: cint; trailing: gboolean; x_pos: pcint); cdecl; external LIB_PANGO;
procedure pango_layout_line_get_x_ranges(line: PPangoLayoutLine; start_index: cint; end_index: cint; ranges: ppcint; n_ranges: pcint); cdecl; external LIB_PANGO;
procedure pango_layout_line_get_extents(line: PPangoLayoutLine; ink_rect: PPangoRectangle; logical_rect: PPangoRectangle); cdecl; external LIB_PANGO;
procedure pango_layout_line_get_pixel_extents(layout_line: PPangoLayoutLine; ink_rect: PPangoRectangle; logical_rect: PPangoRectangle); cdecl; external LIB_PANGO;

type
  PangoLayoutIter = record
  end;
  PPangoLayoutIter = ^PangoLayoutIter;

//todo #define PANGO_TYPE_LAYOUT_ITER (pango_layout_iter_get_type ())

function pango_layout_iter_get_type(): GType; cdecl; external LIB_PANGO;

function pango_layout_get_iter(layout: PPangoLayout): PPangoLayoutIter; cdecl; external LIB_PANGO;
function pango_layout_iter_copy(iter: PPangoLayoutIter): PPangoLayoutIter; cdecl; external LIB_PANGO;
procedure pango_layout_iter_free(iter: PPangoLayoutIter); cdecl; external LIB_PANGO;

function pango_layout_iter_get_index(iter: PPangoLayoutIter): cint; cdecl; external LIB_PANGO;
function pango_layout_iter_get_run(iter: PPangoLayoutIter): PPangoLayoutRun; cdecl; external LIB_PANGO;
function pango_layout_iter_get_run_readonly(iter: PPangoLayoutIter): PPangoLayoutRun; cdecl; external LIB_PANGO;
function pango_layout_iter_get_line(iter: PPangoLayoutIter): PPangoLayoutLine; cdecl; external LIB_PANGO;
function pango_layout_iter_get_line_readonly(iter: PPangoLayoutIter): PPangoLayoutLine; cdecl; external LIB_PANGO;
function pango_layout_iter_at_last_line(iter: PPangoLayoutIter): gboolean; cdecl; external LIB_PANGO;
function pango_layout_iter_get_layout(iter: PPangoLayoutIter): PPangoLayout; cdecl; external LIB_PANGO;

function pango_layout_iter_next_char(iter: PPangoLayoutIter): gboolean; cdecl; external LIB_PANGO;
function pango_layout_iter_next_cluster(iter: PPangoLayoutIter): gboolean; cdecl; external LIB_PANGO;
function pango_layout_iter_next_run(iter: PPangoLayoutIter): gboolean; cdecl; external LIB_PANGO;
function pango_layout_iter_next_line(iter: PPangoLayoutIter): gboolean; cdecl; external LIB_PANGO;

procedure pango_layout_iter_get_char_extents(iter: PPangoLayoutIter; logical_rect: PPangoRectangle); cdecl; external LIB_PANGO;
procedure pango_layout_iter_get_cluster_extents(iter: PPangoLayoutIter; ink_rect: PPangoRectangle; logical_rect: PPangoRectangle); cdecl; external LIB_PANGO;
procedure pango_layout_iter_get_run_extents(iter: PPangoLayoutIter; ink_rect: PPangoRectangle; logical_rect: PPangoRectangle); cdecl; external LIB_PANGO;
procedure pango_layout_iter_get_line_extents(iter: PPangoLayoutIter; ink_rect: PPangoRectangle; logical_rect: PPangoRectangle); cdecl; external LIB_PANGO;
(* All the yranges meet, unlike the logical_rect's (i.e. the yranges
 * assign between-line spacing to the nearest line)
 *)
procedure pango_layout_iter_get_line_yrange(iter: PPangoLayoutIter; y0_: pcint; y1_: pcint); cdecl; external LIB_PANGO;
procedure pango_layout_iter_get_layout_extents(iter: PPangoLayoutIter; ink_rect: PPangoRectangle; logical_rect: PPangoRectangle); cdecl; external LIB_PANGO;
function pango_layout_iter_get_baseline(iter: PPangoLayoutIter): cint; cdecl; external LIB_PANGO;

// G_END_DECLS

// #endif (* __PANGO_LAYOUT_H__ *)
