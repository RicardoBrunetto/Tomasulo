%{
#include "parser.tab.h"
%}
%%

".section" { return SECTION; }
".data" { return DATA; }
".text" { return TEXT; }
".int" { return INT; }

"add" { return ADD; }
"addi" { return ADDI; }
"addiu" { return ADDIU; }
"and" { return AND; }
"andi" { return ANDI; }
"clo" { return CLO; }
"clz" { return CLZ; }
"div" { return DIV; }
"divu" { return DIVU; }
"mult" { return MULT; }
"multu" { return MULTU; }
"mul" { return MUL; }
"madd" { return MADD; }
"maddu" { return MADDU; }
"msub" { return MSUB; }
"msubu" { return MSUBU; }
"nor" { return NOR; }
"or" { return OR; }
"ori" { return ORI; }
"sll" { return SLL; }
"sllv" { return SLLV; }
"sra" { return SRA; }
"srav" { return SRAV; }
"srl" { return SRL; }
"srlv" { return SRLV; }
"sub" { return SUB; }
"subu" { return SUBU; }
"xor" { return XOR; }
"xori" { return XORI; }
"lui" { return LUI; }
"slt" { return SLT; }
"sltu" { return SLTU; }
"slti" { return SLTI; }
"sltiu" { return SLTIU; }
"beq" { return BEQ; }
"bgez" { return BGEZ; }
"bgezal" { return BGEZAL; }
"bgtz" { return BGTZ; }
"blez" { return BLEZ; }
"bltzal" { return BLTZAL; }
"bltz" { return BLTZ; }
"bne" { return BNE; }
"j" { return J; }
"jal" { return JAL; }
"jalr" { return JALR; }
"jr" { return JR; }
"teq" { return TEQ; }
"teqi" { return TEQI; }
"tne" { return TNE; }
"tneq" { return TNEQ; }
"tge" { return TGE; }
"tgeu" { return TGEU; }
"tgei" { return TGEI; }
"tgeiu" { return TGEIU; }
"tlt" { return TLT; }
"tltu" { return TLTU; }
"tlti" { return TLTI; }
"tltiu" { return TLTIU; }
"lb" { return LB; }
"lbu" { return LBU; }
"lh" { return LH; }
"lhu" { return LHU; }
"lw" { return LW; }
"lwl" { return LWL; }
"lwr" { return LWR; }
"ll" { return LL; }
"sb" { return SB; }
"sh" { return SH; }
"sw" { return SW; }
"swl" { return SWL; }
"swr" { return SWR; }
"sc" { return SC; }
"mfhi" { return MFHI; }
"mflo" { return MFLO; }
"mthi" { return MTHI; }
"mtlo" { return MTLO; }
"movz" { return MOVZ; }
"movf" { return MOVF; }
"movt" { return MOVT; }
"eret" { return ERET; }
"syscall" { return SYSCALL; }
"break" { return BREAK; }
"nop" { return NOP; }

"," { return COMMA; }
":" { return DPTS; }

"$"[s][0-7] { yylval.str = strdup(yytext); return REG_S; }
"$"[t][0-9] { yylval.str = strdup(yytext); return REG_T; }
"$"[a][0-3] { yylval.str = strdup(yytext); return REG_A; }
"$"[v][0-1] { yylval.str = strdup(yytext); return REG_V; }
"$"[k][0-1] { yylval.str = strdup(yytext); return REG_K; }
"$at" { return REG_AT; }
"$sp" { return REG_SP; }
"$fp" { return REG_FP; }
"$gp" { return REG_GP; }
"$ra" { return REG_RA; }
"$zero" { return REG_ZERO; }

[0-9]+ { yylval.str = strdup(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return IDENTIFICADOR; }
[\n]+ {return EOL;}
[ \t]
"#".*

. { /*printf("Mystery character %c\n", *yytext); */}
%%
