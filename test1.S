        .code32
        .globl  ArraySum
        .type   ArraySum, @function

ArraySum:
    pushl    %ebp
    movl    %esp, %ebp
    subl    $16, %esp
    movl    $0, -8(%ebp)
    movl    $0, -4(%ebp)
    jmp    .L2
.L3:
    movl    -4(%ebp), %eax
    sall    $2, %eax
    addl    8(%ebp), %eax
    movl    (%eax), %eax
    addl    %eax, -8(%ebp)
    addl    $1, -4(%ebp)
.L2:
    movl    -4(%ebp), %eax
    cmpl    12(%ebp), %eax
    jl    .L3
    movl    -8(%ebp), %eax
    leave
    ret
