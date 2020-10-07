//-*- coding: utf-8 -*-
//******************************************************************************
// Обозначение: main.c 				       
// Назначение:			
// Разработчик: Сергеева Е.И.
// Дата последней корректировки: 
//******************************************************************************

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "def_types.h"
#include "readWavFuncs.h"


/*
Путь к wav-файлу можно задать из командной строки,
по умолчанию открывается data/ton_signal.wav
 */

int main(int argc, char** argv) {
  
  char* fin_name = "data/ton_signal.wav";
  if(argc > 1){
    fin_name = argv[1];
  }
  
  FILE* f_in = fopen(fin_name, "rb");
  if(f_in == NULL){
    printf("ERROR in OPEN FILE [%s] \n", fin_name);
	  return 1;
  } else {
    printf("OPEN FILE [%s] is OK \n", fin_name);
  }
  
  //Здесь будет Ваш код
  t_wavhdr* header;
  readHeader(header, f_in);

  int N = 512;
  float* data_portion = (float*)malloc(N*sizeof(float));

  readData(data_portion, N, f_in );

  free(data_portion);

  fclose(f_in);
  
  return 0;
}
