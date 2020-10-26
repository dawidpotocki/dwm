/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static int showsystray              = 0;        /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int barpadding         = 10;
static const int barheight          = 14;       /* + font height */
static const char *fonts[]          = { "monospace:pixelsize=15", "Font Awesome 5 Free Solid:size=13" };
static const char *colors[][3]      = {
	/*                    fg         bg         border   */
	[SchemeNorm]     = { "#966bab", "#15191e", "#15191e" },  /* Unselected window */
	[SchemeSel]      = { "#966bab", "#2c2c38", "#966bab" },  /* Selected window */
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd3[] = {"keepassxc", "-name", "keepassxc-sp", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"keepassxc",   spcmd3},
};


/* tagging */
static const char *tags[] = { "1 ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10 " };

/* window rules */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                   instance         title    tag          float    monitor */

	/* Web (WS1) */
	{ "Chromium",              NULL,            NULL,    1 << 0,      0,       -1 },
	{ "Epiphany",              NULL,            NULL,    1 << 0,      0,       -1 },
	{ "Falkon",                NULL,            NULL,    1 << 0,      0,       -1 },
	{ "Firefox",               NULL,            NULL,    1 << 0,      0,       -1 },
	{ "Midori",                NULL,            NULL,    1 << 0,      0,       -1 },
	{ "qutebrowser",           NULL,            NULL,    1 << 0,      0,       -1 },
	{ "Tor Browser",           NULL,            NULL,    1 << 0,      0,       -1 },

	/* Code (WS2) */
	{ "Code - OSS",            NULL,            NULL,    1 << 1,      0,       -1 },

	/* Messages (WS4) */
	{ "discord",               NULL,            NULL,    1 << 3,      0,       -1 },
	{ "Element",               NULL,            NULL,    1 << 3,      0,       -1 },
	{ "Keybase",               NULL,            NULL,    1 << 3,      0,       -1 },
	{ "Signal",                NULL,            NULL,    1 << 3,      0,       -1 },
	{ "TelegramDesktop",       NULL,            NULL,    1 << 3,      0,       -1 },

	/* Mail (WS5) */
	{ NULL,                    "neomutt",       NULL,    1 << 4,      0,       -1 },
	{ "Thunderbird",           NULL,            NULL,    1 << 4,      0,       -1 },

	/* Documents (WS6) */
	{ "Evince",                NULL,            NULL,    1 << 5,      0,       -1 },
	{ "libreoffice",           NULL,            NULL,    1 << 5,      0,       -1 },
	{ "Zathura",               NULL,            NULL,    1 << 5,      0,       -1 },

	/* Graphics (WS7) */
	{ "Gimp",                  NULL,            NULL,    1 << 6,      0,       -1 },
	{ "Inkscape",              NULL,            NULL,    1 << 6,      0,       -1 },

	/* Games (WS8) */
	{ "airshipper",            NULL,            NULL,    1 << 7,      0,       -1 },
	{ "dolphin-emu",           NULL,            NULL,    1 << 7,      0,       -1 },
	{ "Minecraft",             NULL,            NULL,    1 << 7,      0,       -1 },
	{ "minecraft-launcher",    NULL,            NULL,    1 << 7,      0,       -1 },
	{ "MultiMC5",              NULL,            NULL,    1 << 7,      0,       -1 },
	{ "Quadrapassel",          NULL,            NULL,    1 << 7,      0,       -1 },
	{ "retroarch",             NULL,            NULL,    1 << 7,      0,       -1 },
	{ "Slippi",                NULL,            NULL,    1 << 7,      0,       -1 },
	{ "Steam",                 NULL,            NULL,    1 << 7,      0,       -1 },
	{ "supertuxkart",          NULL,            NULL,    1 << 7,      0,       -1 },
	{ "veloren-voxygen",       NULL,            NULL,    1 << 7,      0,       -1 },

	/* Music (WS9) */
	{ NULL,                    "ncmpcpp",       NULL,    1 << 8,      0,       -1 },
	{ "Rhythmbox",             NULL,            NULL,    1 << 8,      0,       -1 },

	/* Video (WS10) */
	{ "mpv",                 NULL,              NULL,    1 << 9,      0,       -1 },
	{ "obs",                 NULL,              NULL,    1 << 9,      0,       -1 },
	{ "vlc",                 NULL,              NULL,    1 << 9,      0,       -1 },

	{ NULL,                  "keepassxc-sp",    NULL,    SPTAG(0),    1,       -1 },
};

/* layout(s) */
static const float mfact     = 0.55;  /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;     /* number of clients in master area */
static const int resizehints = 0;     /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },     /* default */
	{ "[M]",      monocle },
	{ "()(",      NULL },     /* floating */
};

/*
 * key definitions
 */
#define Mod Mod4Mask
#define Alt Mod1Mask
#define Ctrl ControlMask
#define Shift ShiftMask

#define Tag(KEY,TAG) \
	{ Mod,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ Mod|Ctrl,                  KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ Mod|Shift,                 KEY,      tag,            {.ui = 1 << TAG} }, \
	{ Mod|Ctrl|Shift,            KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static Key keys[] = {
	/* modifier      key                 function           argument */

	/* layout */
	{ Mod,           XK_e,               setlayout,         {.v = &layouts[0]} },
	{ Mod,           XK_w,               setlayout,         {.v = &layouts[1]} },

	/* toggle */
	{ Mod,           XK_bracketright,    togglesystray,     {0} },
	{ Mod,           XK_s,               togglesticky,      {0} },
	{ Mod|Shift,     XK_space,           togglefloating,    {0} },
	{ Mod,           XK_b,               togglebar,         {0} },

	/* stack */
	{ Alt,           XK_Return,          zoom,              {0} },
	{ Alt,           XK_j,               focusstack,        {.i = +1 } },
	{ Alt,           XK_k,               focusstack,        {.i = -1 } },
	{ Mod|Shift,     XK_j,               movestack,         {.i = +1 } },
	{ Mod|Shift,     XK_k,               movestack,         {.i = -1 } },
	{ Mod,           XK_h,               setmfact,          {.f = -0.025} },
	{ Mod,           XK_l,               setmfact,          {.f = +0.025} },
	{ Mod,           XK_equal,           incnmaster,        {.i = +1 } },
	{ Mod,           XK_minus,           incnmaster,        {.i = -1 } },

	/* murderer */
	{ Mod|Shift,     XK_q,               killclient,        {0} },
	{ Mod|Shift,     XK_x,               quit,              {0} },

	/* tag */
	Tag(             XK_1,                                  0)
	Tag(             XK_2,                                  1)
	Tag(             XK_3,                                  2)
	Tag(             XK_4,                                  3)
	Tag(             XK_5,                                  4)
	Tag(             XK_6,                                  5)
	Tag(             XK_7,                                  6)
	Tag(             XK_8,                                  7)
	Tag(             XK_9,                                  8)
	Tag(             XK_0,                                  9)
	{ Mod,           XK_j,              shiftview,          {.i = +1 } },
	{ Mod,           XK_k,              shiftview,          {.i = -1 } },
	{ Mod,           XK_Tab,            view,               {0} },
	{ Mod,           XK_p,              togglescratch,      {.ui = 0 } },

	/* monitor */
	{ Alt|Shift,     XK_k,              focusmon,           {.i = +1 } },
	{ Alt|Shift,     XK_j,              focusmon,           {.i = -1 } },
	{ Mod|Shift,     XK_l,              tagmon,             {.i = +1 } },
	{ Mod|Shift,     XK_h,              tagmon,             {.i = -1 } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click           event mask    button      function           argument */
	{ ClkLtSymbol,     0,            Button1,    setlayout,         {0} },
	{ ClkLtSymbol,     0,            Button3,    setlayout,         {.v = &layouts[2]} },
	{ ClkClientWin,    Mod,          Button1,    movemouse,         {0} },
	{ ClkClientWin,    Mod,          Button2,    togglefloating,    {0} },
	{ ClkClientWin,    Mod,          Button3,    resizemouse,       {0} },
	{ ClkTagBar,       0,            Button1,    view,              {0} },
	{ ClkTagBar,       0,            Button3,    toggleview,        {0} },
	{ ClkTagBar,       Mod,          Button1,    tag,               {0} },
	{ ClkTagBar,       Mod,          Button3,    toggletag,         {0} },
};

/* vim: ft=c
 */
