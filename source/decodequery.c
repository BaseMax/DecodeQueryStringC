/**
*
* @Name : DecodeQuery.c
* @Version : 1.0
* @Programmer : Max
* @Date : 2019-03-08
* @Released under : https://github.com/BaseMax/DecodeQueryStringC/blob/master/LICENSE
* @Repository : https://github.com/BaseMax/DecodeQueryStringC
*
**/
#include "decodequery.h"

static const char *const NamedEntities[][2] = {
	{ "AElig;","Æ" },
	{ "Aacute;","Á" },
	{ "Acirc;","Â" },
	{ "Agrave;","À" },
	{ "Alpha;","Α" },
	{ "Aring;","Å" },
	{ "Atilde;","Ã" },
	{ "Auml;","Ä" },
	{ "Beta;","Β" },
	{ "Ccedil;","Ç" },
	{ "Chi;","Χ" },
	{ "Dagger;","‡" },
	{ "Delta;","Δ" },
	{ "ETH;","Ð" },
	{ "Eacute;","É" },
	{ "Ecirc;","Ê" },
	{ "Egrave;","È" },
	{ "Epsilon;","Ε" },
	{ "Eta;","Η" },
	{ "Euml;","Ë" },
	{ "Gamma;","Γ" },
	{ "Iacute;","Í" },
	{ "Icirc;","Î" },
	{ "Igrave;","Ì" },
	{ "Iota;","Ι" },
	{ "Iuml;","Ï" },
	{ "Kappa;","Κ" },
	{ "Lambda;","Λ" },
	{ "Mu;","Μ" },
	{ "Ntilde;","Ñ" },
	{ "Nu;","Ν" },
	{ "OElig;","Œ" },
	{ "Oacute;","Ó" },
	{ "Ocirc;","Ô" },
	{ "Ograve;","Ò" },
	{ "Omega;","Ω" },
	{ "Omicron;","Ο" },
	{ "Oslash;","Ø" },
	{ "Otilde;","Õ" },
	{ "Ouml;","Ö" },
	{ "Phi;","Φ" },
	{ "Pi;","Π" },
	{ "Prime;","″" },
	{ "Psi;","Ψ" },
	{ "Rho;","Ρ" },
	{ "Scaron;","Š" },
	{ "Sigma;","Σ" },
	{ "THORN;","Þ" },
	{ "Tau;","Τ" },
	{ "Theta;","Θ" },
	{ "Uacute;","Ú" },
	{ "Ucirc;","Û" },
	{ "Ugrave;","Ù" },
	{ "Upsilon;","Υ" },
	{ "Uuml;","Ü" },
	{ "Xi;","Ξ" },
	{ "Yacute;","Ý" },
	{ "Yuml;","Ÿ" },
	{ "Zeta;","Ζ" },
	{ "aacute;","á" },
	{ "acirc;","â" },
	{ "acute;","´" },
	{ "aelig;","æ" },
	{ "agrave;","à" },
	{ "alefsym;","ℵ" },
	{ "alpha;","α" },
	{ "amp;","&" },
	{ "and;","∧" },
	{ "ang;","∠" },
	{ "apos;","'" },
	{ "aring;","å" },
	{ "asymp;","≈" },
	{ "atilde;","ã" },
	{ "auml;","ä" },
	{ "bdquo;","„" },
	{ "beta;","β" },
	{ "brvbar;","¦" },
	{ "bull;","•" },
	{ "cap;","∩" },
	{ "ccedil;","ç" },
	{ "cedil;","¸" },
	{ "cent;","¢" },
	{ "chi;","χ" },
	{ "circ;","ˆ" },
	{ "clubs;","♣" },
	{ "cong;","≅" },
	{ "copy;","©" },
	{ "crarr;","↵" },
	{ "cup;","∪" },
	{ "curren;","¤" },
	{ "dArr;","⇓" },
	{ "dagger;","†" },
	{ "darr;","↓" },
	{ "deg;","°" },
	{ "delta;","δ" },
	{ "diams;","♦" },
	{ "divide;","÷" },
	{ "eacute;","é" },
	{ "ecirc;","ê" },
	{ "egrave;","è" },
	{ "empty;","∅" },
	{ "emsp;","\xE2\x80\x83" },
	{ "ensp;","\xE2\x80\x82" },
	{ "epsilon;","ε" },
	{ "equiv;","≡" },
	{ "eta;","η" },
	{ "eth;","ð" },
	{ "euml;","ë" },
	{ "euro;","€" },
	{ "exist;","∃" },
	{ "fnof;","ƒ" },
	{ "forall;","∀" },
	{ "frac12;","½" },
	{ "frac14;","¼" },
	{ "frac34;","¾" },
	{ "frasl;","⁄" },
	{ "gamma;","γ" },
	{ "ge;","≥" },
	{ "gt;",">" },
	{ "hArr;","⇔" },
	{ "harr;","↔" },
	{ "hearts;","♥" },
	{ "hellip;","…" },
	{ "iacute;","í" },
	{ "icirc;","î" },
	{ "iexcl;","¡" },
	{ "igrave;","ì" },
	{ "image;","ℑ" },
	{ "infin;","∞" },
	{ "int;","∫" },
	{ "iota;","ι" },
	{ "iquest;","¿" },
	{ "isin;","∈" },
	{ "iuml;","ï" },
	{ "kappa;","κ" },
	{ "lArr;","⇐" },
	{ "lambda;","λ" },
	{ "lang;","〈" },
	{ "laquo;","«" },
	{ "larr;","←" },
	{ "lceil;","⌈" },
	{ "ldquo;","“" },
	{ "le;","≤" },
	{ "lfloor;","⌊" },
	{ "lowast;","∗" },
	{ "loz;","◊" },
	{ "lrm;","\xE2\x80\x8E" },
	{ "lsaquo;","‹" },
	{ "lsquo;","‘" },
	{ "lt;","<" },
	{ "macr;","¯" },
	{ "mdash;","—" },
	{ "micro;","µ" },
	{ "middot;","·" },
	{ "minus;","−" },
	{ "mu;","μ" },
	{ "nabla;","∇" },
	{ "nbsp;","\xC2\xA0" },
	{ "ndash;","–" },
	{ "ne;","≠" },
	{ "ni;","∋" },
	{ "not;","¬" },
	{ "notin;","∉" },
	{ "nsub;","⊄" },
	{ "ntilde;","ñ" },
	{ "nu;","ν" },
	{ "oacute;","ó" },
	{ "ocirc;","ô" },
	{ "oelig;","œ" },
	{ "ograve;","ò" },
	{ "oline;","‾" },
	{ "omega;","ω" },
	{ "omicron;","ο" },
	{ "oplus;","⊕" },
	{ "or;","∨" },
	{ "ordf;","ª" },
	{ "ordm;","º" },
	{ "oslash;","ø" },
	{ "otilde;","õ" },
	{ "otimes;","⊗" },
	{ "ouml;","ö" },
	{ "para;","¶" },
	{ "part;","∂" },
	{ "permil;","‰" },
	{ "perp;","⊥" },
	{ "phi;","φ" },
	{ "pi;","π" },
	{ "piv;","ϖ" },
	{ "plusmn;","±" },
	{ "pound;","£" },
	{ "prime;","′" },
	{ "prod;","∏" },
	{ "prop;","∝" },
	{ "psi;","ψ" },
	{ "quot;","\"" },
	{ "rArr;","⇒" },
	{ "radic;","√" },
	{ "rang;","〉" },
	{ "raquo;","»" },
	{ "rarr;","→" },
	{ "rceil;","⌉" },
	{ "rdquo;","”" },
	{ "real;","ℜ" },
	{ "reg;","®" },
	{ "rfloor;","⌋" },
	{ "rho;","ρ" },
	{ "rlm;","\xE2\x80\x8F" },
	{ "rsaquo;","›" },
	{ "rsquo;","’" },
	{ "sbquo;","‚" },
	{ "scaron;","š" },
	{ "sdot;","⋅" },
	{ "sect;","§" },
	{ "shy;","\xC2\xAD" },
	{ "sigma;","σ" },
	{ "sigmaf;","ς" },
	{ "sim;","∼" },
	{ "spades;","♠" },
	{ "sub;","⊂" },
	{ "sube;","⊆" },
	{ "sum;","∑" },
	{ "sup1;","¹" },
	{ "sup2;","²" },
	{ "sup3;","³" },
	{ "sup;","⊃" },
	{ "supe;","⊇" },
	{ "szlig;","ß" },
	{ "tau;","τ" },
	{ "there4;","∴" },
	{ "theta;","θ" },
	{ "thetasym;","ϑ" },
	{ "thinsp;","\xE2\x80\x89" },
	{ "thorn;","þ" },
	{ "tilde;","˜" },
	{ "times;","×" },
	{ "trade;","™" },
	{ "uArr;","⇑" },
	{ "uacute;","ú" },
	{ "uarr;","↑" },
	{ "ucirc;","û" },
	{ "ugrave;","ù" },
	{ "uml;","¨" },
	{ "upsih;","ϒ" },
	{ "upsilon;","υ" },
	{ "uuml;","ü" },
	{ "weierp;","℘" },
	{ "xi;","ξ" },
	{ "yacute;","ý" },
	{ "yen;","¥" },
	{ "yuml;","ÿ" },
	{ "zeta;","ζ" },
	{ "zwj;","\xE2\x80\x8D" },
	{ "zwnj;","\xE2\x80\x8C" }
};

static int stringCompare(const void *key,const void *value) {
	return strncmp(
				(const char *) key,
				*(const char *const *) value,
				strlen(*(const char *const *)value)
			);
}

static const char *getNamedEntity(const char *name) {
	const char *const *entity = (const char *const *)
			bsearch(
				name,
				NamedEntities,sizeof NamedEntities / sizeof *NamedEntities,
				sizeof *NamedEntities,stringCompare
			);
	return entity ? entity[1] : NULL;
}

static size_t putUtf8Char(unsigned long value,char *buffer) {
	unsigned char *bytes = (unsigned char *) buffer;
	if(value <= 0x007Ful) {
		bytes[0] = (unsigned char) value;
		return 1;
	}
	if(value <= 0x07FFul) {
		bytes[1] = (unsigned char)
						(
							(2 << 6) |
							(value & 0x3F)
						);
		bytes[0] = (unsigned char)
						(
							(6 << 5) |
							(value >> 6)
						);
		return 2;
	}
	if(value <= 0xFFFFul) {
		bytes[2] = (unsigned char)
						(
							(2 << 6) |
							(value & 0x3F)
						);
		bytes[1] = (unsigned char)
						(
							(2 << 6) |
							((value >> 6) & 0x3F)
						);
		bytes[0] = (unsigned char)
						(
							(14 << 4) |
							(value >> 12)
						);
		return 3;
	}
	if(value <= 0x10FFFFul) {
		bytes[3] = (unsigned char)
					(
						(2 << 6) |
						(value & 0x3F)
					);
		bytes[2] = (unsigned char)
					(
						(2 << 6) |
						((value >>  6) & 0x3F)
					);
		bytes[1] = (unsigned char)
					(
						(2 << 6) |
						((value >> 12) & 0x3F)
					);
		bytes[0] = (unsigned char)
					(
						(30 << 3) |
						(value >> 18)
					);
		return 4;
	}
	return 0;
}

static int parseEntity(const char *current,char **to,const char **from) {
	const char *end = strchr(current,59);
	if(!end) {
		return 0;
	}
	if(current[1] == 35) {
		char *tail = NULL;
		int errno_save = errno;
		int hex = current[2] == 120 || current[2] == 88;
		errno = 0;
		unsigned long cp = strtoul(current + (hex ? 3 : 2),&tail,hex ? 16 : 10);
		int fail = errno ||
				tail != end ||
				cp > 0x10FFFFul;
		errno = errno_save;
		if(fail) return 0;
		*to += putUtf8Char(cp,*to);
		*from = end + 1;
		return 1;
	}
	else {
		const char *entity = getNamedEntity(&current[1]);
		if(!entity) {
			return 0;
		}
		size_t len = strlen(entity);
		memcpy(*to,entity,len);
		*to += len;
		*from = end + 1;
		return 1;
	}
}

// 4bit
// const char asciiHex[23] = {
// 	0,
// 	1,
// 	2,
// 	3,
// 	4,
// 	5,
// 	6,
// 	7,
// 	8,
// 	9,
// 	0,
// 	0,
// 	0,
// 	0,
// 	0,
// 	0,
// 	0,
// 	10,
// 	11,
// 	12,
// 	13,
// 	14,
// 	15
// };

// static inline char toUpper(char c) {
// 	if((c >= 97) && (c <= 122)) {//a,z
// 		return c ^ 0x20;//fast way
// 	}
// 	return c;
// }

// char *urlDecode(const char *str) {
// 	size_t i,j,len = strlen(str);
// 	char c,d,url_hex;
// 	char *decoded = malloc(len + 1);
// 	if(decoded == NULL) {
// 		return NULL;
// 	}
// 	i = 0;
// 	j = 0;
// 	do {
// 		c = str[i];
// 		d = 0;
// 		if(c == 37) {
// 			url_hex = toUpper(str[++i]);
// 			if(
// 				(
// 					(url_hex >= 48) &&
// 					(url_hex <= 57)) ||
// 					((url_hex >= 65) && (url_hex <= 70))
// 				) {
// 				d = asciiHex[url_hex - 48] << 4;
// 				url_hex = toUpper(str[++i]);
// 				if(
// 					(
// 						(url_hex >= 48) && 
// 						(url_hex <= 57)
// 					) || 
// 					(
// 						(url_hex >= 65) &&
// 						(url_hex <= 70)
// 					)
// 				) {
// 					d |= asciiHex[url_hex - 48];
// 				}
// 				else {
// 					d = 0;
// 				}
// 			}
// 		}
// 		else if(c == 43) {
// 			d = 32;
// 		}
// 		else if(
// 			(c == 42) ||
// 			(c == 45) ||
// 			(c == 46) ||
// 			((c >= 48) && (c <= 57)) ||
// 			((c >= 65) && (c <= 90)) ||
// 			(c == 95) ||
// 			((c >= 97) && (c <= 122))
// 		) {
// 			d = c;
// 		}
// 		decoded[j++] = d;
// 		++i;
// 	}
// 	while((i < len) && (d != 0));
// 	decoded[j] = 0;
// 	return decoded;
// }

size_t decodeHtmlEntities(char *destination,const char *source) {
	if(!source) {
		source = destination;
	}
	char *to = destination;
	const char *from = source;
	for(const char *current;(current = strchr(from,38));) {//&
		memmove(to,from,(size_t)(current - from));
		to += current - from;
		if(parseEntity(current,&to,&from)) {
			continue;
		}
		from = current;
		*to++ = *from++;
	}
	size_t remaining = strlen(from);
	memmove(to,from,remaining);
	to += remaining;
	*to = 0;
	return (size_t)(to - destination);
}

void decodeUrl(char *destination,const char *source) {
	char x,y;
	while(*source) {
		if((*source == 37) &&//%
		((x = source[1]) && (y = source[2])) &&
		(isxdigit(x) && isxdigit(y))) {
			if(x >= 97) {
				x -= 32;//97,65
			}
			if(x >= 65) {
				x -= 55;//65
			}
			else {
				x -= 48;
			}
			if(y >= 97) {
				y -= 32;//97,65
			}
			if(y >= 65) {
				y -= 55;//65
			}
			else {
				y -= 48;
			}
			*destination++ = 16*x+y;
			source += 3;
		}
		else if(*source == 43) {
			*destination++ = 32;
			source++;
		}
		else {
			*destination++ = *source++;
		}
	}
	*destination++ = '\0';
}
