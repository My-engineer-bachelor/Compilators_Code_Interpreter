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
extern YYSTYPE yylval;
