# #!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Created on Sun Nov 22 10:47:18 2020

@author: helladmin
""" 

import numpy as np

import matplotlib as mpl
import matplotlib.pyplot as plt

##########################################################
# https://matplotlib.org/gallery.html
# хорошая подборка разных примеров отображения данных
##########################################################

if (__name__ ==  '__main__'):
###
    data = np.loadtxt('output.dat')
    datasize = 2*(len(data)-1) # в файл то записано всего N/2+1 отсчётов спектра
    arr_n = np.arange(datasize/2) # а частотных каналов N/2
    fd = 24000/2 #!! значение f_d из заголовка делим пополам (это особенность генерации данных wav-файлов)
    
    x = arr_n * (fd/datasize) ## значения по оси X
    fig1, ax1 = plt.subplots()
    
    ax1.plot(x, data[0:len(arr_n)]) # должен быть такой же размер как и по оси x 
    #ax1.set_yscale('linear') ## масштаб по оси Y

    # Подписи
    ax1.set_title(f'DFT ton_signal N = {datasize}') # простой способ вывести значение переменной в форматированной строке
    ax1.set_xlabel('Частота')
    ax1.set_ylabel('Амплитуда')
    
    ax1.grid(True) #включить сетку

## Отображаем все рисунки (вызывается один раз)
    plt.show()
else:
    print(__name__, 'is imported')
    
   
