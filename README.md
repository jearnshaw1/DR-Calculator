        ------------------------------------BUILDING---------------------------------------

            ---------------------------------CMAKE-------------------------------------
                1.  In the root of the project execute 'cmake -B _build' which will
                    perform cmake magic like creating a makefile etc...     
                2.  In the root again, execute 'cmake --build _build'


NOTES
some variables that can be set to override the behaviour of findboost at this page
https://discourse.cmake.org/t/findboost-ignores-all-hints-and-wont-find-the-right-installation/3883

CMAKE_CXX_FLAGS can be set with -nostdinc to avoid any of the /usr lib or include directories
