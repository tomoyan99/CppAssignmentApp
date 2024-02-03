add_library(Lib SHARED
        pause.hpp
        AllLib.hpp
        )
# インクルードディレクトリを指定
target_include_directories(Lib
    PUBLIC ${PROJECT_SOURCE_DIR}/lib
    PUBLIC ${PROJECT_SOURCE_DIR}/lib/classes
)