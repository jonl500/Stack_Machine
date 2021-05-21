#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//for main project work on file storage, first read and parse the file (optional struct fr individual instruction types),
//from there work on the stack and implementing the linked list
//make the stack (file read, then stack is created, only after that are the instructions fed
//don't forget to free pointers

//use enum -> probably unused due to change in plan, I want to do it, but i don't have time
typedef enum InstructionType {
    IN, OUT, LIT, DROP, DUP, SWAP, ADD, SUB, MUL, DIV, MOD, AND, OR, IFEQ, IFLT, JUMP
} InstructionType;

//unused?
typedef struct instruction {
    InstructionType type;
    int arg;
} instruction;

typedef struct node {
    int value;
    struct node *next;
} node;

node *head = NULL;
//int isEmpty(){
//if
//}

void printList() {
    node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("end of list\n");
}

void push(int value) {
    node *result = malloc(sizeof(node));

    if (head == NULL) {
        result->value = value;
        result->next = head;
        head = result;
    } else {
        result->value = value;
        result->next = head;
        head = result;

    }

}

int peek() {

    node *peeker = head;
    if (head != NULL) {
        int tempInt = peeker->value;

        return tempInt;
    } else {
        return printf("NULL\n");
    }

}

int pop() {

    if (head != NULL) {
        node *popper = head;
        int tempVal = head->value;
        popper = head;
        head = head->next;
        free(popper);
        popper = NULL;
        return tempVal;
    } else {

        printf("These are not the droids you're looking for\n");

    }
}


node *findNode(node *head, int value) {
    node *tmp = head;
    while (tmp != NULL) {
        if (tmp->value == value)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}


int main() {
    char *line = malloc(sizeof(char) * 100);


    FILE *filePointer;
    filePointer = fopen("/home/jonl500/Desktop/School PDF's/Spring '20/CSC 344/Project1/Project 1/Instructions.txt",
                        "r");
    //printf("this thing works \n");
    fgets(line, 100, filePointer);
    int n;
    //printf("fgets worked \n");
    sscanf(line, "%d", &n);
    //printf("sscanf worked \n");
    char *array[n];
    //printf("array set\n");
    printf("test\n");
    for (int i = 0; i < n; i++) {
        // read line
        // store line
        fgets(line, 100, filePointer);//get the line from the file
        //printf("%s\n", line);
        // printf("%s\n", array[i]);
        array[i] = malloc(sizeof(char) * 100);
        strncpy(array[i], line, 100); // strncopy
        // sscanf(array[i], "%s\n", line );
        printf("%s", array[i]);

        // get first part
        instruction *command = malloc(sizeof(instruction));
        char str[4];
        sscanf(array[i], "%s", str);
        //read each instruction and compare...
    }
    printf("----\n");
    int extraStorage[256];
    for (int i = 0; i < n; i++) {
        printf("%s", array[i]);
        printList(head);
        printf("%d\n", i);
//--------------------------STOR--------------------------------------------------------



//------------------------- IN -------------------------------------------------------
        if (strncmp(array[i], "IN", 2) == 0) {
            char *input = malloc(sizeof(char) * 10);
            fgets(input, 40, stdin);
            push(atoi(input));

        } //else if(strncmp(array[i], "DUP",3)==0) {}
// ------------------------ LIT fn -------------------------------------------
        else if (strncmp(array[i], "LIT", 3) == 0) {
            char *litty = array[i] + 4;
            int litter = atoi(litty);
            push(litter);
            printList(head);
        }

            //------------------------- OUT -------------------------------------------------------

        else if (strncmp(array[i], "OUT", 3) == 0) {
            int out = pop();
            printf("%d\n", out);

        }


            //-------------------------- IFEQ -----------------------------------------------
        else if (strncmp(array[i], "IFEQ", 4) == 0) {
            char *equality = array[i] + 5;
            int eqJmp = atoi(equality);
//takes the first value to compare eq
            node *thing1 = head;

            int first = thing1->value;
            //printf("beep %d\n",first);
//takes the second thing to compare eq
            node *thing2 = thing1->next;

            int second = thing2->value;
            //printf("beep %d\n",second);
            pop();
            pop();

            if (first == second) {
                i = eqJmp - 2;
                printf("yo");
                printList(head);
            } else {

            }
 //-------------------------------------------------------------------------------------
        } else if (strncmp(array[i], "IFLT", 4) == 0) {
            char *inequality = array[i] + 5;
            int eqJmp = atoi(inequality);
//takes the first value to compare eq
            node *thing1 = head;

            int first = thing1->value;
            //printf("beep %d\n",first);
//takes the second thing to compare eq
            node *thing2 = thing1->next;

            int second = thing2->value;
            //printf("beep %d\n",second);
            pop();
            pop();

            if (first < second) {
                i = eqJmp - 1;
                printf("yo\n");
              //  printList(head);
            } else {
                i++;
            }
        }
            //compare xx and yy, if equal change i. if not change y

            //for iflt, same code. except. if top element is less than the second, change i. else i++

//----------------------------------------------ADD--------------------------------------------------------------
        else if (strncmp(array[i], "ADD", 3) == 0) {
            int add1 = pop();

            int add2 = pop();

            int sum = add1 + add2;

            push(sum);

        }
//---------------------------------------SUB------------------------------------------------------------------

        else if (strncmp(array[i], "SUB", 3) == 0) {
            int sub1 = pop();

            int sub2 = pop();

            int sum1 = sub1 - sub2;

            push(sum1);
        }
            //-----------------------------------------MUL---------------------------------------------------------

        else if (strncmp(array[i], "MUL", 3) == 0) {
            int mul1 = pop();

            int mul2 = pop();

            int result = mul1 * mul2;

            push(result);
        }
//------------------------------------------------DIV----------------------------------------------------------

        else if (strncmp(array[i], "DIV", 3) == 0) {
            int div1 = pop();

            int div2 = pop();

            int result1 = div1 / div2;

            push(result1);
        }

//-------------------------------------------MOD--------------------------------------------------------------

        else if (strncmp(array[i], "MOD", 3) == 0) {
            int mod1 = pop();
            int mod2 = pop();

            int modulo = mod1 % mod2;

            push(modulo);
        }

//---------------------------------------------AND-----------------------------------------------------------

        else if (strncmp(array[i], "AND", 3) == 0) {
            int and1 = pop();
            int and2 = pop();

            int anded = and1 & and2;

            push(anded);
        }

//--------------------------------------------OR----------------------------------------------------------------

        else if (strncmp(array[i], "OR", 2) == 0) {
            int or1 = pop();
            int or2 = pop();

            int ord = or1 | or2;

            push(ord);
        }

//---------------------------------------------DROP------------------------------------------------------------

        else if (strncmp(array[i], "DROP", 4) == 0) {
          pop();

        }
//----------------------------------------------- JUMP --------------------------------------------------------

     else if (strncmp(array[i], "JUMP", 4) == 0) {
          char *jump = array[i] + 5;
         int jmp = atoi(jump);
//takes the first value to compare eq
//            node *thing1 = head;
//
//            int first = thing1->value;
//            //printf("beep %d\n",first);
//takes the second thing to compare eq
//            node *thing2 = thing1->next;
//
//            int second = thing2->value;
//            //printf("beep %d\n",second);
//            pop();
//            pop();

            i = jmp - 2;
//               printf("yo");
//                i++;
//                //printList(head);
//
    }

//-------------------- SWAP ------------------------------------------------------------------------------------
        else if (strncmp(array[i], "SWAP", 4) == 0) {
            //char *swapping = array[i] + 5;

            int peeked = pop();

            int peeked2 = pop();

            push(peeked);
            push(peeked2);

//            printList(head);
        }
            //printf("thing");


//--------------------------------------------- DUP --------------------------------------------------------------
        else if (strncmp(array[i], "DUP", 3) == 0) {
            char *duplicate = array[i] + 4;
            int dub = atoi(duplicate);
            //takes the number of values requested and duplicate
            //node *thing1 = head;
            int copy[dub];
            //printf("%d",dub);
            for (int g = dub -1; g >= 0; g--) {
                copy[g] = pop();
            }
            for (int j = 0; j < dub; ++j) {
                push(copy[j]);
            }
            for (int k = 0; k < dub; ++k) {
                push(copy[k]);
            }


            // instruction set type to IN and arg to -1

            // else if it was "DUP"
            // also read arg, and new instruction with type DUP and arg = arg

        }
        //---------------------------------------------------------------------------------------------------------------



    }
//    pop(head);
    printList(head);
    fclose(filePointer);
    findNode(head, 2);
    return 0;
}
