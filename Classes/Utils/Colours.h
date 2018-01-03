#ifndef COLOURS_H
#define COLOURS_H

#include "RGBA.h"

/// Names from http://htmlhelp.com/cgi-bin/color.cgi or my own.

namespace colours
{
    const RGBA black = RGBA(0,0,0,255);
    const RGBA grey = RGBA(128,128,128,255);
    const RGBA dim_grey = RGBA(105,105,105,255);
    const RGBA dark_grey = RGBA(169,169,169,255);
    const RGBA white = RGBA(255,255,255,255);
    const RGBA green = RGBA(0,128,0,255);
    const RGBA orange = RGBA(255,165,0,255);
    const RGBA blue_violet = RGBA(138,43,226,255);
    const RGBA blue = RGBA(0,0,255,255);
    const RGBA red = RGBA(255,0,0,255);
    const RGBA lime = RGBA(0,255,0,255);
    const RGBA medium_slate_blue = RGBA(123,104,238,255);
    const RGBA burlywood = RGBA(222,184,135,255);
    const RGBA brown = RGBA(165,42,42,255);
    const RGBA dodger_blue = RGBA(30,144,255,255);
    const RGBA gold = RGBA(255,215,0,255);
    const RGBA gainsboro = RGBA(220,220,220,255);
}

#endif
