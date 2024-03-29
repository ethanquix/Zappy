########################################################################################################################
#                                                                                                                      #
#                                               COLOR MACROS                                                           #
#                                                                                                                      #
########################################################################################################################


if (UNIX)
    string(ASCII 27 Esc)
    set(Reset "${Esc}[m")
    set(ColourBold "${Esc}[1m")
    set(Red "${Esc}[31m")
    set(Green "${Esc}[32m")
    set(Yellow "${Esc}[33m")
    set(Blue "${Esc}[34m")
    set(Magenta "${Esc}[35m")
    set(Cyan "${Esc}[36m")
    set(White "${Esc}[37m")
    set(BoldRed "${Esc}[1;31m")
    set(BoldGreen "${Esc}[1;32m")
    set(BoldYellow "${Esc}[1;33m")
    set(BoldBlue "${Esc}[1;34m")
    set(BoldMagenta "${Esc}[1;35m")
    set(BoldCyan "${Esc}[1;36m")
    set(BoldWhite "${Esc}[1;37m")
endif ()

########################################################################################################################
#                                                                                                                      #
#                                               HEADER FUNCTION/MACROS                                                 #
#                                                                                                                      #
########################################################################################################################

set(PROJECT_NAME "Zappy")
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)
set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})
set(SETTINGS_ORGANIZATION "${BoldCyan}Epitech${Reset}")
set(SETTINGS_APPLICATION ${PROJECT_NAME}${Reset})
set(PROJECT_AUTHOR "${BoldYellow}Dimitri Wyzlic${Reset}, ${BoldRed}Hugo Laroche${Reset}, ${BoldGreen}Valentin Gaillard${Reset}, ${BoldBlue}Olivier Gillon${Reset}, ${BoldMagenta}Raphael Chriqui${Reset},
${BoldCyan}")
set(ORGANIZATION_BUILD_MESSAGE "Organization : ${SETTINGS_ORGANIZATION}")
set(PROJECT_YEAR_COPYRIGHT "2017")
set(PROJECT_AUTHOR_EMAIL "${BoldYellow}dimitri1.wyzlic@epitech.eu${Reset}, ${BoldRed}hugo1.laroche@epitech.eu${Reset}, ${BoldGreen}valentin.gaillard@epitech.eu${Reset}")
set(PROJECT_AUTHOR_EMAIL2 "${BoldBlue}olivier.gillon@epitech.eu${Reset}, ${BoldMagenta}raphael.chriqui@epitech.eu${Reset}")
set(PROJECT_BUILD_MESSAGE  " v" ${PROJECT_VERSION} " (" ${CMAKE_BUILD_TYPE} ")")
set(COPYRIGHT_BUILD_MESSAGE "Copyright (c) ${PROJECT_YEAR_COPYRIGHT}  ${PROJECT_AUTHOR}")
set(EMAIL_BUILD_MESSAGE "Email : ${PROJECT_AUTHOR_EMAIL}")

set(ZAPPY_MSG "

 ▄███████▄     ▄████████    ▄███████▄    ▄███████▄ ▄██   ▄
██▀     ▄██   ███    ███   ███    ███   ███    ███ ███   ██▄
      ▄███▀   ███    ███   ███    ███   ███    ███ ███▄▄▄███
 ▀█▀▄███▀▄▄   ███    ███   ███    ███   ███    ███ ▀▀▀▀▀▀███
  ▄███▀   ▀ ▀███████████ ▀█████████▀  ▀█████████▀  ▄██   ███
▄███▀         ███    ███   ███          ███        ███   ███
███▄     ▄█   ███    ███   ███          ███        ███   ███
 ▀████████▀   ███    █▀   ▄████▀       ▄████▀       ▀█████▀
")

macro(PRINT_HEADER)
    message(" " ${BoldMagenta}${ZAPPY_MSG}${Reset})
    #message(" ----------------------------------------------------------------------------------------------------------")
    message("                      " ${BoldMagenta}${PROJECT_NAME}${Reset} ${PROJECT_BUILD_MESSAGE})
    message(" ")
    message(" " ${COPYRIGHT_BUILD_MESSAGE})
    message(" " ${EMAIL_BUILD_MESSAGE})
    message("         " ${PROJECT_AUTHOR_EMAIL2})
    message(" " ${ORGANIZATION_BUILD_MESSAGE})
    message(" ")
    message(" ")
    #message(" ----------------------------------------------------------------------------------------------------------")
endmacro()
