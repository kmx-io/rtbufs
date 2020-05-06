/*
 * Copyright 2018-2020 Thomas de Grivel <thoxdg@gmail.com>
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
#ifndef RTBUF_H
#define RTBUF_H

#include <rtbuf/data.h>
#include <rtbuf/defs.h>
#include <rtbuf/type.h>
#include <rtbuf/proc.h>

#define RTBUF_SORT   0x0001
#define RTBUF_DELETE 0x0002

struct rtbuf_binding
{
  int rtb;
  unsigned int out;
};

struct rtbuf
{
  void           *data;
  unsigned int    flags;
  s_rtbuf_proc   *proc;
  unsigned int    refc;
  s_rtbuf_binding in[RTBUF_PROC_IN_MAX];
  unsigned int    in_n;
};

#define RTBUF_MAX         10000
#define RTBUF_INSTANCE_MAX  100

extern s_data_alloc g_rtbuf_alloc;
extern s_rtbuf     *g_rtbuf;
extern int          g_rtbuf_run;

int   librtbuf_init ();

int   rtbuf_err (const char *msg);
int   rtbuf_new (s_rtbuf_proc *rp);
void  rtbuf_in_unbind (s_rtbuf *rtb, unsigned int in);
void  rtbuf_out_unbind (s_rtbuf *rtb, unsigned int out);
void  rtbuf_unbind_all (s_rtbuf *rtb);
void  rtbuf_delete (s_rtbuf *rtb);
int   rtbuf_clone (s_rtbuf *rtb);
int   rtbuf_find (symbol sym);
int   rtbuf_in_find (s_rtbuf *rtb, const char *x);
void  rtbuf_bind (unsigned int src, unsigned int out,
                  s_rtbuf *dest, unsigned int var);
int   rtbuf_out_find (s_rtbuf *rtb, symbol sym);
int   rtbuf_data_set (s_rtbuf *rtb, symbol name, void *value,
                      unsigned int size);
void  rtbuf_sort ();
int   rtbuf_start ();
int   rtbuf_run ();
void  rtbuf_stop ();
void  rtbuf_print (unsigned int i);
void  rtbuf_print_long (unsigned int i);
void  rtbuf_print_sorted ();

int  rtbuf_out_int (s_rtbuf *rtb, unsigned int out, int default_value);

double min (double a, double b);
double max (double a, double b);
double clamp (double inf, double x, double sup);

#endif /* RTBUF_H */