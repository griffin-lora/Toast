#!/bin/sh
cd src
g++ -o ../out toaster.cpp toast.cpp t_cmp.cpp t_inp.cpp -lstdc++ -Wl,--no-as-needed -ldl