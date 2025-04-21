/*
 * Three Address Code - skeleton for CS 423
 */
#include <stdio.h>
#include <stdlib.h>
#include "tac.h"
#include "tree.h"
#include "k0gram.tab.h"

char *regionnames[] = {"global","loc", "class", "lab", "const", "", "none"};
char *regionname(int i) { return regionnames[i-R_GLOBAL]; }
char *opcodenames[] = {
   "ADD","SUB", "MUL", "DIV", "NEG", "ASN", "ADDR", "LCONT", "SCONT", "GOTO",
   "BLT", "BLE", "BGT", "BGE", "BEQ", "BNE", "BIF", "BNIF", "PARM", "CALL",
   "RETURN"
   };
char *opcodename(int i) { return opcodenames[i-O_ADD]; }
char *pseudonames[] = {
   "glob","proc", "loc", "lab", "end", "prot"
   };
char *pseudoname(int i) { return pseudonames[i-D_GLOB]; }

int labelcounter;

/**
 * @brief Generates a new label address.
 *
 * This function creates a new label address by allocating memory for an
 * `addr` structure, setting its region to `R_LABEL`, and assigning it a
 * unique offset using a label counter. The function also prints the
 * generated label to the standard output.
 *
 * @return A pointer to the newly created label address.
 */
struct addr *genlabel()
{
   // Allocate memory for a new address structure.
   struct addr *a = malloc(sizeof(struct addr));
   if (a == NULL) {
       // Print an error message and exit if memory allocation fails.
       fprintf(stderr, "out of memory\n");
       exit(4);
   }

   // Set the region to R_LABEL and assign a unique offset.
   a->region = R_LABEL;
   a->u.offset = labelcounter++;
   
   // Print the generated label to the standard output.
   printf("generated a label %d\n", a->u.offset);
   
   return a; // Return the newly created label address.
}
void assign_first(struct tree *t)
{
   int i;
   for(i=0; i<t->nkids; i++) assign_first(t->kids[i]);
   switch(t->prodrule) {
      /* Add cases that require a label */
      case 1011://ifExpression
      case 1073: //while, for ,do while  
         t->first = genlabel();
         break;
      default:
         t->first = NULL; // No label needed for other cases
         break;
   }
}
/**
 * @brief Generates a new instruction with the specified opcode and operands.
 *
 * This function allocates memory for a new instruction, initializes its fields
 * with the provided opcode and operand addresses, and sets the `next` pointer
 * to NULL. If memory allocation fails, the program prints an error message
 * and exits with a status code of 4.
 *
 * @param op The opcode for the instruction.
 * @param a1 The destination address for the instruction.
 * @param a2 The first source address for the instruction.
 * @param a3 The second source address for the instruction.
 *
 * @return A pointer to the newly created instruction.
 */
struct instr *gen(int op, struct addr a1, struct addr a2, struct addr a3)
{
   // Allocate memory for a new instruction.
   struct instr *rv = malloc(sizeof(struct instr));
   if (rv == NULL) {
       // Print an error message and exit if memory allocation fails.
       fprintf(stderr, "out of memory\n");
       exit(4);
   }
   
   // Initialize the instruction fields with the provided values.
   rv->opcode = op;
   rv->dest = a1;
   rv->src1 = a2;
   rv->src2 = a3;
   rv->next = NULL; // Set the next pointer to NULL.
   
   return rv; // Return the newly created instruction.
}

/**
 * @brief Creates a deep copy of a linked list of instructions.
 *
 * This function takes a linked list of instructions and recursively creates
 * a new linked list that is a deep copy of the original. Each instruction
 * in the list is duplicated, including its opcode, destination, and source
 * operands. The `next` pointer of each instruction is also recursively copied.
 *
 * @param l Pointer to the head of the linked list of instructions to be copied.
 *          If the input list is NULL, the function returns NULL.
 *
 * @return A pointer to the head of the newly created linked list that is a
 *         deep copy of the input list. If the input list is NULL, returns NULL.
 */
struct instr *copylist(struct instr *l)
{
   if (l == NULL) return NULL;
   struct instr *lcopy = gen(l->opcode, l->dest, l->src1, l->src2);
   lcopy->next = copylist(l->next);
   return lcopy;
}

// Appends two instruction lists together.
// If the first list (l1) is NULL, it simply returns the second list (l2).
// Otherwise, it traverses the first list to its end and links it to the second list.
struct instr *append(struct instr *l1, struct instr *l2)
{
   if (l1 == NULL) return l2; // If the first list is empty, return the second list.
   struct instr *ltmp = l1;   // Temporary pointer to traverse the first list.
   while(ltmp->next != NULL)  // Traverse to the end of the first list.
       ltmp = ltmp->next;
   ltmp->next = l2;           // Link the end of the first list to the second list.
   return l1;                 // Return the combined list.
}

struct instr *concat(struct instr *l1, struct instr *l2)
{
   return append(copylist(l1), l2);
}
