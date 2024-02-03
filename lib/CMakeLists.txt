add_library(Lib SHARED
        calc.hpp
        Game.hpp
        bar.hpp
        )
# インクルードディレクトリを指定
target_include_directories(Lib
    PUBLIC ${PROJECT_SOURCE_DIR}/lib
)