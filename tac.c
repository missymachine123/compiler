/*
 * Three Address Code - skeleton for CS 423
 */
#include <stdio.h>
#include <stdlib.h>
#include "tac.h"
#include "tree.h"
#include "k0gram.tab.h"
#include <string.h>
#include "symtab.h"

struct token {
   int category;   /* the integer code returned by yylex */
   char *text;     /* the actual string (lexeme) matched */
   int lineno;     /* the line number on which the token occurs */
   char *filename; /* the source file in which the token occurs */
   int ival;       /* for integer constants, store binary value here */
   double dval;	   /* for real constants, store binary value here */
   char *sval;     /* for string constants, malloc space, de-escape, store */
                   /*    the string (less quotes and after escapes) here */
};
void printnode(struct tree *t);

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
int local_offset;
int global_offset;
int temp_offset;
int str_offset;

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
//    printf("generated a label %d\n", a->u.offset);
   
   return a; // Return the newly created label address.
}
struct addr *genvar(int region) {
   struct addr *a = malloc(sizeof(struct addr));
   if (!a) {
       fprintf(stderr, "Memory allocation failed\n");
       exit(1);
   }

   a->region = region;

   switch(region) {
       case R_GLOBAL:
           a->u.offset = global_offset;
           global_offset += 8;  // Assume 8 bytes per variable
           break;
       case R_LOCAL:
           a->u.offset = local_offset;
           local_offset += 8;
           break;
       // case R_PARAM:
       //     a->u.offset = param_offset;
       //     param_offset += 8;
       //     break; 
       case R_CONST:
           //a->u.offset = temp_offset++;
           break;
        case R_STRING:
              a->u.offset = str_offset;
              str_offset += 8; // Assume 8 bytes for string
              break;
       case R_FLOAT:
            break;
       default:
           fprintf(stderr, "Unknown region\n");
           free(a);
           exit(4);
   }

   return a;
}

void assign_first(struct tree *t)
{
   
   if (t == NULL) return;
   int i;
   for(i=0; i<t->nkids; i++) assign_first(t->kids[i]);
   switch(t->prodrule) {
      /* Add cases that require a label */
      case 1067://ifExpression
      case 2020: //while
      case 2021: //for
      case 2022: //dowhile
      case 1016:
      case 1086: //expression
      case 1087:        
      case 1088:
      case 1089: //equality operations
      case 1074:
      case 1015: //statements:  optional_statement_sequence
         t->first = genlabel();
         t->firstflag = true;
         break; 
      default:
         t->first = NULL; // No label needed for other cases
         break;
   }
}
void assign_follow(struct tree *t) {
    if (t == NULL) return;
    int i;
    
    switch(t->prodrule) { 
        case 1012: 
            if (t->kids[1]->follow != NULL){
                t->kids[1]->follow = genlabel();
            }
            else if(t->kids[1] == NULL) {
                t->first = genlabel(); // Set follow for the first child
            }
            break;
        case 1013:
        
            t->kids[2]->follow = t->follow;
            // if (t->kids[2] != NULL) {
            //     t->kids[0]->follow = t->kids[2]->first; // Set follow for the first child
            // } 
            break;
        case 1014: // statement sequence
            t->follow = genlabel();
            if (t->kids[1]) {
                t->kids[0]->follow = t->kids[1]->kids[2]->first;  
                t->kids[0]->followFlag = true;
                t->kids[1]->follow = t->follow; // Set follow for the second child
                t->kids[1]->followFlag = true;
                t->kids[1]->kids[2]->follow = t->follow; // Set follow for the second child's first child
                t->kids[1]->kids[2]->followFlag = true;
            } else {
                t->kids[0]->follow = t->follow;
                t->kids[0]->followFlag = true;
            }
            break;
        case 1015:
            t->follow = genlabel();
            if (t->kids[0]) { 
                t->kids[0]->follow = t->follow;
            }
            break; 
            
            
        case 1067: { // If Expression
            if (t->kids[4] != NULL) {
                t->kids[4]->follow = t->follow;
                t->kids[4]->followFlag = true;
            }
            if (t->kids[5] != NULL && t->kids[5]->nkids > 1 && t->kids[5]->kids[1] != NULL) {
                t->kids[5]->kids[1]->follow = t->follow;
                t->kids[5]->kids[1]->followFlag = true;
            }
            break;
        }
            
        case 2020: { // While Statement
            if (t->kids[4] != NULL && t->kids[2] != NULL) {
                t->kids[4]->follow = t->kids[2]->first;
                t->kids[4]->followFlag = true;
            }
            printf("Follow information:\n");
            printf("Node: %p, Follow: %p, FollowFlag: %d\n", t, t->follow, t->followFlag);
            break;
        }
            
        case 2021: { // For Statement
            if (t->kids[6] != NULL && t->kids[4] != NULL) {
                t->kids[6]->follow = t->kids[4]->first;
                t->kids[6]->followFlag = true;
            }
            break;
        }
            
        case 2022: { // Do-While Statement
            if (t->kids[1] != NULL && t->kids[4] != NULL) {
                t->kids[1]->follow = t->kids[4]->first;
                t->kids[1]->followFlag = true;
            }
            break;
        }

        case 1073: { // loopStatement
            if (t->kids[0] != NULL) {
                t->kids[0]->follow = t->follow;
                t->kids[0]->followFlag = true;
            }
            break;
        }
        
            
        default:
            // No special follow handling for other cases
            break;
    }
     
    for(i = 0; i < t->nkids; i++) {
        assign_follow(t->kids[i]);
    }
}void assign_onTrue_onFalse(struct tree *t) {
    if (t == NULL) return;
    
    switch(t->prodrule) {
        case 1067: { // If Expression
            t->kids[2]->onTrue = t->kids[4]->first;  // jump to then part
            t->kids[2]->onTrueFlag = true;
            
            if (t->kids[5]) { // else exists
                t->kids[2]->onFalse = t->kids[5]->kids[1]->first;
            } else {
                t->kids[2]->onFalse = t->follow;  // no else, jump to follow
            }
            t->kids[2]->onFalseFlag = true;
            break;
        }

        case 1087://disjunction || conjunction

        if (t->nkids == 3){
            t->kids[0]->onTrue = t->onTrue;
            t->kids[0]->onTrueFlag = true;
            t->kids[0]->onFalse = t->kids[2]->first;  // EqExpr.onFalse = AndExpr1.first;
            t->kids[2]->onTrue = t->onTrue;  // AndExpr1.onTrue = EqExpr.onTrue;
            t->kids[2]->onTrueFlag = true;
            t->kids[2]->onFalse = t->onFalse;  // AndExpr1.onFalse = EqExpr.onFalse;
            t->kids[0]->onFalseFlag = true;
        }
        break;
        case 1088: // conjunction && equality
        if (t->nkids == 3){
            t->kids[0]->onTrue = t->kids[2]->first;  // AndExpr1.onTrue = EqExpr.first;
            t->kids[0]->onTrueFlag = true;
            t->kids[0]->onFalse = t->onFalse;  // AndExpr1.onFalse = follow
            t->kids[2]->onTrue = t->onTrue;  //  EqExpr.onTrue = AndExpr.onTrue;
            t->kids[2]->onTrueFlag = true;
            t->kids[2]->onFalse = t->onFalse;  // EqExpr.onFalse = AndExpr.onFalse;
            t->kids[0]->onFalseFlag = true; 
        }
        break;
            
        case 2020: { // While Statement
            t->kids[2]->onTrue = t->kids[4]->kids[0]->first;  // condition true: enter body
            t->kids[2]->onTrueFlag = true;
            struct tree *current = t->kids[2];
            while (current != NULL && current->nkids != 3) {
                current = current->kids[0]; // Traverse down the left child

            if (current != NULL) {
                current->onTrue = t->kids[4]->kids[0]->first;  // Set onTrue to the loop body
                current->onTrueFlag = true;
            }}
            t->kids[2]->onFalse = t->follow;        // condition false: exit loop
            t->kids[2]->onFalseFlag = true;
            break;
        }
            
        case 2021: { // For Statement
            t->kids[4]->onTrue = t->kids[6]->first;  // condition true: enter body
            t->kids[4]->onTrueFlag = true;
            t->kids[4]->onFalse = t->follow;        // condition false: exit loop
            t->kids[4]->onFalseFlag = true;
            break;
        }
            
        case 2022: { // Do-While Statement
            t->kids[4]->onTrue = t->kids[1]->first;  // condition true: repeat body
            t->kids[4]->onTrueFlag = true;
            t->kids[4]->onFalse = t->follow;        // condition false: exit loop
            t->kids[4]->onFalseFlag = true;
            break;
        }
    }
    
    // Recursively process children
    for (int i = 0; i < t->nkids; i++) {
        assign_onTrue_onFalse(t->kids[i]);
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
/**
 * @brief Creates a copy of a single instruction.
 *
 * This function takes a single instruction and creates a new instruction
 * that is a copy of the original. The fields of the new instruction are
 * initialized to match the original instruction, and the `next` pointer
 * is set to NULL.
 *
 * @param instr The instruction to be copied.
 * @return A pointer to the newly created instruction.
 */
struct instr *copyinstr(struct instr *instr) {
    if (instr == NULL) return NULL;

    // Allocate memory for the new instruction
    struct instr *copy = malloc(sizeof(struct instr));
    if (copy == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(4);
    }

    // Copy the fields from the original instruction
    copy->opcode = instr->opcode;
    copy->dest = instr->dest;
    copy->src1 = instr->src1;
    copy->src2 = instr->src2;
    copy->next = NULL; // Ensure the next pointer is NULL

    return copy;
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

void print_addr(struct addr a) {
   switch (a.region) {
       case R_NAME:   printf("%s", a.u.name); break;
       case R_GLOBAL: printf("global:%d", a.u.offset); break;
       case R_LOCAL:  printf("loc:%d", a.u.offset); break;
       case R_CONST:  printf("const:%d", a.u.offset); break;
       case R_FLOAT:  printf("float:%f", a.u.dval); break;
       case R_STRING:  printf("str:%d", a.u.offset); break;
       case R_PARAM:  printf("%d", a.u.offset); break;
       case R_LABEL:  printf("%d", a.u.offset); break;
       default:       printf("?(%d)", a.u.offset); break;
   }
}
const char *opcode_to_string(int opcode) {
   switch (opcode) {
       case O_ADD: return "add";
       case O_SUB: return "sub";
       case O_MUL: return "mul";
       case O_DIV: return "div";
       case O_NEG: return "neg";
       case O_ASN: return "asn";
       case O_ADDR: return "addr";
       case O_LCONT: return "lcont";
       case O_SCONT: return "scont";
       case O_GOTO: return "goto";
       case O_BLT: return "blt";
       case O_BLE: return "ble";
       case O_BGT: return "bgt";
       case O_BGE: return "bge";
       case O_BEQ: return "beq";
       case O_BNE: return "bne";
       case O_BIF: return "bif";
       case O_BNIF: return "bnif";
       case O_PARM: return "parm";
       case O_CALL: return "call";
       case O_RET: return "ret";
       case D_GLOB: return "glob";
       case D_PROC: return "proc";
       case D_LOCAL: return "local";
       case D_LABEL: return "label";
       case D_END: return "end";
       case D_PROT: return "prot";
       default: return "???";
   }
}

void printcode(struct instr *L) {
    struct instr *p = L; 
         printf("%s ", opcode_to_string(p->opcode));
         if (p->dest.region != R_NONE) {
              print_addr(p->dest);
         }
         if (p->src1.region != R_NONE) {
              printf(", ");
              print_addr(p->src1);
         }
         if (p->src2.region != R_NONE) {
              printf(", ");
              print_addr(p->src2);
         }
         printf("\n");
 
    
}

int operator_to_opcode(char *op) {
    if (strcmp(op, "+") == 0) return O_ADD;
    else if (strcmp(op, "-") == 0) return O_SUB;
    else if (strcmp(op, "*") == 0) return O_MUL;
    else if (strcmp(op, "/") == 0) return O_DIV;
    else if (strcmp(op, "==") == 0) return O_BEQ;
    else if (strcmp(op, "!=") == 0) return O_BNE;
    else if (strcmp(op, "<") == 0) return O_BLT;
    else if (strcmp(op, "<=") == 0) return O_BLE;
    else if (strcmp(op, ">") == 0) return O_BGT;
    else if (strcmp(op, ">=") == 0) return O_BGE;
    else {
        printf("Unknown operator: %s\n", op);
        return -1; // or some invalid opcode
    }
}
void assignaddr(struct tree *t){
   if (t==NULL) return;

}
extern SymbolTable current; // Current symbol table
extern SymbolTable globals; // Global symbol table
struct tree *find_leaf(struct tree *t, int category) ; 
struct instr *tcode_head = NULL;
struct instr *tcode_tail = NULL;

void add_to_tcode(struct instr *new_instr) {
    if (new_instr == NULL) {
        fprintf(stderr, "Error: Attempted to add a NULL instruction to tcode.\n");
        return;
    }
    if (tcode_head == NULL) {
        // If the list is empty, initialize head and tail
        tcode_head = new_instr;
        tcode_tail = new_instr;
    } else {
        // If new_instr contains multiple instructions, traverse to its tail
        struct instr *current = new_instr;
        while (current->next != NULL) {
            current = current->next;
        }
        // Append the new instructions to the tail of tcode
        tcode_tail->next = new_instr;
        tcode_tail = current;
    }
}
void print_icode(struct instr *icode) {
    if (icode == NULL) {
        printf("No intermediate code to print.\n");
        return;
    }
 
    struct instr *current = icode;
    while (current != NULL) {
        printf("%s ", opcode_to_string(current->opcode));
        if (current->dest.region != R_NONE) {
            print_addr(current->dest);
        }
        if (current->src1.region != R_NONE) {
            printf(", ");
            print_addr(current->src1);
        }
        if (current->src2.region != R_NONE) {
            printf(", ");
            print_addr(current->src2);
        }
        printf("\n");
        current = current->next;
    }
}
void print_tcode(const char *filename, struct entry_list *global_entries, struct string_table *table) {
    printf(".file\t\"%s\"\n", filename); // Print the file name at the beginning

    if (table != NULL) {
        //fprintf(stderr, "Error: String table is NULL.\n");
        //return;
        printf(".string %d\n", table->total_bytes);
        for (int i = 0; i < table->count; i++) {
            // Optionally escape % signs for printf-style
            printf("\t");
            for (char *p = table->strings[i]; *p; p++) {
                putchar(*p);
            }
            printf("\\000\n");
        }
    }
    struct instr *current = tcode_head;
    while (current != NULL) {
        if (current->dest.region == R_CONST) {
            printf("const:%d\n", current->dest.u.offset);
        }
        current = current->next;
    }
 
    // Ensure global_entries is defined and initialized before use
    if (global_entries != NULL) {
        // Print global entries in a single line
        printf(".data\n");
        struct entry_list *entry = global_entries;
        while (entry != NULL) {
            printf("\t%s", entry->name);
            entry = entry->next;
        }
        printf("\n");
    } else {
        printf(".data\n");
    }


    printf(".code\n");
    current = tcode_head;
    while (current != NULL) {
        if (current->opcode != D_PROC || (current->dest.region != R_NAME && current->dest.region != R_LABEL)) {
            printf("\t");
        }
        printf("%s ", opcode_to_string(current->opcode));
        if (current->dest.region != R_NONE) {
            print_addr(current->dest);
        }
        if (current->src1.region != R_NONE) {
            printf(", ");
            print_addr(current->src1);
        }
        if (current->src2.region != R_NONE) {
            printf(", ");
            print_addr(current->src2);
        }
        printf("\n");
        current = current->next;
    }
}
void initStringTable(struct string_table *table) {
    table->count = 0;
    table->total_bytes = 0;
  }
  
int addString(struct string_table *table, const char *s) {
    for (int i = 0; i < table->count; i++) {
        if (strcmp(table->strings[i], s) == 0) {
            return table->offsets[i];
        }
    }

    // Allocate and store the new string
    table->strings[table->count] = strdup(s);
    table->offsets[table->count] = table->total_bytes;

    // Update total size (align to 8 bytes)
    int len = strlen(s) + 1; // include null terminator
    int aligned_len = ((len + ALIGNMENT - 1) / ALIGNMENT) * ALIGNMENT;
    table->total_bytes += aligned_len;

    return table->offsets[table->count++];
}

void print_child_icode(struct tree *t) {
    if (t == NULL) {
        printf("Node is NULL.\n");
        return;
    }

    printf("Printing child icode for node with id %d :\n", t->id);
    for (int i = 0; i < t->nkids; i++) {
        if (t->kids[i] != NULL) {
            printf("Child %d:\n", i);
            if (t->kids[i]->icode != NULL) {
                printcode(t->kids[i]->icode); // Use printcode to display the instruction list
            } else {
                printf("Child %d has no icode.\n", i);
            }
            print_child_icode(t->kids[i]); // Recursively go down all the way
        } else {
            printf("Child %d is NULL.\n", i);
        }
    }
}

void codegen(struct tree *t)
{
    int i, j;
    int opcode_operator;
    if (t == NULL) return;
    switch (t->prodrule) {
        case 1004: {
            for (i = 0; i < t->nkids; i++) {
                if (t->kids[i] != NULL && t->kids[i]->leaf != NULL && t->kids[i]->leaf->category == 407) {
                    char *function_name = t->kids[i]->leaf->text;
                    struct instr *function = gen(D_PROC, *t->address, (struct addr){R_NONE}, (struct addr){R_NONE});
                    add_to_tcode(function);
                }
            }
            break;
        }
         
    
    }
    /*
     * this is a post-order traversal, so visit children first
     */
    for (i = 0; i < t->nkids; i++)
        codegen(t->kids[i]);

    /*
     * back from children, consider what we have to do with
     * this node. The main thing we have to do, one way or
     * another, is assign t->code
     */
    switch (t->prodrule) {
        case 1011: //functionBody
            if (t->nkids == 1) { // block : { statements }
                t->icode = concat(t->kids[0]->kids[1]->icode, gen(D_LABEL, *t->kids[0]->kids[1]->follow, (struct addr){R_NONE}, (struct addr){R_NONE}));
                // add_to_tcode(t->icode);
                t->icode = concat(t->icode, gen(O_RET, (struct addr){R_NONE}, (struct addr){R_NONE}, (struct addr){R_NONE}));
                // add_to_tcode(t->icode);
            }
            break;
    
        case 1043: { // Assignment with operators like =, +=, -=, *=, /=
            t->address = t->kids[0]->kids[0]->kids[0]->address; // Assignment.addr = IDENT.addr
    
            // Determine the operator
            char *operator = t->kids[0]->kids[1]->leaf->text;
    
            if (strcmp(operator, "=") == 0) {
                  // Simple assignment
                  struct instr *assign = gen(O_ASN, *t->address, *t->kids[1]->address, (struct addr){R_NONE});
                  t->icode = concat(t->kids[1]->icode, assign);
                  add_to_tcode(assign);
                  
            } else if (strcmp(operator, "+=") == 0 || strcmp(operator, "-=") == 0 ||
                           strcmp(operator, "*=") == 0 || strcmp(operator, "/=") == 0) {
                  // Compound assignment (+=, -=, *=, /=)
                  int opcode_operator;
                  if (strcmp(operator, "+=") == 0) opcode_operator = O_ADD;
                  else if (strcmp(operator, "-=") == 0) opcode_operator = O_SUB;
                  else if (strcmp(operator, "*=") == 0) opcode_operator = O_MUL;
                  else if (strcmp(operator, "/=") == 0) opcode_operator = O_DIV;
    
                  // Generate a temporary variable to store the result
                  struct addr *temp = genvar(R_LOCAL);
    
                  // Generate the computation instruction
                  struct instr *compute = gen(opcode_operator, *temp, *t->address, *t->kids[1]->address);
                  add_to_tcode(compute);
    
                  // Generate the assignment instruction
                  struct instr *assign = gen(O_ASN, *t->address, *temp, (struct addr){R_NONE});
                  add_to_tcode(assign);
    
                  // Concatenate the instructions
                  t->icode = concat(t->kids[1]->icode, compute);
                  t->icode = concat(t->icode, assign);
            } else {
                  fprintf(stderr, "Unsupported operator: %s\n", operator);
                  exit(1);
            }
            break;
       } 

    case 1015:
        if (t->kids[0] == NULL){
        // StatementList.icode = gen(LABEL, StatementList.first) || gen(NOOP)
        t->icode = gen(D_LABEL, *t->first, 
            (struct addr){R_NONE}, 
            (struct addr){R_NONE});
            // add_to_tcode(t->icode);
        t->icode = concat(t->icode, 
            gen(R_NONE, (struct addr){R_NONE}, 
                (struct addr){R_NONE}, 
                (struct addr){R_NONE}));        }
    case 1014:
        if (t->kids[1] != NULL) { // statement sequence
            t->icode = concat(t->kids[0]->icode,t->kids[1]->kids[2]->icode);
        }
        break;
     case 1028: // property declaration
          if (t->kids[3] && t->kids[3]->prodrule == 1027) {
                struct tree *id = t->kids[3];
                t->address = id->address; // PropertyDeclaration.addr = IDENT.addr
                if (t->kids[4] && t->kids[4]->kids[1]) { // expression
                     struct instr *assign = gen(O_ASN, *id->address, *t->kids[4]->kids[1]->address, (struct addr){R_NONE});
                     t->icode = concat(t->kids[4]->icode, assign);
                     add_to_tcode(assign);
                }
          }
          break;
    

     
     case 1086:
    case 1087:
    case 1088: // disjunction || conjunction
    case 1089:
    case 1091: // genericCallLikeComparison
    case 1092: // elvisExpression
    case 1093: // rangeExpression
    case 1094: // additiveExpression  
    case 1095: // multiplicativeExpression 
    {
        if (t->nkids == 3) {
            

             // Ensure t->address is initialized
             if (t->address == NULL) {
                 t->address = genvar(R_LOCAL); // Generate a temporary variable
             }
             t->icode = concat(t->kids[0]->icode, t->kids[2]->icode);
             struct instr *g;
             opcode_operator = operator_to_opcode(t->kids[1]->leaf->text);
             g = gen(opcode_operator, *t->address, *t->kids[0]->address, *t->kids[2]->address);
             t->icode = concat(t->icode, g);
             add_to_tcode(g);
             break;
        } else if (t->nkids == 1) {
             // Synthesize the single child's code and address
             if (t->kids[0]->icode != NULL) {
                 t->icode = t->kids[0]->icode; 
             }
             }                

        
        break;
    }

    
    case 1090: { // comparison
    if (t->nkids == 3) {
        // Generate code for left and right operands
        codegen(t->kids[0]);
        codegen(t->kids[2]);
        
        // Allocate temporary for result
        t->address = genvar(R_LOCAL);
        
        // Get operator
        char *op = t->kids[1]->leaf->text;
        int opcode;
        if (strcmp(op, ">") == 0) opcode = O_BGT;
        else if (strcmp(op, "<") == 0) opcode = O_BLT;
        else if (strcmp(op, ">=") == 0) opcode = O_BGE;
        else if (strcmp(op, "<=") == 0) opcode = O_BLE;
        else if (strcmp(op, "==") == 0) opcode = O_BEQ;
        else if (strcmp(op, "!=") == 0) opcode = O_BNE;
        
        // Generate comparison instruction
        struct instr *cmp = gen(opcode, *t->address, 
                              *t->kids[0]->address, 
                              *t->kids[2]->address);
        
        // Combine code from both operands and the comparison
        t->icode = concat(t->kids[0]->icode, t->kids[2]->icode);
        t->icode = concat(t->icode, cmp);
    }
    break;
}

     case 2020: { //  WHILE LPAREN expression RPAREN control_structure_body_or_comma {$$ = alctree(2020, "whileLoop", 5, $1, $2, $3, $4, $5);}

         // Generate the start label for the loop
         struct instr *start_label = gen(D_LABEL, *t->kids[2]->first, 
                                         (struct addr){R_NONE}, 
                                         (struct addr){R_NONE});
            printf("print from start_label\n");
            print_icode(start_label); // Print the start label for debugging

         // Generate the condition code (expression)
         struct instr *cond_code = copyinstr(t->kids[2]->icode); //Expr.icode
         printf("print from cond_code\n");
         print_icode(cond_code); // Print the condition code for debugging

         // Generate the true label for the loop body
         struct instr *true_label = gen(D_LABEL, *t->kids[2]->onTrue, 
                                        (struct addr){R_NONE}, 
                                        (struct addr){R_NONE});
        printf("print from tru_label\n");
        print_icode(true_label); // Print the true label for debugging

         // Generate the body code

         codegen(t->kids[4]->kids[0]);
         struct instr *body_code =  t->kids[4]->kids[0]->icode;
         printf("print from body_code\n");
         print_icode(body_code); // Print the body code for debugging
 

         // Generate the jump back to the start of the loop
         struct instr *loop_jump = gen(O_GOTO, *t->kids[2]->first, 
                                       (struct addr){R_NONE}, 
                                       (struct addr){R_NONE});

         // Combine all parts
         t->icode = start_label;
         add_to_tcode(start_label);

         t->icode = concat(t->icode, cond_code);
         add_to_tcode(cond_code);

         t->icode = concat(t->icode, true_label);
         add_to_tcode(true_label);

         t->icode = concat(t->icode, body_code);
         add_to_tcode(body_code);

         t->icode = concat(t->icode, loop_jump);
         add_to_tcode(loop_jump);
         break;
 
     }
    case 1075:
       if (t->kids[1]) {
          t->icode =  gen(O_RET,*t->kids[1]->address, (struct addr){R_NONE}, (struct addr){R_NONE});
          add_to_tcode(t->icode);
       } else {
          t->icode = gen(O_RET, (struct addr){R_NONE}, (struct addr){R_NONE}, (struct addr){R_NONE});
          add_to_tcode(t->icode);
       }
       break;
     case 1067: { // ifExpression
    // Generate labels
    struct addr *then_label = genlabel();
    struct addr *else_label = t->kids[5] ? genlabel() : NULL;
    struct addr *end_label = genlabel();
    
    // Generate condition code
    codegen(t->kids[2]); // expression
    add_to_tcode(t->kids[2]->icode);
    
    // Generate conditional jump
    struct instr *cond_jump = gen(O_BLE, *t->kids[2]->address,
                                (struct addr){R_CONST, .u.offset=0},
                                t->kids[5] ? *else_label : *end_label);
    add_to_tcode(cond_jump);
    
    // Generate then part
    struct instr *then_label_instr = gen(D_LABEL, *then_label,
                                       (struct addr){R_NONE},
                                       (struct addr){R_NONE});
    add_to_tcode(then_label_instr);
    
    codegen(t->kids[4]); // controlStructureBody
    add_to_tcode(t->kids[4]->icode);
    
    // Jump to end after then part if else exists
    if (t->kids[5]) {
        struct instr *then_jump = gen(O_GOTO, *end_label,
                                    (struct addr){R_NONE},
                                    (struct addr){R_NONE});
        add_to_tcode(then_jump);
    }
    
    // Generate else part if exists
    if (t->kids[5]) {
        struct instr *else_label_instr = gen(D_LABEL, *else_label,
                                          (struct addr){R_NONE},
                                          (struct addr){R_NONE});
        add_to_tcode(else_label_instr);
        
        codegen(t->kids[5]); // opt_else
        add_to_tcode(t->kids[5]->icode);
    }
    
    // Generate end label
    struct instr *end_label_instr = gen(D_LABEL, *end_label,
                                      (struct addr){R_NONE},
                                      (struct addr){R_NONE});
    add_to_tcode(end_label_instr);
    
    // Build the complete icode for this node
    t->icode = concat(t->kids[2]->icode, cond_jump);
    t->icode = concat(t->icode, then_label_instr);
    t->icode = concat(t->icode, t->kids[4]->icode);
    
    if (t->kids[5]) {
        struct instr *then_jump = gen(O_GOTO, *end_label,
                                    (struct addr){R_NONE},
                                    (struct addr){R_NONE});
        t->icode = concat(t->icode, then_jump);
        
        struct instr *else_label_instr = gen(D_LABEL, *else_label,
                                          (struct addr){R_NONE},
                                          (struct addr){R_NONE});
        t->icode = concat(t->icode, else_label_instr);
        t->icode = concat(t->icode, t->kids[5]->icode);
    }
    
    t->icode = concat(t->icode, end_label_instr);
    break;
}

    
     
    //  case 1087:
    //  case 1088:
    // //  case 1089: // equality    

    //  {
    //     if (t->nkids == 3) {
    //         t->icode = concat(t->kids[0]->icode, gen(D_LABEL, *t->kids[2]->first, (struct addr){R_NONE}, (struct addr){R_NONE}));
    //         t->icode = concat(t->icode, t->kids[2]->icode);
    //     }
    //     break;
    //  }
     /*
      * ... really, a bazillion cases, up to one for each
      * production rule (in the worst case)
      */
     default:
          /* default is: concatenate our children's code */
          t->icode = NULL;
          for (i = 0; i < t->nkids; i++)
                if (t->icode != NULL && t->kids[i]->icode != NULL)
                     t->icode = concat(t->icode, t->kids[i]->icode);
     }

}