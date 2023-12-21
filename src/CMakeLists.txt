cmake_minimum_required(VERSION 3.25)
project(survival_game)
add_executable(${PROJECT_NAME} 
    main.c 
    player.c player.h 
    engine.c engine.h 
    area.h)