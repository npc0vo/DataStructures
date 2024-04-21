//
// Created by Npc on 2024/4/21.
//
/*Target:
 * 1.定义一套opcode
 * 2.实现opcode的解释器*/
#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

#define OPCODE_N 7  //定义opcode的长度
#define F_LEN 12

char *vm_stack; //虚拟机的栈
char enc_flag[] = {0x23, 0x76, 0x61, 0x2a, 0x7b, 0x22, 0x38, 0x63, 0x53, 0x22, 0x3f,0x22};
//flag=1ds8i0*qA0-0
//要将想要实现功能的伪代码转成自定义的opcode
unsigned char vm_code[] = {
	0xf5,
    0xf1,0xe1,0x0,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x20,0x00,0x00,0x00,
    0xf1,0xe1,0x1,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x21,0x00,0x00,0x00,
    0xf1,0xe1,0x2,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x22,0x00,0x00,0x00,
    0xf1,0xe1,0x3,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x23,0x00,0x00,0x00,
    0xf1,0xe1,0x4,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x24,0x00,0x00,0x00,
    0xf1,0xe1,0x5,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x25,0x00,0x00,0x00,
    0xf1,0xe1,0x6,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x26,0x00,0x00,0x00,
    0xf1,0xe1,0x7,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x27,0x00,0x00,0x00,
    0xf1,0xe1,0x8,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x28,0x00,0x00,0x00,
    0xf1,0xe1,0x9,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x29,0x00,0x00,0x00,
    0xf1,0xe1,0xa,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x2a,0x00,0x00,0x00,
    0xf1,0xe1,0xb,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x2b,0x00,0x00,0x00,
    0xf1,0xe1,0xc,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x2c,0x00,0x00,0x00,
    0xf4
};
enum opcodes{
    MOV=0xf1,
    XOR=0xf2,
    RET=0xf4,
    READ=0xf5,
};

enum regist{
    R1=0xe1,
    R2=0xe2,
    R3=0xe3,
};
//vm_opcode定义
typedef struct
{
    unsigned char opcode;
    void (*handle)(void *);
    /*声明了一个函数指针 handle，该指针指向一个函数，
     * 该函数接受一个 void* 类型的参数，并且不返回任何值。*/
}vm_opcode;

//vm_cpu结构体
/*其中R1-3是定义的通用寄存器，用来传参或者存放返回值,eip指向正在解释的opcode地址*/
typedef struct vm_cpus
{
   int r1; //虚拟寄存器R1
   int r2; //虚拟寄存器R2
   int r3; //虚拟寄存器R3
   unsigned char *eip; //指向正在解释的opcode地址

   vm_opcode op_list[OPCODE_N];//opcode列表，存放所有的opcode以及对应的处理函数
}vm_cpu;



void mov_(vm_cpu *cpu);      //change flag position
void xor_(vm_cpu *cpu);      //xor flag , 0x1-0x9
void read_(vm_cpu *cpu);    //call read ,read the flag
void vm_init(vm_cpu *cpu);
void vm_start(vm_cpu *cpu);
void vm_dispatcher(vm_cpu *cpu);
void check();
//handles具体实现
void mov_(vm_cpu *cpu)
{
    /*//mov指令的参数都隐藏在字节码中，指令表示后的一个字节是寄存器标识，
     * 第二到第五是要mov的数据在vm_stack上的偏移
    //我这里只是实现了从vm_stack上取数据和存数据到vm_stack上*/
    unsigned char *res=cpu->eip+1; //寄存器标识,即指令的第一个字节
    int *offset=(int *)(cpu->eip+2); //数据在vm_stack上的偏移,即指令的第二道第5字节
    char *dest=0;
    dest=vm_stack;

    switch (*res) {
        case 0xe1:
            cpu->r1=*(dest+*offset);// 从vm_stack上取数据，存储到cpu结构体的r1寄存器中
            break;
        case 0xe2:
            cpu->r2=*(dest+*offset);// 从vm_stack上取数据，存储到cpu结构体的r2寄存器中
            break;
        case 0xe3:
            cpu->r3=*(dest+*offset);  // 从vm_stack上取数据，存储到cpu结构体的r3寄存器中
            break;
        case 0xe4:
        {
            int x=cpu->r1; // 从cpu结构体的r1寄存器中取数据
            *(dest+*offset)=x; // 将数据存储到vm_stack的指定偏移位置上
            break;
        }
    }


    cpu->eip+=6; //mov指令占6个字节，eip向后偏移6位
}

void xor_(vm_cpu *cpu)
{
    int temp;
    temp=cpu->r1^cpu->r2;
    temp ^=0x12;
    cpu->r1=temp;
    cpu->eip+=1;  //xor指令占一个字节
}

void read_(vm_cpu *cpu)
{
    char *dest=vm_stack;
    read(0,dest,12); //用于往虚拟栈中读入数据
    cpu->eip+=1;
}



//vm_init函数
void vm_init(vm_cpu *cpu)
{
    cpu->r1=0;
    cpu->r2=0;
    cpu->r3=0;
    cpu->eip=(unsigned char *)vm_code; //将eip指向opcode的地址

    cpu->op_list[0].opcode=0xf1;
    cpu->op_list[0].handle=(void (*)(void *))mov_;
   /*   mov：这是一个函数名，表示函数的地址。
        (*)：这表示一个指针，指向一个函数。
        (void *)：这表 示函数接受一个 void* 类型的参数。
         void：这表示函数不返回任何值。*/
   //这样就可以将0xF1的操作码与对应的handle函数关联在一起了

   //以下同理
   cpu->op_list[1].opcode=0xf2;
   cpu->op_list[1].handle=(void (*)(void *))xor_;

   cpu->op_list[2].opcode=0xf5;
   cpu->op_list[2].handle=(void (*)(void *))read_;

   vm_stack=(char *)malloc(0x512);
   memset(vm_stack,0,0x512);
}

//分发器
void vm_dispatcher(vm_cpu *cpu)
{
    int i;
    for(i=0;i<OPCODE_N;i++)
    {
        if(*cpu->eip==cpu->op_list[i].opcode)
        {
            cpu->op_list[i].handle(cpu);
            break;
        }
    }
}

void vm_start(vm_cpu *cpu)
{
    cpu->eip=(unsigned char*)vm_code;
    while((*cpu->eip)!=RET)
    {
        vm_dispatcher(cpu);  //执行对应函数
    }
}



void check()
{
    int i;
    char *target=vm_stack;
    for(i=0;i<F_LEN;i++)
    {
        int offset=i+0x20;
        if((char)target[offset]!=enc_flag[i])
        {
            puts("error");
        }
        else{
            continue;
        }
    }
     puts("right");
}
