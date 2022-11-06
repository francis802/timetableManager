cmake_minimum_required(VERSION 3.23)
project(project_aed)

set(CMAKE_CXX_STANDARD 14)

add_executable(project_aed main.cpp codigo/Aula.h codigo/Estudante.h codigo/GestaoHor.h codigo/UCTurma.h
        codigo/Aula.cpp codigo/UCTurma.cpp codigo/GestaoHor.cpp codigo/Estudante.cpp codigo/Menu.cpp
        codigo/Menu.h codigo/Pedido.cpp codigo/Pedido.h codigo/MenuOcupacao.cpp codigo/MenuOcupacao.h
        codigo/MenuHorario.cpp codigo/MenuHorario.h codigo/MenuEstudantes.cpp codigo/MenuEstudantes.h)
