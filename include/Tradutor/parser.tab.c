/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/assembler.util.h"
#include "../definitions.h"

LinkedList lista;

int address = 0, secondPass = 0, dados_offset = START_ADDRESS_DATA, data_Bytes = 0;
char * error_msg = "Instrução não definida\n";

FILE* yyin;
char * mnemonico, *start_label;
int state, hasinserted = 0;

typedef struct{
  int numeros[10];
  int qtdNum;
}NumStruct;

NumStruct nstruct;


#line 91 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ABRE_PAR = 258,
    FECHA_PAR = 259,
    NUMBER = 260,
    ECOM = 261,
    ADDRESS = 262,
    IDENTIFICADOR = 263,
    REG_S = 264,
    REG_AT = 265,
    REG_T = 266,
    REG_A = 267,
    REG_V = 268,
    REG_K = 269,
    REG_GP = 270,
    REG_SP = 271,
    REG_FP = 272,
    REG_R = 273,
    REG_ZERO = 274,
    ADD = 275,
    ADDU = 276,
    AND = 277,
    CLO = 278,
    CLZ = 279,
    DIV = 280,
    DIVU = 281,
    MULT = 282,
    MULTU = 283,
    MUL = 284,
    MADD = 285,
    MOVN = 286,
    MADDU = 287,
    MSUB = 288,
    MSUBU = 289,
    NOR = 290,
    OR = 291,
    SLL = 292,
    SLLV = 293,
    SRA = 294,
    SRAV = 295,
    SRL = 296,
    SRLV = 297,
    SUB = 298,
    SUBU = 299,
    XOR = 300,
    SLT = 301,
    SLTU = 302,
    TEQ = 303,
    TNE = 304,
    TGE = 305,
    TGEU = 306,
    TLT = 307,
    TLTU = 308,
    MFHI = 309,
    MFLO = 310,
    MTHI = 311,
    MTLO = 312,
    MOVZ = 313,
    MOVF = 314,
    MOVT = 315,
    ERET = 316,
    SYSCALL = 317,
    BREAK = 318,
    NOP = 319,
    ADDI = 320,
    ADDIU = 321,
    ANDI = 322,
    ORI = 323,
    XORI = 324,
    LUI = 325,
    SLTI = 326,
    SLTIU = 327,
    BEQ = 328,
    BGEZ = 329,
    BGEZAL = 330,
    BGTZ = 331,
    BLEZ = 332,
    BLTZAL = 333,
    BLTZ = 334,
    BNE = 335,
    TEQI = 336,
    TNEQ = 337,
    TGEI = 338,
    TGEIU = 339,
    TLTI = 340,
    TLTIU = 341,
    LB = 342,
    LBU = 343,
    LH = 344,
    LHU = 345,
    LW = 346,
    LWL = 347,
    LWR = 348,
    LL = 349,
    SB = 350,
    SH = 351,
    SW = 352,
    SWR = 353,
    SWL = 354,
    SC = 355,
    J = 356,
    JAL = 357,
    JALR = 358,
    JR = 359,
    DATA = 360,
    TEXT = 361,
    SECTION = 362,
    DPTS = 363,
    INT = 364,
    EOL = 365,
    COMMA = 366,
    GLOBL = 367,
    HEX_VAL = 368
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "parser.y" /* yacc.c:355  */

  struct R_type{
    int opcode, rd, rs, rt, func, shift;
  }instruction_R;
  struct J_type{
    int opcode, target;
  }instruction_J;
  struct I_type{
    int opcode, rs, rt, imm;
  }instruction_I;
  int valor;
  char *str;

#line 259 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 276 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   666

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  114
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  425

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   368

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    61,    61,    62,    64,    66,    74,    75,    87,   100,
     101,   104,   106,   107,   109,   110,   112,   113,   115,   116,
     118,   129,   130,   132,   132,   134,   134,   134,   136,   137,
     139,   140,   142,   143,   150,   151,   152,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   191,   192,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ABRE_PAR", "FECHA_PAR", "NUMBER",
  "ECOM", "ADDRESS", "IDENTIFICADOR", "REG_S", "REG_AT", "REG_T", "REG_A",
  "REG_V", "REG_K", "REG_GP", "REG_SP", "REG_FP", "REG_R", "REG_ZERO",
  "ADD", "ADDU", "AND", "CLO", "CLZ", "DIV", "DIVU", "MULT", "MULTU",
  "MUL", "MADD", "MOVN", "MADDU", "MSUB", "MSUBU", "NOR", "OR", "SLL",
  "SLLV", "SRA", "SRAV", "SRL", "SRLV", "SUB", "SUBU", "XOR", "SLT",
  "SLTU", "TEQ", "TNE", "TGE", "TGEU", "TLT", "TLTU", "MFHI", "MFLO",
  "MTHI", "MTLO", "MOVZ", "MOVF", "MOVT", "ERET", "SYSCALL", "BREAK",
  "NOP", "ADDI", "ADDIU", "ANDI", "ORI", "XORI", "LUI", "SLTI", "SLTIU",
  "BEQ", "BGEZ", "BGEZAL", "BGTZ", "BLEZ", "BLTZAL", "BLTZ", "BNE", "TEQI",
  "TNEQ", "TGEI", "TGEIU", "TLTI", "TLTIU", "LB", "LBU", "LH", "LHU", "LW",
  "LWL", "LWR", "LL", "SB", "SH", "SW", "SWR", "SWL", "SC", "J", "JAL",
  "JALR", "JR", "DATA", "TEXT", "SECTION", "DPTS", "INT", "EOL", "COMMA",
  "GLOBL", "HEX_VAL", "$accept", "all", "general", "spec", "definitions",
  "eol", "assembly", "data_section", "text_section", "global_def",
  "variaveis", "variavel", "numeros", "nro", "nrorlabel", "comma",
  "lista_instrucoes", "label_decl", "instrucao", "instrucao_R",
  "instrucao_J", "instrucao_I", "reg", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368
};
# endif

#define YYPACT_NINF -158

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-158)))

#define YYTABLE_NINF -29

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,     3,  -158,    21,  -158,  -158,  -158,  -158,   -85,   -84,
    -158,   -84,  -102,    20,  -158,    19,    25,  -158,  -158,  -158,
     -79,  -158,    22,   -90,     7,   -78,   -84,   -76,    26,  -158,
      27,     2,    31,  -158,   -84,   -71,  -158,  -158,  -158,     0,
     -73,    10,    34,   -84,  -158,     2,    35,   -67,   562,  -158,
    -158,   -69,  -158,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,  -158,  -158,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,     1,     1,   177,   177,  -158,  -158,  -158,
    -158,     9,    37,   -84,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,  -158,  -158,  -158,  -158,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
    -158,  -158,  -158,  -158,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,  -158,  -158,  -158,  -158,  -158,   137,  -158,
     -84,    38,   -33,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,     2,   177,   177,   177,     1,     1,
       1,     1,     1,     1,   177,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,   177,    -1,   108,
     -68,   -68,   -68,  -158,  -158,  -158,  -158,  -158,   -68,   -68,
    -158,  -158,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,  -158,   -68,   -68,   -68,  -158,  -158,  -158,  -158,  -158,
    -158,   -68,   117,   119,   120,   121,   122,   123,   130,   154,
     155,   156,   157,   158,  -158,   159,    51,   177,   177,   177,
     177,   177,   177,   177,     2,   177,     2,   177,     2,   177,
     177,   177,   177,   177,   177,   177,     2,     2,     2,     2,
       2,     2,     2,     1,     1,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,  -158,   160,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,  -158,   162,   164,   166,
     168,   169,   170,   171,   172,   173,   174,   224,   230,    11,
      -3,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,  -158,  -158,   227,  -158,   231,    55,   -84,   126,   234,
     235,  -158,   237,  -158,   -84
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      12,     0,     9,     0,     2,     9,     3,     9,     0,    18,
       1,     6,    14,     0,    10,    13,     4,     9,    11,     9,
       0,     9,     0,    16,     0,     0,    19,     0,     0,     9,
       0,     0,     0,    17,    30,     0,    23,    24,     9,    21,
       0,    32,     0,    20,    29,     0,     0,     0,     0,     9,
      22,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,    34,    36,
      35,     0,     0,    33,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      64,    65,    66,    67,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    25,    27,    26,    72,    73,    62,    63,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    28,    28,    40,    41,    42,    43,    44,    28,    28,
      46,    47,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    79,    28,    28,    28,    83,    84,    85,    86,    87,
      88,    28,    91,    93,    95,    97,    99,   101,   103,   105,
     107,   109,   113,   111,    61,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,     0,    37,
      38,    39,    45,    68,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    69,    74,    75,
      76,    77,    78,    80,    81,    82,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    92,    94,    96,    98,   100,   102,   104,   106,
     108,   112,   110,     0,     9,     0,     0,     7,     0,     0,
       0,     5,     0,     9,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,  -158,  -158,  -158,  -158,    -5,  -158,  -158,  -158,  -158,
    -158,  -158,   197,  -157,  -111,   284,  -158,  -158,  -158,  -158,
    -158,  -158,    -6
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    16,     9,     6,     7,    18,    29,
      15,    21,    38,    39,   196,    45,    41,    48,   117,   118,
     119,   120,   135
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      11,   414,    12,   197,    17,   -28,   193,    36,    14,   194,
     -15,     8,    23,    30,    24,   201,    26,   413,    47,     1,
      14,    10,    28,    13,    34,    19,    14,    20,    22,    25,
      27,    31,    32,    43,    33,    35,    40,    42,    46,    49,
      51,    52,   122,    44,   121,   202,   258,   123,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   291,   259,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   315,   415,   198,
     199,    44,   200,   -28,   195,    37,   316,    14,     2,    14,
     345,    14,   346,   347,   348,   349,   350,   295,   296,   297,
     298,   299,   300,   351,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,   352,   353,   354,
     355,   356,   358,   419,   357,   400,   401,   366,   402,   368,
     403,   370,   404,   405,   406,   407,   408,   409,   410,   378,
     379,   380,   381,   382,   383,   384,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   411,   292,
     293,   294,   385,   386,   412,   416,   418,   420,   301,   421,
     422,   423,    50,     0,     0,     0,     0,     0,    44,     0,
       0,   314,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   359,   360,   361,   362,   363,   364,   365,     0,   367,
       0,   369,     0,   371,   372,   373,   374,   375,   376,   377,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,   399,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   417,
       0,     0,     0,     0,     0,     0,     0,     0,   424,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,     0,     0,     0,     0,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,     0,     0,     0,
       0,     0,   257,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   317,   318,   319,     0,     0,     0,
       0,     0,   320,   321,     0,     0,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,     0,   341,   342,   343,     0,
       0,     0,    53,    54,    55,   344,    56,    57,    58,    59,
      60,    61,     0,    62,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
       0,     0,     0,     0,     0,     0,    78,    79,    80,    81,
      82,     0,     0,     0,    83,     0,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,     0,   108,   109,   110,
     111,   112,     0,   113,   114,   115,   116
};

static const yytype_int16 yycheck[] =
{
       5,     4,     7,   114,   106,     5,     5,     5,   110,     8,
       0,     8,    17,     6,    19,     6,    21,     6,     8,     6,
     110,     0,   112,   108,    29,     5,   110,     8,     3,   108,
       8,   109,   108,    38,     8,     8,     5,   108,   111,     5,
       5,   108,   111,   111,    49,     8,     8,    52,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,   234,   111,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   108,   111,   115,
     116,   111,   117,   113,   113,   113,     8,   110,   105,   110,
       3,   110,     3,     3,     3,     3,     3,   238,   239,   240,
     241,   242,   243,     3,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     3,     3,     3,
       3,     3,   111,   108,     5,     5,     4,   324,     4,   326,
       4,   328,     4,     4,     4,     4,     4,     4,     4,   336,
     337,   338,   339,   340,   341,   342,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,     4,   235,
     236,   237,   343,   344,     4,     8,     5,   111,   244,     5,
       5,     4,    45,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   317,   318,   319,   320,   321,   322,   323,    -1,   325,
      -1,   327,    -1,   329,   330,   331,   332,   333,   334,   335,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,    -1,   357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   414,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   423,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   260,   261,   262,    -1,    -1,    -1,
      -1,    -1,   268,   269,    -1,    -1,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,    -1,   292,   293,   294,    -1,
      -1,    -1,    20,    21,    22,   301,    24,    25,    26,    27,
      28,    29,    -1,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,    57,
      58,    -1,    -1,    -1,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    99,    -1,   101,   102,   103,   104
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,   105,   115,   116,   117,   120,   121,     8,   119,
       0,   119,   119,   108,   110,   124,   118,   106,   122,     5,
       8,   125,     3,   119,   119,   108,   119,     8,   112,   123,
       6,   109,   108,     8,   119,     8,     5,   113,   126,   127,
       5,   130,   108,   119,   111,   129,   111,     8,   131,     5,
     126,     5,   108,    20,    21,    22,    24,    25,    26,    27,
      28,    29,    31,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    54,    55,
      56,    57,    58,    62,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    87,    88,    89,    90,    91,    92,    93,    95,    96,
      97,    98,    99,   101,   102,   103,   104,   132,   133,   134,
     135,   119,   111,   119,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,     5,     8,   113,   128,   128,   136,   136,
     119,     6,     8,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,     8,   111,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   127,   136,   136,   136,   128,   128,   128,   128,   128,
     128,   136,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   136,   108,     8,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     5,   111,   136,
     136,   136,   136,   136,   136,   136,   127,   136,   127,   136,
     127,   136,   136,   136,   136,   136,   136,   136,   127,   127,
     127,   127,   127,   127,   127,   128,   128,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   119,
       5,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,   111,     8,   119,     5,   108,
     111,     5,     5,     4,   119
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   114,   115,   115,   116,   117,   118,   118,   118,   119,
     119,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     125,   126,   126,   127,   127,   128,   128,   128,   129,   129,
     130,   130,   131,   131,   132,   132,   132,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   134,   134,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,    19,     0,    15,    19,     0,
       2,     3,     0,     3,     0,     5,     0,     2,     0,     3,
       5,     1,     3,     1,     1,     1,     1,     1,     0,     1,
       0,     4,     0,     3,     1,     1,     1,     6,     6,     6,
       4,     4,     4,     4,     4,     6,     4,     4,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     4,     2,     2,     2,     2,     2,     2,     6,     6,
       1,     1,     2,     2,     6,     6,     6,     6,     6,     4,
       6,     6,     6,     4,     4,     4,     4,     4,     4,     6,
       7,     4,     7,     4,     7,     4,     7,     4,     7,     4,
       7,     4,     7,     4,     7,     4,     7,     4,     7,     4,
       7,     4,     7,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 64 "parser.y" /* yacc.c:1646  */
    {show_config();}
#line 1677 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 66 "parser.y" /* yacc.c:1646  */
    {
        QUANTIDADE_ESTACOES_RESERVA_ADD = (yyvsp[-15].valor);
        QUANTIDADE_ESTACOES_RESERVA_MUL = (yyvsp[-10].valor);
        QUANTIDADE_ESTACOES_RESERVA_LOAD = (yyvsp[-5].valor);
        QUANTIDADE_ESTACOES_RESERVA_STORE = (yyvsp[0].valor);
        QUANTIDADE_ESTACOES_RESERVA = (yyvsp[-15].valor) + (yyvsp[-10].valor) + (yyvsp[-5].valor) + (yyvsp[0].valor);
      }
#line 1689 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 75 "parser.y" /* yacc.c:1646  */
    {
             Def * d = (Def *)malloc(sizeof(Def));
             d->mnemonic = (yyvsp[-12].str);
             d->opcode = (yyvsp[-10].valor);
             d->ciclos = (yyvsp[-8].valor);
             d->formato = get_formato_based((yyvsp[-6].str));
             d->tipo_uf = get_uf_based((yyvsp[-4].str));
             d->cessa_emissao = (yyvsp[-2].valor);
             d->function = FLAG_VAZIO; /*Não possuem Function*/
             d->abstract_opcode = (yyvsp[-10].valor); /*Não possuem Abstract Opcode*/
             insertLinkedList(&lista_definicoes, d);
           }
#line 1706 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 87 "parser.y" /* yacc.c:1646  */
    {
             Def * d = (Def *)malloc(sizeof(Def));
             d->mnemonic = (yyvsp[-16].str);
             d->opcode = (yyvsp[-14].valor);
             d->ciclos = (yyvsp[-12].valor);
             d->formato = get_formato_based((yyvsp[-10].str));
             d->tipo_uf = get_uf_based((yyvsp[-8].str));
             d->function = (yyvsp[-6].valor);
             d->abstract_opcode = (yyvsp[-4].valor);
             d->cessa_emissao = (yyvsp[-2].valor);
             insertLinkedList(&lista_definicoes, d);
           }
#line 1723 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 107 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1) insertNop(data_Bytes);}
#line 1729 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 113 "parser.y" /* yacc.c:1646  */
    {start_label = strdup((yyvsp[0].str));}
#line 1735 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 118 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 0){
                                                SLabel * var = (SLabel *)malloc(sizeof(SLabel));
                                                var->lbl_identificador = (yyvsp[-4].str);
                                                var->lbl_offset = dados_offset;
                                                insertLinkedList(&lista, var);
                                                dados_offset += (nstruct.qtdNum * WORD_SIZE);
                                                data_Bytes++;
                                              }else{
                                                setData(getOffset(&lista, (yyvsp[-4].str)), nstruct.numeros, nstruct.qtdNum);
                                              } nstruct.qtdNum = 0;}
#line 1750 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 129 "parser.y" /* yacc.c:1646  */
    {nstruct.numeros[nstruct.qtdNum] = (yyvsp[0].valor); nstruct.qtdNum = nstruct.qtdNum +1;}
#line 1756 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 130 "parser.y" /* yacc.c:1646  */
    {nstruct.numeros[nstruct.qtdNum] = (yyvsp[-2].valor); nstruct.qtdNum = nstruct.qtdNum +1;}
#line 1762 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 132 "parser.y" /* yacc.c:1646  */
    {(yyval.valor) = hex_to_dec((yyvsp[0].str));}
#line 1768 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 134 "parser.y" /* yacc.c:1646  */
    {(yyval.valor) = hex_to_dec((yyvsp[0].str));}
#line 1774 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 134 "parser.y" /* yacc.c:1646  */
    {(yyval.valor) = getOffset(&lista, (yyvsp[0].str));}
#line 1780 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 143 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 0){
                                      SLabel * label_found = (SLabel *)malloc(sizeof(SLabel));
                                      label_found->lbl_identificador = (yyvsp[-2].str);
                                      label_found->lbl_offset = address;
                                      insertLinkedList(&lista, label_found);
                                    }}
#line 1791 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 150 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ if(!hasinserted)setmain(); setInstruction_R((yyvsp[0].instruction_R).opcode, (yyvsp[0].instruction_R).rs, (yyvsp[0].instruction_R).rt, (yyvsp[0].instruction_R).rd, (yyvsp[0].instruction_R).shift, (yyvsp[0].instruction_R).func, address+=WORD_SIZE); }else{ address += WORD_SIZE; }}
#line 1797 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 151 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ if(!hasinserted)setmain(); setInstruction_I((yyvsp[0].instruction_I).opcode, (yyvsp[0].instruction_I).rs, (yyvsp[0].instruction_I).rt, (yyvsp[0].instruction_I).imm, address+=WORD_SIZE); }else{ address += WORD_SIZE; }}
#line 1803 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 152 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ if(!hasinserted)setmain(); setInstruction_J((yyvsp[0].instruction_J).opcode, (yyvsp[0].instruction_J).target, address+=WORD_SIZE); }else{ address += WORD_SIZE; }}
#line 1809 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 154 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-4].valor); (yyval.instruction_R).rs = (yyvsp[-2].valor); (yyval.instruction_R).rt = (yyvsp[0].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1815 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 155 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-4].valor); (yyval.instruction_R).rs = (yyvsp[-2].valor); (yyval.instruction_R).rt = (yyvsp[0].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1821 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 156 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-4].valor); (yyval.instruction_R).rs = (yyvsp[-2].valor); (yyval.instruction_R).rt = 0; (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1827 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 157 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-2].valor); (yyval.instruction_R).rs = (yyvsp[0].valor); (yyval.instruction_R).rt = 0; (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1833 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 158 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = 0; (yyval.instruction_R).rs = (yyvsp[-2].valor); (yyval.instruction_R).rt = (yyvsp[0].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1839 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 159 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = 0; (yyval.instruction_R).rs = (yyvsp[-2].valor); (yyval.instruction_R).rt = (yyvsp[0].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1845 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 160 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = 0; (yyval.instruction_R).rs = (yyvsp[-2].valor); (yyval.instruction_R).rt = (yyvsp[0].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1851 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 161 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = 0; (yyval.instruction_R).rs = (yyvsp[-2].valor); (yyval.instruction_R).rt = (yyvsp[0].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1857 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 162 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-4].valor); (yyval.instruction_R).rs = (yyvsp[-2].valor); (yyval.instruction_R).rt = (yyvsp[0].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1863 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 163 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = 0; (yyval.instruction_R).rs = (yyvsp[-2].valor); (yyval.instruction_R).rt = (yyvsp[0].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1869 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 164 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = 0; (yyval.instruction_R).rs = (yyvsp[-2].valor); (yyval.instruction_R).rt = (yyvsp[0].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1875 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 165 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-4].valor); (yyval.instruction_R).rs = (yyvsp[-2].valor); (yyval.instruction_R).rt = (yyvsp[0].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1881 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 166 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-4].valor); (yyval.instruction_R).rs = (yyvsp[-2].valor); (yyval.instruction_R).rt = (yyvsp[0].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1887 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 167 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-4].valor); (yyval.instruction_R).rs = 0; (yyval.instruction_R).rt = (yyvsp[-2].valor); (yyval.instruction_R).shift = (yyvsp[0].valor); (yyval.instruction_R).func = d->function;}}
#line 1893 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 168 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-4].valor); (yyval.instruction_R).rs = (yyvsp[0].valor); (yyval.instruction_R).rt = (yyvsp[-2].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1899 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 169 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-4].valor); (yyval.instruction_R).rs = 0; (yyval.instruction_R).rt = (yyvsp[-2].valor); (yyval.instruction_R).shift = (yyvsp[0].valor); (yyval.instruction_R).func = d->function;}}
#line 1905 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 170 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-4].valor); (yyval.instruction_R).rs = (yyvsp[0].valor); (yyval.instruction_R).rt = (yyvsp[-2].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1911 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 171 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-4].valor); (yyval.instruction_R).rs = 0; (yyval.instruction_R).rt = (yyvsp[-2].valor); (yyval.instruction_R).shift = (yyvsp[0].valor); (yyval.instruction_R).func = d->function;}}
#line 1917 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 172 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-4].valor); (yyval.instruction_R).rs = (yyvsp[0].valor); (yyval.instruction_R).rt = (yyvsp[-2].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1923 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 173 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-4].valor); (yyval.instruction_R).rs = (yyvsp[-2].valor); (yyval.instruction_R).rt = (yyvsp[0].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1929 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 174 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-4].valor); (yyval.instruction_R).rs = (yyvsp[-2].valor); (yyval.instruction_R).rt = (yyvsp[0].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1935 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 175 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-4].valor); (yyval.instruction_R).rs = (yyvsp[-2].valor); (yyval.instruction_R).rt = (yyvsp[0].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1941 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 176 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-4].valor); (yyval.instruction_R).rs = (yyvsp[-2].valor); (yyval.instruction_R).rt = (yyvsp[0].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1947 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 177 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-4].valor); (yyval.instruction_R).rs = (yyvsp[-2].valor); (yyval.instruction_R).rt = (yyvsp[0].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1953 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 178 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-2].valor); (yyval.instruction_R).rs = (yyvsp[0].valor); (yyval.instruction_R).rt = 0; (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1959 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 179 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = 31; (yyval.instruction_R).rs = (yyvsp[0].valor); (yyval.instruction_R).rt = 0; (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1965 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 180 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = 0; (yyval.instruction_R).rs = (yyvsp[0].valor); (yyval.instruction_R).rt = 0; (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1971 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 181 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[0].valor); (yyval.instruction_R).rs = 0; (yyval.instruction_R).rt = 0; (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1977 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 182 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[0].valor); (yyval.instruction_R).rs = 0; (yyval.instruction_R).rt = 0; (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1983 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 183 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = REG_HI; (yyval.instruction_R).rs = (yyvsp[0].valor); (yyval.instruction_R).rt = 0; (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1989 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 184 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = REG_LO; (yyval.instruction_R).rs = (yyvsp[0].valor); (yyval.instruction_R).rt = 0; (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 1995 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 185 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-4].valor); (yyval.instruction_R).rs = (yyvsp[-2].valor); (yyval.instruction_R).rt = (yyvsp[0].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 2001 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 186 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = (yyvsp[-4].valor); (yyval.instruction_R).rs = (yyvsp[-2].valor); (yyval.instruction_R).rt = (yyvsp[0].valor); (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 2007 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 187 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = 0; (yyval.instruction_R).rs = 2/*$v0*/; (yyval.instruction_R).rt = 4/*$a0*/; (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 2013 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 188 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_R).opcode = d->opcode; (yyval.instruction_R).rd = 0; (yyval.instruction_R).rs = 0; (yyval.instruction_R).rt = 0; (yyval.instruction_R).shift = 0; (yyval.instruction_R).func = d->function;}}
#line 2019 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 191 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_J).opcode = d->opcode; (yyval.instruction_J).target = (yyvsp[0].valor);}}
#line 2025 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 192 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_J).opcode = d->opcode; (yyval.instruction_J).target = (yyvsp[0].valor);}}
#line 2031 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 194 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-4].valor); (yyval.instruction_I).rs = (yyvsp[-2].valor); (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2037 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 195 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-4].valor); (yyval.instruction_I).rs = (yyvsp[-2].valor); (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2043 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 196 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-4].valor); (yyval.instruction_I).rs = (yyvsp[-2].valor); (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2049 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 197 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-4].valor); (yyval.instruction_I).rs = (yyvsp[-2].valor); (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2055 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 198 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-4].valor); (yyval.instruction_I).rs = (yyvsp[-2].valor); (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2061 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 199 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-2].valor); (yyval.instruction_I).rs = 0; (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2067 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 200 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-4].valor); (yyval.instruction_I).rs = (yyvsp[-2].valor); (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2073 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 201 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-4].valor); (yyval.instruction_I).rs = (yyvsp[-2].valor); (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2079 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 202 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-2].valor); (yyval.instruction_I).rs = (yyvsp[-4].valor); (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2085 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 203 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = d->function; (yyval.instruction_I).rs = (yyvsp[-2].valor); (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2091 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 204 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = d->function; (yyval.instruction_I).rs = (yyvsp[-2].valor); (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2097 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 205 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = 0; (yyval.instruction_I).rs = (yyvsp[-2].valor); (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2103 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 206 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = 0; (yyval.instruction_I).rs = (yyvsp[-2].valor); (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2109 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 207 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = d->function; (yyval.instruction_I).rs = (yyvsp[-2].valor); (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2115 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 208 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = d->function; (yyval.instruction_I).rs = (yyvsp[-2].valor); (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2121 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 209 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-2].valor); (yyval.instruction_I).rs = (yyvsp[-4].valor); (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2127 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 210 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-5].valor); (yyval.instruction_I).rs = (yyvsp[-1].valor); (yyval.instruction_I).imm = (yyvsp[-3].valor);}}
#line 2133 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 211 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-2].valor); (yyval.instruction_I).rs = 0; (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2139 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 212 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-5].valor); (yyval.instruction_I).rs = (yyvsp[-1].valor); (yyval.instruction_I).imm = (yyvsp[-3].valor);}}
#line 2145 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 213 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-2].valor); (yyval.instruction_I).rs = 0; (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2151 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 214 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-5].valor); (yyval.instruction_I).rs = (yyvsp[-1].valor); (yyval.instruction_I).imm = (yyvsp[-3].valor);}}
#line 2157 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 215 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-2].valor); (yyval.instruction_I).rs = 0; (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2163 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 216 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-5].valor); (yyval.instruction_I).rs = (yyvsp[-1].valor); (yyval.instruction_I).imm = (yyvsp[-3].valor);}}
#line 2169 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 217 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-2].valor); (yyval.instruction_I).rs = 0; (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2175 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 218 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-5].valor); (yyval.instruction_I).rs = (yyvsp[-1].valor); (yyval.instruction_I).imm = (yyvsp[-3].valor);}}
#line 2181 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 219 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-2].valor); (yyval.instruction_I).rs = 0; (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2187 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 220 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-5].valor); (yyval.instruction_I).rs = (yyvsp[-1].valor); (yyval.instruction_I).imm = (yyvsp[-3].valor);}}
#line 2193 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 221 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-2].valor); (yyval.instruction_I).rs = 0; (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2199 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 222 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-5].valor); (yyval.instruction_I).rs = (yyvsp[-1].valor); (yyval.instruction_I).imm = (yyvsp[-3].valor);}}
#line 2205 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 223 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-2].valor); (yyval.instruction_I).rs = 0; (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2211 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 224 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-5].valor); (yyval.instruction_I).rs = (yyvsp[-1].valor); (yyval.instruction_I).imm = (yyvsp[-3].valor);}}
#line 2217 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 225 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-2].valor); (yyval.instruction_I).rs = 0; (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2223 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 226 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-5].valor); (yyval.instruction_I).rs = (yyvsp[-1].valor); (yyval.instruction_I).imm = (yyvsp[-3].valor);}}
#line 2229 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 227 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-2].valor); (yyval.instruction_I).rs = 0; (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2235 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 228 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-5].valor); (yyval.instruction_I).rs = (yyvsp[-1].valor); (yyval.instruction_I).imm = (yyvsp[-3].valor);}}
#line 2241 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 229 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-2].valor); (yyval.instruction_I).rs = 0; (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2247 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 230 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-5].valor); (yyval.instruction_I).rs = (yyvsp[-1].valor); (yyval.instruction_I).imm = (yyvsp[-3].valor);}}
#line 2253 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 231 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-2].valor); (yyval.instruction_I).rs = 0; (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2259 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 232 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-5].valor); (yyval.instruction_I).rs = (yyvsp[-1].valor); (yyval.instruction_I).imm = (yyvsp[-3].valor);}}
#line 2265 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 233 "parser.y" /* yacc.c:1646  */
    {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); (yyval.instruction_I).opcode = d->opcode; (yyval.instruction_I).rt = (yyvsp[-2].valor); (yyval.instruction_I).rs = 0; (yyval.instruction_I).imm = (yyvsp[0].valor);}}
#line 2271 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 235 "parser.y" /* yacc.c:1646  */
    { (yyval.valor) = get_indice_reg(0, (yyvsp[0].valor)); }
#line 2277 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 236 "parser.y" /* yacc.c:1646  */
    { (yyval.valor) = 1; }
#line 2283 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 237 "parser.y" /* yacc.c:1646  */
    { (yyval.valor) = get_indice_reg(1, (yyvsp[0].valor)); }
#line 2289 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 238 "parser.y" /* yacc.c:1646  */
    { (yyval.valor) = get_indice_reg(2, (yyvsp[0].valor)); }
#line 2295 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 239 "parser.y" /* yacc.c:1646  */
    { (yyval.valor) = (yyvsp[0].valor) == 0 ? 2 : 3; }
#line 2301 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 240 "parser.y" /* yacc.c:1646  */
    { (yyval.valor) = (yyvsp[0].valor) == 0 ? 26 : 27; }
#line 2307 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 241 "parser.y" /* yacc.c:1646  */
    {(yyval.valor) = 28;}
#line 2313 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 242 "parser.y" /* yacc.c:1646  */
    {(yyval.valor) = 29;}
#line 2319 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 243 "parser.y" /* yacc.c:1646  */
    {(yyval.valor) = 30;}
#line 2325 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 244 "parser.y" /* yacc.c:1646  */
    {(yyval.valor) =  31;}
#line 2331 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 245 "parser.y" /* yacc.c:1646  */
    {(yyval.valor) = 0;}
#line 2337 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2341 "parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 246 "parser.y" /* yacc.c:1906  */


void setmain(){
  Def * d = get_def_mnemonico("j");
  if(d==NULL) yyerror(error_msg);
  int opcode = d->opcode; int target = getOffset(&lista, start_label);
  if(target != 0)
    setInstruction_J(opcode, target, address+=WORD_SIZE);
  hasinserted = 1;
}

void call_tradutor(FILE *f){
  state = FLAG_ASSEMBLER;
  nstruct.qtdNum = 0;
  inicializarLista(&lista);
  secondPass = 0;
  if(f == NULL){
    yyerror("Arquivo invalido para o tradutor!");
    return;
  }

  yyrestart(f);
  yyparse();

  print_lista_labels(&lista);

  secondPass = 1;
  system("mkdir -p output/");
  output = fopen("output/output", "w+");

  rewind(f);
  yyparse();


  fclose(output);
}

int get_uf_based(char * uf){
  if(!strcmp(uf, "ADD_UF"))
      return ADD_UF;
  else if(!strcmp(uf, "MUL_UF"))
      return MUL_UF;
  else if(!strcmp(uf, "LOAD_UF"))
      return LOAD_UF;
  else if(!strcmp(uf, "STORE_UF"))
      return STORE_UF;
  else
      yyerror("TIPO INVÁLIDO DE UNIDADE FUNCIONAL");
}

int get_formato_based(char * formato){
  if(!strcmp(formato, "TYPE_R"))
      return TYPE_R;
  else if(!strcmp(formato, "TYPE_J"))
      return TYPE_J;
  else if(!strcmp(formato, "TYPE_I"))
      return TYPE_I;
  else
      yyerror("TIPO INVÁLIDO DE INSTRUÇÃO");
}

int run_definitions(){
  state = FLAG_DEFINER;
  inicializarLista(&lista_definicoes);
  yyin = fopen("include/def_file.txt", "r");
  do {
		yyparse();
	} while (!feof(yyin));
  fclose(yyin);
}

int yyerror(char *s) {
  fprintf(stderr, "\nerror: %s\n", s);
  exit(0);
}
