/*
 * If I ever finish this, it will be a stripped down version of symtab
 * that has removed the string buffery stuff.
 */

 #ifndef SYMTAB_H
 #define SYMTAB_H
 
 
 typedef struct sym_table {
   int nEntries;			/* # of symbols in the table */
   struct sym_entry *next;
   struct sym_table *parent;		/*   enclosing scope, superclass etc. */
   /* more per-scope/per-symbol-table attributes go here */
   } *SymbolTable;

   
 /*
  * Entry in symbol table.
  */
 typedef struct sym_entry {
      char *s;				/* string */
      struct sym_entry *next;
      /* more symbol attributes go here for code generation */
      /*   SymbolTable table;			what symbol table do we belong to*/

      } *SymbolTableEntry;


#define pushscope(stp) do { stp->parent = current; current = stp; } while (0)
#define popscope() do { current = current->parent; } while(0)
 #endif					/* SYMTAB_H */
 