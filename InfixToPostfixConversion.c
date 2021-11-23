// -----------------header files declaration-----------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// --------------stack declaration using struct-----------
struct stack
{
    int size;
    int top;
    int *arr;
};

// --------stacktop (function) -----------------
int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}



// ----------------------check it is operator or not-----------
int operanderCheck(char infix)
{
    if (infix == '+' || infix == '-' || infix == '*' || infix == '/' || infix == '$')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



// -----------------is full (function)-----------------------
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}





// -----------------------insert the element into the stack (function)----------------
void push(struct stack *ptr, char val)
{
    if (isFull(ptr))    //check stack is full or not
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;         
        ptr->arr[ptr->top] = val;           //inserting the values 
    }
}




// -------------check which operator is biggest-----------------
int operanderBigger(char infix)
{
    if (infix == '$')
        return 4;
    else if (infix == '*' || infix == '/')
        return 3;
    else if (infix == '-' || infix == '+')
        return 2;
    else if (infix == '(')
        return 0;
    else
        return 0;
}



// -------------------check empty (function)-----------------------
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}


// ----------------------delecting element from stack (function)-------------------
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))           // checking stack empty or not
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

char *convertInfixToPostfix(char *infix, int size1)
{
    // -------------variable declaration------------
    int i = 0, j = 0;

    // ------------stake dynamically decleration---------
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = size1;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // -------------Logic of infix to postfix expresion-------------
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    while (infix[i] != '\0')
    {
        if (operanderBigger(infix[i]) > operanderBigger(stackTop(s)))
        {
            push(s, infix[i]);
            i++;
        }

        else if (infix[i] == '(')
        {
            push(s, infix[i]);
            i++;
        }
        else if (infix[i] == ')')
        {
            while (s->arr[s->top] != '(')
            {
                postfix[j] = pop(s);
                j++;
            }
            i++;
            pop(s);
        }

        else
        {
            if (!operanderCheck(infix[i]))
            {
                postfix[j] = infix[i];
                j++;
                i++;
            }

            else
            {
                postfix[j] = pop(s);
                j++;
            }
        }
    }


// ---------------removing all remaining element from stack-----------------
    while (!isEmpty(s))
    {
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;         //returning postfix expersion
}


// -------------int main program -----------------

int main()
{
    char *exp = "A+B/d*6C-(D+/D-A)FH+*";   //Infix expresion 
    int size = sizeof(exp) / sizeof(exp[0]);    //finding size of exp
    printf("%s", convertInfixToPostfix(exp, size));     //it will print the postfix expresion
    return 0;
}