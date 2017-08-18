//
// pango-tabs.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pango-tabs.h: Tab-related stuff
 *
 * Copyright (C) 2000 Red Hat Software
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

// #ifndef __PANGO_TABS_H__
// #define __PANGO_TABS_H__

// #include <pango/pango-types.h>

// G_BEGIN_DECLS

type
  PangoTabArray = record
  end;
  PPangoTabArray = ^PangoTabArray;

(**
 * PangoTabAlign:
 * @PANGO_TAB_LEFT: the tab stop appears to the left of the text.
 *
 * A #PangoTabAlign specifies where a tab stop appears relative to the text.
 *)
type
  PangoTabAlign = (
    PANGO_TAB_LEFT

  (* These are not supported now, but may be in the
   * future.
   *
   *  PANGO_TAB_RIGHT,  *  PANGO_TAB_CENTER,  *  PANGO_TAB_NUMERIC
   *)
  );
  PPangoTabAlign = ^PangoTabAlign;
  PPPangoTabAlign = ^PPangoTabAlign;

(**
 * PANGO_TYPE_TAB_ARRAY:
 *
 * The #GObject type for #PangoTabArray.
 *)
//todo #define PANGO_TYPE_TAB_ARRAY (pango_tab_array_get_type ())

function pango_tab_array_new(initial_size: gint; positions_in_pixels: gboolean): PPangoTabArray; cdecl; external LIB_PANGO;
//todo function pango_tab_array_new_with_positions(size: gint; positions_in_pixels: gboolean; first_alignment: PangoTabAlign; first_position: gint; ...): PPangoTabArray; cdecl; external LIB_PANGO;
function pango_tab_array_get_type(): GType; cdecl; external LIB_PANGO;
function pango_tab_array_copy(src: PPangoTabArray): PPangoTabArray; cdecl; external LIB_PANGO;
procedure pango_tab_array_free(tab_array: PPangoTabArray); cdecl; external LIB_PANGO;
function pango_tab_array_get_size(tab_array: PPangoTabArray): gint; cdecl; external LIB_PANGO;
procedure pango_tab_array_resize(tab_array: PPangoTabArray; new_size: gint); cdecl; external LIB_PANGO;
procedure pango_tab_array_set_tab(tab_array: PPangoTabArray; tab_index: gint; alignment: PangoTabAlign; location: gint); cdecl; external LIB_PANGO;
procedure pango_tab_array_get_tab(tab_array: PPangoTabArray; tab_index: gint; alignment: PPangoTabAlign; location: pgint); cdecl; external LIB_PANGO;
procedure pango_tab_array_get_tabs(tab_array: PPangoTabArray; alignments: PPPangoTabAlign; locations: ppgint); cdecl; external LIB_PANGO;

function pango_tab_array_get_positions_in_pixels(tab_array: PPangoTabArray): gboolean; cdecl; external LIB_PANGO;


// G_END_DECLS

// #endif (* __PANGO_TABS_H__ *)
