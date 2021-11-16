/*******************************************************************************
*
*  Filename    : Named.hpp
*  Description : Base Class with std::string as ID and latex title
*  Author      : Yi-Mu "Enoch" Chen [ ensc@hep1.phys.ntu.edu.tw ]
*
*******************************************************************************/
#ifndef MANAGERUTILS_COMMON_PROGRESSBAR_HPP
#define MANAGERUTILS_COMMON_PROGRESSBAR_HPP

#include <iostream>
#include <chrono>
#include <tuple>

#define PBSTR "========================================================================================================================================="
#define PBWIDTH 60

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

//std::cout << RED << "hello world" << RESET << std::endl;

namespace mgr{
    std::tuple<int, int, int> format_duration( std::chrono::milliseconds& );
    void ProgressBar( const int&, const int& );
}

#endif/* end of include guard: MANAGERUTILS_COMMON_NAMED_HPP */
