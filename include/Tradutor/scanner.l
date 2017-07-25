%{
#include "parser.tab.h"
#define FLAG_ASSEMBLER 1
#define FLAG_DEFINER   0

char * mnemonico;
int state;
%}

%%

"#".*.[\n]
"," { return COMMA; }
":" { return DPTS; }
"&" { return ECOM; }
"(" { return ABRE_PAR; }
")" { return FECHA_PAR; }

".section" { return SECTION; }
".data" { return DATA; }
".text" { return TEXT; }
".int" { return INT; }

"add" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return ADD; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"addi" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return ADDI; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"addiu" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return ADDIU; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"and" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return AND; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"andi" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return ANDI; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"clo" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return CLO; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"clz" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return CLZ; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"div" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return DIV; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"divu" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return DIVU; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"mult" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return MULT; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"multu" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return MULTU; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"mul" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return MUL; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"madd" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return MADD; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"maddu" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return MADDU; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"msub" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return MSUB; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"msubu" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return MSUBU; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"nor" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return NOR; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"or" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return OR; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"ori" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return ORI; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"sll" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return SLL; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"sllv" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return SLLV; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"sra" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return SRA; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"srav" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return SRAV; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"srl" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return SRL; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"srlv" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return SRLV; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"sub" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return SUB; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"subu" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return SUBU; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"xor" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return XOR; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"xori" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return XORI; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"lui" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return LUI; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"slt" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return SLT; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"sltu" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return SLTU; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"slti" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return SLTI; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"sltiu" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return SLTIU; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"beq" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return BEQ; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"bgez" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return BGEZ; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"bgezal" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return BGEZAL; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"bgtz" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return BGTZ; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"blez" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return BLEZ; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"bltzal" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return BLTZAL; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"bltz" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return BLTZ; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"bne" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return BNE; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"j" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return J; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"jal" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return JAL; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"jalr" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return JALR; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"jr" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return JR; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"teq" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return TEQ; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"teqi" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return TEQI; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"tne" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return TNE; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"tneq" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return TNEQ; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"tge" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return TGE; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"tgeu" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return TGEU; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"tgei" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return TGEI; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"tgeiu" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return TGEIU; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"tlt" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return TLT; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"tltu" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return TLTU; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"tlti" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return TLTI; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"tltiu" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return TLTIU; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"lb" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return LB; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"lbu" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return LBU; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"lh" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return LH; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"lhu" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return LHU; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"lw" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return LW; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"lwl" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return LWL; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"lwr" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return LWR; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"ll" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return LL; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"sb" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return SB; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"sh" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return SH; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"sw" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return SW; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"swl" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return SWL; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"swr" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return SWR; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"sc" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return SC; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"mfhi" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return MFHI; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"mflo" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return MFLO; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"mthi" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return MTHI; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"mtlo" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return MTLO; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"movz" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return MOVZ; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"movn" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return MOVN; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"movf" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return MOVF; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"movt" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return MOVT; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"eret" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return ERET; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"syscall" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return SYSCALL; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"break" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return BREAK; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }
"nop" { if(state == FLAG_ASSEMBLER){ mnemonico = strdup(yytext); return NOP; }else{ yylval.str = strdup(yytext); return IDENTIFICADOR;} }

0[xX][0-9a-fA-F]+ { yylval.valor = strdup(yytext); return HEX_VAL; }

"$"[s][0-7] { yylval.valor = getNumber(yytext); return REG_S; }
"$"[t][0-9] { yylval.valor = getNumber(yytext); return REG_T; }
"$"[a][0-3] { yylval.valor = getNumber(yytext); return REG_A; }
"$"[v][0-1] { yylval.valor = getNumber(yytext); return REG_V; }
"$"[k][0-1] { yylval.valor = getNumber(yytext); return REG_K; }
"$at" { return REG_AT; }
"$sp" { return REG_SP; }
"$fp" { return REG_FP; }
"$gp" { return REG_GP; }
"$ra" { return REG_RA; }
"$zero" { return REG_ZERO; }

[0-9]+ { yylval.valor = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return IDENTIFICADOR; }
[\n]+ {return EOL;}
[ \t]

. { /*printf("Mystery character %c\n", *yytext); */}
%%
