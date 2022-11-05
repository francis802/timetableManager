cmake_minimum_required(VERSION 3.23)
project(project_aed)

set(CMAKE_CXX_STANDARD 14)

add_executable(project_aed main.cpp Aula.h Estudante.h GestaoHor.h UCTurma.h Aula.cpp UCTurma.cpp GestaoHor.cpp Estudante.cpp Menu.cpp Menu.h Pedido.cpp Pedido.h MenuOcupacao.cpp MenuOcupacao.h MenuHorario.cpp MenuHorario.h MenuEstudantes.cpp MenuEstudantes.h)
