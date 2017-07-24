/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    REG_RA = 273,
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
    MADDU = 286,
    MSUB = 287,
    MSUBU = 288,
    NOR = 289,
    OR = 290,
    SLL = 291,
    SLLV = 292,
    SRA = 293,
    SRAV = 294,
    SRL = 295,
    SRLV = 296,
    SUB = 297,
    SUBU = 298,
    XOR = 299,
    SLT = 300,
    SLTU = 301,
    TEQ = 302,
    TNE = 303,
    TGE = 304,
    TGEU = 305,
    TLT = 306,
    TLTU = 307,
    MFHI = 308,
    MFLO = 309,
    MTHI = 310,
    MTLO = 311,
    MOVZ = 312,
    MOVF = 313,
    MOVT = 314,
    ERET = 315,
    SYSCALL = 316,
    BREAK = 317,
    NOP = 318,
    ADDI = 319,
    ADDIU = 320,
    ANDI = 321,
    ORI = 322,
    XORI = 323,
    LUI = 324,
    SLTI = 325,
    SLTIU = 326,
    BEQ = 327,
    BGEZ = 328,
    BGEZAL = 329,
    BGTZ = 330,
    BLEZ = 331,
    BLTZAL = 332,
    BLTZ = 333,
    BNE = 334,
    TEQI = 335,
    TNEQ = 336,
    TGEI = 337,
    TGEIU = 338,
    TLTI = 339,
    TLTIU = 340,
    LB = 341,
    LBU = 342,
    LH = 343,
    LHU = 344,
    LW = 345,
    LWL = 346,
    LWR = 347,
    LL = 348,
    SB = 349,
    SH = 350,
    SW = 351,
    SWR = 352,
    SWL = 353,
    SC = 354,
    J = 355,
    JAL = 356,
    JALR = 357,
    JR = 358,
    DATA = 359,
    TEXT = 360,
    SECTION = 361,
    DPTS = 362,
    INT = 363,
    EOL = 364,
    COMMA = 365,
    HEX_VAL = 366
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "parser.y" /* yacc.c:1909  */

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

#line 180 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
