{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
    buildInputs = [
        pkgs.cmake
        pkgs.python312
        pkgs.python312Packages.matplotlib
        pkgs.python312Packages.numpy
    ];

    shellHook = ''
        echo "nixpkgs inicializados"
        export CPLUS_INCLUDE_PATH="${toString ./.}/include"
    '';
}