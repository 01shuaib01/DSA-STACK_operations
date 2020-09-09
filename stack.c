#include <stdio.h>                   //header file which can be used in printf() and many other predefined function. 
#include <stdlib.h>                 //header file which contain malloc predefined function.

//<---------------creation of STACK----------------->
struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr);                      //Declaration of isFull() function.
int isEmpty(struct stack *ptr);                     //Declaration of isEmpty() function.
int PUSH(struct stack *ptr,int val);                //Declaration of PUSH() function.
int POP(struct stack *ptr);                         //Declaration of POP() function.
void Display(struct stack *ptr);                    //Declaration of Display() function.
int stackTop(struct stack * ptr);                   //Declaration of stackTop() function.
int stackBottom(struct stack * ptr);                //Declaration of stackBottom() function.

int main()
{
    struct stack *sp;                                   //sp(stack pointer) pointer.
    sp = (struct stack *)malloc(sizeof(struct stack));

    sp->size = 8;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));            //creating a Memory on HEAP.

    printf("Before pushing element is FULL : %d\n",isFull(sp));
    printf("Before Pushing element is Empty : %d\n",isEmpty(sp));

//<------------perform a PUSH (insert element in stack) operation--------------->
    PUSH(sp,20);
    PUSH(sp,30);
    PUSH(sp,40);
    PUSH(sp,50);
    PUSH(sp,34);
    PUSH(sp,43);
    PUSH(sp,59);
    PUSH(sp,33);
    PUSH(sp,11);    //Stack Overflow item cannot store in memory.

    Display(sp);        //Display all element in the stack.

//<--------------This isFull() & isEmpty() check stack full or empty----------->
    printf("After pushing element is FULL : %d\n",isFull(sp));
    printf("After Pushing element is Empty : %d\n",isEmpty(sp));

 //<---------------------perform a POP(Deletion of element) operation.---------> 
    printf("pop element %d \n",POP(sp));
    printf("pop element %d \n",POP(sp)); 
    printf("pop element %d \n",POP(sp));
    printf("\nAfter POP element \n");
       
    Display(sp);        //Display all element in the stack.
    
    printf("\ntop value of stack : %d",stackTop(sp));           //print top most value in the stack.
    printf("\nBottom value of stack : %d",stackBottom(sp));     //print bottom value in the stack.

    return 0;           //This indegate successfull exicute a program.
}

//<-------------Before PUSH an element to check stack full or not----------------->
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

//<-------------Before POP an element to check stack Empty or not----------------->
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

//<-------------------This function PUSH(insert an element) in the stack------------------> 
int PUSH(struct stack *ptr,int val)
{
    if(isFull(ptr)){
        printf("stack overflow cannot PUSH %d to the stack \n",val);
        return -1;
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

//<-------------------This function POP(insert an element) in the stack------------------> 
int POP(struct stack *ptr)
{
    if(isEmpty(ptr)){
        printf("stack Underflow \n");
    }
    else{
       int val = ptr->arr[ptr->top];
        ptr->top--;
          return val;
    }
  
}

//<--------------Print all element in the stack.-------------------------> 
void Display(struct stack *ptr)
{
    for(int i=0;i<=ptr->top;i++){
        printf("stack Element : %d\n",ptr->arr[i]);
    }
}

//<------------print top value in the stack.------------------------->
int stackTop(struct stack * ptr)
{
    return ptr->arr[ptr->top];
}

//<--------------print bottom value in the stack
int stackBottom(struct stack * ptr)
{
    return ptr->arr[0];
}