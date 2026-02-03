#!/bin/bash
# =====================================================
# init.sh - Script de inicialización de la librería
# =====================================================

# Comprobar que se pasó un argumento
if [ $# -ne 1 ]; then
    echo "Uso: $0 [-include_src | -build_only | -python]"
    exit 1
fi

ARG=$1

# Obtener rutas
ROOT_DIR=$(pwd)
TOOLS_DIR="$ROOT_DIR/tools/initializer"
CPP_MAKEFILE="$TOOLS_DIR/cpp/Makefile"
ROOT_MAKEFILE="$ROOT_DIR/Makefile"

# Función para limpiar todo excepto include y src
clean_except_include_src() {
    echo "Limpiando proyecto, dejando solo include/* y src/*..."
    find . -mindepth 1 ! -regex './include\(/.*\)?' \
                     ! -regex './src\(/.*\)?' \
                     ! -name "init.sh" \
                     ! -name "Makefile" \
                     -exec rm -rf {} +
}

# Función para limpiar todo excepto include y build
clean_except_include_build() {
    echo "Limpiando proyecto, dejando solo include/* y build/*..."
    find . -mindepth 1 ! -regex './include\(/.*\)?' \
                     ! -regex './build\(/.*\)?' \
                     -exec rm -rf {} +
}

case "$ARG" in
    -python)
        echo "Not implemented yet."
        ;;

    -include_src)
        echo "Preparando proyecto para incluir solo src e include..."

        # Sustituir makefile
        if [ -f "$CPP_MAKEFILE" ]; then
            echo "Copiando Makefile de cpp..."
            cp "$CPP_MAKEFILE" "$ROOT_MAKEFILE"
        else
            echo "Error: Makefile de cpp no encontrado en $CPP_MAKEFILE"
            exit 1
        fi

        # Limpiar todo excepto include/*, src/* y Makefile
        clean_except_include_src
        echo "Hecho."
        ;;

    -build_only)
        echo "Preparando proyecto para build_only..."

        # Sustituir makefile
        if [ -f "$CPP_MAKEFILE" ]; then
            echo "Copiando Makefile de cpp..."
            cp "$CPP_MAKEFILE" "$ROOT_MAKEFILE"
        else
            echo "Error: Makefile de cpp no encontrado en $CPP_MAKEFILE"
            exit 1
        fi

        # Limpiar todo excepto include/* y src/*
        clean_except_include_src

        # Ejecutar make
        echo "Ejecutando make..."
        if make; then
            echo "Compilación correcta. Limpiando todo excepto include/* y build/*..."
            clean_except_include_build
            echo "Hecho."
        else
            echo "Error: la compilación falló."
            exit 1
        fi
        ;;

    *)
        echo "Opción no reconocida: $ARG"
        echo "Uso: $0 [-include_src | -build_only | -python]"
        exit 1
        ;;
esac
