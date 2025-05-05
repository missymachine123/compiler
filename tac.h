/*
 * Three Address Code - skeleton for CSE 423
 */
#ifndef TAC_H
#define TAC_H

#define MAX_STRINGS 100
#define ALIGNMENT 8

struct addr {
  int region;
  union {
  int offset;
  char *name;
  float dval;
  } u;
};

struct string_table{
  char *strings[MAX_STRINGS];
  int offsets[MAX_STRINGS];
  int count;
  int total_bytes;
};

struct entry_list{
  char *name; 
  struct entry_list *next;
};
/* Regions: */
#define R_GLOBAL 2001 /* can assemble as relative to the pc */
#define R_LOCAL  2002 /* can assemble as relative to the ebp */
#define R_CLASS  2003 /* can assemble as relative to the 'this' register */
#define R_LABEL  2004 /* pseudo-region for labels in the code region */
#define R_CONST  2005 /* pseudo-region for immediate mode constants */
#define R_NAME   2006 /* pseudo-region for source names */
#define R_FLOAT 2007 /* pseudo-region for function load addresses */
#define R_STRING   2008 /* pseudo-region for strings*/

#define R_NONE   2009 /* pseudo-region for unused addresses */

struct instr {
   int opcode;
   struct addr dest, src1, src2;
   struct instr *next;
};
/* Opcodes, per lecture notes */
/*
 * Operation Codes (O_*)
 * ---------------------
 * O_ADD   : Addition operation.
 * O_SUB   : Subtraction operation.
 * O_MUL   : Multiplication operation.
 * O_DIV   : Division operation.
 * O_NEG   : Negation operation (unary minus).
 * O_ASN   : Assignment operation.
 * O_ADDR  : Address-of operation.
 * O_LCONT : Load content (dereference).
 * O_SCONT : Store content (dereference assignment).
 * O_GOTO  : Unconditional jump.
 * O_BLT   : Branch if less than.
 * O_BLE   : Branch if less than or equal.
 * O_BGT   : Branch if greater than.
 * O_BGE   : Branch if greater than or equal.
 * O_BEQ   : Branch if equal.
 * O_BNE   : Branch if not equal.
 * O_BIF   : Branch if condition is true.
 * O_BNIF  : Branch if condition is false.
 * O_PARM  : Pass parameter to a function.
 * O_CALL  : Function call.
 * O_RET   : Return from function.
 *
 * Declaration/Pseudo Instruction Codes (D_*)
 * -------------------------------------------
 * D_GLOB  : Global variable declaration.
 * D_PROC  : Procedure (function) declaration.
 * D_LOCAL : Local variable declaration.
 * D_LABEL : Label declaration.
 * D_END   : End of procedure or program.
 * D_PROT  : Prototype declaration.
 */
#define O_ADD   3001
#define O_SUB   3002
#define O_MUL   3003
#define O_DIV   3004
#define O_NEG   3005
#define O_ASN   3006
#define O_ADDR  3007
#define O_LCONT 3008
#define O_SCONT 3009
#define O_GOTO  3010
#define O_BLT   3011
#define O_BLE   3012
#define O_BGT   3013
#define O_BGE   3014
#define O_BEQ   3015
#define O_BNE   3016
#define O_BIF   3017
#define O_BNIF  3018
#define O_PARM  3019
#define O_CALL  3020
#define O_RET   3021
/* declarations/pseudo instructions */
#define D_GLOB  3051
#define D_PROC  3052
#define D_LOCAL 3053
#define D_LABEL 3054
#define D_END   3055
#define D_PROT  3056 /* prototype "declaration" */

struct instr *gen(int op, struct addr a1, struct addr a2, struct addr a3);
struct instr *concat(struct instr *, struct instr *);
char *regionname(int i);
char *opcodename(int i);
char *pseudoname(int i);
struct addr *genlabel();
struct addr *genvar(int region);
void printcode(struct instr *L);
void print_tcode(const char *filename, struct entry_list *global_entries, struct string_table *table);
 #endif
