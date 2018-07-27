
#include <math.h>
#include <stdio.h>
#include "rtbuf.h"
#include "rtbuf_lib.h"
#include "rtbuf_signal.h"

const char     *rtbuf_lib_name = "signal";
unsigned long   rtbuf_lib_ver = RTBUF_LIB_VER;
s_rtbuf_lib_fun rtbuf_lib_fun[] = {
  { "sinus", rtbuf_signal_sinus, rtbuf_signal_sinus_start, 0,
    sizeof(s_rtbuf_signal_sinus_data) / sizeof(double) + 1,
    sizeof(double),
    (const char*[]) { "frequency", "amplitude", 0 } },
  { "square", rtbuf_signal_square, rtbuf_signal_square_start, 0,
    sizeof(s_rtbuf_signal_square_data) / sizeof(double) + 1,
    sizeof(double),
    (const char*[]) { "frequency", "amplitude", "pulse", 0 } },
  { 0, 0, 0, 0, 0, 0, 0 }
};
