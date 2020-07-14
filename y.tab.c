/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "port.y"
#include <stdio.h>
#include <stdlib.h>
#include "estrutura.c"
void yyerror(char *msg);
extern int yylex();
#line 8 "port.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
	int iValue;
	char id;
	struct treeNode *node;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 40 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define num 264
#define var 265
#define print 266
#define whilestmt 267
#define start_program 268
#define end_program 269
#define GE 270
#define LE 271
#define E 272
#define NE 273
#define DECL 274
#define OR 275
#define AND 276
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    5,    5,    4,    4,    4,    4,    7,    6,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    2,    2,    2,    3,    3,    3,    3,
};
static const YYINT yylen[] = {                            2,
    3,    2,    1,    3,    1,    1,    7,    4,    4,    2,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    1,    3,    3,    1,    3,    1,    2,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    3,    0,    6,    5,    0,
    0,    0,    0,   26,   28,    0,    0,    0,   24,    0,
    1,    2,    0,    0,    0,   27,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    4,    0,    0,
    0,    8,    9,   25,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   22,   23,    0,    0,    0,    7,
};
static const YYINT yydgoto[] = {                          2,
   17,   18,   19,    6,    7,    8,    9,
};
static const YYINT yysindex[] = {                      -255,
 -188,    0,  -58,   55,  -17,    0, -162,    0,    0,   55,
   55,   55, -227,    0,    0,   55,    6,  -32,    0,   55,
    0,    0,   13,   24,   31,    0,  -14,   55,   55,  -39,
  -39,   55,   55,   55,   55,   55,   55,    0,  -39,  -39,
   -1,    0,    0,    0,   42,   42,  -32,  -32,   31,   31,
   31,   31,   31,   31,    0,    0,  -80, -188, -120,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -41,    0,    0,
    0,    0,    0,    0,  -29,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -27,   -7,  -34,  -21,   -5,    4,
   21,   23,   30,   40,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   86,   78,  -23,    1,  -11,    0,    0,
};
#define YYTABLESIZE 320
static const YYINT yytable[] = {                         21,
   16,   21,   11,   21,   60,   13,   19,   22,   19,   39,
   19,   10,    1,   18,   40,   55,   56,   21,   21,   20,
   21,   20,   20,   20,   19,   19,   44,   19,   30,   10,
   31,   18,   18,   17,   18,   13,   26,   20,   20,   57,
   20,   30,   58,   31,   14,   28,   59,   29,   30,    0,
   31,   17,   17,   13,   17,   30,    0,   31,   28,   22,
   29,   15,   14,   16,   38,   28,   30,   29,   31,    0,
   12,   42,   28,   30,   29,   31,    3,    4,    5,   15,
   11,   16,   43,   28,   30,   29,   31,   12,   12,    0,
   28,    0,   29,    0,   16,   23,   24,   25,   11,   13,
    0,   27,    3,    4,    5,   41,   21,   47,   48,    0,
    0,    0,    0,   45,   46,    0,    0,   49,   50,   51,
   52,   53,   54,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    3,    4,    5,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   10,    0,    0,    0,    0,
    0,    0,    0,    0,   14,   15,    0,    0,   21,   21,
   21,   21,    0,   21,   21,   19,   19,   19,   19,    0,
   19,   19,    0,    0,    0,    0,    0,    0,   20,   20,
   20,   20,    0,   20,   20,   32,   33,   34,   35,    0,
   36,   37,    0,    0,    0,    0,    0,    0,   32,   33,
   34,   35,    0,   36,   37,   32,   33,   34,   35,    0,
   36,   37,   32,   33,   34,   35,    0,   36,   37,    0,
    0,    0,    0,   32,   33,   34,   35,    0,   36,   37,
   32,   33,   34,   35,    0,   36,   37,    0,    0,    0,
    0,   32,   33,   34,   35,    0,   36,   37,   14,   15,
};
static const YYINT yycheck[] = {                         41,
   40,   43,   61,   45,  125,   45,   41,    7,   43,   42,
   45,   41,  268,   41,   47,   39,   40,   59,   60,   41,
   62,   43,   40,   45,   59,   60,   41,   62,   43,   59,
   45,   59,   60,   41,   62,   41,  264,   59,   60,   41,
   62,   43,  123,   45,   41,   60,   58,   62,   43,   -1,
   45,   59,   60,   59,   62,   43,   -1,   45,   60,   59,
   62,   41,   59,   41,   59,   60,   43,   62,   45,   -1,
   41,   59,   60,   43,   62,   45,  265,  266,  267,   59,
   41,   59,   59,   60,   43,   62,   45,   33,   59,   -1,
   60,   -1,   62,   -1,   40,   10,   11,   12,   59,   45,
   -1,   16,  265,  266,  267,   20,  269,   30,   31,   -1,
   -1,   -1,   -1,   28,   29,   -1,   -1,   32,   33,   34,
   35,   36,   37,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  265,  266,  267,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  274,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  264,  265,   -1,   -1,  270,  271,
  272,  273,   -1,  275,  276,  270,  271,  272,  273,   -1,
  275,  276,   -1,   -1,   -1,   -1,   -1,   -1,  270,  271,
  272,  273,   -1,  275,  276,  270,  271,  272,  273,   -1,
  275,  276,   -1,   -1,   -1,   -1,   -1,   -1,  270,  271,
  272,  273,   -1,  275,  276,  270,  271,  272,  273,   -1,
  275,  276,  270,  271,  272,  273,   -1,  275,  276,   -1,
   -1,   -1,   -1,  270,  271,  272,  273,   -1,  275,  276,
  270,  271,  272,  273,   -1,  275,  276,   -1,   -1,   -1,
   -1,  270,  271,  272,  273,   -1,  275,  276,  264,  265,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 276
#define YYUNDFTOKEN 286
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"\":=\"","\"&&\"","\"||\"","\">=\"","\"<=\"","\"==\"",
"\"!=\"","num","var","print","whilestmt","start_program","end_program","GE",
"LE","E","NE","DECL","OR","AND",0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : start_program stmts end_program",
"stmts : stmts stmt",
"stmts : stmt",
"stmt : print exp ';'",
"stmt : declaration",
"stmt : assign",
"stmt : whilestmt '(' exp ')' '{' stmts '}'",
"declaration : var DECL exp ';'",
"assign : var '=' exp ';'",
"exp : '!' exp",
"exp : exp AND exp",
"exp : exp OR exp",
"exp : exp GE exp",
"exp : exp LE exp",
"exp : exp E exp",
"exp : exp NE exp",
"exp : exp '>' exp",
"exp : exp '<' exp",
"exp : exp '+' term",
"exp : exp '-' term",
"exp : term",
"term : term '*' factor",
"term : term '/' factor",
"term : factor",
"factor : '(' exp ')'",
"factor : num",
"factor : '-' num",
"factor : var",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 81 "port.y"

void yyerror(char *msg){
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

int main(){
	linkedList = createLinkedList();	
	return yyparse();
}
#line 296 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 35 "port.y"
	{execute(yystack.l_mark[-1].node); exit(1);}
break;
case 2:
#line 38 "port.y"
	{yyval.node = buildNodeStmt(STMT, 2, yystack.l_mark[-1].node, yystack.l_mark[0].node);}
break;
case 3:
#line 39 "port.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 4:
#line 42 "port.y"
	{yyval.node = buildNodeStmt(PRINT, 1, yystack.l_mark[-1].node);}
break;
case 5:
#line 43 "port.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 6:
#line 44 "port.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 7:
#line 45 "port.y"
	{yyval.node = buildNodeStmt(WHILE, 2, yystack.l_mark[-4].node,yystack.l_mark[-1].node);}
break;
case 8:
#line 48 "port.y"
	{
					yyval.node = buildNodeStmt(DECLARATION, 2, buildNodeId(yystack.l_mark[-3].id), yystack.l_mark[-1].node);
				}
break;
case 9:
#line 53 "port.y"
	{yyval.node = buildNodeStmt(ASSIGN, 2, buildNodeId(yystack.l_mark[-3].id), yystack.l_mark[-1].node);}
break;
case 10:
#line 55 "port.y"
	{yyval.node = buildNodeStmt(NAO, 1, yystack.l_mark[0].node);}
break;
case 11:
#line 56 "port.y"
	{yyval.node = buildNodeStmt(E, 2, yystack.l_mark[-2].node, yystack.l_mark[0].node);}
break;
case 12:
#line 57 "port.y"
	{yyval.node = buildNodeStmt(OU, 2, yystack.l_mark[-2].node, yystack.l_mark[0].node);}
break;
case 13:
#line 58 "port.y"
	{yyval.node = buildNodeStmt(MAIOR_IGUAL, 2, yystack.l_mark[-2].node, yystack.l_mark[0].node);}
break;
case 14:
#line 59 "port.y"
	{yyval.node = buildNodeStmt(MENOR_IGUAL, 2, yystack.l_mark[-2].node, yystack.l_mark[0].node);}
break;
case 15:
#line 60 "port.y"
	{yyval.node = buildNodeStmt(IGUAL, 2, yystack.l_mark[-2].node, yystack.l_mark[0].node);}
break;
case 16:
#line 61 "port.y"
	{yyval.node = buildNodeStmt(DIFERENTE, 2, yystack.l_mark[-2].node, yystack.l_mark[0].node);}
break;
case 17:
#line 62 "port.y"
	{yyval.node = buildNodeStmt(MAIOR, 2, yystack.l_mark[-2].node, yystack.l_mark[0].node);}
break;
case 18:
#line 63 "port.y"
	{yyval.node = buildNodeStmt(MENOR, 2, yystack.l_mark[-2].node, yystack.l_mark[0].node);}
break;
case 19:
#line 64 "port.y"
	{yyval.node = buildNodeStmt(SUM, 2, yystack.l_mark[-2].node, yystack.l_mark[0].node);}
break;
case 20:
#line 65 "port.y"
	{yyval.node = buildNodeStmt(SUB, 2, yystack.l_mark[-2].node, yystack.l_mark[0].node);}
break;
case 21:
#line 66 "port.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 22:
#line 69 "port.y"
	{yyval.node = buildNodeStmt(MULT, 2, yystack.l_mark[-2].node, yystack.l_mark[0].node);}
break;
case 23:
#line 70 "port.y"
	{yyval.node = buildNodeStmt(DIV, 2, yystack.l_mark[-2].node, yystack.l_mark[0].node);}
break;
case 24:
#line 71 "port.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 25:
#line 74 "port.y"
	{yyval.node = yystack.l_mark[-1].node;}
break;
case 26:
#line 75 "port.y"
	{yyval.node = buildNodeConst(yystack.l_mark[0].iValue);}
break;
case 27:
#line 76 "port.y"
	{yyval.node = buildNodeConst(-yystack.l_mark[0].iValue);}
break;
case 28:
#line 77 "port.y"
	{yyval.node = buildNodeId(yystack.l_mark[0].id);}
break;
#line 612 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
