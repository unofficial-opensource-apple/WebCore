/* ANSI-C code produced by gperf version 2.7.2 */
/* Command-line: gperf -a -L ANSI-C -C -G -c -o -t -k '*' -NfindEntity -D -s 2 kentities.gperf  */
/*   This file is part of the KDE libraries
  
     Copyright (C) 1999 Lars Knoll (knoll@mpi-hd.mpg.de)
  
     This library is free software; you can redistribute it and/or
     modify it under the terms of the GNU Library General Public
     License as published by the Free Software Foundation; either
     version 2 of the License, or (at your option) any later version.
  
     This library is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
     Library General Public License for more details.
  
     You should have received a copy of the GNU Library General Public License
     along with this library; see the file COPYING.LIB.  If not, write to
     the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
     Boston, MA 02111-1307, USA.
  
  ----------------------------------------------------------------------------
  
    kentities.gperf: input file to generate a hash table for entities
    kentities.c: DO NOT EDIT! generated by the command
    "gperf -a -L "ANSI-C" -C -G -c -o -t -k '*' -NfindEntity -D -s 2 khtmlentities.gperf > entities.c"   
    from kentities.gperf 

*/  
struct entity {
    const char *name;
    int code;
};

#define TOTAL_KEYWORDS 259
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 8
#define MIN_HASH_VALUE 2
#define MAX_HASH_VALUE 1476
/* maximum key range = 1475, duplicates = 1 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash (register const char *str, register unsigned int len)
{
  static const unsigned short asso_values[] =
    {
      1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477,
      1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477,
      1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477,
      1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477,
      1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477,    0,
        20,   15,   10, 1477, 1477, 1477, 1477, 1477, 1477, 1477,
      1477, 1477, 1477, 1477, 1477,   55,    5,    5,    0,  225,
      1477,   10,    0,  140, 1477,   15,    0,    0,   10,  105,
        30,    0,    5,   15,    0,   25, 1477, 1477,    5,   20,
        10, 1477, 1477, 1477, 1477, 1477, 1477,    0,   45,   95,
       155,    5,   45,  100,  305,   15,    0,   10,   10,  345,
       415,  170,  290,  100,    0,  300,   30,  110,   90,   10,
        15,   70,    0, 1477, 1477, 1477, 1477, 1477, 1477, 1477,
      1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477,
      1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477,
      1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477,
      1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477,
      1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477,
      1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477,
      1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477,
      1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477,
      1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477,
      1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477,
      1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477,
      1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477, 1477,
      1477, 1477, 1477, 1477, 1477, 1477
    };
  register int hval = len;

  switch (hval)
    {
      default:
      case 8:
        hval += asso_values[(unsigned char)str[7]];
      case 7:
        hval += asso_values[(unsigned char)str[6]];
      case 6:
        hval += asso_values[(unsigned char)str[5]];
      case 5:
        hval += asso_values[(unsigned char)str[4]];
      case 4:
        hval += asso_values[(unsigned char)str[3]];
      case 3:
        hval += asso_values[(unsigned char)str[2]];
      case 2:
        hval += asso_values[(unsigned char)str[1]];
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval;
}

static const struct entity wordlist[] =
  {
    {"LT", 60},
    {"rarr", 0x2192},
    {"GT", 62},
    {"zwj", 0x200d},
    {"larr", 0x2190},
    {"le", 0x2264},
    {"real", 0x211c},
    {"Xi", 0x039e},
    {"xi", 0x03be},
    {"eta", 0x03b7},
    {"zeta", 0x03b6},
    {"lt", 60},
    {"Beta", 0x0392},
    {"Pi", 0x03a0},
    {"Zeta", 0x0396},
    {"Delta", 0x0394},
    {"rArr", 0x21d2},
    {"lArr", 0x21d0},
    {"beta", 0x03b2},
    {"AMP", 38},
    {"crarr", 0x21b5},
    {"ge", 0x2265},
    {"reg", 0x00ae},
    {"Mu", 0x039c},
    {"Tau", 0x03a4},
    {"uarr", 0x2191},
    {"Nu", 0x039d},
    {"THORN", 0x00de},
    {"rceil", 0x2309},
    {"gt", 62},
    {"QUOT", 34},
    {"aelig", 0x00e6},
    {"lceil", 0x2308},
    {"tau", 0x03c4},
    {"iexcl", 0x00a1},
    {"frac14", 0x00bc},
    {"darr", 0x2193},
    {"frac12", 0x00bd},
    {"uArr", 0x21d1},
    {"frac34", 0x00be},
    {"or", 0x2228},
    {"bull", 0x2022},
    {"loz", 0x25ca},
    {"brvbar", 0x00a6},
    {"trade", 0x2122},
    {"agrave", 0x00e0},
    {"delta", 0x03b4},
    {"egrave", 0x00e8},
    {"circ", 0x02c6},
    {"acirc", 0x00e2},
    {"Dagger", 0x2021},
    {"dArr", 0x21d3},
    {"ecirc", 0x00ea},
    {"igrave", 0x00ec},
    {"iota", 0x03b9},
    {"tilde", 0x02dc},
    {"atilde", 0x00e3},
    {"icirc", 0x00ee},
    {"Ugrave", 0x00d9},
    {"ETH", 0x00d0},
    {"Ntilde", 0x00d1},
    {"Ucirc", 0x00db},
    {"forall", 0x2200},
    {"acute", 0x00b4},
    {"aacute", 0x00e1},
    {"eacute", 0x00e9},
    {"Agrave", 0x00c0},
    {"Eta", 0x0397},
    {"iacute", 0x00ed},
    {"deg", 0x00b0},
    {"Acirc", 0x00c2},
    {"Yacute", 0x00dd},
    {"radic", 0x221a},
    {"Uacute", 0x00da},
    {"Atilde", 0x00c3},
    {"cedil", 0x00b8},
    {"euro", 0x20ac},
    {"Ccedil", 0x00c7},
    {"para", 0x00b6},
    {"Aacute", 0x00c1},
    {"oelig", 0x0153},
    {"Ograve", 0x00d2},
    {"pi", 0x03c0},
    {"harr", 0x2194},
    {"ugrave", 0x00f9},
    {"Ocirc", 0x00d4},
    {"yacute", 0x00fd},
    {"ucirc", 0x00fb},
    {"part", 0x2202},
    {"equiv", 0x2261},
    {"Otilde", 0x00d5},
    {"Chi", 0x03a7},
    {"weierp", 0x2118},
    {"Igrave", 0x00cc},
    {"eth", 0x00f0},
    {"Iota", 0x0399},
    {"Theta", 0x0398},
    {"Psi", 0x03a8},
    {"Icirc", 0x00ce},
    {"Oacute", 0x00d3},
    {"Phi", 0x03a6},
    {"uacute", 0x00fa},
    {"lrm", 0x200e},
    {"rlm", 0x200f},
    {"frasl", 0x2044},
    {"there4", 0x2234},
    {"hArr", 0x21d4},
    {"dagger", 0x2020},
    {"exist", 0x2203},
    {"ograve", 0x00f2},
    {"ordf", 0x00aa},
    {"theta", 0x03b8},
    {"ocirc", 0x00f4},
    {"ccedil", 0x00e7},
    {"raquo", 0x00bb},
    {"Iacute", 0x00cd},
    {"cap", 0x2229},
    {"otilde", 0x00f5},
    {"laquo", 0x00ab},
    {"piv", 0x03d6},
    {"Prime", 0x2033},
    {"rfloor", 0x230b},
    {"AElig", 0x00c6},
    {"lfloor", 0x230a},
    {"quot", 34},
    {"oacute", 0x00f3},
    {"chi", 0x03c7},
    {"ne", 0x2260},
    {"Egrave", 0x00c8},
    {"zwnj", 0x200c},
    {"szlig", 0x00df},
    {"ni", 0x220b},
    {"sect", 0x00a7},
    {"Ecirc", 0x00ca},
    {"divide", 0x00f7},
    {"macr", 0x00af},
    {"mu", 0x03bc},
    {"sub", 0x2282},
    {"OElig", 0x0152},
    {"int", 0x222b},
    {"sube", 0x2286},
    {"uml", 0x00a8},
    {"auml", 0x00e4},
    {"image", 0x2111},
    {"Eacute", 0x00c9},
    {"euml", 0x00eb},
    {"nabla", 0x2207},
    {"rho", 0x03c1},
    {"Sigma", 0x03a3},
    {"Rho", 0x03a1},
    {"iuml", 0x00ef},
    {"Yuml", 0x0178},
    {"yen", 0x00a5},
    {"Uuml", 0x00dc},
    {"cup", 0x222a},
    {"ang", 0x2220},
    {"rang", 0x232a},
    {"Auml", 0x00c4},
    {"lowast", 0x2217},
    {"nu", 0x03bd},
    {"lang", 0x2329},
    {"aring", 0x00e5},
    {"yuml", 0x00ff},
    {"rdquo", 0x201d},
    {"cent", 0x00a2},
    {"ldquo", 0x201c},
    {"Lambda", 0x039b},
    {"Omega", 0x03a9},
    {"lambda", 0x03bb},
    {"clubs", 0x2663},
    {"iquest", 0x00bf},
    {"and", 0x2227},
    {"Ouml", 0x00d6},
    {"uuml", 0x00fc},
    {"bdquo", 0x201e},
    {"perp", 0x22a5},
    {"Aring", 0x00c5},
    {"kappa", 0x03ba},
    {"Kappa", 0x039a},
    {"psi", 0x03c8},
    {"Iuml", 0x00cf},
    {"alpha", 0x03b1},
    {"phi", 0x03c6},
    {"not", 0x00ac},
    {"prod", 0x220f},
    {"oline", 0x203e},
    {"omega", 0x03c9},
    {"copy", 0x00a9},
    {"micro", 0x00b5},
    {"curren", 0x00a4},
    {"ntilde", 0x00f1},
    {"amp", 38},
    {"ouml", 0x00f6},
    {"hellip", 0x2026},
    {"hearts", 0x2665},
    {"sdot", 0x22c5},
    {"prime", 0x2032},
    {"sim", 0x223c},
    {"Alpha", 0x0391},
    {"permil", 0x2030},
    {"ordm", 0x00ba},
    {"shy", 0x00ad},
    {"fnof", 0x0192},
    {"rsquo", 0x2019},
    {"rsaquo", 0x203a},
    {"Euml", 0x00cb},
    {"lsquo", 0x2018},
    {"lsaquo", 0x2039},
    {"times", 0x00d7},
    {"Scaron", 0x0160},
    {"sup", 0x2283},
    {"sup1", 0x00b9},
    {"Gamma", 0x0393},
    {"supe", 0x2287},
    {"supl", 0x00b9},
    {"sup3", 0x00b3},
    {"sup2", 0x00b2},
    {"sbquo", 0x201a},
    {"empty", 0x2205},
    {"isin", 0x2208},
    {"prop", 0x221d},
    {"sum", 0x2211},
    {"apos", 0x0027},
    {"sigma", 0x03c3},
    {"alefsym", 0x2135},
    {"cong", 0x2245},
    {"gamma", 0x03b3},
    {"sigmaf", 0x03c2},
    {"diams", 0x2666},
    {"percnt", 0x0025},
    {"otimes", 0x2297},
    {"nsub", 0x2284},
    {"middot", 0x00b7},
    {"oplus", 0x2295},
    {"infin", 0x221e},
    {"thorn", 0x00fe},
    {"emsp", 0x2003},
    {"scaron", 0x0161},
    {"asymp", 0x2248},
    {"ensp", 0x2002},
    {"upsih", 0x03d2},
    {"Oslash", 0x00d8},
    {"notin", 0x2209},
    {"nbsp", 0x00a0},
    {"spades", 0x2660},
    {"oslash", 0x00f8},
    {"thetasym", 0x03d1},
    {"mdash", 0x2014},
    {"pound", 0x00a3},
    {"Omicron", 0x039f},
    {"ndash", 0x2013},
    {"minus", 0x2212},
    {"epsilon", 0x03b5},
    {"omicron", 0x03bf},
    {"Upsilon", 0x03a5},
    {"upsilon", 0x03c5},
    {"thinsp", 0x2009},
    {"Epsilon", 0x0395},
    {"plusmn", 0x00b1}
  };

static const short lookup[] =
  {
      -1,   -1,    0,   -1,    1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,    2,    3,    4,   -1,
      -1,    5,   -1,    6,   -1,   -1,    7,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
       8,   -1,   -1,   -1,   -1,   -1,    9,   10,
      -1,   -1,   11,   -1,   12,   -1,   -1,   13,
      -1,   14,   15,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   16,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   17,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   18,   -1,   -1,   -1,
      19,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   20,   -1,   -1,   -1,
      -1,   -1,   -1,   21,   22,   -1,   -1,   -1,
      23,   24,   25,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   26,   -1,   -1,   27,   -1,   -1,
      -1,   -1,   28,   -1,   29,   -1,   30,   31,
      -1,   -1,   -1,   -1,   32,   -1,   -1,   33,
      -1,   34,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   35,   -1,   -1,   36,
      -1,   -1,   -1,   -1,   -1,   -1,   37,   -1,
      -1,   38,   -1,   39,   40,   -1,   -1,   -1,
      -1,   -1,   -1,   41,   -1,   -1,   -1,   42,
      -1,   -1,   43,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   44,   -1,   -1,   -1,   -1,
      -1,   45,   -1,   -1,   -1,   46,   47,   -1,
      -1,   48,   49,   50,   -1,   -1,   51,   52,
      53,   -1,   -1,   54,   55,   56,   -1,   -1,
      -1,   57,   58,   -1,   59,   -1,   -1,   60,
      -1,   -1,   -1,   61,   -1,   -1,   -1,   -1,
      -1,   62,   -1,   -1,   -1,   63,   64,   -1,
      -1,   -1,   -1,   65,   -1,   -1,   -1,   -1,
      66,   -1,   67,   -1,   -1,   68,   -1,   69,
      -1,   70,   71,   -1,   -1,   -1,   72,   73,
      -1,   -1,   -1,   -1,   74,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   75,   -1,   -1,
      -1,   76,   -1,   77,   -1,   -1,   78,   -1,
      -1,   -1,   -1,   -1,   -1,   79,   -1,   -1,
      -1,   80,   81,   82,   -1,   83,   -1,   84,
      -1,   -1,   -1,   85,   86,   -1,   -1,   -1,
      87,   -1,   -1,   -1,   88,   89,   90,   -1,
      91,   -1,   -1,   92,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   93,   -1,   94,
      95,   96,   -1,   -1,   97,   -1,   98,   99,
      -1,  100,   -1,   -1,  101,   -1, -622,   -1,
     104,  105, -157,   -2,  106,   -1,  107,   -1,
      -1,   -1,  108,  109,   -1,   -1,  110,  111,
      -1,   -1,   -1,   -1,  112,  113,   -1,   -1,
      -1,  114,  115,   -1,  116,   -1,   -1,  117,
      -1,   -1,   -1,  118,   -1,   -1,  119,   -1,
     120,  121,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  122,  123,   -1,   -1,  124,   -1,
     125,   -1,  126,   -1,   -1,   -1,  127,   -1,
      -1,   -1,  128,   -1,   -1,  129,  130,   -1,
     131,   -1,  132,  133,   -1,   -1,   -1,   -1,
      -1,  134,   -1,   -1,  135,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  136,  137,   -1,  138,   -1,   -1,  139,
     140,   -1,   -1,   -1,  141,  142,  143,  144,
      -1,   -1,  145,  146,   -1,   -1,  147,   -1,
     148,   -1,   -1,  149,  150,   -1,   -1,   -1,
      -1,  151,   -1,   -1,   -1,  152,  153,   -1,
      -1,   -1,  154,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  155,  156,
      -1,   -1,   -1,   -1,  157,   -1,  158,  159,
      -1,  160,   -1,   -1,   -1,   -1,   -1,  161,
      -1,   -1,   -1,  162,  163,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  164,  165,  166,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     167,  168,   -1,   -1,   -1,  169,  170,   -1,
      -1,   -1,   -1,   -1,   -1,  171,  172,   -1,
      -1,   -1,   -1,  173,   -1,   -1,   -1,   -1,
      -1,  174,   -1,   -1,   -1,  175,  176,   -1,
      -1,   -1,   -1,  177,   -1,   -1,   -1,   -1,
     178,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     179,  180,  181,   -1,   -1,  182,   -1,   -1,
      -1,   -1,  183,  184,  185,   -1,   -1,   -1,
      -1,  186,   -1,   -1,   -1,  187,  188,  189,
      -1,   -1,   -1,   -1,  190,   -1,  191,  192,
      -1,  193,   -1,   -1,   -1,   -1,  194,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  195,  196,   -1,   -1,  197,
      -1,  198,   -1,   -1,   -1,   -1,   -1,  199,
      -1,   -1,  200,   -1,   -1,   -1,  201,  202,
      -1,   -1,   -1,   -1,   -1,  203,  204,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  205,  206,
     207,   -1,   -1,   -1,  208,  209,   -1,  210,
     211,  212,   -1,   -1,   -1,  213,   -1,   -1,
      -1,   -1,  214,   -1,   -1,   -1,   -1,  215,
      -1,   -1,   -1,   -1,  216,   -1,   -1,   -1,
      -1,   -1,  217,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  218,   -1,   -1,   -1,  219,   -1,   -1,
      -1,   -1,  220,   -1,   -1,   -1,  221,   -1,
      -1,   -1,   -1,   -1,  222,  223,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  224,   -1,
     225,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  226,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  227,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  228,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  229,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  230,
      -1,   -1,  231,   -1,  232,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  233,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  234,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  235,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     236,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  237,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  238,   -1,   -1,   -1,  239,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  240,  241,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  242,   -1,   -1,   -1,  243,   -1,
     244,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  245,   -1,  246,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  247,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  248,   -1,   -1,   -1,   -1,   -1,   -1,
     249,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  250,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  251,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  252,   -1,   -1,   -1,
      -1,  253,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     254,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  255,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  256,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     257,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  258
  };

#ifdef __GNUC__
__inline
#endif
const struct entity *
findEntity (register const char *str, register unsigned int len)
{
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register int index = lookup[key];

          if (index >= 0)
            {
              register const char *s = wordlist[index].name;

              if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
                return &wordlist[index];
            }
          else if (index < -TOTAL_KEYWORDS)
            {
              register int offset = - 1 - TOTAL_KEYWORDS - index;
              register const struct entity *wordptr = &wordlist[TOTAL_KEYWORDS + lookup[offset]];
              register const struct entity *wordendptr = wordptr + -lookup[offset + 1];

              while (wordptr < wordendptr)
                {
                  register const char *s = wordptr->name;

                  if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
                    return wordptr;
                  wordptr++;
                }
            }
        }
    }
  return 0;
}

