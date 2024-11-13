add_executable(annotate annotate.cpp)
set_target_properties(annotate PROPERTIES FOLDER "Tools")
target_link_libraries(annotate PUBLIC annotater)
