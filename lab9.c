#include <stdio.h>
#include "tac.h"

void tacprint(struct instr *list) {
    while (list) {
        printf("%s %s(%s), %s(%s), %s(%s)\n", opcodename(list->opcode), 
               regionname(list->dest.region), 
               list->dest.region == R_NAME ? list->dest.u.name : list->dest.u.offset,
               regionname(list->src1.region), 
               list->src1.region == R_NAME ? list->src1.u.name : list->src1.u.offset,
               regionname(list->src2.region), 
               list->src2.region == R_NAME ? list->src2.u.name : list->src2.u.offset);
        list = list->next;
    }
}
int main() {
    struct instr *head = NULL;
    struct instr *tail = NULL;
    struct addr i = {R_LOCAL, .u.offset = 0};
    struct addr five = {R_CONST, .u.offset = 5};
    struct addr one = {R_CONST, .u.offset = 1};
    struct addr temp1 = {R_LOCAL, .u.offset = 8};
    struct addr temp2 = {R_LOCAL, .u.offset = 16};
    struct addr string = {R_NAME, .u.name = "Variable i is %d"};
    struct addr none = {R_NONE, .u.offset = 0};



    struct instr *assign_i = gen(O_ASN, i, five, none);
    struct instr *Mult = gen(O_MUL, temp1,i,i );
    struct instr *add = gen(O_ADD, temp2, temp1, one);
    struct instr *assign_i1 = gen(O_ASN,i,temp2, none);
    struct instr *pmaram = gen(O_PARM, i,none, none);
    struct instr *pmaram1 = gen(O_PARM,string,none, none);
    struct instr *call = gen(O_CALL, none, string, i);
    struct instr *ret = gen(O_RET, none, none, none);

    // Build the linked list
    head = concat(assign_i, concat(Mult, concat(add, concat(assign_i1, concat(pmaram, concat(pmaram1, concat(call, ret)))))));

    // Print TAC linked list
    tacprint(head);

    return 0;



}