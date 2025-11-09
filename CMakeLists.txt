cmake_minimum_required(VERSION 3.10.0)
project(motor-ajedrez VERSION 0.1.0 LANGUAGES C CXX)

# 1. Busca automáticamente todos los archivos .cpp en la carpeta 'src'
#    y los guarda en una variable llamada "SOURCES"
file(GLOB SOURCES "src/*.cpp")

# 2. Crea el ejecutable usando esa lista de archivos
add_executable(motor-ajedrez ${SOURCES})

# 3. Le dice dónde buscar los .h
target_include_directories(motor-ajedrez PUBLIC include)