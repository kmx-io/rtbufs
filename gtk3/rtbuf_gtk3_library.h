/*
 * Copyright 2020 Thomas de Grivel <thoxdg@gmail.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#ifndef RTBUF_GTK_LIBRARY_H
#define RTBUF_GTK_LIBRARY_H

#include <gtk/gtk.h>

typedef struct rtbuf_gtk_library_tree s_rtbuf_gtk_library_tree;

struct rtbuf_gtk_library_tree {
  const char *dir_name;
  const char *leaf_name;
  GtkMenu *menu;
  s_rtbuf_gtk_library_tree *children;
  s_rtbuf_gtk_library_tree *next;
};

extern s_rtbuf_gtk_library_tree *g_rtbuf_gtk_library_tree;

void rtbuf_gtk_library_load ();

#endif /* RTBUF_GTK_LIBRARY_H */
