//-*- coding: utf-8 -*-
//******************************************************************************
// Обозначение:			readWavFuncs.h 				       
// Назначение:			
// Разработчик:     	Сергеева Е.И. 
// Дата последней корректировки: 
//******************************************************************************

#ifndef _DEF_READWAVFUNCS_H_
#define _DEF_READWAVFUNCS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "def_types.h"

void readHeader(t_wavhdr* header, FILE* f_in);

void readData(float* data_portion, int N, FILE* f_in );

#endif  
