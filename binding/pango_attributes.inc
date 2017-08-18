//
// pango-attributes.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pango-attributes.h: Attributed text
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

// #ifndef __PANGO_ATTRIBUTES_H__
// #define __PANGO_ATTRIBUTES_H__

// #include <pango/pango-font.h>
// #include <glib-object.h>

// G_BEGIN_DECLS

(* PangoColor *)

(**
 * PangoColor:
 * @red: value of red component
 * @green: value of green component
 * @blue: value of blue component
 *
 * The #PangoColor structure is used to
 * represent a color in an uncalibrated RGB color-space.
 *)
type
  PangoColor = record
    red: guint16;
    green: guint16;
    blue: guint16;
  end;
  PPangoColor = ^PangoColor;

(**
 * PANGO_TYPE_COLOR:
 *
 * The #GObject type for #PangoColor.
 *)
//todo #define PANGO_TYPE_COLOR pango_color_get_type ()
function pango_color_get_type(): GType; cdecl; external LIB_PANGO;

function pango_color_copy(const src: PPangoColor): PPangoColor; cdecl; external LIB_PANGO;
procedure pango_color_free(color: PPangoColor); cdecl; external LIB_PANGO;
function pango_color_parse(color: PPangoColor; const spec: pchar): gboolean; cdecl; external LIB_PANGO;
function pango_color_to_string(const color: PPangoColor): pgchar; cdecl; external LIB_PANGO;

(* Attributes *)

(**
 * PangoAttrType:
 * @PANGO_ATTR_INVALID: does not happen
 * @PANGO_ATTR_LANGUAGE: language (#PangoAttrLanguage)
 * @PANGO_ATTR_FAMILY: font family name list (#PangoAttrString)
 * @PANGO_ATTR_STYLE: font slant style (#PangoAttrInt)
 * @PANGO_ATTR_WEIGHT: font weight (#PangoAttrInt)
 * @PANGO_ATTR_VARIANT: font variant (normal or small caps) (#PangoAttrInt)
 * @PANGO_ATTR_STRETCH: font stretch (#PangoAttrInt)
 * @PANGO_ATTR_SIZE: font size in points scaled by %PANGO_SCALE (#PangoAttrInt)
 * @PANGO_ATTR_FONT_DESC: font description (#PangoAttrFontDesc)
 * @PANGO_ATTR_FOREGROUND: foreground color (#PangoAttrColor)
 * @PANGO_ATTR_BACKGROUND: background color (#PangoAttrColor)
 * @PANGO_ATTR_UNDERLINE: whether the text has an underline (#PangoAttrInt)
 * @PANGO_ATTR_STRIKETHROUGH: whether the text is struck-through (#PangoAttrInt)
 * @PANGO_ATTR_RISE: baseline displacement (#PangoAttrInt)
 * @PANGO_ATTR_SHAPE: shape (#PangoAttrShape)
 * @PANGO_ATTR_SCALE: font size scale factor (#PangoAttrFloat)
 * @PANGO_ATTR_FALLBACK: whether fallback is enabled (#PangoAttrInt)
 * @PANGO_ATTR_LETTER_SPACING: letter spacing (#PangoAttrInt)
 * @PANGO_ATTR_UNDERLINE_COLOR: underline color (#PangoAttrColor)
 * @PANGO_ATTR_STRIKETHROUGH_COLOR: strikethrough color (#PangoAttrColor)
 * @PANGO_ATTR_ABSOLUTE_SIZE: font size in pixels scaled by %PANGO_SCALE (#PangoAttrInt)
 * @PANGO_ATTR_GRAVITY: base text gravity (#PangoAttrInt)
 * @PANGO_ATTR_GRAVITY_HINT: gravity hint (#PangoAttrInt)
 * @PANGO_ATTR_FONT_FEATURES: OpenType font features (#PangoAttrString). Since 1.38
 * @PANGO_ATTR_FOREGROUND_ALPHA: foreground alpha (#PangoAttrInt). Since 1.38
 * @PANGO_ATTR_BACKGROUND_ALPHA: background alpha (#PangoAttrInt). Since 1.38
 *
 * The #PangoAttrType
 * distinguishes between different types of attributes. Along with the
 * predefined values, it is possible to allocate additional values
 * for custom attributes using pango_attr_type_register(). The predefined
 * values are given below. The type of structure used to store the
 * attribute is listed in parentheses after the description.
 *)
type
  PangoAttrType = (
    PANGO_ATTR_INVALID, (* 0 is an invalid attribute type *)
    PANGO_ATTR_LANGUAGE, (* PangoAttrLanguage *)
    PANGO_ATTR_FAMILY, (* PangoAttrString *)
    PANGO_ATTR_STYLE, (* PangoAttrInt *)
    PANGO_ATTR_WEIGHT, (* PangoAttrInt *)
    PANGO_ATTR_VARIANT, (* PangoAttrInt *)
    PANGO_ATTR_STRETCH, (* PangoAttrInt *)
    PANGO_ATTR_SIZE, (* PangoAttrSize *)
    PANGO_ATTR_FONT_DESC, (* PangoAttrFontDesc *)
    PANGO_ATTR_FOREGROUND, (* PangoAttrColor *)
    PANGO_ATTR_BACKGROUND, (* PangoAttrColor *)
    PANGO_ATTR_UNDERLINE, (* PangoAttrInt *)
    PANGO_ATTR_STRIKETHROUGH, (* PangoAttrInt *)
    PANGO_ATTR_RISE, (* PangoAttrInt *)
    PANGO_ATTR_SHAPE, (* PangoAttrShape *)
    PANGO_ATTR_SCALE, (* PangoAttrFloat *)
    PANGO_ATTR_FALLBACK, (* PangoAttrInt *)
    PANGO_ATTR_LETTER_SPACING, (* PangoAttrInt *)
    PANGO_ATTR_UNDERLINE_COLOR, (* PangoAttrColor *)
    PANGO_ATTR_STRIKETHROUGH_COLOR,(* PangoAttrColor *)
    PANGO_ATTR_ABSOLUTE_SIZE, (* PangoAttrSize *)
    PANGO_ATTR_GRAVITY, (* PangoAttrInt *)
    PANGO_ATTR_GRAVITY_HINT, (* PangoAttrInt *)
    PANGO_ATTR_FONT_FEATURES, (* PangoAttrString *)
    PANGO_ATTR_FOREGROUND_ALPHA, (* PangoAttrInt *)
    PANGO_ATTR_BACKGROUND_ALPHA (* PangoAttrInt *)
  );

(**
 * PangoAttrDataCopyFunc:
 * @user_data: user data to copy
 *
 * Type of a function that can duplicate user data for an attribute.
 *
 * Return value: new copy of @user_data.
 **)
type
  PangoAttrDataCopyFunc = function (const user_data: gpointer): gpointer; cdecl;

type
  PPangoAttrClass = ^PangoAttrClass;

(**
 * PangoAttribute:
 * @klass: the class structure holding information about the type of the attribute
 * @start_index: the start index of the range (in bytes).
 * @end_index: end index of the range (in bytes). The character at this index
 * is not included in the range.
 *
 * The #PangoAttribute structure represents the common portions of all
 * attributes. Particular types of attributes include this structure
 * as their initial portion. The common portion of the attribute holds
 * the range to which the value in the type-specific part of the attribute
 * applies and should be initialized using pango_attribute_init().
 * By default an attribute will have an all-inclusive range of [0,%G_MAXUINT].
 *)
  PangoAttribute = record
    klass: PPangoAttrClass;
    start_index: guint; (* in bytes *)
    end_index: guint; (* in bytes. The character at this index is not included *)
  end;
  PPangoAttribute = ^PangoAttribute;

(**
 * PangoAttrClass:
 * @type: the type ID for this attribute
 * @copy: function to duplicate an attribute of this type (see pango_attribute_copy())
 * @destroy: function to free an attribute of this type (see pango_attribute_destroy())
 * @equal: function to check two attributes of this type for equality (see pango_attribute_equal())
 *
 * The #PangoAttrClass structure stores the type and operations for
 * a particular type of attribute. The functions in this structure should
 * not be called directly. Instead, one should use the wrapper functions
 * provided for #PangoAttribute.
 *)
  PangoAttrClass = record
    (*< public >*)
    type_: PangoAttrType;
    copy: function(const attr: PPangoAttribute): PPangoAttribute; cdecl;
    destroy: procedure(attr: PPangoAttribute); cdecl;
    equal: function(const attr1: PPangoAttribute; const attr2: PPangoAttribute): gboolean; cdecl;
  end;

(**
 * PangoAttrString:
 * @attr: the common portion of the attribute
 * @value: the string which is the value of the attribute
 *
 * The #PangoAttrString structure is used to represent attributes with
 * a string value.
 *)
  PangoAttrString = record
    attr: PangoAttribute;
    value: pchar;
  end;
  PPangoAttrString = ^PangoAttrString;
(**
 * PangoAttrLanguage:
 * @attr: the common portion of the attribute
 * @value: the #PangoLanguage which is the value of the attribute
 *
 * The #PangoAttrLanguage structure is used to represent attributes that
 * are languages.
 *)
  PangoAttrLanguage = record
    attr: PangoAttribute;
    value: PPangoLanguage;
  end;
  PPangoAttrLanguage = ^PangoAttrLanguage;
(**
 * PangoAttrInt:
 * @attr: the common portion of the attribute
 * @value: the value of the attribute
 *
 * The #PangoAttrInt structure is used to represent attributes with
 * an integer or enumeration value.
 *)
  PangoAttrInt = record
    attr: PangoAttribute;
    value: cint;
  end;
  PPangoAttrInt = ^PangoAttrInt;
(**
 * PangoAttrFloat:
 * @attr: the common portion of the attribute
 * @value: the value of the attribute
 *
 * The #PangoAttrFloat structure is used to represent attributes with
 * a float or double value.
 *)
  PangoAttrFloat = record
    attr: PangoAttribute;
    value: cdouble;
  end;
  PPangoAttrFloat = ^PangoAttrFloat;
(**
 * PangoAttrColor:
 * @attr: the common portion of the attribute
 * @color: the #PangoColor which is the value of the attribute
 *
 * The #PangoAttrColor structure is used to represent attributes that
 * are colors.
 *)
  PangoAttrColor = record
    attr: PangoAttribute;
    color: PangoColor;
  end;
  PPangoAttrColor = ^PangoAttrColor;

(**
 * PangoAttrSize:
 * @attr: the common portion of the attribute
 * @size: size of font, in units of 1/%PANGO_SCALE of a point (for
 * %PANGO_ATTR_SIZE) or of a device uni (for %PANGO_ATTR_ABSOLUTE_SIZE)
 * @absolute: whether the font size is in device units or points.
 * This field is only present for compatibility with Pango-1.8.0
 * (%PANGO_ATTR_ABSOLUTE_SIZE was added in 1.8.1); and always will
 * be %FALSE for %PANGO_ATTR_SIZE and %TRUE for %PANGO_ATTR_ABSOLUTE_SIZE.
 *
 * The #PangoAttrSize structure is used to represent attributes which
 * set font size.
 *)
  PangoAttrSize = record
    attr: PangoAttribute;
    size: cint;
    absolute: guint; //todo absolute: guint = 1;
  end;
  PPangoAttrSize = ^PangoAttrSize;

(**
 * PangoAttrShape:
 * @attr: the common portion of the attribute
 * @ink_rect: the ink rectangle to restrict to
 * @logical_rect: the logical rectangle to restrict to
 * @data: user data set (see pango_attr_shape_new_with_data())
 * @copy_func: copy function for the user data
 * @destroy_func: destroy function for the user data
 *
 * The #PangoAttrShape structure is used to represent attributes which
 * impose shape restrictions.
 *)
  PangoAttrShape = record
    attr: PangoAttribute;
    ink_rect: PangoRectangle;
    logical_rect: PangoRectangle;
  
    data: gpointer;
    copy_func: PangoAttrDataCopyFunc;
    destroy_func: GDestroyNotify;
  end;
  PPangoAttrShape = ^PangoAttrShape;

(**
 * PangoAttrFontDesc:
 * @attr: the common portion of the attribute
 * @desc: the font description which is the value of this attribute
 *
 * The #PangoAttrFontDesc structure is used to store an attribute that
 * sets all aspects of the font description at once.
 *)
  PangoAttrFontDesc = record
    attr: PangoAttribute;
    desc: PPangoFontDescription;
  end;
  PPangoAttrFontDesc = ^PangoAttrFontDesc;
  PPPangoAttrFontDesc = ^PPangoAttrFontDesc;

(**
 * PangoAttrFontFeatures:
 * @attr: the common portion of the attribute
 * @features: the featues, as a string in CSS syntax
 *
 * The #PangoAttrFontFeatures structure is used to represent OpenType
 * font features as an attribute.
 *
 * Since: 1.38
 *)
  PangoAttrFontFeatures = record
    attr: PangoAttribute;
    features: pgchar;
  end;
  PPangoAttrFontFeatures = ^PangoAttrFontFeatures;

(**
 * PANGO_TYPE_ATTR_LIST:
 *
 * The #GObject type for #PangoAttrList.
 *)
//todo #define PANGO_TYPE_ATTR_LIST pango_attr_list_get_type ()
(**
 * PangoAttrIterator:
 *
 * The #PangoAttrIterator structure is used to represent an
 * iterator through a #PangoAttrList. A new iterator is created
 * with pango_attr_list_get_iterator(). Once the iterator
 * is created, it can be advanced through the style changes
 * in the text using pango_attr_iterator_next(). At each
 * style change, the range of the current style segment and the
 * attributes currently in effect can be queried.
 *)
(**
 * PangoAttrList:
 *
 * The #PangoAttrList structure represents a list of attributes
 * that apply to a section of text. The attributes are, in general,  * allowed to overlap in an arbitrary fashion, however, if the
 * attributes are manipulated only through pango_attr_list_change(),  * the overlap between properties will meet stricter criteria.
 *
 * Since the #PangoAttrList structure is stored as a linear list,  * it is not suitable for storing attributes for large amounts
 * of text. In general, you should not use a single #PangoAttrList
 * for more than one paragraph of text.
 *)
  PangoAttrList = record
  end;
  PPangoAttrList = ^PangoAttrList;
  PPPangoAttrList = ^PPangoAttrList;

  PangoAttrIterator = record
  end;
  PPangoAttrIterator = ^PangoAttrIterator;

(**
 * PangoUnderline:
 * @PANGO_UNDERLINE_NONE: no underline should be drawn
 * @PANGO_UNDERLINE_SINGLE: a single underline should be drawn
 * @PANGO_UNDERLINE_DOUBLE: a double underline should be drawn
 * @PANGO_UNDERLINE_LOW: a single underline should be drawn at a position
 * beneath the ink extents of the text being
 * underlined. This should be used only for underlining
 * single characters, such as for keyboard
 * accelerators. %PANGO_UNDERLINE_SINGLE should
 * be used for extended portions of text.
 * @PANGO_UNDERLINE_ERROR: a wavy underline should be drawn below.
 * This underline is typically used to indicate
 * an error such as a possilble mispelling; in some
 * cases a contrasting color may automatically
 * be used. This type of underlining is available since Pango 1.4.
 *
 * The #PangoUnderline enumeration is used to specify
 * whether text should be underlined, and if so, the type
 * of underlining.
 *)
  PangoUnderline = (
    PANGO_UNDERLINE_NONE,
    PANGO_UNDERLINE_SINGLE,
    PANGO_UNDERLINE_DOUBLE,
    PANGO_UNDERLINE_LOW,
    PANGO_UNDERLINE_ERROR
  );

(**
 * PANGO_ATTR_INDEX_FROM_TEXT_BEGINNING:
 *
 * This value can be used to set the start_index member of a #PangoAttribute
 * such that the attribute covers from the beginning of the text.
 *
 * Since: 1.24
 *)
(**
 * PANGO_ATTR_INDEX_TO_TEXT_END:
 *
 * This value can be used to set the end_index member of a #PangoAttribute
 * such that the attribute covers to the end of the text.
 *
 * Since: 1.24
 *)
const
  PANGO_ATTR_INDEX_FROM_TEXT_BEGINNING = 0;
  PANGO_ATTR_INDEX_TO_TEXT_END = G_MAXUINT;

(**
 * PangoAttrFilterFunc:
 * @attribute: a Pango attribute
 * @user_data: user data passed to the function
 *
 * Type of a function filtering a list of attributes.
 *
 * Return value: %TRUE if the attribute should be selected for
 * filtering, %FALSE otherwise.
 **)
type
   PangoAttrFilterFunc = function (attribute: PPangoAttribute; user_data: gpointer): gboolean; cdecl;


function pango_attr_type_register(const name: pgchar): PangoAttrType; cdecl; external LIB_PANGO;
function pango_attr_type_get_name(type_: PangoAttrType): pchar; cdecl; external LIB_PANGO;

procedure pango_attribute_init(Pattr: PangoAttribute; const klass: PPangoAttrClass); cdecl; external LIB_PANGO;
function pango_attribute_copy(const attr: PPangoAttribute): PPangoAttribute; cdecl; external LIB_PANGO;
procedure pango_attribute_destroy(attr: PPangoAttribute); cdecl; external LIB_PANGO;
function pango_attribute_equal(const attr1: PPangoAttribute; const attr2: PPangoAttribute): gboolean; cdecl; external LIB_PANGO;

function pango_attr_language_new(language: PPangoLanguage): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_family_new(const family: pchar): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_foreground_new(red: guint16; green: guint16; blue: guint16): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_background_new(red: guint16; green: guint16; blue: guint16): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_size_new(size: cint): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_size_new_absolute(size: cint): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_style_new(style: PangoStyle): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_weight_new(weight: PangoWeight): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_variant_new(variant: PangoVariant): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_stretch_new(stretch: PangoStretch): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_font_desc_new(const desc: PPangoFontDescription): PPangoAttribute; cdecl; external LIB_PANGO;

function pango_attr_underline_new(underline: PangoUnderline): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_underline_color_new(red: guint16; green: guint16; blue: guint16): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_strikethrough_new(strikethrough: gboolean): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_strikethrough_color_new(red: guint16; green: guint16; blue: guint16): PPangoAttribute; cdecl; external LIB_PANGO;

function pango_attr_rise_new(rise: cint): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_scale_new(scale_factor: double): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_fallback_new(enable_fallback: gboolean): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_letter_spacing_new(letter_spacing: cint): PPangoAttribute; cdecl; external LIB_PANGO;

function pango_attr_shape_new(const ink_rect: PPangoRectangle; const logical_rect: PPangoRectangle): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_shape_new_with_data(const ink_rect: PPangoRectangle; const logical_rect: PPangoRectangle; data: gpointer; copy_func: PangoAttrDataCopyFunc; destroy_func: GDestroyNotify): PPangoAttribute; cdecl; external LIB_PANGO;

function pango_attr_gravity_new(gravity: PangoGravity): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_gravity_hint_new(hint: PangoGravityHint): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_font_features_new(const features: pgchar): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_foreground_alpha_new(alpha: guint16): PPangoAttribute; cdecl; external LIB_PANGO;
function pango_attr_background_alpha_new(alpha: guint16): PPangoAttribute; cdecl; external LIB_PANGO;

function pango_attr_list_get_type(): GType; cdecl; external LIB_PANGO;
function pango_attr_list_new(): PPangoAttrList; cdecl; external LIB_PANGO;
function pango_attr_list_ref(list: PPangoAttrList): PPangoAttrList; cdecl; external LIB_PANGO;
procedure pango_attr_list_unref(list: PPangoAttrList); cdecl; external LIB_PANGO;
function pango_attr_list_copy(list: PPangoAttrList): PPangoAttrList; cdecl; external LIB_PANGO;
procedure pango_attr_list_insert(list: PPangoAttrList; attr: PPangoAttribute); cdecl; external LIB_PANGO;
procedure pango_attr_list_insert_before(list: PPangoAttrList; attr: PPangoAttribute); cdecl; external LIB_PANGO;
procedure pango_attr_list_change(list: PPangoAttrList; attr: PPangoAttribute); cdecl; external LIB_PANGO;
procedure pango_attr_list_splice(list: PPangoAttrList; other: PPangoAttrList; pos: gint; len: gint); cdecl; external LIB_PANGO;

function pango_attr_list_filter(list: PPangoAttrList; func: PangoAttrFilterFunc; data: gpointer): PPangoAttrList; cdecl; external LIB_PANGO;

function pango_attr_list_get_iterator(list: PPangoAttrList): PPangoAttrIterator; cdecl; external LIB_PANGO;

procedure pango_attr_iterator_range(iterator: PPangoAttrIterator; start: pgint; end_: pgint); cdecl; external LIB_PANGO;
function pango_attr_iterator_next(iterator: PPangoAttrIterator): gboolean; cdecl; external LIB_PANGO;
function pango_attr_iterator_copy(iterator: PPangoAttrIterator): PPangoAttrIterator; cdecl; external LIB_PANGO;
procedure pango_attr_iterator_destroy(iterator: PPangoAttrIterator); cdecl; external LIB_PANGO;
function pango_attr_iterator_get(iterator: PPangoAttrIterator; type_: PangoAttrType): PPangoAttribute; cdecl; external LIB_PANGO;
procedure pango_attr_iterator_get_font(iterator: PPangoAttrIterator; desc: PPangoFontDescription; language: PPPangoLanguage; extra_attrs: PPGSList); cdecl; external LIB_PANGO;
function pango_attr_iterator_get_attrs(iterator: PPangoAttrIterator): PGSList; cdecl; external LIB_PANGO;

function pango_parse_markup(const markup_text: Pchar; length: cint; accel_marker: gunichar; attr_list: PPPangoAttrList; text: ppchar; accel_char: Pgunichar; error: PPGError): gboolean; cdecl; external LIB_PANGO;

function pango_markup_parser_new(accel_marker: gunichar): PGMarkupParseContext; cdecl; external LIB_PANGO;
function pango_markup_parser_finish(context: PGMarkupParseContext; attr_list: PPPangoAttrList; text: ppchar; accel_char: Pgunichar; error: PPGError): gboolean; cdecl; external LIB_PANGO;

// G_END_DECLS

// #endif (* __PANGO_ATTRIBUTES_H__ *)
