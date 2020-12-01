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
#include "fftw3.h"

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

  // Reading a header of file  
  t_wavhdr header;
  readHeader(&header, f_in);

  int N = 512;


  // Calculate the number of portions and the tail size
  int portions_info[2]; //[PortionQuantity, TailSize]
  calcPortions(&portions_info[0], &header, N);

  // Reading portions till the end in cycle
  double data_portion[N];

  readData(&data_portion[0], N, f_in);
  
  char* f_out_name = "python/output.dat";
  FILE* f_out = fopen(f_out_name, "wb");
  if(f_out == NULL){
    printf("ERROR in OPEN FILE [%s] \n", f_out_name);
	  return 1;
  } else {
    printf("OPEN FILE [%s] is OK \n", f_out_name);
  }
  fftw_complex out[N/2+1];
  //test fft
  fftw_plan plan;
  plan = fftw_plan_dft_r2c_1d(N, data_portion, out,  FFTW_ESTIMATE);

  fftw_execute(plan);

  fftw_destroy_plan(plan);
  int j;
  double sq[N/2+1];
  for(j=0;j<N/2+1;j++){

    sq[j]=sqrt((out[j][0])*(out[j][0])+(out[j][1])*(out[j][1]));
    fprintf(f_out, "%f\n",sq[j]);
  }



  int i;
  for(i = 0; i < portions_info[0]; ++i){
      readData(&data_portion[0], N, f_in );
  }

  // Reading tail
  if (portions_info[1] > 0) {
    memset(data_portion, 0.0, sizeof data_portion);
    readData(&data_portion[0], portions_info[1], f_in );
  }



  //float data_portion[N];
  //readData(&data_portion[0], N, f_in );

  fclose(f_in);
  
  return 0;
}
