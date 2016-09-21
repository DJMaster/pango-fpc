//
// pango-font.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pango-font.h: Font handling
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

// #ifndef __PANGO_FONT_H__
// #define __PANGO_FONT_H__

// #include <pango/pango-coverage.h>
// #include <pango/pango-types.h>

// #include <glib-object.h>

// G_BEGIN_DECLS

(**
 * PangoFontDescription:
 *
 * The #PangoFontDescription structure represents the description
 * of an ideal font. These structures are used both to list
 * what fonts are available on the system and also for specifying
 * the characteristics of a font to load.
 *)
type
  PangoFontDescription = record
  end;
  PPangoFontDescription = ^PangoFontDescription;
  PPPangoFontDescription = ^PPangoFontDescription;
(**
 * PangoFontMetrics:
 *
 * A #PangoFontMetrics structure holds the overall metric information
 * for a font (possibly restricted to a script). The fields of this
 * structure are private to implementations of a font backend. See
 * the documentation of the corresponding getters for documentation
 * of their meaning.
 *)
type
  PangoFontMetrics = record
    (* <private> *)
    ref_count: guint;
  
    ascent: cint;
    descent: cint;
    approximate_char_width: cint;
    approximate_digit_width: cint;
    underline_position: cint;
    underline_thickness: cint;
    strikethrough_position: cint;
    strikethrough_thickness: cint;
  end;
  PPangoFontMetrics = ^PangoFontMetrics;

(**
 * PangoStyle:
 * @PANGO_STYLE_NORMAL: the font is upright.
 * @PANGO_STYLE_OBLIQUE: the font is slanted, but in a roman style.
 * @PANGO_STYLE_ITALIC: the font is slanted in an italic style.
 *
 * An enumeration specifying the various slant styles possible for a font.
 **)
type
  PangoStyle = (
    PANGO_STYLE_NORMAL,
    PANGO_STYLE_OBLIQUE,
    PANGO_STYLE_ITALIC
  );
  PPangoStyle = ^PangoStyle;

(**
 * PangoVariant:
 * @PANGO_VARIANT_NORMAL: A normal font.
 * @PANGO_VARIANT_SMALL_CAPS: A font with the lower case characters
 * replaced by smaller variants of the capital characters.
 *
 * An enumeration specifying capitalization variant of the font.
 *)
type
  PangoVariant = (
    PANGO_VARIANT_NORMAL,
    PANGO_VARIANT_SMALL_CAPS
  );
  PPangoVariant = ^PangoVariant;

(**
 * PangoWeight:
 * @PANGO_WEIGHT_THIN: the thin weight (= 100; Since: 1.24)
 * @PANGO_WEIGHT_ULTRALIGHT: the ultralight weight (= 200)
 * @PANGO_WEIGHT_LIGHT: the light weight (= 300)
 * @PANGO_WEIGHT_SEMILIGHT: the semilight weight (= 350; Since: 1.36.7)
 * @PANGO_WEIGHT_BOOK: the book weight (= 380; Since: 1.24)
 * @PANGO_WEIGHT_NORMAL: the default weight (= 400)
 * @PANGO_WEIGHT_MEDIUM: the normal weight (= 500; Since: 1.24)
 * @PANGO_WEIGHT_SEMIBOLD: the semibold weight (= 600)
 * @PANGO_WEIGHT_BOLD: the bold weight (= 700)
 * @PANGO_WEIGHT_ULTRABOLD: the ultrabold weight (= 800)
 * @PANGO_WEIGHT_HEAVY: the heavy weight (= 900)
 * @PANGO_WEIGHT_ULTRAHEAVY: the ultraheavy weight (= 1000; Since: 1.24)
 *
 * An enumeration specifying the weight (boldness) of a font. This is a numerical
 * value ranging from 100 to 1000, but there are some predefined values:
 *)
type
  PangoWeight = (
    PANGO_WEIGHT_THIN = 100,
    PANGO_WEIGHT_ULTRALIGHT = 200,
    PANGO_WEIGHT_LIGHT = 300,
    PANGO_WEIGHT_SEMILIGHT = 350,
    PANGO_WEIGHT_BOOK = 380,
    PANGO_WEIGHT_NORMAL = 400,
    PANGO_WEIGHT_MEDIUM = 500,
    PANGO_WEIGHT_SEMIBOLD = 600,
    PANGO_WEIGHT_BOLD = 700,
    PANGO_WEIGHT_ULTRABOLD = 800,
    PANGO_WEIGHT_HEAVY = 900,
    PANGO_WEIGHT_ULTRAHEAVY = 1000
  );
  PPangoWeight = ^PangoWeight;

(**
 * PangoStretch:
 * @PANGO_STRETCH_ULTRA_CONDENSED: ultra condensed width
 * @PANGO_STRETCH_EXTRA_CONDENSED: extra condensed width
 * @PANGO_STRETCH_CONDENSED: condensed width
 * @PANGO_STRETCH_SEMI_CONDENSED: semi condensed width
 * @PANGO_STRETCH_NORMAL: the normal width
 * @PANGO_STRETCH_SEMI_EXPANDED: semi expanded width
 * @PANGO_STRETCH_EXPANDED: expanded width
 * @PANGO_STRETCH_EXTRA_EXPANDED: extra expanded width
 * @PANGO_STRETCH_ULTRA_EXPANDED: ultra expanded width
 *
 * An enumeration specifying the width of the font relative to other designs
 * within a family.
 *)
type
  PangoStretch = (
    PANGO_STRETCH_ULTRA_CONDENSED,
    PANGO_STRETCH_EXTRA_CONDENSED,
    PANGO_STRETCH_CONDENSED,
    PANGO_STRETCH_SEMI_CONDENSED,
    PANGO_STRETCH_NORMAL,
    PANGO_STRETCH_SEMI_EXPANDED,
    PANGO_STRETCH_EXPANDED,
    PANGO_STRETCH_EXTRA_EXPANDED,
    PANGO_STRETCH_ULTRA_EXPANDED
  );
  PPangoStretch = ^PangoStretch;

(**
 * PangoFontMask:
 * @PANGO_FONT_MASK_FAMILY: the font family is specified.
 * @PANGO_FONT_MASK_STYLE: the font style is specified.
 * @PANGO_FONT_MASK_VARIANT: the font variant is specified.
 * @PANGO_FONT_MASK_WEIGHT: the font weight is specified.
 * @PANGO_FONT_MASK_STRETCH: the font stretch is specified.
 * @PANGO_FONT_MASK_SIZE: the font size is specified.
 * @PANGO_FONT_MASK_GRAVITY: the font gravity is specified (Since: 1.16.)
 *
 * The bits in a #PangoFontMask correspond to fields in a
 * #PangoFontDescription that have been set.
 *)
type
  PangoFontMask = (
    PANGO_FONT_MASK_FAMILY  = 1 shl 0,
    PANGO_FONT_MASK_STYLE   = 1 shl 1,
    PANGO_FONT_MASK_VARIANT = 1 shl 2,
    PANGO_FONT_MASK_WEIGHT  = 1 shl 3,
    PANGO_FONT_MASK_STRETCH = 1 shl 4,
    PANGO_FONT_MASK_SIZE    = 1 shl 5,
    PANGO_FONT_MASK_GRAVITY = 1 shl 6
  );

(* CSS scale factors (1.2 factor between each size) *)
(**
 * PANGO_SCALE_XX_SMALL:
 *
 * The scale factor for three shrinking steps (1 / (1.2 * 1.2 * 1.2)).
 *)
(**
 * PANGO_SCALE_X_SMALL:
 *
 * The scale factor for two shrinking steps (1 / (1.2 * 1.2)).
 *)
(**
 * PANGO_SCALE_SMALL:
 *
 * The scale factor for one shrinking step (1 / 1.2).
 *)
(**
 * PANGO_SCALE_MEDIUM:
 *
 * The scale factor for normal size (1.0).
 *)
(**
 * PANGO_SCALE_LARGE:
 *
 * The scale factor for one magnification step (1.2).
 *)
(**
 * PANGO_SCALE_X_LARGE:
 *
 * The scale factor for two magnification steps (1.2 * 1.2).
 *)
(**
 * PANGO_SCALE_XX_LARGE:
 *
 * The scale factor for three magnification steps (1.2 * 1.2 * 1.2).
 *)
const
  PANGO_SCALE_XX_SMALL = 0.5787037037037;
  PANGO_SCALE_X_SMALL  = 0.6444444444444;
  PANGO_SCALE_SMALL    = 0.8333333333333;
  PANGO_SCALE_MEDIUM   = 1.0;
  PANGO_SCALE_LARGE    = 1.2;
  PANGO_SCALE_X_LARGE  = 1.4399999999999;
  PANGO_SCALE_XX_LARGE = 1.728;

(*
 * PangoFontDescription
 *)

(**
 * PANGO_TYPE_FONT_DESCRIPTION:
 *
 * The #GObject type for #PangoFontDescription.
 *)
//todo #define PANGO_TYPE_FONT_DESCRIPTION (pango_font_description_get_type ())

function pango_font_description_get_type(): GType; cdecl; external LIB_PANGO;
function pango_font_description_new(): PPangoFontDescription; cdecl; external LIB_PANGO;
function pango_font_description_copy(const desc: PPangoFontDescription): PPangoFontDescription; cdecl; external LIB_PANGO;
function pango_font_description_copy_static(const desc: PPangoFontDescription): PPangoFontDescription; cdecl; external LIB_PANGO;
function pango_font_description_hash(const desc: PPangoFontDescription): guint; cdecl; external LIB_PANGO;
function pango_font_description_equal(const desc1: PPangoFontDescription; const desc2: PPangoFontDescription): gboolean; cdecl; external LIB_PANGO;
procedure pango_font_description_free(desc: PPangoFontDescription); cdecl; external LIB_PANGO;
procedure pango_font_descriptions_free(descs: PPPangoFontDescription; n_descs: cint); cdecl; external LIB_PANGO;

procedure pango_font_description_set_family(desc: PPangoFontDescription; const family: Pchar); cdecl; external LIB_PANGO;
procedure pango_font_description_set_family_static(desc: PPangoFontDescription; const family: Pchar); cdecl; external LIB_PANGO;
function pango_font_description_get_family(const desc: PPangoFontDescription): Pchar; cdecl; external LIB_PANGO;
procedure pango_font_description_set_style(desc: PPangoFontDescription; style: PangoStyle); cdecl; external LIB_PANGO;
function pango_font_description_get_style(const desc: PPangoFontDescription): PangoStyle; cdecl; external LIB_PANGO;
procedure pango_font_description_set_variant(desc: PPangoFontDescription; variant: PangoVariant); cdecl; external LIB_PANGO;
function pango_font_description_get_variant(const desc: PPangoFontDescription): PangoVariant; cdecl; external LIB_PANGO;
procedure pango_font_description_set_weight(desc: PPangoFontDescription; weight: PangoWeight); cdecl; external LIB_PANGO;
function pango_font_description_get_weight(const desc: PPangoFontDescription): PangoWeight; cdecl; external LIB_PANGO;
procedure pango_font_description_set_stretch(desc: PPangoFontDescription; stretch: PangoStretch); cdecl; external LIB_PANGO;
function pango_font_description_get_stretch(const desc: PPangoFontDescription): PangoStretch; cdecl; external LIB_PANGO;
procedure pango_font_description_set_size(desc: PPangoFontDescription; size: gint); cdecl; external LIB_PANGO;
function pango_font_description_get_size(const desc: PPangoFontDescription): gint; cdecl; external LIB_PANGO;
procedure pango_font_description_set_absolute_size(desc: PPangoFontDescription; size: double); cdecl; external LIB_PANGO;
function pango_font_description_get_size_is_absolute(const desc: PPangoFontDescription): gboolean; cdecl; external LIB_PANGO;
procedure pango_font_description_set_gravity(desc: PPangoFontDescription; gravity: PangoGravity); cdecl; external LIB_PANGO;
function pango_font_description_get_gravity(const desc: PPangoFontDescription): PangoGravity; cdecl; external LIB_PANGO;

function pango_font_description_get_set_fields(const desc: PPangoFontDescription): PangoFontMask; cdecl; external LIB_PANGO;
procedure pango_font_description_unset_fields(desc: PPangoFontDescription; to_unset: PangoFontMask); cdecl; external LIB_PANGO;

procedure pango_font_description_merge(desc: PPangoFontDescription; const desc_to_merge: PPangoFontDescription; replace_existing: gboolean); cdecl; external LIB_PANGO;
procedure pango_font_description_merge_static(desc: PPangoFontDescription; const desc_to_merge: PPangoFontDescription; replace_existing: gboolean); cdecl; external LIB_PANGO;

function pango_font_description_better_match(const desc: PPangoFontDescription; const old_match: PPangoFontDescription; const new_match: PPangoFontDescription): gboolean; cdecl; external LIB_PANGO;

function pango_font_description_from_string(const str: Pchar): PPangoFontDescription; cdecl; external LIB_PANGO;
function pango_font_description_to_string(const desc: PPangoFontDescription): Pchar; cdecl; external LIB_PANGO;
function pango_font_description_to_filename(const desc: PPangoFontDescription): Pchar; cdecl; external LIB_PANGO;

(*
 * PangoFontMetrics
 *)

(**
 * PANGO_TYPE_FONT_METRICS:
 *
 * The #GObject type for #PangoFontMetrics.
 *)
//todo #define PANGO_TYPE_FONT_METRICS  (pango_font_metrics_get_type ())
function pango_font_metrics_get_type(): GType; cdecl; external LIB_PANGO;
function pango_font_metrics_ref(metrics: PPangoFontMetrics): PPangoFontMetrics; cdecl; external LIB_PANGO;
procedure pango_font_metrics_unref(metrics: PPangoFontMetrics); cdecl; external LIB_PANGO;
function pango_font_metrics_get_ascent(metrics: PPangoFontMetrics): cint; cdecl; external LIB_PANGO;
function pango_font_metrics_get_descent(metrics: PPangoFontMetrics): cint; cdecl; external LIB_PANGO;
function pango_font_metrics_get_approximate_char_width(metrics: PPangoFontMetrics): cint; cdecl; external LIB_PANGO;
function pango_font_metrics_get_approximate_digit_width(metrics: PPangoFontMetrics): cint; cdecl; external LIB_PANGO;
function pango_font_metrics_get_underline_position(metrics: PPangoFontMetrics): cint; cdecl; external LIB_PANGO;
function pango_font_metrics_get_underline_thickness(metrics: PPangoFontMetrics): cint; cdecl; external LIB_PANGO;
function pango_font_metrics_get_strikethrough_position(metrics: PPangoFontMetrics): cint; cdecl; external LIB_PANGO;
function pango_font_metrics_get_strikethrough_thickness(metrics: PPangoFontMetrics): cint; cdecl; external LIB_PANGO;

{$ifdef PANGO_ENABLE_BACKEND}

function pango_font_metrics_new(): PPangoFontMetrics; cdecl; external LIB_PANGO;


{$endif} (* PANGO_ENABLE_BACKEND *)

(*
 * PangoFontFamily
 *)

(**
 * PANGO_TYPE_FONT_FAMILY:
 *
 * The #GObject type for #PangoFontFamily.
 *)
(**
 * PANGO_FONT_FAMILY:
 * @object: a #GObject.
 *
 * Casts a #GObject to a #PangoFontFamily.
 *)
(**
 * PANGO_IS_FONT_FAMILY:
 * @object: a #GObject.
 *
 * Returns: %TRUE if @object is a #PangoFontFamily.
 *)
//todo #define PANGO_TYPE_FONT_FAMILY              (pango_font_family_get_type ())
//todo #define PANGO_FONT_FAMILY(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_FONT_FAMILY, PangoFontFamily))
//todo #define PANGO_IS_FONT_FAMILY(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_FONT_FAMILY))

type
  PangoFontFamily = record
  end;
  PPangoFontFamily = ^PangoFontFamily;
  PPPangoFontFamily = ^PPangoFontFamily;
  PPPPangoFontFamily = ^PPPangoFontFamily;

  PangoFontFace = record
  end;
  PPangoFontFace = ^PangoFontFace;
  PPPangoFontFace = ^PPangoFontFace;
  PPPPangoFontFace = ^PPPangoFontFace;

function pango_font_family_get_type(): GType; cdecl; external LIB_PANGO;

procedure pango_font_family_list_faces(family: PPangoFontFamily; faces: PPPPangoFontFace; n_faces: pcint); cdecl; external LIB_PANGO;
function pango_font_family_get_name(family: PPangoFontFamily): pchar; cdecl; external LIB_PANGO;
function pango_font_family_is_monospace(family: PPangoFontFamily): gboolean; cdecl; external LIB_PANGO;

{$ifdef PANGO_ENABLE_BACKEND}

//todo #define PANGO_FONT_FAMILY_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), PANGO_TYPE_FONT_FAMILY, PangoFontFamilyClass))
//todo #define PANGO_IS_FONT_FAMILY_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), PANGO_TYPE_FONT_FAMILY))
//todo #define PANGO_FONT_FAMILY_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), PANGO_TYPE_FONT_FAMILY, PangoFontFamilyClass))

(**
 * PangoFontFamily:
 *
 * The #PangoFontFamily structure is used to represent a family of related
 * font faces. The faces in a family share a common design, but differ in
 * slant, weight, width and other aspects.
 *)
type
  PangoFontFamily = record
    parent_instance: GObject;
  end;

type
  PangoFontFamilyClass = record
    GObjectClass parent_class;
  
    (*< public >*)
  
    list_faces: procedure(family: PPangoFontFamily; faces: PPPPangoFontFace; n_faces: pcint); cdecl;
    get_name: function(family: PPangoFontFamily): pchar; cdecl;
    is_monospace: function(family: PPangoFontFamily): gboolean; cdecl;
  
    (*< private >*)
  
    (* Padding for future expansion *)
    _pango_reserved2: procedure(); cdecl;
    _pango_reserved3: procedure(); cdecl;
    _pango_reserved4: procedure(); cdecl;
  end;
  PPangoFontFamilyClass = ^PangoFontFamilyClass;

{$endif} (* PANGO_ENABLE_BACKEND *)

(*
 * PangoFontFace
 *)

(**
 * PANGO_TYPE_FONT_FACE:
 *
 * The #GObject type for #PangoFontFace.
 *)
(**
 * PANGO_FONT_FACE:
 * @object: a #GObject.
 *
 * Casts a #GObject to a #PangoFontFace.
 *)
(**
 * PANGO_IS_FONT_FACE:
 * @object: a #GObject.
 *
 * Returns: %TRUE if @object is a #PangoFontFace.
 *)
//todo #define PANGO_TYPE_FONT_FACE              (pango_font_face_get_type ())
//todo #define PANGO_FONT_FACE(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_FONT_FACE, PangoFontFace))
//todo #define PANGO_IS_FONT_FACE(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_FONT_FACE))

function pango_font_face_get_type(): GType; cdecl; external LIB_PANGO;

function pango_font_face_describe(face: PPangoFontFace): PPangoFontDescription; cdecl; external LIB_PANGO;
function pango_font_face_get_face_name(face: PPangoFontFace): Pchar; cdecl; external LIB_PANGO;
procedure pango_font_face_list_sizes(face: PPangoFontFace; sizes: ppcint; n_sizes: pcint); cdecl; external LIB_PANGO;
function pango_font_face_is_synthesized(face: PPangoFontFace): gboolean; cdecl; external LIB_PANGO;

{$ifdef PANGO_ENABLE_BACKEND}

//todo #define PANGO_FONT_FACE_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), PANGO_TYPE_FONT_FACE, PangoFontFaceClass))
//todo #define PANGO_IS_FONT_FACE_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), PANGO_TYPE_FONT_FACE))
//todo #define PANGO_FONT_FACE_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), PANGO_TYPE_FONT_FACE, PangoFontFaceClass))


(**
 * PangoFontFace:
 *
 * The #PangoFontFace structure is used to represent a group of fonts with
 * the same family, slant, weight, width, but varying sizes.
 *)
type
  PangoFontFace = record
    parent_instance: GObject;
  end;

type
  PangoFontFaceClass = record
    GObjectClass parent_class;
  
    (*< public >*)
  
    get_face_name: function(face: PPangoFontFace): pchar; cdecl;
    describe: function(face: PPangoFontFace): PPangoFontDescription; cdecl;
    list_sizes: procedure(face: PPangoFontFace; sizes: ppcint; n_sizes: pcint); cdecl;
    is_synthesized: function(face: PPangoFontFace): gboolean; cdecl;

    (*< private >*)
  
    (* Padding for future expansion *)
    _pango_reserved3: procedure(); cdecl;
    _pango_reserved4: procedure(); cdecl;
  end;
  PPangoFontFaceClass = ^PangoFontFaceClass;

{$endif} (* PANGO_ENABLE_BACKEND *)

(*
 * PangoFont
 *)

(**
 * PANGO_TYPE_FONT:
 *
 * The #GObject type for #PangoFont.
 *)
(**
 * PANGO_FONT:
 * @object: a #GObject.
 *
 * Casts a #GObject to a #PangoFont.
 *)
(**
 * PANGO_IS_FONT:
 * @object: a #GObject.
 *
 * Returns: %TRUE if @object is a #PangoFont.
 *)
//todo #define PANGO_TYPE_FONT              (pango_font_get_type ())
//todo #define PANGO_FONT(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_FONT, PangoFont))
//todo #define PANGO_IS_FONT(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_FONT))

function pango_font_get_type(): GType; cdecl; external LIB_PANGO;

function pango_font_describe(font: PPangoFont): PPangoFontDescription; cdecl; external LIB_PANGO;
function pango_font_describe_with_absolute_size(font: PPangoFont): PPangoFontDescription; cdecl; external LIB_PANGO;
function pango_font_get_coverage(font: PPangoFont; language: PPangoLanguage): PPangoCoverage; cdecl; external LIB_PANGO;
function pango_font_find_shaper(font: PPangoFont; language: PPangoLanguage; ch: guint32): PPangoEngineShape; cdecl; external LIB_PANGO;
function pango_font_get_metrics(font: PPangoFont; language: PPangoLanguage): PPangoFontMetrics; cdecl; external LIB_PANGO;
procedure pango_font_get_glyph_extents(font: PPangoFont; glyph: PangoGlyph; ink_rect: PPangoRectangle; logical_rect: PPangoRectangle); cdecl; external LIB_PANGO;
function pango_font_get_font_map(font: PPangoFont): PPangoFontMap; cdecl; external LIB_PANGO;

{$ifdef PANGO_ENABLE_BACKEND}

//todo #define PANGO_FONT_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), PANGO_TYPE_FONT, PangoFontClass))
//todo #define PANGO_IS_FONT_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), PANGO_TYPE_FONT))
//todo #define PANGO_FONT_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), PANGO_TYPE_FONT, PangoFontClass))

type
  PangoFontClass = record
  end;
  PPangoFontClass = ^PangoFontClass;

(**
 * PangoFont:
 *
 * The #PangoFont structure is used to represent
 * a font in a rendering-system-independent matter.
 * To create an implementation of a #PangoFont,  * the rendering-system specific code should allocate
 * a larger structure that contains a nested
 * #PangoFont, fill in the <structfield>klass</structfield> member of
 * the nested #PangoFont with a pointer to
 * a appropriate #PangoFontClass, then call
 * pango_font_init() on the structure.
 *
 * The #PangoFont structure contains one member
 * which the implementation fills in.
 *)
type
  PangoFont = record
    parent_instance: GObject;
  end;
  PPangoFont = ^PangoFont;

  PangoFontClass = record
    parent_class: GObjectClass;
  
    (*< public >*)
  
    describe: function(font: PPangoFont): PPangoFontDescription; cdecl;
    get_coverage: function(font: PPangoFont; lang: PPangoLanguage): PPangoCoverage; cdecl;
    find_shaper: function(font: PPangoFont; lang: PPangoLanguage; ch: guint32): PPangoEngineShape; cdecl;
    get_glyph_extents: procedure(font: PPangoFont; glyph: PangoGlyph; ink_rect: PPangoRectangle; logical_rect: PPangoRectangle); cdecl;
    get_metrics: function(font: PPangoFont; language: PPangoLanguage): PPangoFontMetrics; cdecl;
    get_font_map: function(font: PPangoFont): PPangoFontMap; cdecl;
    describe_absolute: function(font: PPangoFont): PPangoFontDescription; cdecl;
    (*< private >*)
  
    (* Padding for future expansion *)
    _pango_reserved1: procedure(); cdecl;
    _pango_reserved2: procedure(); cdecl;
  end;

(* used for very rare and miserable situtations that we cannot even
 * draw a hexbox
 *)
const
  PANGO_UNKNOWN_GLYPH_WIDTH = 10;
  PANGO_UNKNOWN_GLYPH_HEIGHT = 14;

{$endif} (* PANGO_ENABLE_BACKEND *)

(**
 * PANGO_GLYPH_EMPTY:
 *
 * The %PANGO_GLYPH_EMPTY macro represents a #PangoGlyph value that has a
 *  special meaning, which is a zero-width empty glyph.  This is useful for
 * example in shaper modules, to use as the glyph for various zero-width
 * Unicode characters (those passing pango_is_zero_width()).
 *)
(**
 * PANGO_GLYPH_INVALID_INPUT:
 *
 * The %PANGO_GLYPH_INVALID_INPUT macro represents a #PangoGlyph value that has a
 * special meaning of invalid input.  #PangoLayout produces one such glyph
 * per invalid input UTF-8 byte and such a glyph is rendered as a crossed
 * box.
 *
 * Note that this value is defined such that it has the %PANGO_GLYPH_UNKNOWN_FLAG
 * on.
 *
 * Since: 1.20
 *)
(**
 * PANGO_GLYPH_UNKNOWN_FLAG:
 *
 * The %PANGO_GLYPH_UNKNOWN_FLAG macro is a flag value that can be added to
 * a #gunichar value of a valid Unicode character, to produce a #PangoGlyph
 * value, representing an unknown-character glyph for the respective #gunichar.
 *)
(**
 * PANGO_GET_UNKNOWN_GLYPH:
 * @wc: a Unicode character
 *
 * The way this unknown glyphs are rendered is backend specific.  For example,  * a box with the hexadecimal Unicode code-point of the character written in it
 * is what is done in the most common backends.
 *
 * Returns: a #PangoGlyph value that means no glyph was found for @wc.
 *)
//todo #define PANGO_GLYPH_EMPTY           ((PangoGlyph)0x0FFFFFFF)
//todo #define PANGO_GLYPH_INVALID_INPUT   ((PangoGlyph)0xFFFFFFFF)
//todo #define PANGO_GLYPH_UNKNOWN_FLAG    ((PangoGlyph)0x10000000)
//todo #define PANGO_GET_UNKNOWN_GLYPH(wc) ((PangoGlyph)(wc)|PANGO_GLYPH_UNKNOWN_FLAG)


// G_END_DECLS

// #endif (* __PANGO_FONT_H__ *)
