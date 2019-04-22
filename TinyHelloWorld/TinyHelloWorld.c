char* str = "Hello World!\n";

void print()
{
    asm( "movq $13,%%rdx \n\t"
        "movq %0,%%rcx \n\t"
        "movq $0,%%rbx \n\t"
        "movq $4,%%rax \n\t"
        "int $0x80     \n\t"
        ::"r"(str):"rdx","rcx","rbx");
}

void exit()
{
    asm("movq $42,%rbx \n\t"
        "movq $1,%rax \n\t"
        "int $0x80     \n\t");
}

void nomain()
{
    print();
    exit();
}

//系统调用通过0x8中断实现,其中eax为调用号,ebx,ecx,edx等通用寄存器传递参数
//WRITE调用是往一个文件句柄写入数据,C语言原型是
//int write(int filedesc, char* buffer, int size);
//终端的文件句柄为0