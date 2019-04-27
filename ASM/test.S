.code32
.globl	ArraySum
.type	ArraySum, @function

ArraySum:
    pushl    %ebp
    movl    %esp, %ebp
    movl    8(%ebp), %eax    
    movl    12(%ebp), %edx  
    movl    %edx, (%eax)      
    movl    8(%ebp), %eax
    movl    16(%ebp), %edx  
    movl    %edx, 4(%eax)   
    popl    %ebp
    ret
