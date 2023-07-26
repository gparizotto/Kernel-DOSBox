/* TESTE DOS SLIDES DA AULA, IMPLEMENTAÇÃO DO TESTE BASE DO NÚCLEO */

#include <kernel.h>
#include <stdio.h>

void far processo1(){
 int i = 0;

 while(i < 10000){
  printf("1");
  i++;
 }

 endProcess();
}

void far processo2(){
 int i = 0;

 while(i < 10000){
  printf("2");
  i++;
 }

 endProcess();
}

void far processo3(){
 int i = 0;

 while(i < 10000){
  printf("3");
  i++;
 }

 endProcess();
}

main()
{
 createProcess(processo1, "proc1");
 createProcess(processo2, "proc2");
 createProcess(processo3, "proc3");

 activeScheduler();
}