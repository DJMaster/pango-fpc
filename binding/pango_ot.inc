//
// pango-ot.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pango-ot.h:
 *
 * Copyright (C) 2000,2007 Red Hat Software
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

// #ifndef __PANGO_OT_H__
// #define __PANGO_OT_H__

(* Deprecated.  Use HarfBuzz directly! *)

// #include <pango/pangofc-font.h>
// #include <pango/pango-glyph.h>
// #include <pango/pango-font.h>
// #include <pango/pango-script.h>
// #include <pango/pango-language.h>

// G_BEGIN_DECLS

{$ifdef PANGO_ENABLE_ENGINE}

(**
 * PangoOTTag:
 *
 * The #PangoOTTag typedef is used to represent TrueType and OpenType
 * four letter tags inside Pango. Use PANGO_OT_TAG_MAKE()
 * or PANGO_OT_TAG_MAKE_FROM_STRING() macros to create <type>PangoOTTag</type>s manually.
 *)
type
  PangoOTTag = guint32;

(**
 * PANGO_OT_TAG_MAKE:
 * @c1: First character.
 * @c2: Second character.
 * @c3: Third character.
 * @c4: Fourth character.
 *
 * Creates a #PangoOTTag from four characters.  This is similar and
 * compatible with the <function>FT_MAKE_TAG()</function> macro from FreeType.
 *)
(**
 * PANGO_OT_TAG_MAKE_FROM_STRING:
 * @s: The string representation of the tag.
 *
 * Creates a #PangoOTTag from a string. The string should be at least
 * four characters long (pad with space characters if needed), and need
 * not be nul-terminated.  This is a convenience wrapper around
 * PANGO_OT_TAG_MAKE(), but cannot be used in certain situations, for
 * example, as a switch expression, as it dereferences pointers.
 *)
//todo #define PANGO_OT_TAG_MAKE(c1,c2,c3,c4)  ((PangoOTTag) FT_MAKE_TAG (c1, c2, c3, c4))
//todo #define PANGO_OT_TAG_MAKE_FROM_STRING(s) (PANGO_OT_TAG_MAKE(((const char *) s)[0], \
//todo            ((const char *) s)[1], \
//todo            ((const char *) s)[2], \
//todo            ((const char *) s)[3]))

type
  PangoOTInfo = record
  end;
  PPangoOTInfo = ^PangoOTInfo;

  PangoOTBuffer = record
  end;
  PPangoOTBuffer = ^PangoOTBuffer;

  PangoOTRuleset = record
  end;
  PPangoOTRuleset = ^PangoOTRuleset;

(**
 * PangoOTTableType:
 * @PANGO_OT_TABLE_GSUB: The GSUB table.
 * @PANGO_OT_TABLE_GPOS: The GPOS table.
 *
 * The <type>PangoOTTableType</type> enumeration values are used to
 * identify the various OpenType tables in the
 * <function>pango_ot_info_*</function> functions.
 *)
type
  PangoOTTableType = ( 
    PANGO_OT_TABLE_GSUB,
    PANGO_OT_TABLE_GPOS
  );

(**
 * PANGO_OT_ALL_GLYPHS:
 *
 * This is used as the property bit in pango_ot_ruleset_add_feature() when a
 * feature should be applied to all glyphs.
 *
 * Since: 1.16
 *)
(**
 * PANGO_OT_NO_FEATURE:
 *
 * This is used as a feature index that represent no feature, that is, should be
 * skipped.  It may be returned as feature index by pango_ot_info_find_feature()
 * if the feature is not found, and pango_ot_ruleset_add_feature() function
 * automatically skips this value, so no special handling is required by the user.
 *
 * Since: 1.18
 *)
(**
 * PANGO_OT_NO_SCRIPT:
 *
 * This is used as a script index that represent no script, that is, when the
 * requested script was not found, and a default ('DFLT') script was not found
 * either.  It may be returned as script index by pango_ot_info_find_script()
 * if the script or a default script are not found, all other functions
 * taking a script index essentially return if the input script index is
 * this value, so no special handling is required by the user.
 *
 * Since: 1.18
 *)
(**
 * PANGO_OT_DEFAULT_LANGUAGE:
 *
 * This is used as the language index in pango_ot_info_find_feature() when
 * the default language system of the script is desired.
 *
 * It is also returned by pango_ot_info_find_language() if the requested language
 * is not found, or the requested language tag was PANGO_OT_TAG_DEFAULT_LANGUAGE.
 * The end result is that one can always call pango_ot_tag_from_language()
 * followed by pango_ot_info_find_language() and pass the result to
 * pango_ot_info_find_feature() without having to worry about falling back to
 * default language system explicitly.
 *
 * Since: 1.16
 *)
const
  PANGO_OT_ALL_GLYPHS = $FFFF;
  PANGO_OT_NO_FEATURE = $FFFF;
  PANGO_OT_NO_SCRIPT = $FFFF;
  PANGO_OT_DEFAULT_LANGUAGE = $FFFF;

(**
 * PANGO_OT_TAG_DEFAULT_SCRIPT:
 *
 * This is a #PangoOTTag representing the special script tag 'DFLT'.  It is
 * returned as script tag by pango_ot_tag_from_script() if the requested script
 * is not found.
 *
 * Since: 1.18
 *)
(**
 * PANGO_OT_TAG_DEFAULT_LANGUAGE:
 *
 * This is a #PangoOTTag representing a special language tag 'dflt'.  It is
 * returned as language tag by pango_ot_tag_from_language() if the requested
 * language is not found.  It is safe to pass this value to
 * pango_ot_info_find_language() as that function falls back to returning default
 * language-system if the requested language tag is not found.
 *
 * Since: 1.18
 *)
//todo #define PANGO_OT_TAG_DEFAULT_SCRIPT  PANGO_OT_TAG_MAKE ('D', 'F', 'L', 'T')
//todo #define PANGO_OT_TAG_DEFAULT_LANGUAGE  PANGO_OT_TAG_MAKE ('d', 'f', 'l', 't')

(* Note that this must match hb_glyph_info_t *)
(**
 * PangoOTGlyph:
 * @glyph: the glyph itself.
 * @properties: the properties value, identifying which features should be
 * applied on this glyph.  See pango_ot_ruleset_add_feature().
 * @cluster: the cluster that this glyph belongs to.
 * @component: a component value, set by the OpenType layout engine.
 * @ligID: a ligature index value, set by the OpenType layout engine.
 * @internal: for Pango internal use
 *
 * The #PangoOTGlyph structure represents a single glyph together with
 * information used for OpenType layout processing of the glyph.
 * It contains the following fields.
 *)
type
  PangoOTGlyph = record
    glyph: guint32;
    properties: guint;
    cluster: guint;
    component: gushort;
    ligID: gushort;

    internal: guint;
  );
  PPangoOTGlyph = ^PangoOTGlyph;

(**
 * PangoOTFeatureMap:
 * @feature_name: feature tag in represented as four-letter ASCII string.
 * @property_bit: the property bit to use for this feature.  See
 * pango_ot_ruleset_add_feature() for details.
 *
 * The #PangoOTFeatureMap typedef is used to represent an OpenType
 * feature with the property bit associated with it.  The feature tag is
 * represented as a char array instead of a #PangoOTTag for convenience.
 *
 * Since: 1.18
 *)
type
  PangoOTFeatureMap = record
    feature_name: array[0..4] of char;
    property_bit: gulong;
  end;
  PPangoOTFeatureMap = ^PangoOTFeatureMap;

(**
 * PangoOTRulesetDescription:
 * @script: a #PangoScript.
 * @language: a #PangoLanguage.
 * @static_gsub_features: (nullable): static map of GSUB features,  * or %NULL.
 * @n_static_gsub_features: length of @static_gsub_features, or 0.
 * @static_gpos_features: (nullable): static map of GPOS features,  * or %NULL.
 * @n_static_gpos_features: length of @static_gpos_features, or 0.
 * @other_features: (nullable): map of extra features to add to both
 * GSUB and GPOS, or %NULL.  Unlike the static maps, this pointer
 * need not live beyond the life of function calls taking this
 * struct.
 * @n_other_features: length of @other_features, or 0.
 *
 * The #PangoOTRuleset structure holds all the information needed
 * to build a complete #PangoOTRuleset from an OpenType font.
 * The main use of this struct is to act as the key for a per-font
 * hash of rulesets.  The user populates a ruleset description and
 * gets the ruleset using pango_ot_ruleset_get_for_description()
 * or create a new one using pango_ot_ruleset_new_from_description().
 *
 * Since: 1.18
 *)
type
  PangoOTRulesetDescription = record
    script: PangoScript;
    language: PPangoLanguage;
    static_gsub_features: PPangoOTFeatureMap;
    n_static_gsub_features: guint;
    static_gpos_features: PPangoOTFeatureMap;
    n_static_gpos_features: guint;
    other_features: PPangoOTFeatureMap;
    n_other_features: guint;
  end;
  PPangoOTRulesetDescription = ^PangoOTRulesetDescription;


//todo #define PANGO_TYPE_OT_INFO              (pango_ot_info_get_type ())
//todo #define PANGO_OT_INFO(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_OT_INFO, PangoOTInfo))
//todo #define PANGO_IS_OT_INFO(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_OT_INFO))
function pango_ot_info_get_type(): GType; cdecl; external LIB_PANGO;

//todo #define PANGO_TYPE_OT_RULESET           (pango_ot_ruleset_get_type ())
//todo #define PANGO_OT_RULESET(object)        (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_OT_RULESET, PangoOTRuleset))
//todo #define PANGO_IS_OT_RULESET(object)     (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_OT_RULESET))
function pango_ot_ruleset_get_type(): GType; cdecl; external LIB_PANGO;


function pango_ot_info_get(face: FT_Face): PPangoOTInfo; cdecl; external LIB_PANGO; deprecated;

function pango_ot_info_find_script(info: PPangoOTInfo; table_type: PangoOTTableType; script_tag: PangoOTTag; script_index: Pguint): gboolean; cdecl; external LIB_PANGO; deprecated;

function pango_ot_info_find_language(info: PPangoOTInfo; table_type: PangoOTTableType; script_index: guint; language_tag: PangoOTTag; language_index: Pguint; required_feature_index: Pguint): gboolean; cdecl; external LIB_PANGO; deprecated;
function pango_ot_info_find_feature(info: PPangoOTInfo; table_type: PangoOTTableType; feature_tag: PangoOTTag; script_index: guint; language_index: guint; feature_index: Pguint): gboolean; cdecl; external LIB_PANGO; deprecated;

function pango_ot_info_list_scripts(info: PPangoOTInfo; table_type: PangoOTTableType): PPangoOTTag; cdecl; external LIB_PANGO; deprecated;
function pango_ot_info_list_languages(info: PPangoOTInfo; table_type: PangoOTTableType; script_index: guint; language_tag: PangoOTTag): PPangoOTTag; cdecl; external LIB_PANGO; deprecated;
function pango_ot_info_list_features(info: PPangoOTInfo; table_type: PangoOTTableType; tag: PangoOTTag; script_index: guint; language_index: guint): PPangoOTTag; cdecl; external LIB_PANGO; deprecated;

function pango_ot_buffer_new(font: PPangoFcFont): PPangoOTBuffer; cdecl; external LIB_PANGO; deprecated;
procedure pango_ot_buffer_destroy(buffer: PPangoOTBuffer); cdecl; external LIB_PANGO; deprecated;
procedure pango_ot_buffer_clear(buffer: PPangoOTBuffer); cdecl; external LIB_PANGO; deprecated;
procedure pango_ot_buffer_set_rtl(buffer: PPangoOTBuffer; rtl: gboolean); cdecl; external LIB_PANGO; deprecated;
procedure pango_ot_buffer_add_glyph(buffer: PPangoOTBuffer; glyph: guint; properties: guint; cluster: guint); cdecl; external LIB_PANGO; deprecated;
procedure pango_ot_buffer_get_glyphs(const buffer: PPangoOTBuffer; glyphs: PPPangoOTGlyph; n_glyphs: pcint); cdecl; external LIB_PANGO; deprecated;
procedure pango_ot_buffer_output(const buffer: PPangoOTBuffer; glyphs: PPangoGlyphString); cdecl; external LIB_PANGO; deprecated;

procedure pango_ot_buffer_set_zero_width_marks(buffer: PPangoOTBuffer; zero_width_marks: gboolean); cdecl; external LIB_PANGO; deprecated;

function pango_ot_ruleset_get_for_description(info: PPangoOTInfo; const desc: PPangoOTRulesetDescription): PPangoOTRuleset; cdecl; external LIB_PANGO; deprecated;
function pango_ot_ruleset_new(info: PPangoOTInfo): PPangoOTRuleset; cdecl; external LIB_PANGO; deprecated;
function pango_ot_ruleset_new_for(info: PPangoOTInfo; script: PangoScript; language: PPangoLanguage): PPangoOTRuleset; cdecl; external LIB_PANGO; deprecated;
function pango_ot_ruleset_new_from_description(info: PPangoOTInfo; const desc: PPangoOTRulesetDescription): PPangoOTRuleset; cdecl; external LIB_PANGO; deprecated;
procedure pango_ot_ruleset_add_feature(ruleset: PPangoOTRuleset; table_type: PangoOTTableType; feature_index: guint; property_bit: gulong); cdecl; external LIB_PANGO; deprecated;
function pango_ot_ruleset_maybe_add_feature(ruleset: PPangoOTRuleset; table_type: PangoOTTableType; feature_tag: PangoOTTag; property_bit: gulong): gboolean; cdecl; external LIB_PANGO; deprecated;
function pango_ot_ruleset_maybe_add_features(ruleset: PPangoOTRuleset; table_type: PangoOTTableType; const features: PPangoOTFeatureMap; n_features: guint): guint; cdecl; external LIB_PANGO; deprecated;
function pango_ot_ruleset_get_feature_count(const ruleset: PPangoOTRuleset; n_gsub_features: Pguint; n_gpos_features: Pguint): guint; cdecl; external LIB_PANGO; deprecated;

procedure pango_ot_ruleset_substitute(const ruleset: PPangoOTRuleset; buffer: PPangoOTBuffer); cdecl; external LIB_PANGO; deprecated;

procedure pango_ot_ruleset_position(const ruleset: PPangoOTRuleset; buffer: PPangoOTBuffer); cdecl; external LIB_PANGO; deprecated;

function pango_ot_tag_to_script(script_tag: PangoOTTag): PangoScript; cdecl; external LIB_PANGO; deprecated;

function pango_ot_tag_from_script(script: PangoScript): PangoOTTag; cdecl; external LIB_PANGO; deprecated;

function pango_ot_tag_to_language(language_tag: PangoOTTag): PPangoLanguage; cdecl; external LIB_PANGO; deprecated;

function pango_ot_tag_from_language(language: PPangoLanguage): PangoOTTag; cdecl; external LIB_PANGO; deprecated;

function pango_ot_ruleset_description_hash(const desc: PPangoOTRulesetDescription): guint; cdecl; external LIB_PANGO; deprecated;

function pango_ot_ruleset_description_equal(const desc: PPangoOTRulesetDescription1; const desc: PPangoOTRulesetDescription2): gboolean; cdecl; external LIB_PANGO; deprecated;

function pango_ot_ruleset_description_copy(const desc: PPangoOTRulesetDescription): PPangoOTRulesetDescription; cdecl; external LIB_PANGO; deprecated;

procedure pango_ot_ruleset_description_free(desc: PPangoOTRulesetDescription); cdecl; external LIB_PANGO; deprecated;


{$endif} (* PANGO_ENABLE_ENGINE *)

// G_END_DECLS

// #endif (* __PANGO_OT_H__ *)
