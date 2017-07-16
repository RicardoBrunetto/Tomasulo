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
    NUMBER = 258,
    ADDRESS = 259,
    IDENTIFICADOR = 260,
    REG_S = 261,
    REG_AT = 262,
    REG_T = 263,
    REG_A = 264,
    REG_V = 265,
    REG_K = 266,
    REG_GP = 267,
    REG_SP = 268,
    REG_FP = 269,
    REG_RA = 270,
    REG_ZERO = 271,
    ADD = 272,
    ADDU = 273,
    AND = 274,
    CLO = 275,
    CLZ = 276,
    DIV = 277,
    DIVU = 278,
    MULT = 279,
    MULTU = 280,
    MUL = 281,
    MADD = 282,
    MADDU = 283,
    MSUB = 284,
    MSUBU = 285,
    NOR = 286,
    OR = 287,
    SLL = 288,
    SLLV = 289,
    SRA = 290,
    SRAV = 291,
    SRL = 292,
    SRLV = 293,
    SUB = 294,
    SUBU = 295,
    XOR = 296,
    SLT = 297,
    SLTU = 298,
    TEQ = 299,
    TNE = 300,
    TGE = 301,
    TGEU = 302,
    TLT = 303,
    TLTU = 304,
    MFHI = 305,
    MFLO = 306,
    MTHI = 307,
    MTLO = 308,
    MOVZ = 309,
    MOVF = 310,
    MOVT = 311,
    ERET = 312,
    SYSCALL = 313,
    BREAK = 314,
    NOP = 315,
    ADDI = 316,
    ADDIU = 317,
    ANDI = 318,
    ORI = 319,
    XORI = 320,
    LUI = 321,
    SLTI = 322,
    SLTIU = 323,
    BEQ = 324,
    BGEZ = 325,
    BGEZAL = 326,
    BGTZ = 327,
    BLEZ = 328,
    BLTZAL = 329,
    BLTZ = 330,
    BNE = 331,
    TEQI = 332,
    TNEQ = 333,
    TGEI = 334,
    TGEIU = 335,
    TLTI = 336,
    TLTIU = 337,
    LB = 338,
    LBU = 339,
    LH = 340,
    LHU = 341,
    LW = 342,
    LWL = 343,
    LWR = 344,
    LL = 345,
    SB = 346,
    SH = 347,
    SW = 348,
    SWR = 349,
    SWL = 350,
    SC = 351,
    J = 352,
    JAL = 353,
    JALR = 354,
    JR = 355,
    DATA = 356,
    TEXT = 357,
    SECTION = 358,
    DPTS = 359,
    INT = 360,
    EOL = 361,
    COMMA = 362
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "parser.y" /* yacc.c:1909  */

  struct R_type{
    char *opcode, *rd, *rs, *rt, *func, *shift;
  }instruction_R;
  struct J_type{
    char *opcode, *target;
  }instruction_J;
  struct I_type{
    char *opcode, *rs, *rt, *imm;
  }instruction_I;
  struct val{
    char ** numeros;
    int qtdNum;
  }num;
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
