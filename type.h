#ifndef TYPE_H
#define TYPE_H
#include "tree.h"
typedef struct param {
   char *name;
   struct typeinfo *type;
   struct param *next;
   } *paramlist;

struct field {			/* members (fields) of structs */
   char *name;
   struct type *elemtype;
};

/* base types. How many more base types do we need? */
#define FIRST_TYPE   1000000

#define NULL_TYPE    1000000
#define BYTE_TYPE    1000001
#define SHORT_TYPE   1000002
#define INT_TYPE     1000003  
#define LONG_TYPE    1000004
#define FLOAT_TYPE   1000005
#define DOUBLE_TYPE  1000006
#define BOOL_TYPE    1000007
#define STRING_TYPE  1000008
#define CHAR_TYPE    1000009
#define ARRAY_TYPE   1000010
#define FUNC_TYPE    1000011
#define CLASS_TYPE   1000012 /* in k0 these are only for a couple built-ins */
#define PACKAGE_TYPE 1000013 /* do we need this for built-ins in k0? maybe */
/* if we were doing a Lisp-like language, such as Python
#define LIST_TYPE    1000010
#define DICT_TYPE    1000011
*/
#define ANY_TYPE     1000014
#define LAST_TYPE    1000015

// Define the structure for type information.
typedef struct typeinfo {
   int basetype;            // Stores the base type identifier (e.g., INT_TYPE, ARRAY_TYPE).
   union {                  // Union to store additional information based on the base type.
      struct funcinfo {     // Information specific to functions.
         char *name;        // Name of the function.
         int defined;       // 0 for prototype, 1 for defined function.
         struct sym_table *st; // Pointer to the symbol table of the function.
         struct typeinfo *returntype; // Pointer to the return type of the function.
         int nparams;       // Number of parameters.
         struct param *parameters; // Linked list of parameters.
      } f;
      struct arrayinfo {    // Information specific to arrays.
         int size;          // Size of the array (-1 for unspecified/unknown size).
         struct typeinfo *elemtype; // Pointer to the type of elements in the array.
      } a;
   } u;
} *typeptr;                 // Type alias for a pointer to type information.

/* add constructors for each of the types if needed*/

typeptr alctype(int);
typeptr alcfunctype(struct tree * r, struct tree * p, struct sym_table * st);
typeptr alcarraytype(struct tree * s, struct tree * e);
char *typename(typeptr t);

typeptr assignType(char *typeName);
extern struct sym_table *global_table;
extern typeptr integer_typeptr;
extern typeptr double_typeptr;
extern typeptr char_typeptr;
extern typeptr null_typeptr;
extern typeptr string_typeptr;

extern char *typenam[];
#endif
