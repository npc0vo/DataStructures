//
// Created by Npc on 2024/4/21.
//
#include "vm.h"
int main() {
    vm_cpu cpu = {0};
    puts("---------------------");
    puts("please input the flag:");
    vm_init(&cpu);
    vm_start(&cpu);
    check();
    system("pause");
    return 0;
}