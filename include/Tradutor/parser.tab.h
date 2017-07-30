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
    MOVE = 320,
    ADDI = 321,
    ADDIU = 322,
    ANDI = 323,
    ORI = 324,
    XORI = 325,
    LUI = 326,
    SLTI = 327,
    SLTIU = 328,
    BEQ = 329,
    BGEZ = 330,
    BGEZAL = 331,
    BGTZ = 332,
    BLEZ = 333,
    BLTZAL = 334,
    BLTZ = 335,
    BNE = 336,
    TEQI = 337,
    TNEQ = 338,
    TGEI = 339,
    TGEIU = 340,
    TLTI = 341,
    TLTIU = 342,
    LB = 343,
    LBU = 344,
    LH = 345,
    LHU = 346,
    LW = 347,
    LWL = 348,
    LWR = 349,
    LL = 350,
    SB = 351,
    SH = 352,
    SW = 353,
    SWR = 354,
    SWL = 355,
    SC = 356,
    LI = 357,
    J = 358,
    JAL = 359,
    JALR = 360,
    JR = 361,
    DATA = 362,
    TEXT = 363,
    SECTION = 364,
    DPTS = 365,
    INT = 366,
    EOL = 367,
    COMMA = 368,
    GLOBL = 369,
    HEX_VAL = 370
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "parser.y" /* yacc.c:1909  */

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

#line 184 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
