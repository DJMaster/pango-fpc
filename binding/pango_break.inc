//
// pango-break.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pango-break.h:
 *
 * Copyright (C) 1999 Red Hat Software
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

// #ifndef __PANGO_BREAK_H__
// #define __PANGO_BREAK_H__

// #include <glib.h>

// G_BEGIN_DECLS

// #include <pango/pango-item.h>

(* Logical attributes of a character.
 *)
(**
 * PangoLogAttr:
 * @is_line_break: if set, can break line in front of character
 * @is_mandatory_break: if set, must break line in front of character
 * @is_char_break: if set, can break here when doing character wrapping
 * @is_white: is whitespace character
 * @is_cursor_position: if set, cursor can appear in front of character.
 * i.e. this is a grapheme boundary, or the first character
 * in the text.
 * This flag implements Unicode's
 * <ulink url="http://www.unicode.org/reports/tr29/">Grapheme
 * Cluster Boundaries</ulink> semantics.
 * @is_word_start: is first character in a word
 * @is_word_end: is first non-word char after a word
 * Note that in degenerate cases, you could have both @is_word_start
 * and @is_word_end set for some character.
 * @is_sentence_boundary: is a sentence boundary.
 * There are two ways to divide sentences. The first assigns all
 * inter-sentence whitespace/control/format chars to some sentence,  * so all chars are in some sentence; @is_sentence_boundary denotes
 * the boundaries there. The second way doesn't assign
 * between-sentence spaces, etc. to any sentence, so
 * @is_sentence_start/@is_sentence_end mark the boundaries of those sentences.
 * @is_sentence_start: is first character in a sentence
 * @is_sentence_end: is first char after a sentence.
 * Note that in degenerate cases, you could have both @is_sentence_start
 * and @is_sentence_end set for some character. (e.g. no space after a
 * period, so the next sentence starts right away)
 * @backspace_deletes_character: if set, backspace deletes one character
 * rather than the entire grapheme cluster. This
 * field is only meaningful on grapheme
 * boundaries (where @is_cursor_position is
 * set).  In some languages, the full grapheme
 * (e.g.  letter + diacritics) is considered a
 * unit, while in others, each decomposed
 * character in the grapheme is a unit. In the
 * default implementation of pango_break(), this
 * bit is set on all grapheme boundaries except
 * those following Latin, Cyrillic or Greek base characters.
 * @is_expandable_space: is a whitespace character that can possibly be
 * expanded for justification purposes. (Since: 1.18)
 * @is_word_boundary: is a word boundary.
 * More specifically, means that this is not a position in the middle
 * of a word.  For example, both sides of a punctuation mark are
 * considered word boundaries.  This flag is particularly useful when
 * selecting text word-by-word.
 * This flag implements Unicode's
 * <ulink url="http://www.unicode.org/reports/tr29/">Word
 * Boundaries</ulink> semantics. (Since: 1.22)
 *
 * The #PangoLogAttr structure stores information
 * about the attributes of a single character.
 *)
type
  PangoLogAttr = record
    is_line_break: guint; //todo is_line_break: guint = 1;      (* Can break line in front of character *)
  
    is_mandatory_break: guint; //todo is_mandatory_break: guint = 1; (* Must break line in front of character *)
  
    is_char_break: guint; //todo is_char_break: guint = 1;      (* Can break here when doing char wrap *)
  
    is_white: guint; //todo is_white: guint = 1;           (* Whitespace character *)
  
    (* Cursor can appear in front of character (i.e. this is a grapheme
     * boundary, or the first character in the text).
     *)
    is_cursor_position: guint; //todo is_cursor_position: guint = 1;
  
    (* Note that in degenerate cases, you could have both start/end set on
     * some text, most likely for sentences (e.g. no space after a period, so
     * the next sentence starts right away).
     *)
  
    is_word_start: guint; //todo is_word_start: guint = 1;    (* first character in a word *)
    is_word_end: guint; //todo is_word_end: guint = 1;      (* is first non-word char after a word *)
  
    (* There are two ways to divide sentences. The first assigns all
     * intersentence whitespace/control/format chars to some sentence,  * so all chars are in some sentence; is_sentence_boundary denotes
     * the boundaries there. The second way doesn't assign
     * between-sentence spaces, etc. to any sentence, so
     * is_sentence_start/is_sentence_end mark the boundaries of those
     * sentences.
     *)
    is_sentence_boundary: guint; //todo is_sentence_boundary: guint = 1;
    is_sentence_start: guint; //todo is_sentence_start: guint = 1;  (* first character in a sentence *)
    is_sentence_end: guint; //todo is_sentence_end: guint = 1;    (* first non-sentence char after a sentence *)
  
    (* If set, backspace deletes one character rather than
     * the entire grapheme cluster.
     *)
    backspace_deletes_character: guint; //todo backspace_deletes_character: guint = 1;
  
    (* Only few space variants (U+0020 and U+00A0) have variable
     * width during justification.
     *)
    is_expandable_space: guint; //todo is_expandable_space: guint = 1;
  
    (* Word boundary as defined by UAX#29 *)
    is_word_boundary: guint; //todo is_word_boundary: guint = 1; (* is NOT in the middle of a word *)
  end;
  PPangoLogAttr = ^PangoLogAttr;
  PPPangoLogAttr = ^PPangoLogAttr;

(* Determine information about cluster/word/line breaks in a string
 * of Unicode text.
 *)
procedure pango_break(const text: pgchar; length: cint; analysis: PPangoAnalysis; attrs: PPangoLogAttr; attrs_len: cint); cdecl; external LIB_PANGO;

procedure pango_find_paragraph_boundary(const text: pgchar; length: gint; paragraph_delimiter_index: pgint; next_paragraph_start: pgint); cdecl; external LIB_PANGO;

procedure pango_get_log_attrs(const text: pchar; length: cint; level: cint; language: PPangoLanguage; log_attrs: PPangoLogAttr; attrs_len: cint); cdecl; external LIB_PANGO;

{$ifdef PANGO_ENABLE_ENGINE}

(* This is the default break algorithm, used if no language
 * engine overrides it. Normally you should use pango_break()
 * instead; this function is mostly useful for chaining up
 * from a language engine override.
 *)
procedure pango_default_break(const text: pgchar; length: cint; analysis: PPangoAnalysis; attrs: PPangoLogAttr; attrs_len: cint); cdecl; external LIB_PANGO;

{$endif} (* PANGO_ENABLE_ENGINE *)

// G_END_DECLS

// #endif (* __PANGO_BREAK_H__ *)
