//
// pangofc-fontmap.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pangofc-fontmap.h: Base fontmap type for fontconfig-based backends
 *
 * Copyright (C) 2003 Red Hat Software
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

// #ifndef __PANGO_FC_FONT_MAP_H__
// #define __PANGO_FC_FONT_MAP_H__

// #include <pango/pango.h>
// #include <fontconfig/fontconfig.h>
// #include <pango/pangofc-decoder.h>
// #include <pango/pangofc-font.h>

// G_BEGIN_DECLS


{$ifdef PANGO_ENABLE_BACKEND}

(**
 * PangoFcFontsetKey:
 *
 * An opaque structure containing all the information needed for
 * loading a fontset with the PangoFc fontmap.
 *
 * Since: 1.24
 **)
type
  PangoFcFontsetKey = record
  end;
  PPangoFcFontsetKey = ^PangoFcFontsetKey;

function pango_fc_fontset_key_get_language(const key: PPangoFcFontsetKey): PPangoLanguage; cdecl; external LIB_PANGO;
function pango_fc_fontset_key_get_description(const key: PPangoFcFontsetKey): PPangoFontDescription; cdecl; external LIB_PANGO;
function pango_fc_fontset_key_get_matrix(const key: PPangoFcFontsetKey): PPangoMatrix; cdecl; external LIB_PANGO;
function pango_fc_fontset_key_get_absolute_size(const key: PPangoFcFontsetKey): cdouble; cdecl; external LIB_PANGO;
function pango_fc_fontset_key_get_resolution(const key: PPangoFcFontsetKey): cdouble; cdecl; external LIB_PANGO;
function pango_fc_fontset_key_get_context_key(const key: PPangoFcFontsetKey): gpointer; cdecl; external LIB_PANGO;

(**
 * PangoFcFontKey:
 *
 * An opaque structure containing all the information needed for
 * loading a font with the PangoFc fontmap.
 *
 * Since: 1.24
 **)
type
  PangoFcFontKey = record
  end;
  PPangoFcFontKey = ^PangoFcFontKey;

function pango_fc_font_key_get_pattern(const key: PPangoFcFontKey): PFcPattern; cdecl; external LIB_PANGO;
function pango_fc_font_key_get_matrix(const key: PPangoFcFontKey): PPangoMatrix; cdecl; external LIB_PANGO;
function pango_fc_font_key_get_context_key(const key: PPangoFcFontKey): gpointer; cdecl; external LIB_PANGO;

{$endif}


(*
 * PangoFcFontMap
 *)

//todo #define PANGO_TYPE_FC_FONT_MAP              (pango_fc_font_map_get_type ())
//todo #define PANGO_FC_FONT_MAP(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_FC_FONT_MAP, PangoFcFontMap))
//todo #define PANGO_IS_FC_FONT_MAP(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_FC_FONT_MAP))

type
  PangoFcFontMapClass = record
  end;
  PPangoFcFontMapClass = ^PangoFcFontMapClass;

  PangoFcFontMapPrivate = record
  end;
  PPangoFcFontMapPrivate = ^PangoFcFontMapPrivate;

{$ifdef PANGO_ENABLE_BACKEND}

//todo #define PANGO_FC_FONT_MAP_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), PANGO_TYPE_FC_FONT_MAP, PangoFcFontMapClass))
//todo #define PANGO_IS_FC_FONT_MAP_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), PANGO_TYPE_FC_FONT_MAP))
//todo #define PANGO_FC_FONT_MAP_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), PANGO_TYPE_FC_FONT_MAP, PangoFcFontMapClass))

(**
 * PangoFcFontMap:
 *
 * #PangoFcFontMap is a base class for font map implementations
 * using the Fontconfig and FreeType libraries. To create a new
 * backend using Fontconfig and FreeType, you derive from this class
 * and implement a new_font() virtual function that creates an
 * instance deriving from #PangoFcFont.
 **)
type
  PangoFcFontMap = record
    parent_instance: PangoFontMap;

    priv: PPangoFcFontMapPrivate;
  end;
  PPangoFcFontMap = ^PangoFcFontMap;

(**
 * PangoFcFontMapClass:
 * @default_substitute: (nullable): Substitutes in default
 *  values for unspecified fields in a #FcPattern. This will
 *  be called prior to creating a font for the pattern. May be
 *  %NULL.  Deprecated in favor of @font_key_substitute().
 * @new_font: Creates a new #PangoFcFont for the specified
 *  pattern of the appropriate type for this font map. The
 *  @pattern argument must be passed to the "pattern" property
 *  of #PangoFcFont when you call g_object_new(). Deprecated
 *  in favor of @create_font().
 * @get_resolution: Gets the resolution (the scale factor
 *  between logical and absolute font sizes) that the backend
 *  will use for a particular fontmap and context. @context
 *  may be null.
 * @context_key_get: Gets an opaque key holding backend
 *  specific options for the context that will affect
 *  fonts created by @create_font(). The result must point to
 *  persistant storage owned by the fontmap. This key
 *  is used to index hash tables used to look up fontsets
 *  and fonts.
 * @context_key_copy: Copies a context key. Pango uses this
 *  to make a persistant copy of the value returned from
 *  @context_key_get.
 * @context_key_free: Frees a context key copied with
 *  @context_key_copy.
 * @context_key_hash: Gets a hash value for a context key
 * @context_key_equal: Compares two context keys for equality.
 * @fontset_key_substitute: (nullable): Substitutes in
 *  default values for unspecified fields in a
 *  #FcPattern. This will be called prior to creating a font
 *  for the pattern. May be %NULL.  (Since: 1.24)
 * @create_font: (nullable): Creates a new #PangoFcFont for
 *  the specified pattern of the appropriate type for this
 *  font map using information from the font key that is
 *  passed in. The @pattern member of @font_key can be
 *  retrieved using pango_fc_font_key_get_pattern() and must
 *  be passed to the "pattern" property of #PangoFcFont when
 *  you call g_object_new().  If %NULL, new_font() is used.
 *  (Since: 1.24)
 *
 * Class structure for #PangoFcFontMap.
 **)
type
  PangoFcFontMapClass = record
    (*< private >*)
    parent_class: PangoFontMapClass;
  
    (*< public >*)
    (* Deprecated in favor of fontset_key_substitute *)
    void         (*default_substitute) (PangoFcFontMap *fontmap,           FcPattern *pattern);
    (* Deprecated in favor of create_font *)
    PangoFcFont *(*new_font)          (PangoFcFontMap *fontmap,           FcPattern *pattern);
  
    double       (*get_resolution)     (PangoFcFontMap *fcfontmap,           PangoContext *context);
  
    gconstpointer (*context_key_get)   (PangoFcFontMap *fcfontmap,           PangoContext *context);
    gpointer     (*context_key_copy)   (PangoFcFontMap *fcfontmap,           gconstpointer               key);
    void         (*context_key_free)   (PangoFcFontMap *fcfontmap,           gpointer                    key);
    guint32      (*context_key_hash)   (PangoFcFontMap *fcfontmap,           gconstpointer               key);
    gboolean     (*context_key_equal)  (PangoFcFontMap *fcfontmap,           gconstpointer               key_a,           gconstpointer               key_b);
  
    void         (*fontset_key_substitute)(PangoFcFontMap *fontmap,           PangoFcFontsetKey *fontsetkey,           FcPattern *pattern);
    PangoFcFont *(*create_font)       (PangoFcFontMap *fontmap,           PangoFcFontKey *fontkey);
    (*< private >*)
  
    (* Padding for future expansion *)
    _pango_reserved1: procedure(); cdecl;
    _pango_reserved2: procedure(); cdecl;
    _pango_reserved3: procedure(); cdecl;
    _pango_reserved4: procedure(); cdecl;
  end;

{$ifndef PANGO_DISABLE_DEPRECATED}
// G_DEPRECATED_FOR(pango_font_map_create_context)
function pango_fc_font_map_create_context(fcfontmap: PPangoFcFontMap): PPangoContext; cdecl; external LIB_PANGO;
{$endif}
procedure pango_fc_font_map_shutdown(fcfontmap: PPangoFcFontMap); cdecl; external LIB_PANGO;

{$endif}

function pango_fc_font_map_get_type(): GType; cdecl; external LIB_PANGO;

procedure pango_fc_font_map_cache_clear(fcfontmap: PPangoFcFontMap); cdecl; external LIB_PANGO;

procedure pango_fc_font_map_config_changed(fcfontmap: PPangoFcFontMap); cdecl; external LIB_PANGO;

procedure pango_fc_font_map_set_config(fcfontmap: PPangoFcFontMap; fcconfig: PFcConfig); cdecl; external LIB_PANGO;
function pango_fc_font_map_get_config(fcfontmap: PPangoFcFontMap): PFcConfig; cdecl; external LIB_PANGO;

(**
 * PangoFcDecoderFindFunc:
 * @pattern: a fully resolved #FcPattern specifying the font on the system
 * @user_data: user data passed to pango_fc_font_map_add_decoder_find_func()
 *
 * Callback function passed to pango_fc_font_map_add_decoder_find_func().
 *
 * Return value: a new reference to a custom decoder for this pattern,  *  or %NULL if the default decoder handling should be used.
 **)
type
  PangoFcDecoderFindFunc = function (pattern: PFcPattern; user_data: gpointer): PPangoFcDecoder; cdecl;

procedure pango_fc_font_map_add_decoder_find_func(fcfontmap: PPangoFcFontMap; findfunc: PangoFcDecoderFindFunc; user_data: gpointer; dnotify: GDestroyNotify); cdecl; external LIB_PANGO;
function pango_fc_font_map_find_decoder(fcfontmap: PPangoFcFontMap; pattern: PFcPattern): PPangoFcDecoder; cdecl; external LIB_PANGO;

function pango_fc_font_description_from_pattern(pattern: PFcPattern; include_size: gboolean): PPangoFontDescription; cdecl; external LIB_PANGO;

(**
 * PANGO_FC_GRAVITY:
 *
 * String representing a fontconfig property name that Pango sets on any
 * fontconfig pattern it passes to fontconfig if a #PangoGravity other
 * than %PANGO_GRAVITY_SOUTH is desired.
 *
 * The property will have a #PangoGravity value as a string, like "east".
 * This can be used to write fontconfig configuration rules to choose
 * different fonts for horizontal and vertical writing directions.
 *
 * Since: 1.20
 *)
const
  PANGO_FC_GRAVITY = 'pangogravity';

(**
 * PANGO_FC_VERSION:
 *
 * String representing a fontconfig property name that Pango sets on any
 * fontconfig pattern it passes to fontconfig.
 *
 * The property will have an integer value equal to what
 * pango_version() returns.
 * This can be used to write fontconfig configuration rules that only affect
 * certain pango versions (or only pango-using applications, or only
 * non-pango-using applications).
 *
 * Since: 1.20
 *)
const
  PANGO_FC_VERSION = 'pangoversion';

(**
 * PANGO_FC_PRGNAME:
 *
 * String representing a fontconfig property name that Pango sets on any
 * fontconfig pattern it passes to fontconfig.
 *
 * The property will have a string equal to what
 * g_get_prgname() returns.
 * This can be used to write fontconfig configuration rules that only affect
 * certain applications.
 *
 * This is equivalent to FC_PRGNAME in versions of fontconfig that have that.
 *
 * Since: 1.24
 *)
const
  PANGO_FC_PRGNAME = 'prgname';

(**
 * PANGO_FC_FONT_FEATURES:
 *
 * String representing a fontconfig property name that Pango reads from font
 * patterns to populate list of OpenType features to be enabled for the font
 * by default.
 *
 * The property will have a number of string elements, each of which is the
 * OpenType feature tag of one feature to enable.
 *
 * This is equivalent to FC_FONT_FEATURES in versions of fontconfig that have that.
 *
 * Since: 1.34
 *)
const
  PANGO_FC_FONT_FEATURES = 'fontfeatures';

// G_END_DECLS

// #endif (* __PANGO_FC_FONT_MAP_H__ *)
