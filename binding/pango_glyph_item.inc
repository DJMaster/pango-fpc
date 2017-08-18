//
// pango-glyph-item.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pango-glyph-item.h: Pair of PangoItem and a glyph string
 *
 * Copyright (C) 2002 Red Hat Software
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

// #ifndef __PANGO_GLYPH_ITEM_H__
// #define __PANGO_GLYPH_ITEM_H__

// #include <pango/pango-attributes.h>
// #include <pango/pango-break.h>
// #include <pango/pango-item.h>
// #include <pango/pango-glyph.h>

// G_BEGIN_DECLS

(**
 * PangoGlyphItem:
 * @item: corresponding #PangoItem.
 * @glyphs: corresponding #PangoGlyphString.
 *
 * A #PangoGlyphItem is a pair of a #PangoItem and the glyphs
 * resulting from shaping the text corresponding to an item.
 * As an example of the usage of #PangoGlyphItem, the results
 * of shaping text with #PangoLayout is a list of #PangoLayoutLine,  * each of which contains a list of #PangoGlyphItem.
 *)

type
  PangoGlyphItem = record
    item: PPangoItem;
    glyphs: PPangoGlyphString;
  end;
  PPangoGlyphItem = ^PangoGlyphItem;

(**
 * PANGO_TYPE_GLYPH_ITEM:
 *
 * The #GObject type for #PangoGlyphItem.
 *)
//todo #define PANGO_TYPE_GLYPH_ITEM (pango_glyph_item_get_type ())

function pango_glyph_item_get_type(): GType; cdecl; external LIB_PANGO;

function pango_glyph_item_split(orig: PPangoGlyphItem; const text: Pchar; split_index: cint): PPangoGlyphItem; cdecl; external LIB_PANGO;
function pango_glyph_item_copy(orig: PPangoGlyphItem): PPangoGlyphItem; cdecl; external LIB_PANGO;
procedure pango_glyph_item_free(glyph_item: PPangoGlyphItem); cdecl; external LIB_PANGO;
function pango_glyph_item_apply_attrs(glyph_item: PPangoGlyphItem; const text: Pchar; list: PPangoAttrList): PGSList; cdecl; external LIB_PANGO;
procedure pango_glyph_item_letter_space(glyph_item: PPangoGlyphItem; const text: Pchar; log_attrs: PPangoLogAttr; letter_spacing: cint); cdecl; external LIB_PANGO;
procedure pango_glyph_item_get_logical_widths(glyph_item: PPangoGlyphItem; const text: Pchar; logical_widths: pcint); cdecl; external LIB_PANGO;


(**
 * PangoGlyphItemIter:
 *
 * A #PangoGlyphItemIter is an iterator over the clusters in a
 * #PangoGlyphItem.  The <firstterm>forward direction</firstterm> of the
 * iterator is the logical direction of text.  That is, with increasing
 * @start_index and @start_char values.  If @glyph_item is right-to-left
 * (that is, if <literal>@glyph_item->item->analysis.level</literal> is odd),  * then @start_glyph decreases as the iterator moves forward.  Moreover,  * in right-to-left cases, @start_glyph is greater than @end_glyph.
 *
 * An iterator should be initialized using either of
 * pango_glyph_item_iter_init_start() and
 * pango_glyph_item_iter_init_end(), for forward and backward iteration
 * respectively, and walked over using any desired mixture of
 * pango_glyph_item_iter_next_cluster() and
 * pango_glyph_item_iter_prev_cluster().  A common idiom for doing a
 * forward iteration over the clusters is:
 * <programlisting>
 * PangoGlyphItemIter cluster_iter;
 * gboolean have_cluster;
 *
 * for (have_cluster = pango_glyph_item_iter_init_start (&amp;cluster_iter,  *                                                       glyph_item, text);
 *      have_cluster;
 *      have_cluster = pango_glyph_item_iter_next_cluster (&amp;cluster_iter))
 * {
 *   ...
 * }
 * </programlisting>
 *
 * Note that @text is the start of the text for layout, which is then
 * indexed by <literal>@glyph_item->item->offset</literal> to get to the
 * text of @glyph_item.  The @start_index and @end_index values can directly
 * index into @text.  The @start_glyph, @end_glyph, @start_char, and @end_char
 * values however are zero-based for the @glyph_item.  For each cluster, the
 * item pointed at by the start variables is included in the cluster while
 * the one pointed at by end variables is not.
 *
 * None of the members of a #PangoGlyphItemIter should be modified manually.
 *
 * Since: 1.22
 *)
type
  PangoGlyphItemIter = record
    glyph_item: PPangoGlyphItem;
    text: pgchar;
    
    start_glyph: cint;
    start_index: cint;
    start_char: cint;
    
    end_glyph: cint;
    end_index: cint;
    end_char: cint;
  end;
  PPangoGlyphItemIter = ^PangoGlyphItemIter;

(**
 * PANGO_TYPE_GLYPH_ITEM_ITER:
 *
 * The #GObject type for #PangoGlyphItemIter.
 *
 * Since: 1.22
 *)
//todo #define PANGO_TYPE_GLYPH_ITEM_ITER (pango_glyph_item_iter_get_type ())

function pango_glyph_item_iter_get_type(): GType; cdecl; external LIB_PANGO;
function pango_glyph_item_iter_copy(orig: PPangoGlyphItemIter): PPangoGlyphItemIter; cdecl; external LIB_PANGO;
procedure pango_glyph_item_iter_free(iter: PPangoGlyphItemIter); cdecl; external LIB_PANGO;

function pango_glyph_item_iter_init_start(iter: PPangoGlyphItemIter; glyph_item: PPangoGlyphItem; const text: Pchar): gboolean; cdecl; external LIB_PANGO;
function pango_glyph_item_iter_init_end(iter: PPangoGlyphItemIter; glyph_item: PPangoGlyphItem; const text: Pchar): gboolean; cdecl; external LIB_PANGO;
function pango_glyph_item_iter_next_cluster(iter: PPangoGlyphItemIter): gboolean; cdecl; external LIB_PANGO;
function pango_glyph_item_iter_prev_cluster(iter: PPangoGlyphItemIter): gboolean; cdecl; external LIB_PANGO;

// G_END_DECLS

// #endif (* __PANGO_GLYPH_ITEM_H__ *)
